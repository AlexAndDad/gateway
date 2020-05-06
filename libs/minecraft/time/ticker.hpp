#pragma once

#include "minecraft/net.hpp"
#include "polyfill/async/future.hpp"

#include <boost/asio/high_resolution_timer.hpp>
#include <chrono>

namespace minecraft::time
{
    using delta_time_type = std::chrono::milliseconds;

    struct tick_result
    {
        tick_result(delta_time_type d_time, bool slow)
        : delta_time(std::move(d_time))
        , slow(slow)
        {
        }

        delta_time_type delta_time;
        bool            slow;
    };

    struct ticker
    {
        using strand_type = config::net::io_context::strand;

        using timer_type      = boost::asio::high_resolution_timer;
        using clock_type      = timer_type::clock_type;
        using time_point_type = clock_type::time_point;

        ticker(strand_type &strand, delta_time_type tick_interval)
        : strand_(strand)
        , awaited_(false)
        , timer_(strand_)
        , tick_interval_(tick_interval)
        , last_tick_()
        , canceled_(false)
        , tick_callback_()
        {
        }

        void start()
        {
            BOOST_ASSERT(this_thread());
            last_tick_ = cur_time();
        }

        void cancel() { BOOST_ASSERT(this_thread()); }

        config::net::awaitable< tick_result > await_next_tick()
        {
            BOOST_ASSERT(this_thread());
            if (canceled_)
            {
                throw system_error(net::error::operation_aborted);
            }

            BOOST_ASSERT(not awaited_);
            // Figure out when the next tick should be
            auto current_time   = cur_time();
            auto next_tick_time = last_tick_ + tick_interval_;

            // Has the time for the next tick already passed?
            if (next_tick_time <= current_time)   // Yes, no need to wait to sent result.
            {
                delta_time_type delta_time = std::chrono::duration_cast< delta_time_type >(current_time - last_tick_);
                last_tick_                 = current_time;
                co_return tick_result(delta_time, true);
            }
            else   // No, wait on a timer then send result.
            {
                auto time_until_tick = next_tick_time - current_time;
                timer_.expires_after(time_until_tick);
                co_await timer_.async_wait(config::net::use_awaitable);
                current_time               = cur_time();
                delta_time_type delta_time = std::chrono::duration_cast< delta_time_type >(current_time - last_tick_);
                last_tick_                 = current_time;
                co_return tick_result(delta_time, false);
            }
        }

      private:
        bool                   this_thread() { return strand_.running_in_this_thread(); }
        clock_type::time_point cur_time() { return clock_type::now(); }

        strand_type &strand_;
        bool         awaited_;

        timer_type      timer_;
        delta_time_type tick_interval_;
        time_point_type last_tick_;
        bool            canceled_;

        polyfill::async::promise< void > tick_callback_;
    };
}   // namespace minecraft::time