#pragma once

#include "config/net.hpp"
#include "minecraft/player.hpp"
#include "minecraft/region/player_updates_queue.hpp"
#include "player/player_manager.hpp"

#include <iostream>
#include <memory>



namespace region
{
    struct region_server
    {
        using executor_type = config::net::io_context::executor_type;
        using strand_type   = config::net::io_context::strand;
        using signal_set    = config::net::basic_signal_set< executor_type >;

        region_server(executor_type exec, minecraft::region::player_update_queue &queue)
        : strand_(exec.context())
        , queue_(queue)
        , player_manager_(exec)
        {
            std::cout << "Region Server created\n";
        }

        void start()
        {
            std::cout << "Region Server starting\n";
            config::net::co_spawn(
                get_strand(),
                [this]() -> config::net::awaitable< void > { co_await this->run(); },
                config::net::detached);
        }

      private:
        config::net::awaitable< void > run()
        {
            // Start the world

            // Start accepting new players
            config::net::co_spawn(
                get_strand(),
                [this]() -> config::net::awaitable< void > {
                    BOOST_ASSERT(get_strand().running_in_this_thread());
                    while (true)
                    {
                        auto        player_update_queue = co_await queue_.consume_new_player();
                        std::string name                = player_update_queue.name;
                        auto        player_connection   = player::player_connection(std::move(player_update_queue));
                        player_manager_.add_player(std::move(name), std::move(player_connection));
                    }
                },
                config::net::detached);

            co_return;
        }

        strand_type &                           get_strand() { return strand_; }
        strand_type                             strand_;
        minecraft::region::player_update_queue &queue_;
        player::player_manager                  player_manager_;
    };
}   // namespace region
