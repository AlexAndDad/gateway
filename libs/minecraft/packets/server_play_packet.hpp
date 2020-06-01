#pragma once

#include "play_packet.hpp"
#include "server/play_id.hpp"

// packets
#include "server/chat_message.hpp"
#include "server/join_game.hpp"
#include "server/keep_alive.hpp"
#include "server/player_position_and_look.hpp"
#include "server/spawn_position.hpp"
#include "server/chunk_data.hpp"
#include "server/plugin_message.hpp"

namespace minecraft::packets::server
{
    using play_packet_variant = variant< monostate,
                                         server::chat_message,
                                         server::spawn_position,
                                         server::keep_alive,
                                         server::join_game,
                                         server::player_position_and_look,
                                         server::chunk_data,
                                         server::plugin_message>;

    struct server_play_packet : play_packet< server::play_id, play_packet_variant >
    {
    };

}   // namespace minecraft::packets::server
