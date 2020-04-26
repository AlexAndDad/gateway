//
// Created by rhodges on 13/04/2020.
//

#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/types.hpp"
#include "minecraft/parse_error.hpp"
#include "play_id.hpp"
#include <wise_enum/wise_enum.h>

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

    void compose(join_game const &packet, std::vector< char > &target);
    std::ostream& operator<<(std::ostream& os, join_game const& pkt);

    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, join_game& pkt, error_code& ec);

}   // namespace minecraft::packets::server
