#pragma once

#include "client/play_id.hpp"
#include "play_packet.hpp"

// Packets
#include "client/animation.hpp"
#include "client/client_settings.hpp"
#include "client/keep_alive.hpp"
#include "client/play_id.hpp"
#include "client/player_position_and_rotation.hpp"
#include "client/plugin_message.hpp"
#include "client/teleport_confirm.hpp"
#include "client/held_item_change.hpp"

namespace minecraft::packets::client
{
    using play_packet_variant = variant< monostate,
                                         teleport_confirm,
                                         plugin_message,
                                         keep_alive,
                                         client_settings,
                                         player_position_and_rotation,
                                         animation,
                                         held_item_change>;

    struct client_play_packet : play_packet< client::play_id, play_packet_variant >
    {
    };
}   // namespace minecraft::packets::client