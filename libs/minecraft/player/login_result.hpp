//
// Created by ahodges on 26/05/2020.
//

#pragma once

#include "packets/client_play_packet.hpp"

namespace minecraft::player
{
    struct login_result
    {
        template < typename T >
        using opt = std::optional< T >;

        opt< packets::client::plugin_message >               opt_plugin_message;
        opt< packets::client::client_settings >              opt_client_settings;
        opt< packets::client::teleport_confirm >             opt_teleport_confirm;
        opt< packets::client::player_position_and_rotation > opt_player_position_and_rotation;
        opt< packets::client::client_status >                opt_client_status;
    };
}   // namespace minecraft::player