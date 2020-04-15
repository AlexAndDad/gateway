#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/server/play_id.hpp"

namespace minecraft::server
{
    struct spawn_position
    {

        static auto constexpr id() { return play_id::spawn_position; }

        position location;

        friend std::ostream &operator<<(std::ostream &os, spawn_position const &arg);
    };

    template < class Container >
    void encode(spawn_position const &packet, Container &target)
    {
        using minecraft::encode;
        thread_local static std::vector< std::uint8_t > buf;
        buf.clear();

        auto i1 = std::back_inserter(buf);
        i1      = encode(packet.id(), i1);
        encode(packet.location, i1);

        return encode_to_container(buf, target);
    }

}   // namespace minecraft::server
