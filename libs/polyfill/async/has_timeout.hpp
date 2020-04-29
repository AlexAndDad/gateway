#include "polyfill/net.hpp"

#include <boost/beast/core/bind_handler.hpp>
#include <cassert>

#pragma once
namespace polyfill::async
{
    template < class Derived >
    struct has_timeout
    {
        has_timeout(net::executor exec)
        : timer_(exec)
        , current_id_(0)
        , running_(false)
        {
        }

        struct timer_event
        {
            unsigned int id;
        };

        template < class SharedSelf >
        void start_timeout(std::chrono::milliseconds how_long, SharedSelf self)
        {
            assert(!running_);
            current_id_ = (current_id_ + 1) % 1024;
            timer_.expires_after(how_long);
            timer_.async_wait(boost::beast::bind_front_handler(std::move(self), timer_event { current_id_ }));
            this->running_ = true;
        }

        void cancel_timeout() { timer_.cancel(); }

        template < class SharedSelf >
        void operator()(SharedSelf self, timer_event event, error_code ec)
        {
            assert(event.id == current_id_);
            assert(running_);
            running_ = false;
            if (!ec)
                ec = net::error::timed_out;
            if (ec != net::error::operation_aborted)
            {
                auto &this_ = *static_cast< Derived * >(this);
                this_.on_timeout();
                this_(std::move(self), this_.set_error(ec));
            }
        }

        void on_timeout() { assert(!"implement me in the derived class"); }

        bool timing_out() const { return running_; }
        bool timed_out() const { return not running_; }

      private:
        net::high_resolution_timer timer_;
        unsigned int               current_id_;
        bool                       running_;
    };
}   // namespace polyfill::async