#pragma once

#include "minecraft/client/encryption_response.hpp"
#include "minecraft/client/handshake.hpp"
#include "minecraft/client/login_start.hpp"
#include "minecraft/net.hpp"
#include "minecraft/send_frame.hpp"
#include "minecraft/server/encryption_request.hpp"
#include "minecraft/server/login_success.hpp"
#include "read_frame.hpp"

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
            auto next  = parse(first, last, which_packet_type, ec);

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

        // arguments and results

        client::handshake           client_handshake;
        client::login_start         client_login_start;
        server::encryption_request  server_encryption_request;
        client::encryption_response client_encryption_response;
        server::login_success       server_login_success;

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
        void operator()(Self &self, error_code ec = {}, std::size_t bytes_transferred = 0)
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
                      auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
#include <boost/asio/yield.hpp>
            reenter(coro)
            {
                //
                // Hello and inform server of protocol version
                //
                yield s.async_write_frame(state.client_handshake, std::move(self));
                if (ec.failed())
                    return self.complete(ec);

                //
                // send login start frame
                //
                yield s.async_write_frame(state.client_login_start, std::move(self));
                if (ec.failed())
                    return self.complete(ec);

                //
                // We will now either receive a logon success or an encryption request
                //

                yield s.async_read_frame(std::move(self));
                if (ec.failed())
                    return self.complete(ec);

                if (expect_frames(s.current_frame(),
                                  state.which_packet_type,
                                  std::tie(state.server_encryption_request, state.server_login_success),
                                  ec)
                        .failed())
                    return self.complete(ec);

                if (state.which_packet_type.value() == server_login_packet::encryption_request)
                {
                    // encrypt and send back
                    // todo encryption
                    +++ HERE +++

                    compose(s.async_write_frame(), s.compose_buffer);
                    yield s.async_write_frame(net::buffer(s.compose_buffer), ec);
                    if (ec.failed())
                        return self.complete(ec);
                    s.set_encryption(net::buffer(s.secret));
                    yield s.async_read_frame(std::move(self));
                    if (ec.failed())
                        return self.complete(ec);
                    if (expect_frame(s.current_frame(), state.server_login_success, std::move(self)).failed)
                        return self.complete(ec);
                }

                // read any success data here

                return self.complete(ec);
            }
#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionToken, void(error_code) >(std::move(op), token, s);
    }
}   // namespace minecraft::protocol