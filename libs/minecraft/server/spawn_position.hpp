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

    inline void compose(spawn_position const &packet, std::vector< char > &target)
    {
        auto iter = std::back_inserter(target);
        iter      = encode(variable_length(packet.id()), iter);
        encode(packet.location, iter);
    }

    template < class Container >
    void encode(spawn_position const &packet, Container &target)
    {
        using minecraft::encode;
        thread_local static std::vector< char > buf;
        buf.clear();
        compose(packet, buf);
        return encode_to_container(buf, target);
    }

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, spawn_position &packet, error_code &ec);

}   // namespace minecraft::server
