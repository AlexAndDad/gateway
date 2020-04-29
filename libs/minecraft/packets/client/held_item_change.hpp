#pragma once

#include "minecraft/packets/packet_base.hpp"
#include "minecraft/types.hpp"
#include "play_id.hpp"

namespace minecraft::packets::client
{
    struct held_item_change : packet_base<play_id::held_item_change, held_item_change >
    {
        short slot;

        template < class Self >
        static auto as_nvps(Self &self)
        {
            return nvp_set(nvp("slot", self.slot));
        }
    };
}   // namespace minecraft::packets::client