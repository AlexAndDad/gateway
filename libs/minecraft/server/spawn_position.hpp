#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/net.hpp"
#include "minecraft/server/play_id.hpp"
#include "minecraft/types/position.hpp"
#include "minecraft/types/position2.hpp"

#define POSITION_TYPE_ALEX 0
#define POSITION_TYPE_DAD 1

#define POSITION_TYPE POSITION_TYPE_DAD

namespace minecraft::server
{
    struct spawn_position
    {
        static auto constexpr id() { return play_id::spawn_position; }

#if POSITION_TYPE == POSITION_TYPE_ALEX
        position location;
#else
        position2 location;
#endif

        friend std::ostream &operator<<(std::ostream &os, spawn_position const &arg);
    };

    void compose(spawn_position const &packet, std::vector< char > &target);

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, spawn_position &packet, error_code &ec);

}   // namespace minecraft::server
