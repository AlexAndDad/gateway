//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "config.hpp"
#include "minecraft/protocol/stream.hpp"

namespace bot
{
    struct client_ping_impl
    {
        using executor_type = net::io_context::executor_type;
        using protocol_type = net::ip::tcp;
        using socket_type   = net::basic_stream_socket< protocol_type, executor_type >;
        using stream_type   = minecraft::protocol::stream< socket_type >;

        client_ping_impl(executor_type exec)
        : stream_(socket_type(std::move(exec)))
        {
        }

        auto get_executor() -> executor_type
        {
            return stream_.get_executor();
        }
      private:

        stream_type stream_;
    };
}   // namespace bot
