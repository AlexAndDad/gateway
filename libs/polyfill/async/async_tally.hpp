//
// Created by ahodges on 24/05/2020.
//

#pragma once

#include "future.hpp"
#include "net.hpp"

namespace polyfill::async
{
    struct async_tally
    {
        async_tally()
        :count_(0)
        {}

        net::awaitable< void > await_decrement()
        {
            assert(not waiting_);

            waiting_.emplace();
            auto fut = waiting_.value().get_future();
            co_await fut();
        }

        void increment() { count_++; }
        void decrement()
        {
            count_--;
            if (waiting_)
            {
                waiting_.value().set_value();
                waiting_.reset();
            }
        }

        std::size_t count() const { return count_; }
        void cancel()
        {
            if (waiting_)
            {
                waiting_.value().set_error(net::error::operation_aborted);
                waiting_.reset();
            }
        }

      private:
        std::size_t                      count_;
        std::optional< promise< void > > waiting_;
    };
}   // namespace polyfill