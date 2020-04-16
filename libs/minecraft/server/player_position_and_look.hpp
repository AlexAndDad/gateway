#pragma once
#include "minecraft/encode.hpp"
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

        friend std::ostream &operator<<(std::ostream &os, player_position_and_look const &arg);
    };

    inline void compose(player_position_and_look const& packet, std::vector<char>& target)
    {
        using minecraft::encode;
        auto i1 = std::back_inserter(target);
        i1 = encode(variable_length(packet.id()), i1);
        i1 = encode(packet.x, i1);
        i1 = encode(packet.y, i1);
        i1 = encode(packet.z, i1);
        i1 = encode(packet.yaw, i1);
        i1 = encode(packet.pitch, i1);
        i1 = encode(static_cast< std::uint8_t >(packet.flags.to_ulong()), i1);
        encode(packet.teleport_ID, i1);
    }


    template < class Container >
    void encode(player_position_and_look const &packet, Container &target)
    {
        using minecraft::encode;
        thread_local static std::vector< char > buf;
        buf.clear();

        compose(packet, buf);

        return encode_to_container(buf, target);
    }

}   // namespace minecraft::server
