//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "polyfill/async/detail/future_wait_op.hpp"
#include "polyfill/net.hpp"

namespace polyfill::async
{
    template < class T >
    struct promise;

    template < class T >
    struct future
    {
        using impl_class = detail::future_state_impl< T >;
        using impl_type  = std::shared_ptr< impl_class >;

        using result_type = future_result_type< T >;

        template < class CompletionHandler >
        auto async_wait(CompletionHandler &&token);

        auto operator()() -> net::awaitable< T >;

      private:
        friend promise< T >;

        future(impl_type impl)
        : impl_(std::move(impl))
        {
        }

        impl_type impl_;
    };

    template < class T >
    struct promise
    {
        using impl_class = detail::future_state_impl< T >;
        using impl_type  = std::shared_ptr< impl_class >;

        promise();

        promise(promise &&other) noexcept;

        promise &operator=(promise &&other) noexcept;

        ~promise() noexcept;

        void set_value(T val);

        void set_error(error_code ec);

        void set_exception(std::exception_ptr ep);

        future< T > get_future();

      private:
        void destroy();

        impl_type impl_;
        impl_type future_impl_;
    };

}   // namespace polyfill::net

#include "future.ipp"
#include "promise.ipp"