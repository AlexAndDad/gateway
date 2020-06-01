//
// Created by ahodges on 26/05/2020.
//

#pragma once

#include "minecraft/wise_enum.hpp"

namespace minecraft
{
    struct gamemode
    {
        WISE_ENUM_MEMBER((gamemode_type, std::uint8_t),
        (survival, 0),
        (creative, 1),
        (adventure, 2),
        (spectator, 3),
        (hardcore, 0x8))
        WISE_ENUM_MEMBER_ENABLE_IO(gamemode_type)
    };
}