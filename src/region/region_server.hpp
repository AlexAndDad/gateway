#pragma once

#include "config/net.hpp"
#include <iostream>

#include "player_cache.hpp"
#include "player_connection.hpp"


#include "minecraft/player.hpp"



namespace region
{
    struct region_server
    {
        using executor_type = config::net::io_context::executor_type;
        using signal_set    = config::net::basic_signal_set< executor_type >;


        region_server(executor_type exec)
        :players_()
        {
            std::cout << "Region Server starting\n";

        }

        void start();

      private:
        player_cache<minecraft::player<player_connection>> players_;

    };
}   // namespace region
