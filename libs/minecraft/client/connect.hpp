#pragma once

#include "minecraft/client/handshake.hpp"
#include "minecraft/client/login_start.hpp"
#include "minecraft/net.hpp"
#include "minecraft/read_frame.hpp"
#include "minecraft/send_frame.hpp"
#include "minecraft/server/login_success.hpp"

namespace minecraft::client
{
    struct connect_params
    {
        void connection_args(std::string hostname, std::uint16_t port)
        {
            client_handshake.server_address = hostname;
            client_handshake.server_port    = port;
        }

        void name(std::string player_name) { client_login_start.name = player_name; }

        //
        client::handshake     client_handshake;
        client::login_start   client_login_start;
        server::login_success server_login_success;
    };

    template < class Stream, class DynamicBuffer >
    struct connect_op : net::coroutine
    {
        connect_op(Stream &stream, DynamicBuffer buffer, connect_params &params)
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

        Stream &        stream_;
        DynamicBuffer   buffer_;
        connect_params &params_;
    };

    template < class Stream, class DynamicBuffer, class CompletionToken >
    auto async_connect(Stream &s, DynamicBuffer buffer, connect_params &params, CompletionToken &&token)
    {
        auto op = connect_op< Stream, DynamicBuffer >(s, buffer, params);
        return net::async_compose< CompletionToken, void(error_code) >(std::move(op), token, s);
    }
}   // namespace minecraft::client