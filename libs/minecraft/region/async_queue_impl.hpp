#pragma once
#include "config/net.hpp"
#include "polyfill/async/co_future.hpp"
#include "polyfill/async/future.hpp"

#include <deque>
#include <memory>

using namespace config;

namespace minecraft::region
{
    template < class MessageType >
    struct async_queue_impl : std::enable_shared_from_this< async_queue_impl< MessageType > >
    {
        using promise_type = polyfill::async::promise< MessageType >;

        async_queue_impl(net::io_context::executor_type exec)
        : strand_(exec.context())
        {
        }

        net::awaitable< MessageType > consume()
        {
            co_return co_await polyfill::async::co_future< MessageType >(
                net::bind_executor(strand_, [self = this->shared_from_this()]() -> net::awaitable< MessageType > {
                    BOOST_ASSERT(self->get_strand().running_in_this_thread());
                    if (self->deque_.empty())   // await on a future
                    {
                        self->consumers_.emplace_back();   // Emplace a promise representing a consumer
                        auto fut    = self->consumers_.back().get_future();   // Get a future
                        auto result = co_await fut();                         // wait for a message
                        co_return result;
                    }
                    else   // return a message off the bus
                    {
                        MessageType message = std::move(self->deque_.front());
                        self->deque_.pop_front();
                        co_return message;
                    }
                }))();
        }

        void produce(MessageType message)
        {
            net::dispatch(net::bind_executor(get_strand(),
                                             [self = this->shared_from_this(), message = std::move(message)]() mutable {
                                                 BOOST_ASSERT(self->get_strand().running_in_this_thread());
                                                 if (self->consumers_.empty())
                                                 {
                                                     self->deque_.push_back(std::move(message));
                                                 }
                                                 else
                                                 {
                                                     auto promise = std::move(self->consumers_.front());
                                                     self->consumers_.pop_front();
                                                     promise.set_value(std::move(message));
                                                 }
                                             }));
        }

      private:
        net::io_context::strand get_strand() { return strand_; }

        net::io_context::strand    strand_;
        std::deque< MessageType >  deque_;
        std::deque< promise_type > consumers_;
    };
}   // namespace minecraft::region