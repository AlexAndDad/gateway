#pragma once

#include "config/net.hpp"
#include "minecraft/player.hpp"
#include "player_connection.hpp"
#include "player_handle.hpp"

namespace region::player
{
    using namespace config;
    struct player_manager : std::enable_shared_from_this< player_manager >
    {
        using player_type        = minecraft::player< player_connection >;
        using player_handle_type = player_handle< player_type >;
        using executor_type      = net::io_context::executor_type;
        using strand_type        = net::io_context::strand;

        player_manager(executor_type exec)
        : strand_(exec.context())
        {
        }

        void add_player(std::string name, player_connection player_con)
        {
            net::co_spawn(
                get_strand(),
                [self       = shared_from_this(),
                 player_con = std::move(player_con),
                 name       = std::move(name)]() -> net::awaitable< void > {
                    BOOST_ASSERT(self->get_strand().running_in_this_thread());

                    // Construct a player and give it to a handle to be managed
                    auto player = std::make_shared< player_type >(
                        name, std::move(player_con), self->get_strand().context().get_executor());
                    auto p_handle = player_handle_type(std::move(player));

                    // Start the player
                    p_handle.get().start();

                    // Store the player in the cache
                    self->players_.emplace(std::move(name), std::move(p_handle));

                    co_return;
                },
                net::detached);
        }

        void remove_player(player_type::name_type player_name)
        {
            net::co_spawn(
                get_strand(),
                [self = shared_from_this(), name = std::move(player_name)]() -> net::awaitable< void > {
                    BOOST_ASSERT(self->get_strand().running_in_this_thread());

                    auto iter = self->players_.find(name);
                    iter->second.get().stop();
                    if (iter != self->players_.end())
                    {
                        self->players_.erase(iter);
                    }
                    co_return;
                },
                net::detached);
        }

      private:   // Functions
        strand_type get_strand() { return strand_; }

      private:   // Data
        // Net
        strand_type strand_;

        std::unordered_map< std::string, player_handle_type > players_;
    };
}   // namespace region::player
