#pragma once

#include "config/net.hpp"
#include "polyfill/net/future.hpp"

#include <functional>
#include <memory>
#include <minecraft/packets/client_play_packet.hpp>
#include <minecraft/packets/server_play_packet.hpp>
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
        using username_handle_type  = std::shared_ptr< username_promise_type >;

        using server_packet_type = minecraft::packets::server_play_packet;
        using client_packet_type = minecraft::packets::client_play_packet;

        fake_bus(executor_type exec)
        : strand_(net::make_strand(exec))
        {
        }

      public:   // Functions
        net::awaitable< username_storage_type > consume_username(net::io_context::strand &exec)
        {
            co_await net::post(get_strand(), net::use_awaitable);
            BOOST_ASSERT(get_strand().running_in_this_thread());

            username_handle_type promise = std::make_shared< username_promise_type >(get_strand());
            username_consumer_queue_.push_back(promise);
            auto fut = promise->get_future(exec);
            auto res = co_await fut();

            BOOST_ASSERT(exec.running_in_this_thread());   // Make sure we are ready to return on the exec of the caller
            co_return res;
        }

        void produce_username(username_storage_type username_storage)
        {
            dispatch(bind_executor(get_strand(), [this, username = std::move(username_storage)]() mutable {
                this->handle_produce_username(std::move(username));
            }));
        }

        void produce_client_packet(std::string name, client_packet_type packet) {

        }

        net::awaitable< client_packet_type > consume_client_packet(net::io_context::strand &exec,
                                                                                        std::string player_name)
        {
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
            else   // notify a consumer of a new message
            {
                auto prom = username_consumer_queue_.back();
                prom->set_value(std::move(username_storage));

                username_consumer_queue_.pop_back();
            }
        }

        strand_type get_strand() { return strand_; }

      private:   // data
        // Net
        strand_type strand_;

        // Username queue
        std::vector< username_handle_type >  username_consumer_queue_;
        std::vector< username_storage_type > username_storage_queue_;

        // Packet queue
    };
}   // namespace minecraft::region