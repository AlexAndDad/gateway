#pragma once

#include "minecraft/wise_enum.hpp"

namespace minecraft::packets::server
{
    WISE_ENUM_CLASS((play_id, std::int32_t),
                    (invalid, 0x7f),
                    (chat_message, 0x0f),
                    (spawn_position, 0x4E),
                    (keep_alive, 0x21),
                    (join_game, 0x26),
                    (player_position_and_look, 0x36),
                    (chunk_data, 0x22))
    WISE_ENUM_ENABLE_IO(play_id)

}   // namespace minecraft::packets::server
