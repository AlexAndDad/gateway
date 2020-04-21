//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "polyfill/net.hpp"

#include <optional>
#include <variant>

namespace polyfill::net::detail
{
    /// A signal type indicating that the future does not yet have state
    struct future_pending
    {
    };

    /// A signal type that indicates that the future state has completed the promise by invoking the future's handler
    /// with either an error or a value
    struct future_completed
    {
    };

    template < class T >
    struct future_state_impl
    {
        using optional_value = std::optional< T >;
        using variant_type   = std::variant< future_pending, error_code, optional_value, future_completed >;

        explicit future_state_impl()
        : invoker_()
        , var_()
        , mutex_()
        {
        }

        void set_value(T val)
        {
            auto lock = std::unique_lock(mutex_);
            assert(std::holds_alternative< future_pending >(var_));
            if (invoker_)
            {
                auto pinvoker = std::move(invoker_);
                var_          = future_completed();
                lock.unlock();
                pinvoker->notify_value(optional_value(std::move(val)));
            }
            else
                var_ = optional_value(std::move(val));
        }

        void set_error(error_code ec)
        {
            auto lock = std::unique_lock(mutex_);
            assert(std::holds_alternative< future_pending >(var_));
            if (invoker_)
            {
                auto pinvoker = std::move(invoker_);
                var_          = future_completed();
                lock.unlock();
                pinvoker->notify_error(ec);
            }
            else
                var_ = ec;
        }

        void set_invoker(std::unique_ptr< detail::future_invoker_base< T > > pinvoker)
        {
            auto lock = std::unique_lock(mutex_);
            assert(not invoker_);

            if (std::holds_alternative< future_pending >(var_))
            {
                invoker_ = std::move(pinvoker);
                return;
            }
            else if (std::holds_alternative< error_code >(var_))
            {
                auto ec = std::get< error_code >(var_);
                var_    = future_completed();
                lock.unlock();
                pinvoker->notify_error(ec);
                return;
            }
            else if (std::holds_alternative< optional_value >(var_))
            {
                auto val = std::move(std::get< optional_value >(var_));
                var_     = future_completed();
                lock.unlock();
                assert(val.has_value());
                pinvoker->notify_value(std::move(val));
                return;
            }
            else if (std::holds_alternative< future_completed >(var_))
            {
                assert(!"promise invoked more than once");
            }
            assert(!"serious logic error");
        }

      private:
        std::unique_ptr< detail::future_invoker_base< T > > invoker_;
        variant_type                                        var_;
        std::mutex                                          mutex_;
    };

}   // namespace polyfill::net::detail
