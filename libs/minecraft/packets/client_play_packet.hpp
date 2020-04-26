#pragma once

#include "client/play_id.hpp"
#include "play_packet.hpp"

// Packets
#include "minecraft/packets/client/client_settings.hpp"
#include "minecraft/packets/client/keep_alive.hpp"
#include "minecraft/packets/client/play_id.hpp"
#include "minecraft/packets/client/teleport_confirm.hpp"
#include "minecraft/packets/client/plugin_message.hpp"

namespace minecraft::packets::client
{
    using play_packet_variant =
        std::variant< std::monostate, client::teleport_confirm, client::plugin_message, client::keep_alive, client::client_settings >;

    struct client_play_packet : play_packet< client::play_id, play_packet_variant >
    {
    };
}   // namespace minecraft::packets::client