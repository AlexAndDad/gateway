#pragma once

#include <wise_enum/wise_enum.h>

namespace minecraft::server
{
    WISE_ENUM_CLASS((play_id, std::int32_t), (chat_message, 0x0f), (spawn_position, 0x4E), (player_position_and_look,0x36));

}