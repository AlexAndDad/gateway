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
        using signal_set    = config::net::basic_signal_set< strand_type >;

        region_server(executor_type exec, minecraft::region::player_update_queue &queue)
        : strand_(exec.context())
        , signal_(strand_)
        , queue_(queue)
        , player_manager_(exec)
        {
            std::cout << "Region Server created\n";
            signal_.add(SIGINT);
        }

        void start()
        {
            std::cout << "Region Server starting\n";
            config::net::co_spawn(
                get_strand(),
                [this]() -> config::net::awaitable< void > {
                    // Do strand confined startup here
                    signal_.async_wait([this](error_code const &ec, int sig) { handle_signal(ec, sig); });
                    co_await this->run();
                },
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
                    spdlog::info("region_server: started accepting new players");
                    while (true)
                    {
                        try
                        {
                            auto        player_update_queue = co_await queue_.consume_new_player();
                            std::string name                = player_update_queue.name;
                            auto        player_connection   = player::player_connection(std::move(player_update_queue));
                            player_manager_.add_player(std::move(name), std::move(player_connection));
                        }
                        catch (system_error &se)
                        {
                            auto ec = se.code();
                            if (ec != net::error::operation_aborted)
                            {
                                spdlog::error(
                                    "region_server: error while consuming from player_update_queue. exception: {}",
                                    polyfill::explain());
                            }
                            break;
                        }
                    }
                    spdlog::info("region_server: stopped accepting new players");
                },
                config::net::detached);

            co_return;
        }

        void handle_signal(error_code const &ec, int sig)
        {
            BOOST_ASSERT(get_strand().running_in_this_thread());

            if (ec.failed())
            {
                if (ec != net::error::operation_aborted)
                {
                    cancel_all_services();
                }
            }
            else if (sig == SIGINT)
            {
                std::clog << "region_server: interrupted" << std::endl;
                cancel_all_services();
            }
            else
            {
                std::clog << "region_server: unexpected signal " << sig << std::endl;
                cancel_all_services();
            }
        }

        void cancel_all_services()
        {
            BOOST_ASSERT(get_strand().running_in_this_thread());
            player_manager_.cancel();
            queue_.cancel();
        }

        strand_type &                           get_strand() { return strand_; }
        strand_type                             strand_;
        signal_set                              signal_;
        minecraft::region::player_update_queue &queue_;
        player::player_manager                  player_manager_;
    };
}   // namespace region
