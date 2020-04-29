#pragma once

#include "client_ping/ping_op.hpp"

namespace bot
{
    template < class NextLayer, class CompletionToken >
    auto async_client_ping(minecraft::protocol::stream< NextLayer > &stream,
                           std::string const &                       hostname,
                           std::string const &                       port,
                           CompletionToken &&                        token)
    {
        return net::async_compose< CompletionToken, void(error_code, ping_result) >(
            ping_op(stream, hostname, port), token, stream);
    }

}   // namespace bot