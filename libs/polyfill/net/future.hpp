//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "polyfill/net.hpp"
#include "polyfill/net/detail/future_wait_op.hpp"
namespace polyfill::net
{
    template < class T>
    struct promise;

    template < class T>
    struct future
    {
        using impl_class    = detail::future_state_impl< T >;
        using impl_type     = std::shared_ptr< impl_class >;
        using executor_type = net::executor;

        template < class CompletionHandler >
        auto async_wait(CompletionHandler &&token);

        auto operator()() -> awaitable< T>;

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

    template < class T>
    struct promise
    {
        using impl_class    = detail::future_state_impl< T >;
        using impl_type     = std::shared_ptr< impl_class >;
        using executor_type = net::executor;

        promise(executor_type const& exec)
        : impl_(std::make_shared< detail::future_state_impl< T > >())
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
            impl_->set_value(ec);
            impl_.reset();
        }

        future< T > get_future() { return future< T >(impl_, get_executor()); }

        future< T > get_future(net::executor fe)
        {
            return future< T >(impl_, fe);
        }

        auto get_executor() const -> executor_type { return exec_; }

      private:
        void destroy()
        {
            if (impl_)
            {
                impl_->set_value(error_code(error::operation_aborted));
                impl_.reset();
            }
        }

        impl_type     impl_;
        executor_type exec_;
    };

}   // namespace polyfill::net

#include "polyfill/net/impl/future.hpp"