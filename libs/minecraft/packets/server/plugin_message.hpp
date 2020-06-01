//
// Created by ahodges on 26/05/2020.
//

#pragma once

#include "minecraft/types/remaining_bytes.hpp"
#include "minecraft/types/varchar.hpp"
#include "play_id.hpp"

namespace minecraft::packets::server
{
    struct plugin_message : packet_base< play_id::plugin_message, plugin_message >
    {
        varchar< 32767 > channel;
        remaining_bytes  data;

        template < typename Self >
        static auto as_nvps(Self &self)
        {
            return nvp_set(nvp("channel", self.channel), nvp("data", self.data));
        }
    };
}   // namespace minecraft::packets::server
