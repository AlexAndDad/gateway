#pragma once

#include "minecraft/wise_enum.hpp"

namespace minecraft::packets::client
{
    WISE_ENUM_CLASS((play_id, std::int32_t), (invalid, 0x7f), (keep_alive, 0x0F));
    WISE_ENUM_ENABLE_IO(play_id);
}