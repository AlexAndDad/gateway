#pragma once

#include "config/net.hpp"
#include "minecraft/player.hpp"
#include "player_cache.hpp"
#include "player_connection.hpp"

namespace region::player
{
    using namespace config;
    struct player_manager: std::enable_shared_from_this<player_manager>
    {
        using player_type   = minecraft::player< player_connection >;
        using executor_type = net::io_context::executor_type;
        using strand_type   = net::io_context::strand;

        player_manager(executor_type exec)
        : strand_(exec.context())
        {
        }

        void add_player(player_type player)
        {
            net::co_spawn(get_strand(),[self=shared_from_this(), player=std::move(player)]() -> net::awaitable<void>{
                    BOOST_ASSERT(self->get_strand().running_in_this_thread());
                    auto name = player.name;
                    self->players_.set(std::move(name),std::move(player));
                    co_return;
                }, net::detached);
        }

        void remove_player(player_type::name_type player_name);

      private:   // Functions
        strand_type get_strand() {return strand_;}

      private:   // Data
        // Net
        strand_type strand_;

        player_cache< player_type::name_type, player_type > players_;
    };
}   // namespace region::player
