#pragma once

#include "config/net.hpp"
#include "minecraft/player.hpp"
#include "minecraft/region/fake_bus.hpp"
#include "player/player_manager.hpp"

#include <iostream>
#include <memory>

namespace region
{
    struct region_server : std::enable_shared_from_this< region_server >
    {
        using executor_type = config::net::io_context::executor_type;
        using strand_type   = config::net::io_context::strand;
        using signal_set    = config::net::basic_signal_set< executor_type >;

        region_server(executor_type exec, minecraft::region::fake_bus &bus)
        : strand_(exec.context())
        , bus_(bus)
        , player_manager_(exec)
        {
            std::cout << "Region Server created\n";
        }

        void start()
        {
            std::cout << "Region Server starting\n";
            config::net::co_spawn(
                get_strand(),
                [self = shared_from_this()]() -> config::net::awaitable< void > { co_await self->run(); },
                config::net::detached);
        }

      private:
        /// @brief Starts and runs the region_server and all subprocesses.
        ///
        /// @CORO
        ///
        /// @return

        config::net::awaitable< void > run()
        {
            // Start the world

            // Start accepting new players
            config::net::co_spawn(
                get_strand(),
                [self = shared_from_this()]() -> config::net::awaitable< void > {
                    BOOST_ASSERT(self->get_strand().running_in_this_thread());
                    while (true)
                    {
                        auto res = co_await self->bus_.consume_username(self->get_strand());
                        if (res.second)   // Adding a new player
                        {
                            // Create a bus subscription for that player
                            //self->player_manager_.create_player(res.)
                        }
                        else   // removing an existing player
                        {
                        }
                        co_return;
                    }
                },
                config::net::detached);

            co_return;
        }

        strand_type &                get_strand() { return strand_; }
        strand_type                  strand_;
        minecraft::region::fake_bus &bus_;
        player::player_manager       player_manager_;
    };
}   // namespace region
