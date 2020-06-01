//
// Created by ahodges on 25/05/2020.
//

#pragma once

#include "net.hpp"

#include "packets/client_play_packet.hpp"
#include "login_result.hpp"
#include "world/world.hpp"

#include <packets/server_play_packet.hpp>


namespace minecraft::player
{
    struct player;

    struct player_connection_base
    {
        virtual auto async_get_client_packet() -> net::awaitable< packets::client::client_play_packet > = 0;
        virtual auto send_packet(packets::server::server_play_packet packet) -> void                    = 0;
        virtual auto start_play() -> void = 0;
        virtual auto cancel() -> void = 0;

        //virtual ~player_connection_base() = default;
    };
}   // namespace minecraft::player