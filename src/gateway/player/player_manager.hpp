//
// Created by ahodges on 23/05/2020.
//
#pragma once

#include "gateway/net.hpp"
#include "minecraft/player/player_cache.hpp"
#include "minecraft/chunks/chunk_update_provider/chunk_update_provider.hpp"
#include "polyfill/configuration.hpp"

#include "minecraft/world/world.hpp"


namespace gateway
{
    struct player_manager
    {
        using executor_type = net::executor;

        player_manager(executor_type exec, polyfill::configuration &config)
        : executor_(exec)
        , config_(config)
        {
        }

        net::awaitable< void > start()
        {
            spdlog::debug("player manager started.");
            boost::ignore_unused(config_);co_return;
        }

        void cancel() {
            spdlog::debug("player manager cancelled.");
        }

        executor_type get_executor() { return executor_; }

        void create_player(minecraft::player::player::name_type name,executor_type exec, connection con, minecraft::world &current_world, minecraft::chunks::chunk_update_provider * provider) {
            spdlog::debug("Player_manager - creating new player: {}.",name);
            cache_.create_player(std::move(name),exec,con.get_impl(),current_world, provider);
        }

      private:
        executor_type            executor_;
        polyfill::configuration &config_;

        minecraft::player::player_cache cache_;
    };
}   // namespace gateway