//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "polyfill/net.hpp"
#include "polyfill/net/detail/future_invoker_base.hpp"

#include <boost/beast/core/bind_handler.hpp>
#include <variant>
#include <wise_enum/wise_enum.h>

namespace polyfill::net
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
        {
        }

        void set_value(T val)
        {
            assert(var_.index() == 0);
            if (invoker_)
            {
                auto pinvoker = std::move(invoker_);
                var_          = optional_value(std::nullopt);
                pinvoker->notify_value(optional_value(std::move(val)));
            }
            else
                var_ = optional_value(std::move(val));
        }

        void set_error(error_code ec)
        {
            assert(var_.index() == 0);
            if (invoker_)
            {
                auto pinvoker = std::move(invoker_);
                var_          = ec;
                pinvoker->notify_error(std::move(ec));
            }
            else
                var_ = std::move(ec);
        }

        void set_invoker(std::unique_ptr< detail::future_invoker_base< T > > pinvoker)
        {
            // we should assert that this has not happened more than once
            assert(!invoker_);
            switch (var_.index())
            {
            case 0:   // not set
                invoker_ = std::move(pinvoker);
                break;
            case 1:   // error
            {
                auto ec = std::get< error_code >(var_);
                pinvoker->notify_error(ec);
                break;
            }
            case 2:   // value
            {
                auto &ov = std::get< optional_value >(var_);
                assert(ov.has_value());
                auto val = std::move(ov);
                ov.reset();
                pinvoker->notify_value(std::move(val));
                break;
            }
            }
        }

        std::unique_ptr< detail::future_invoker_base< T > > invoker_;
        variant_type                                        var_;
    };

    template < class T, class Handler >
    struct future_invoker : detail::future_invoker_base< T >
    {
        explicit future_invoker(Handler &&handler)
        : handler_(std::move(handler))
        {
        }

        virtual void notify_value(std::optional< T > &&value) override
        {
            assert(handler_.has_value());
            net::post(boost::beast::bind_front_handler(std::move(*handler_), std::move(value)));
            handler_.reset();
        }

        virtual void notify_error(error_code ec) override
        {
            assert(handler_.has_value());
            net::post(boost::beast::bind_front_handler(std::move(*handler_), std::move(ec)));
            handler_.reset();
        }

        std::optional< Handler > handler_;
    };

    template < class T >
    struct future_wait_op
    {
        template < class Self >
        void operator()(Self &self)
        {
            // initial operation
            shared_state_->set_invoker(std::make_unique< future_invoker< T, Self > >(std::move(self)));
        }

        template < class Self >
        void operator()(Self &self, std::optional< T > &&value)
        {
            self.complete(error_code(), std::move(value));
        }

        template < class Self >
        void operator()(Self &self, error_code ec)
        {
            self.complete(ec, std::optional< T >());
        }

        std::shared_ptr< future_state_impl< T > > shared_state_;
    };

    template < class T, class Executor = net::executor >
    struct promise;

    template < class T, class Executor = net::executor >
    struct future
    {
        using impl_class    = future_state_impl< T >;
        using impl_type     = std::shared_ptr< impl_class >;
        using executor_type = Executor;

        auto operator()() -> awaitable< T, executor_type >;

        template < class CompletionHandler >
        auto async_wait(CompletionHandler &&token);

        auto co_get() -> awaitable< T, executor_type >;

        auto get_executor() const -> executor_type { return exec_; }

      private:
        friend promise< T >;

        future(impl_type impl, executor_type exec)
        : impl_(std::move(impl))
        , exec_(exec)
        {
        }

        impl_type     impl_;
        executor_type exec_;
    };

    template < class T, class Executor >
    struct promise
    {
        using impl_class    = future_state_impl< T >;
        using impl_type     = std::shared_ptr< impl_class >;
        using executor_type = Executor;

        promise(executor_type exec)
        : impl_(std::make_shared< future_state_impl< T > >())
        , exec_(exec)
        {
        }

        promise(promise &&other) noexcept
        : impl_(std::move(other.impl_))
        {
        }

        promise &operator=(promise &&other) noexcept
        {
            destroy();
            impl_ = std::move(other.impl_);
            return *this;
        }

        ~promise() noexcept { destroy(); }

        void set_value(T val)
        {
            impl_->set_value(std::move(val));
            impl_.reset();
        }

        void set_error(error_code ec)
        {
            impl_->set_error(std::move(ec));
            impl_.reset();
        }

        future< T, executor > get_future() { return future< T, executor >(impl_, get_executor()); }

        template < class FutureExecutor >
        future< T, FutureExecutor > get_future(FutureExecutor fe)
        {
            return future< T, FutureExecutor >(impl_, fe);
        }

        auto get_executor() const -> executor_type { return exec_; }

      private:
        void destroy()
        {
            if (impl_)
            {
                impl_->set_error(error::operation_aborted);
                impl_.reset();
            }
        }

        impl_type     impl_;
        executor_type exec_;
    };

}   // namespace polyfill::net

#include "polyfill/net/impl/future.hpp"