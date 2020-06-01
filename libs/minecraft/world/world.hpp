//
// Created by ahodges on 25/05/2020.
//

#pragma once

#include "dimension.hpp"
#include "gamemode.hpp"
#include "types/position2.hpp"

namespace minecraft
{
    struct world
    {

        world()
        :level_type_("default")
        , view_distance_(12)
        , respawn_screen_(true)
        , spawn_position_(0,0,0)
        {}

        std::int64_t get_hashed_seed() const   // TODO
        {
            return 1010101010101;
        }
        std::string   get_level_type() const { return level_type_; }
        std::uint16_t get_view_distance() const { return view_distance_; }
        bool          respawn_screen() const { return respawn_screen_; }
        position2     get_spawn_position() const { return spawn_position_; }

      private:



        std::string   level_type_;
        std::uint16_t view_distance_;
        bool          respawn_screen_;
        position2     spawn_position_;
    };
}   // namespace minecraft