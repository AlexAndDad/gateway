//
// Created by rhodges on 13/04/2020.
//

#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/packets/packet_base.hpp"
#include "minecraft/parse_error.hpp"
#include "minecraft/types/varchar.hpp"
#include "minecraft/types/var.hpp"
#include "minecraft/wise_enum.hpp"
#include "play_id.hpp"

namespace minecraft::packets::server
{
    struct join_game : packet_base< play_id::join_game, join_game >
    {
        WISE_ENUM_MEMBER((game_mode_type, std::uint8_t),
                         (survival, 0),
                         (creative, 1),
                         (adventure, 2),
                         (spectator, 3),
                         (hardcore, 0x8))
        WISE_ENUM_MEMBER_ENABLE_IO(game_mode_type)

        WISE_ENUM_MEMBER((dimension_type, std::int32_t), (nether, -1), (overworld, 0), (end, 1))
        WISE_ENUM_MEMBER_ENABLE_IO(dimension_type)

        std::int32_t   entity_id;
        game_mode_type game_mode;
        dimension_type dimension;
        std::int64_t   hashed_seed;
        std::uint8_t   max_players;   // Ignored by client
        varchar< 16 >  level_type;
        var_int        view_distance;
        bool           reduced_debug_info;
        bool           enable_respawn_screen;

        template < class Self >
        static auto as_nvps(Self &self)
        {
            return nvp_set(nvp("entity_id", self.entity_id),
                           nvp("game_mode", self.game_mode),
                           nvp("dimension", self.dimension),
                           nvp("nashed_seed", self.hashed_seed),
                           nvp("max_players", self.max_players),
                           nvp("level_type", self.level_type),
                           nvp("view_distance", self.view_distance),
                           nvp("reduced_debug_info", self.reduced_debug_info),
                           nvp("enable_respawn_screen", self.enable_respawn_screen));
        }
    };

}   // namespace minecraft::packets::server
