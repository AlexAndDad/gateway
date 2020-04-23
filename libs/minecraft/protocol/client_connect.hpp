#pragma once

#include "minecraft/packets/client/encryption_response.hpp"
#include "minecraft/packets/client/handshake.hpp"
#include "minecraft/packets/client/login_start.hpp"
#include "minecraft/net.hpp"
#include "minecraft/send_frame.hpp"
#include "minecraft/packets/server/encryption_request.hpp"
#include "minecraft/packets/server/login_success.hpp"
#include "minecraft/packets/server/set_compression.hpp"
#include "read_frame.hpp"
#include "minecraft/protocol/expect_frame.hpp"

namespace minecraft::protocol
{
    struct client_connect_state
    {
        void connection_args(std::string hostname, std::uint16_t port)
        {
            client_handshake.server_address = hostname;
            client_handshake.server_port    = port;
        }

        void name(std::string player_name) { client_login_start.name = player_name; }

        auto version(protocol::version_type v) -> void { client_handshake.protocol_version = v; }

        auto version() const -> protocol::version_type { return client_handshake.protocol_version.value(); }

        auto parse_which_packet(net::const_buffer data, error_code &ec) -> error_code &
        {
            auto first = reinterpret_cast< const char * >(data.data());
            auto last  = first + data.size();
            auto _ = parse(first, last, which_packet_type, ec);
            boost::ignore_unused(_);

            if (not ec.failed())
            {
                switch (which_packet_type.value())
                {
                case server_login_packet::encryption_request:

                case server_login_packet::login_success:
                default:
                    ec = error::unexpected_packet;
                    break;
                }
            }

            return ec;
        }

        error_code &parse_server_key(error_code &ec)
        {
            ec.clear();
            try
            {
                server_key.public_key_from_asn1(net::buffer(server_encryption_request.public_key));
            }
            catch (system_error &se)
            {
                ec = se.code();
            }
            return ec;
        }

        // arguments and results

        packets::client::handshake           client_handshake;
        packets::client::login_start         client_login_start;
        packets::server::set_compression     server_set_compression;
        packets::server::encryption_request  server_encryption_request;
        packets::client::encryption_response client_encryption_response;
        packets::server::login_success       server_login_success;

        security::private_key server_key;
        shared_secret         secret;

        // active state

        var_enum< server_login_packet > which_packet_type;
        std::vector< char >             compose_buffer;
    };

    template < class Stream, class DynamicBuffer >
    struct connect_op : net::coroutine
    {
        connect_op(Stream &stream, DynamicBuffer buffer, client_connect_state &params)
        : stream_(stream)
        , buffer_(buffer)
        , params_(params)
        {
        }

        template < class Self >
        void operator()(Self &self, error_code ec = {}, std::size_t /*bytes_transferred*/ = 0)
        {
#include <boost/asio/yield.hpp>
            reenter(this) for (;;)
            {
                yield async_send_frame(stream_, params_.client_handshake, std::move(self));
                if (ec.failed())
                    return self.complete(ec);
                yield async_send_frame(stream_, params_.client_login_start, std::move(self));
                if (ec.failed())
                    return self.complete(ec);

                yield async_expect_frame(stream_, buffer_, params_.server_login_success, std::move(self));

                return self.complete(ec);
            }
#include <boost/asio/unyield.hpp>
        }

        Stream &              stream_;
        DynamicBuffer         buffer_;
        client_connect_state &params_;
    };

    template < class Stream, class DynamicBuffer, class CompletionToken >
    auto async_connect(Stream &s, DynamicBuffer buffer, client_connect_state &params, CompletionToken &&token)
    {
        auto op = connect_op< Stream, DynamicBuffer >(s, buffer, params);
        return net::async_compose< CompletionToken, void(error_code) >(std::move(op), token, s);
    }

    template < class NextLayer, class CompletionToken >
    auto async_client_connect(protocol::stream< NextLayer > &s, client_connect_state &state, CompletionToken &&token)
    {
        auto op = [&s, &state, coro = net::coroutine()](
                      auto &self, error_code ec = {}, std::size_t /*bytes_transferred*/ = 0) mutable {
            auto log_fail = [&s, &ec](auto &&context) {
                auto fail = ec.failed();
                if (fail)
                    spdlog::warn("[client_connect {}]::{} {}", report(s.next_layer()), context, report(ec));
                return fail;
            };
            auto log_info = [&s](auto &&context) {
                spdlog::warn("[client_connect {}]  {}", report(s.next_layer()), context);
            };
#include <boost/asio/yield.hpp>
            reenter(coro)
            {
                //
                // Hello and inform server of protocol version
                //
                yield s.async_write_packet(state.client_handshake, std::move(self));
                if (log_fail("client_handshake"))
                    return self.complete(ec);

                //
                // send login start frame
                //
                yield s.async_write_packet(state.client_login_start, std::move(self));
                if (log_fail("client_login_start"))
                    return self.complete(ec);

                //
                // We will now either receive a logon success or an encryption request
                //

            wait_server_response:
                yield s.async_read_frame(std::move(self));
                if (log_fail("read first server frame"))
                    return self.complete(ec);

                expect_frames(
                    s.current_frame(),
                    state.which_packet_type,
                    std::tie(state.server_set_compression, state.server_encryption_request, state.server_login_success),
                    ec);
                if (log_fail("expect encryption request or login success"))
                    return self.complete(ec);

                if (state.which_packet_type == server_login_packet::set_compression)
                {
                    spdlog::info("[client_connect {}] server requests compression {}",
                                 s.log_id(),
                                 state.server_set_compression);
                    s.compression_threshold(state.server_set_compression.threshold.value());
                    goto wait_server_response;
                }

                if (state.which_packet_type.value() == server_login_packet::encryption_request)
                {
                    log_info("server encryption request");
                    validate(state.server_encryption_request, state.server_key, ec);
                    if (log_fail("validate encryption request"))
                        return self.complete(ec);
                    // encrypt and send back
                    state.secret.generate();
                    state.server_key.public_encrypt(net::buffer(state.server_encryption_request.verify_token),
                                                    state.client_encryption_response.verify_token);
                    state.server_key.public_encrypt(buffer(state.secret),
                                                    state.client_encryption_response.shared_secret);
                    yield s.async_write_packet(state.client_encryption_response, std::move(self));
                    if (log_fail("client encryption response"))
                        return self.complete(ec);
                    spdlog::info("[client_connect {}] encrypting connection with secret: {:n}",
                                 report(s.next_layer()),
                                 spdlog::to_hex(state.secret));
                    s.set_encryption(state.secret);
                    yield s.async_read_frame(std::move(self));
                    if (log_fail("receive first encrypted frame"))
                        return self.complete(ec);
                    expect_frame(s.current_frame(), state.server_login_success, ec);
                }

                // read any success data here

                if (not log_fail("expect server_login_success"))
                    spdlog::info("[client_connect {}] login success {}",
                                 s.log_id(),
                                 state.server_login_success);
                return self.complete(ec);
            }
#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionToken, void(error_code) >(std::move(op), token, s);
    }
}   // namespace minecraft::protocol