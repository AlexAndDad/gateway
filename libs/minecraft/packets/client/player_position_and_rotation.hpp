#pragma once

#include "minecraft/packets/packet_base.hpp"
#include "play_id.hpp"

namespace minecraft::packets::client
{
    struct player_position_and_rotation : packet_base< play_id::position_and_rotation, player_position_and_rotation >
    {
        double x;
        double feet_y;
        double z;
        float  yaw;
        float  pitch;
        bool   on_ground;

        template < class Self >
        static auto as_nvps(Self &self)
        {
            return nvp_set(nvp("x", self.x),
                           nvp("feet_y", self.feet_y),
                           nvp("z", self.z),
                           nvp("yaw", self.yaw),
                           nvp("pitch", self.pitch),
                           nvp("on_ground", self.on_ground));
        }
    };
}   // namespace minecraft::packets::client