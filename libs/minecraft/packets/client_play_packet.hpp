#pragma once

#include "client/play_id.hpp"
#include "play_packet.hpp"

// Packets
#include "minecraft/packets/client/keep_alive.hpp"
#include "minecraft/packets/client/play_id.hpp"

namespace minecraft::packets
{
    using play_packet_variant = std::variant< std::monostate, client::keep_alive >;

    struct client_play_packet : play_packet< client::play_id, play_packet_variant >
    {
    };
}   // namespace minecraft::packets