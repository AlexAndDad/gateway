//
// Created by ahodges on 25/05/2020.
//

#pragma once

#include "minecraft/world/world.hpp"

#include <player/player.hpp>
#include <player/player_connection_base.hpp>
#include <unordered_map>


namespace minecraft
{
    struct world;
}

namespace minecraft::player
{
    struct player_cache
    {
        using executor_type = net::executor;
        using player_type = player;
        using name_type = player_type::name_type;

        void create_player(name_type name, executor_type exec, std::shared_ptr<player_connection_base> connection, minecraft::world & world, chunks::chunk_update_provider * provider)
        {
            auto res = cache_.emplace(std::make_pair(name,std::make_shared<player_type>(name,exec,std::move(connection),world, provider)));
            if (res.second)
            {
                res.first->second->start();
            }
        }

        std::optional<std::shared_ptr<player_type>> get_player(const name_type & name)
        {
            auto result = std::optional<std::shared_ptr<player_type>>();
            auto ifind = cache_.find(name);
            if (ifind != std::end(cache_))
                result = ifind->second;

            return result;
        }

        void cancel()
        {
            for (auto & player : cache_)
            {
                player.second->cancel();
            }
        }

      private:
        std::unordered_map< player_type::name_type, std::shared_ptr< player_type > > cache_;
    };
}   // namespace gateway