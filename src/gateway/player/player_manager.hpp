//
// Created by ahodges on 23/05/2020.
//
#pragma once

#include "net.hpp"

#include "polyfill/configuration.hpp"
namespace gateway
{
    struct player_manager
    {
        using executor_type = net::executor;

        player_manager(executor_type exec, polyfill::configuration & config)
        :config_(config)
        {}

        net::awaitable<void> start()
        {

        }

        void cancel()
        {

        }

        executor_type get_executor() {return executor_;}


        void create_player(connection con)
        {

        }

      private:



        executor_type executor_;
        polyfill::configuration & config_;
    };
}