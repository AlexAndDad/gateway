//
// Created by rhodges on 13/04/2020.
//

#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/types.hpp"
#include "play_id.hpp"

namespace minecraft::packets::server
{
    struct join_game
    {
        WISE_ENUM_MEMBER((game_mode_type, std::uint8_t),
                         (survival, 0),
                         (creative, 1),
                         (adventure, 2),
                         (spectator, 3),
                         (hardcore, 0x8))
        WISE_ENUM_MEMBER((dimension_type, std::int32_t), (nether, -1), (overworld, 0), (end, 1))

        static auto constexpr id() { return play_id::join_game; }

        std::int32_t   entity_id;
        game_mode_type game_mode;
        dimension_type dimension;
        std::int64_t   hashed_seed;
        std::uint8_t   max_players;   // Ignored by client
        varchar< 16 >  level_type;
        var_int        view_distance;
        bool           reduced_debug_info;
        bool           enable_respawn_screen;
    };

    inline void compose(join_game const &packet, std::vector< char > &target)
    {
        using minecraft::encode;
        auto i1 = std::back_inserter(target);
        i1      = encode(variable_length(packet.id()), i1);
        i1      = encode(packet.entity_id, i1);
        i1      = encode(packet.game_mode, i1);
        i1      = encode(packet.dimension, i1);
        i1      = encode(packet.hashed_seed, i1);
        i1      = encode(packet.max_players, i1);
        i1      = encode(packet.level_type, i1);
        i1      = encode(packet.view_distance, i1);
        i1      = encode(packet.reduced_debug_info, i1);
        encode(packet.enable_respawn_screen, i1);
    }

}   // namespace minecraft::packets::server
