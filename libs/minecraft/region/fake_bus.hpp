#pragma once

#include "config/net.hpp"
#include "polyfill/net/future.hpp"

#include <deque>
#include <functional>
#include <memory>
#include <minecraft/packets/server/play_packet.hpp>
#include <string>

namespace minecraft::region
{
    using namespace config;

    struct fake_bus : std::enable_shared_from_this< fake_bus >
    {
        using executor_type = config::net::io_context::executor_type;
        using strand_type   = net::strand< executor_type >;

        using username_storage_type = std::pair< std::string, bool >;
        using username_promise_type = polyfill::net::promise< username_storage_type >;

        using server_packet_type = minecraft::packets::server::play_packet;

        fake_bus(executor_type exec)
        : strand_(net::make_strand(exec))
        {
        }

      public:   // Functions
        net::awaitable< username_storage_type > consume_username(net::io_context::strand &exec)
        {
            co_await net::post(get_strand(), net::use_awaitable);
            BOOST_ASSERT(get_strand().running_in_this_thread());

            auto p = polyfill::net::promise< username_storage_type >();
            auto f = p.get_future();

            net::co_spawn(
                this->get_strand(),
                [p = std::move(p), self = this->shared_from_this()]() mutable -> net::awaitable< void > {
                    if (self->username_storage_queue_.empty())
                    {
                        self->username_consumer_queue_.push_back(std::move(p));
                    }
                    else
                    {
                        auto user = std::move(self->username_storage_queue_.front());
                        self->username_storage_queue_.pop_front();
                        p.set_value(std::move(user));
                    }
                    co_return;
                },
                net::detached);

            auto result = co_await f();
            co_return result;
        }

        void produce_username(username_storage_type username_storage)
        {
            dispatch(bind_executor(get_strand(),
                                   [self = this->shared_from_this(), username = std::move(username_storage)]() mutable {
                                       BOOST_ASSERT(self->get_strand().running_in_this_thread());

                                       if (self->username_consumer_queue_.empty())
                                       {
                                           self->username_storage_queue_.push_back(std::move(username));
                                       }
                                       else   // notify a consumer of a new message
                                       {
                                           auto prom = std::move(self->username_consumer_queue_.front());
                                           self->username_consumer_queue_.pop_front();
                                           prom.set_value(std::move(username));
                                       }
                                   }));
        }

        /*
        void produce_client_packet(minecraft::packets::server::play_packet packet) {}
        net::awaitable< minecraft::packets::server::play_packet > consume_client_packet(net::io_context::strand &exec,
                                                                                        std::string player_name)
        {
        }
*/

      private:   // functions
        strand_type get_strand() { return strand_; }

      private:   // data
        // Net
        strand_type strand_;

        // Username queue
        std::deque< username_promise_type > username_consumer_queue_;
        std::deque< username_storage_type > username_storage_queue_;

        // Packet queue
    };
}   // namespace minecraft::region