//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "minecraft/packets/client/handshake.hpp"
#include "minecraft/protocol/stream.hpp"
#include "minecraft/net.hpp"

#include <cstdint>
#include <string>

namespace minecraft::protocol
{
    template < class NextLayer >
    auto
    send_handshake(stream< NextLayer > &stream, std::string const &hostname, std::uint16_t port, version_type version)
        -> net::awaitable< void >
    {
        auto handshake             = minecraft::packets::client::handshake();
        handshake.protocol_version = version;
        handshake.server_address   = hostname;
        handshake.server_port      = port;
        handshake.next_state       = minecraft::protocol::connection_state::status;
        co_await stream.async_write_packet(handshake, net::use_awaitable);
    }

}   // namespace minecraft::protocol