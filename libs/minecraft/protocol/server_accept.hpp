#pragma once
#include "daft_hash.hpp"
#include "minecraft/client/encryption_response.hpp"
#include "minecraft/client/handshake.hpp"
#include "minecraft/client/login_start.hpp"
#include "minecraft/hexdump.hpp"
#include "minecraft/multibyte.hpp"
#include "minecraft/net.hpp"
#include "minecraft/protocol/daft_hash.hpp"
#include "minecraft/report.hpp"
#include "minecraft/security/private_key.hpp"
#include "minecraft/server/encryption_request.hpp"
#include "minecraft/server/login_success.hpp"
#include "minecraft/server/set_compression.hpp"
#include "read_frame.hpp"
#include "stream.hpp"

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <spdlog/spdlog.h>
#include <variant>

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

        using client_packet_variant = std::variant< client::login_start, client::encryption_response >;
        using server_packet_variant =
            std::variant< server::set_compression, server::encryption_request, server::login_success >;

        client_packet_variant  client_packet;
        server_packet_variant  server_packet;
        std::vector< uint8_t > server_public_key_der;

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

        /*
        template<class Self>
        void operator()(Self& self, error_code ec, boost::webclient::http_response&& response)
        {

        }
*/
        template < class Self >
        void operator()(Self &self, error_code ec = {}, std::size_t bytes_transferred = 0)
        {
#include <boost/asio/yield.hpp>
            if (log_fail(ec).failed())
                return self.complete(ec);

            reenter(coro)
            {
                yield
                {
                    auto &pkt = state.client_packet.emplace< client::login_start >();
                    async_expect_frame(stream, pkt, std::move(self));
                }

                {
                    auto &logstart = std::get< client::login_start >(state.client_packet);
                    if (verify(logstart, ec).failed())
                        return self.complete(log_fail(ec));
                    stream.player_name(logstart.name);
                }

                if (state.server_key.has_value())
                {
                    context = "encryption request";

                    yield
                    {
                        auto &pkt = state.server_packet.emplace< server::encryption_request >();
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
                        auto &pkt = state.client_packet.emplace< client::encryption_response >();
                        async_expect_frame(stream, pkt, std::move(self));
                    }

                    //
                    // decode shared secret
                    //

                    {
                        using net::buffer;
                        auto &request  = std::get< server::encryption_request >(state.server_packet);
                        auto &response = std::get< client::encryption_response >(state.client_packet);
                        auto  secret   = response.decrypt_secret(*state.server_key, request.verify_token, ec);
                        if (log_fail(ec).failed())
                            return self.complete(ec);
                        stream.set_encryption(secret);
                        daft_hash_impl hasher;
                        hasher.update(buffer(state.server_id));
                        hasher.update(buffer(secret));
                        hasher.update(buffer(state.server_public_key_der));
                        auto hash = hasher.finalise();
                        /*
                        auto url  = "https://sessionserver.mojang.com/session/minecraft/hasJoined?username=" +
                                   stream.player_name() + "&serverId=" + hash;   // + "&ip=ip";
                        boost::webclient::async_get(url, std::move(self));
                         */
                    }

                    //
                    // todo : contact minecraft server here for uuid
                    //
                }

                yield
                {
                    context       = "set compression";
                    auto &pkt     = state.server_packet.emplace< server::set_compression >();
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
                    context      = "success";
                    auto &pkt    = state.server_packet.emplace< server::login_success >();
                    pkt.username = stream.player_name();
                    pkt.uuid     = to_string(server_accept_op_base::generate_uuid());
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