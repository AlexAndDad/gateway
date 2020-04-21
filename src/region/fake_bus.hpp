#pragma once

#include "config/net.hpp"
#include "polyfill/net/future.hpp"

#include <functional>
#include <string>

namespace region
{
    using namespace config;

    struct fake_bus
    {
        using executor_type = config::net::io_context::executor_type;
        using strand_type   = net::strand< executor_type >;

        using username_storage_type = std::pair<std::string, bool>;

        fake_bus(executor_type exec)
        : strand_(net::make_strand(exec))
        {
        }

        net::awaitable< std::string > consume_username() {}

        void produce_username(username_storage_type username_storage)
        {
            dispatch(bind_executor(get_strand(), [this, username = std::move(username_storage)]() mutable {
                this->handle_produce_username(std::move(username));
            }));
        }

      private:   // functions
        void handle_produce_username(username_storage_type username_storage)
        {
            BOOST_ASSERT(get_strand().running_in_this_thread());

            if (username_consumer_queue_.empty())
            {
                username_storage_queue_.emplace_back(std::move(username_storage));
                return;
            }
            else // notify a consumer of a new message
            {
                auto promise = username_consumer_queue_.pop_back();
            }

        }


        strand_type get_strand() { return strand_; }

      private:   // data
        // Net
        strand_type strand_;

        // Username queue
        std::vector< polyfill::net::promise< username_storage_type > > username_consumer_queue_;
        std::vector< username_storage_type >                           username_storage_queue_;

        // Packet queue
    };
}   // namespace region