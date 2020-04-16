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

    inline void compose(spawn_position const& packet, std::vector<char>& target)
    {
        auto iter = std::back_inserter(target);
        iter = encode(variable_length(packet.id()), iter);
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

}   // namespace minecraft::server
