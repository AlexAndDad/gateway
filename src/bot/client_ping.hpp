#pragma once

#include "client_ping/ping_op.hpp"
#include "config.hpp"

#include <boost/beast/core/basic_stream.hpp>

namespace bot
{
    using transport_protocol = net::ip::tcp;
    using transport_stream   = boost::beast::basic_stream< transport_protocol >;
    using minecraft_stream   = minecraft::protocol::stream< transport_stream >;

    template < class NextLayer, class CompletionToken >
    auto async_client_ping(minecraft::protocol::stream< NextLayer > &stream,
                           std::string const &                       hostname,
                           std::string const &                       port,
                           CompletionToken &&                        token)
    {
        return net::async_compose< CompletionToken, void(error_code, ping_result) >(
            ping_op(stream, hostname, port), token, stream);
    }

    auto send_status_handshake(minecraft_stream &                stream,
                               std::string const &               hostname,
                               std::uint16_t                     port,
                               minecraft::protocol::version_type version = minecraft::protocol::version_type::v1_15_2)
        -> net::awaitable< void >;

    auto coro_ping(std::string const &hostname, std::string const &port) -> net::awaitable< ping_result >;

}   // namespace bot