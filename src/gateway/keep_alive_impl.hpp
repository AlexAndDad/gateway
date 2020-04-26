#pragma once

#include "config/net.hpp"

#include <boost/asio/high_resolution_timer.hpp>
#include <boost/optional.hpp>
#include <functional>
#include <iostream>

namespace gateway
{
    struct keep_alive_impl
    {
        using executor_type = config::net::executor;

        keep_alive_impl(executor_type strand)
        : expiry_timer_(strand)
        , update_timer_(strand)
        {
        }

        template < class ExpiryCallback, class UpdateCallback >
        void set_callbacks(ExpiryCallback expiry, UpdateCallback update)
        {
            expiry_ = std::move(expiry);
            update_ = std::move(update);
        }

        void start()
        {
            start_expiry_timer();
            start_update_timer();
        }

        void reset()
        {
            expiry_timer_.cancel();
            update_timer_.cancel();
            stop_ = true;
        }

        void reset_expiry() { start_expiry_timer(); }

      private:
        executor_type get_executor() { return expiry_timer_.get_executor(); }
        void          start_update_timer()
        {
            if (not stop_)
            {
                update_timer_.cancel();
                update_timer_.expires_after(std::chrono::seconds(10));
                update_timer_.async_wait([this](auto ec) mutable { this->update_callback_handler(ec); });
            }
        }
        void start_expiry_timer()
        {
            if (not stop_)
            {
                expiry_timer_.cancel();
                expiry_timer_.expires_after(std::chrono::seconds(30));
                expiry_timer_.async_wait([this](auto ec) mutable { this->expiry_callback_handler(ec); });
            }
        }

        void expiry_callback_handler(boost::system::error_code ec)
        {
            if (ec)   // Timer was canceled, dont call callback
            {
                if (stop_ or ec != config::net::error::operation_aborted)
                {
                    expiry_ = nullptr;
                }
                return;
            }
            if (expiry_)
            {
                update_timer_.cancel();          // Cancel the update timer
                auto tmp = std::move(expiry_);   // Call expiry callback
                tmp();
            }
            else
            {
                std::cout << "Keep alive handler expiry_timer finished but there was no handler to invoke."
                          << std::endl;
            }
        }

        void update_callback_handler(boost::system::error_code ec)
        {
            if (ec)   // Canceled
            {
                update_ = nullptr;
                return;
            }
            if (update_)
            {
                start_update_timer();   // Reschedule the update
                update_();              // Call update callback
            }
            else
            {
                std::cout << "Keep alive handler update_timer finished but there was no handler to invoke."
                          << std::endl;
            }
        }

        std::function< void() >            expiry_;
        std::function< void() >            update_;
        boost::asio::high_resolution_timer expiry_timer_;
        boost::asio::high_resolution_timer update_timer_;
        bool                               stop_ = false;
    };
}   // namespace gateway