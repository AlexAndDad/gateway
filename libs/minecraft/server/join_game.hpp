//
// Created by rhodges on 13/04/2020.
//

#pragma once

#include "play_id.hpp"

namespace minecraft::server
{
    struct join_game
    {
        WISE_ENUM_MEMBER((game_mode_type, std::uint8_t), (survival,0), (creative,1), (adventure, 2), (spectator, 3), (hardcore, 0x8))
        WISE_ENUM_MEMBER((dimension_type, std::int32_t), (nether,-1), (overworld,0), (end, 1))


        std::int32_t entity_id;
        game_mode_type game_mode;
        dimension_type dimension;

    };

}
