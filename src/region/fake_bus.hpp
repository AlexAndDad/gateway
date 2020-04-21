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
        using strand_type   = net::strand< executor_type >;

        fake_bus(executor_type exec)
        : strand_(net::make_strand(exec))
        {
        }

        net::awaitable< const std::string > consume_username() {}

        void produce_username(std::string username)
        {
            dispatch(bind_executor(get_strand(), [this, username = std::move(username)] mutable {
                this->handle_produce_username(std::move(username));
            }));
        }



      private:
        strand_type get_strand() { return strand_; }

        void        handle_produce_username(std::string username)
        {
            BOOST_ASSERT(get_strand().running_in_this_thread());


        }
        // Net
        strand_type strand_;

        // Username queue
        std::vector


        // Packet queue
    };
}   // namespace region