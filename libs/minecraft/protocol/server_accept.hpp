#pragma once
#include "daft_hash.hpp"
#include "minecraft/hexdump.hpp"
#include "minecraft/multibyte.hpp"
#include "minecraft/net.hpp"
#include "minecraft/packets/client/encryption_response.hpp"
#include "minecraft/packets/client/handshake.hpp"
#include "minecraft/packets/client/login_start.hpp"
#include "minecraft/packets/server/encryption_request.hpp"
#include "minecraft/packets/server/login_success.hpp"
#include "minecraft/packets/server/set_compression.hpp"
#include "minecraft/protocol/daft_hash.hpp"
#include "minecraft/protocol/mojang_login_data.hpp"
#include "minecraft/report.hpp"
#include "minecraft/security/private_key.hpp"
#include "minecraft/variant.hpp"
#include "read_frame.hpp"
#include "stream.hpp"

#include <boost/json.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/webclient/get.hpp>
#include <boost/webclient/internet_session.hpp>
#include <spdlog/spdlog.h>

namespace minecraft::protocol
{
    struct server_accept_state
    {
        server_accept_state(std::string                                       server_id,
                            std::optional< minecraft::security::private_key > pk                    = {},
                            int                                               compression_threshold = 256);

        //
        // inputs
        //
        std::string                                       server_id;
        std::optional< minecraft::security::private_key > server_key;
        int                                               compression_threshold;

        // frames

        using client_packet_variant = variant< packets::client::login_start, packets::client::encryption_response >;
        using server_packet_variant = variant< packets::server::set_compression,
                                               packets::server::encryption_request,
                                               packets::server::login_success >;

        client_packet_variant                                   client_packet;
        server_packet_variant                                   server_packet;
        std::vector< uint8_t >                                  server_public_key_der;
        std::optional< boost::webclient::unique_http_response > auth_response;
        std::optional< mojang_login_data >                      mojang_data;

        friend auto operator<<(std::ostream &os, server_accept_state const &arg) -> std::ostream &;
    };

    struct server_accept_op_base
    {
        server_accept_op_base(server_accept_state &state)
        : state(state)
        , coro()
        , context("login start")
        {
        }

      protected:
        static boost::uuids::uuid generate_uuid();

        auto log_fail(error_code &ec) const -> error_code &
        {
            if (ec.failed())
                spdlog::warn("{} failed: {}", context, report(ec));
            return ec;
        };

        auto log_fail(error_code const &ec) const -> error_code const &
        {
            if (ec.failed())
                spdlog::warn("{} failed: {}", context, report(ec));
            return ec;
        };

        server_accept_state &state;
        net::coroutine       coro;
        const char *         context = "login start";
    };

    template < class NextLayer >
    struct server_accept_op : server_accept_op_base
    {
        using stream_type = stream< NextLayer >;

        server_accept_op(stream_type &stream, server_accept_state &state)
        : server_accept_op_base(state)
        , stream(stream)
        {
        }

        template < class Self >
        void operator()(Self &self, error_code ec, boost::webclient::unique_http_response response)
        {
            state.auth_response.emplace(std::move(response));
            spdlog::info("response: \n{}\n", state.auth_response->body());
            spdlog::info("log: \n{}\n", state.auth_response->log());
            (*this)(self, ec);
        }

        template < class Self >
        void operator()(Self &self, error_code ec = {}, std::size_t bytes_transferred = 0)
        {
            boost::ignore_unused(bytes_transferred);
#include <boost/asio/yield.hpp>
            if (log_fail(ec).failed())
                return self.complete(ec);

            reenter(coro)
            {
                yield
                {
                    auto &pkt = state.client_packet.emplace< packets::client::login_start >();
                    async_expect_frame(stream, pkt, std::move(self));
                }

                {
                    auto &logstart = get< packets::client::login_start >(state.client_packet);
                    if (verify(logstart, ec).failed())
                        return self.complete(log_fail(ec));
                    stream.player_name(logstart.name);
                }

                if (state.server_key.has_value())
                {
                    context = "encryption request";

                    yield
                    {
                        auto &pkt = state.server_packet.emplace< packets::server::encryption_request >();
                        prepare(pkt, state.server_id, *state.server_key);
                        state.server_public_key_der = pkt.public_key;
                        stream.async_write_packet(pkt, std::move(self));
                    }

                    //
                    // receive encryption response
                    //

                    yield
                    {
                        context   = "encryption response";
                        auto &pkt = state.client_packet.emplace< packets::client::encryption_response >();
                        async_expect_frame(stream, pkt, std::move(self));
                    }

                    //
                    // decode shared secret
                    //

                    yield
                    {
                        context = "verify with mojang";
                        using net::buffer;
                        auto &request  = get< packets::server::encryption_request >(state.server_packet);
                        auto &response = get< packets::client::encryption_response >(state.client_packet);
                        auto  secret   = response.decrypt_secret(*state.server_key, request.verify_token, ec);
                        if (log_fail(ec).failed())
                            return self.complete(ec);
                        stream.set_encryption(secret);
                        daft_hash_impl hasher;
                        hasher.update(buffer(state.server_id));
                        hasher.update(buffer(secret));
                        hasher.update(buffer(state.server_public_key_der));
                        auto hash = hasher.finalise();
                        auto url  = "https://sessionserver.mojang.com/session/minecraft/hasJoined?username=" +
                                   stream.player_name() + "&serverId=" + hash;   // + "&ip=ip";
                        spdlog::info("url [{}]", url);
                        boost::webclient::async_get(stream.inet_session(), url, std::move(self));
                    }

                    this->context = "parse mojang response";
                    if (state.auth_response->status_int() != 200)
                    {
                        spdlog::warn("mojang response [code {}] [reason {}]",
                                     state.auth_response->status_int(),
                                     state.auth_response->status_message());
                        log_fail(error::invalid_mojang_response);
                        return self.complete(ec);
                    }
                    state.mojang_data.emplace(boost::json::parse(state.auth_response->body(), ec));
                    if (log_fail(ec).failed())
                        return self.complete(ec);
                }

                yield
                {
                    context       = "set compression";
                    auto &pkt     = state.server_packet.emplace< packets::server::set_compression >();
                    pkt.threshold = state.compression_threshold;
                    stream.async_write_packet(pkt, std::move(self));
                }

                // note: set threshold after writing packet
                stream.compression_threshold(state.compression_threshold);

                //
                // send login success
                //
                yield
                {
                    context   = "success";
                    auto &pkt = state.server_packet.emplace< packets::server::login_success >();
                    if (state.mojang_data)
                    {
                        pkt.username.assign(state.mojang_data->name.begin(), state.mojang_data->name.end());
                        pkt.uuid = insert_dashes(state.mojang_data->id);
                    }
                    else
                    {
                        pkt.username = stream.player_name();
                        pkt.uuid     = to_string(server_accept_op_base::generate_uuid());
                    }
                    stream.async_write_packet(pkt, std::move(self));
                }
                return self.complete(log_fail(ec));
            }
#include <boost/asio/unyield.hpp>
        }

      private:
        stream_type &stream;
    };

    template < class NextLayer, class CompletionHandler >
    auto async_server_accept(stream< NextLayer > &stream, server_accept_state &state, CompletionHandler &&handler)
    {
        return net::async_compose< CompletionHandler, void(error_code) >(
            server_accept_op< NextLayer >(stream, state), handler, stream);
    }
}   // namespace minecraft::protocol