#pragma once

#include "minecraft/packets/client/play_id.hpp"
#include "minecraft/packets/packet_base.hpp"
#include "minecraft/types.hpp"
#include "minecraft/types/remaining_bytes.hpp"

namespace minecraft::packets::client
{
    struct plugin_message : packet_base< play_id::plugin_message, plugin_message >
    {
        varchar< 32767 > channel;
        remaining_bytes  data;

        template < class Self >
        static auto as_nvps(Self &self)
        {
            return nvp_set(nvp("channel", self.channel), nvp("data", self.data));
        }
    };

}   // namespace minecraft::packets::client
