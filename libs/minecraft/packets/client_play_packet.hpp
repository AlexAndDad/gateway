#pragma once

#include "client/play_id.hpp"
#include "play_packet.hpp"

// Packets
#include "minecraft/packets/client/animation.hpp"
#include "minecraft/packets/client/client_settings.hpp"
#include "minecraft/packets/client/keep_alive.hpp"
#include "minecraft/packets/client/play_id.hpp"
#include "minecraft/packets/client/player_position_and_rotation.hpp"
#include "minecraft/packets/client/plugin_message.hpp"
#include "minecraft/packets/client/teleport_confirm.hpp"

namespace minecraft::packets::client
{
    using play_packet_variant = variant< monostate,
                                         teleport_confirm,
                                         plugin_message,
                                         keep_alive,
                                         client_settings,
                                         player_position_and_rotation,
                                         animation >;

    struct client_play_packet : play_packet< client::play_id, play_packet_variant >
    {
    };
}   // namespace minecraft::packets::client