#pragma once

#include "config/net.hpp"
#include "polyfill/async/future.hpp"

#include <boost/asio/high_resolution_timer.hpp>
#include <chrono>

namespace minecraft::time
{
    struct ticker
    {
        using strand_type = config::net::io_context::strand;

        using timer_type      = boost::asio::high_resolution_timer;
        using clock_type      = timer_type::clock_type;
        using time_point_type = clock_type::time_point;
        using delta_time_type = std::chrono::milliseconds;

        ticker(strand_type &strand)
        : strand_(strand)
        , started_(false)
        , timer_(strand_)
        , tick_callback_()
        {
        }

        void start()
        {
            BOOST_ASSERT(this_thread());
            started_ = true;
        }

        config::net::awaitable< delta_time_type > await_tick() { BOOST_ASSERT(this_thread()); }

      private:
        bool                   this_thread() { strand_.running_in_this_thread(); }
        clock_type::time_point cur_time() { return clock_type::now(); }

        strand_type &strand_;
        bool         started_;

        timer_type      timer_;
        time_point_type last_tick_;

        polyfill::async::promise< void > tick_callback_;
    };
}   // namespace minecraft::time