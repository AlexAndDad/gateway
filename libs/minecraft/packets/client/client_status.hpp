//
// Created by ahodges on 26/05/2020.
//

#pragma once

#include "packets/packet_base.hpp"
#include "play_id.hpp"

namespace minecraft::packets::client
{
    WISE_ENUM_CLASS((action_id_vals, std::int32_t), (perform_respawn, 0), (request_stats, 1));
    WISE_ENUM_ENABLE_IO(action_id_vals);

    struct client_status : packets::packet_base< play_id::client_status, client_status >
    {
        var_enum< action_id_vals > action_id;

        template <typename Self>
        static auto as_nvps(Self &self) { return nvp_set(nvp("action_id", self.action_id)); }

    };   // namespace minecraft::packets::client
}   // namespace minecraft::packets::client
