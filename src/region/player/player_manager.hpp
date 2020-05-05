#pragma once

#include "config/net.hpp"
#include "minecraft/player.hpp"
#include "minecraft/time/ticker.hpp"
#include "player_connection.hpp"
#include "player_handle.hpp"
#include "polyfill/class_logger.hpp"

namespace region::player
{
    using namespace config;
    struct player_manager : polyfill::class_logger
    {
        using player_type        = minecraft::player< player_connection >;
        using player_handle_type = player_handle< player_type >;
        using executor_type      = net::io_context::executor_type;
        using strand_type        = net::io_context::strand;

        player_manager(executor_type exec)
        : class_logger("player_manager")
        , strand_(exec.context())
        , ticker_(get_strand(), minecraft::time::delta_time_type(20))
        {
        }

        void start()
        {
            // Start tick manager
            net::co_spawn(
                get_strand(), [this]() -> net::awaitable< void > { co_await this->player_ticker(); }, minecraft::utils::make_exception_handler_standalone("play_manager start"));
        }

        void add_player(std::string name, player_connection player_con)
        {
            net::co_spawn(
                get_strand(),
                [this, player_con = std::move(player_con), name = std::move(name)]() -> net::awaitable< void > {
                    BOOST_ASSERT(get_strand().running_in_this_thread());

                    // Construct a player and give it to a handle to be managed
                    auto player = std::make_shared< player_type >(
                        name, std::move(player_con), get_strand().context().get_executor());
                    auto p_handle = player_handle_type(std::move(player));

                    // Start the player
                    p_handle.get().start();

                    // Store the player in the cache
                    players_.emplace(std::move(name), std::move(p_handle));

                    co_return;
                },
                net::detached);
        }

        void remove_player(player_type::name_type player_name)
        {
            net::co_spawn(
                get_strand(),
                [this, name = std::move(player_name)]() -> net::awaitable< void > {
                    BOOST_ASSERT(get_strand().running_in_this_thread());

                    auto iter = players_.find(name);
                    iter->second.get().cancel();
                    if (iter != players_.end())
                    {
                        players_.erase(iter);
                    }
                    co_return;
                },
                net::detached);
        }

        void cancel()
        {
            net::post(net::bind_executor(get_strand(), [this]() { this->handle_cancel(); }));
        }

      private:   // Functions
        void handle_cancel()
        {
            BOOST_ASSERT(get_strand().running_in_this_thread());
            ticker_.cancel();
            for (auto &player : players_)
            {
                player.second.get().cancel();
            }
            players_.clear();
        }

        net::awaitable< void > player_ticker()
        {
            ticker_.start();
            while (true)
            {
                // Await the next tick
                try
                {
                    minecraft::time::tick_result tick_result = co_await ticker_.await_next_tick();
                    if (tick_result.slow)
                    {
                        warn("Slow player tick. Delta: {}",tick_result.delta_time.count());
                    }

                    // Tick all players
                    for (auto &player : players_)
                    {
                        player.second.get().tick(tick_result.delta_time);
                    }
                }
                catch (system_error &se)
                {
                    auto ec = se.code();
                    if (ec == net::error::operation_aborted)
                    {
                        info("player_ticker loop canceled, dropping out of coroutine...");
                        break;
                    }
                    else
                    {
                        error("unhandled system_error in player_ticker loop: {}\nContinuing player_ticker loop as "
                              "normal.",
                              polyfill::explain());
                    }
                }
                catch (std::exception &)
                {
                    error("unhandled exception in player_ticker loop: {}\nContinuing player_ticker loop as normal.",
                          polyfill::explain());
                }
            }
        }

        strand_type &get_strand() { return strand_; }

      private:   // Data
        // Net
        strand_type                                           strand_;
        std::unordered_map< std::string, player_handle_type > players_;
        minecraft::time::ticker                               ticker_;
    };
}   // namespace region::player
