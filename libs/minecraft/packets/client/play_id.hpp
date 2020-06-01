#pragma once

#include "minecraft/wise_enum.hpp"

namespace minecraft::packets::client
{
    WISE_ENUM_CLASS((play_id, std::int32_t),
                    (teleport_confirm, 0),
                    (client_status, 0x04),
                    (client_settings, 0x05),
                    (plugin_message, 0x0b),
                    (invalid, 0x7f),
                    (keep_alive, 0x0F),
                    (position_and_rotation, 0x12),
                    (animation, 0x2A),
                    (held_item_change, 0x23));
    WISE_ENUM_ENABLE_IO(play_id);
}   // namespace minecraft::packets::client