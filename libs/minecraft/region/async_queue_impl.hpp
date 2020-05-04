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
        , canceled_(false)
        {
        }

        void cancel()
        {
            net::dispatch(
                net::bind_executor(get_strand(), [self = async_queue_impl< MessageType >::shared_from_this()]() {
                    self->handle_cancel();
                }));
        }

        /// @brief consume a <MessageType> from the bus
        /// @throws system_error
        /// operation_aborted when the queue is canceled.
        /// @return MessageType
        net::awaitable< MessageType > consume()
        {
            auto promise = promise_type();
            auto future  = promise.get_future();

            net::post(net::bind_executor(
                get_strand(), [self = this->shared_from_this(), promise = std::move(promise)]() mutable {
                    BOOST_ASSERT(self->get_strand().running_in_this_thread());

                    if (self->canceled_)
                    {
                        return;   // Destroys the promise, setting an error in future.
                    }

                    if (self->deque_.empty())   // await on a future
                    {
                        self->consumers_.push_back(std::move(promise));   // Emplace a promise representing a consumer
                    }
                    else   // return a message off the bus
                    {
                        MessageType message = std::move(self->deque_.front());
                        self->deque_.pop_front();
                        promise.set_value(std::move(message));
                    }
                }));

            co_return co_await future();
        }

        void produce(MessageType message, error_code & ec)
        {
            if (canceled_)
            {
                ec = net::error::operation_aborted;
                return;
            }

            net::post(net::bind_executor(get_strand(),
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
        void handle_cancel()
        {
            BOOST_ASSERT(get_strand().running_in_this_thread());
            canceled_ = true;
            consumers_.clear();   // Cancel all consumers
        }

        net::io_context::strand get_strand() { return strand_; }

        net::io_context::strand    strand_;
        std::deque< MessageType >  deque_;
        std::deque< promise_type > consumers_;
        bool                       canceled_;
    };
}   // namespace minecraft::region