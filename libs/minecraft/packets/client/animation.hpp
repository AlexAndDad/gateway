#pragma once

#include "minecraft/packets/packet_base.hpp"
#include "minecraft/types.hpp"
#include "play_id.hpp"

namespace minecraft::packets::client
{
    WISE_ENUM_CLASS((hand_type, std::int32_t), (main_hand, 0), (off_hand, 1));
    WISE_ENUM_ENABLE_IO(hand_type);

    struct animation : packet_base< play_id::animation, animation >
    {
        var_enum< hand_type > hand;

        template < class Self >
        static auto as_nvps(Self &self)
        {
            return nvp_set(nvp("hand", self.hand));
        }
    };
}   // namespace minecraft::packets::client