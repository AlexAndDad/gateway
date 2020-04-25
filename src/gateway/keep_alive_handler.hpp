#pragma once

#include "config/net.hpp"

#include <boost/asio/high_resolution_timer.hpp>
#include <boost/optional.hpp>
#include <functional>

namespace gateway
{
    struct keep_alive_handler
    {
        using executor_type = net::executor;

        keep_alive_handler(executor_type strand)
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
            expiry_.reset();
            update_.reset();
            expiry_timer_.cancel();
            update_timer_.cancel();
        }

        void reset_expiry() { start_expiry_timer(); }

      private:
        executor_type get_executor() { return expiry_timer_.get_executor(); }
        void          start_update_timer()
        {
            update_timer_.cancel();
            update_timer_.expires_after(std::chrono::seconds(1));
            update_timer_.async_wait([this](auto ec) mutable { this->update_callback_handler(ec); });
        }
        void start_expiry_timer()
        {
            expiry_timer_.cancel();
            expiry_timer_.expires_after(std::chrono::seconds(20));
            expiry_timer_.async_wait([this](auto ec) mutable { this->expiry_callback_handler(ec); });
        }

        void expiry_callback_handler(boost::system::error_code ec)
        {
            if (ec)   // Timer was canceled, dont call callback
            {
                return;
            }
            if (expiry_)
            {
                update_timer_.cancel();                // Cancel the update timer
                auto tmp = std::move(expiry_.get());   // Call expity callback
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
                return;
            }
            if (update_)
            {
                start_update_timer();   // Reschedule the update
                update_.get()();        // Call update callback
            }
            else
            {
                std::cout << "Keep alive handler update_timer finished but there was no handler to invoke."
                          << std::endl;
            }
        }

        boost::optional< std::function< void() > > expiry_;
        boost::optional< std::function< void() > > update_;
        boost::asio::high_resolution_timer         expiry_timer_;
        boost::asio::high_resolution_timer         update_timer_;
    };
}   // namespace gateway