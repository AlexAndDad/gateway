#pragma once

#include "config/net.hpp"

#include <functional>
#include <string>

namespace region
{
    using namespace config;

    struct fake_bus
    {
        using executor_type = config::net::io_context::executor_type;


        fake_bus(executor_type exec)
        {
        }

        net::awaitable<std::string> consume_username()
        {

        }

        void generate_add_player_func()
        {}


      private:



        executor_type strand_;

    };
}   // namespace region