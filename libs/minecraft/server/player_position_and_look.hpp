#pragma once
#include "minecraft/encode.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/server/play_id.hpp"
#include "minecraft/types.hpp"

#include <bitset>

namespace minecraft::server
{
    struct player_position_and_look
    {
        static auto constexpr id() { return play_id::player_position_and_look; }

        double x;
        double y;
        double z;

        float yaw;
        float pitch;

        std::bitset< 5 > flags;

        var_int teleport_ID;

        void set_flags(bool X, bool Y, bool Z, bool Y_ROT, bool X_ROT)
        {
            flags.set(0,X);
            flags.set(1,Y);
            flags.set(2,Z);
            flags.set(3,Y_ROT);
            flags.set(4,X_ROT);
        }

        friend std::ostream &operator<<(std::ostream &os, player_position_and_look const &arg);
    };

    inline void compose(player_position_and_look const &packet, std::vector< char > &target)
    {
        using minecraft::encode;
        auto i1 = std::back_inserter(target);
        i1      = encode(variable_length(packet.id()), i1);
        i1      = encode(packet.x, i1);
        i1      = encode(packet.y, i1);
        i1      = encode(packet.z, i1);
        i1      = encode(packet.yaw, i1);
        i1      = encode(packet.pitch, i1);
        i1      = encode(static_cast< std::uint8_t >(packet.flags.to_ulong()), i1);
        encode(packet.teleport_ID, i1);
    }

    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, player_position_and_look &packet, error_code &ec)
    {
        using minecraft::parse;
        auto next = parse(first, last, packet.x, ec);
        next      = parse(next, last, packet.y, ec);
        next      = parse(next, last, packet.z, ec);
        next      = parse(next, last, packet.yaw, ec);
        next      = parse(next, last, packet.pitch, ec);
        next      = parse(next, last, packet.teleport_ID, ec);
        return next;
    }

}   // namespace minecraft::server
