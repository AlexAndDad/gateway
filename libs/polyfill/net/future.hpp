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


        /// @brief Asynchronously wait for fulfilment of the associated promise.
        ///
        /// If the promise is destroyed before providing a value or error, the completion handler will be
        /// invoked with the error net::error::operation_aborted.
        /// The completion handler will happen as if by net::post on the associated executor of token.
        /// @tparam CompletionHandler A completion token whose handler is compatible with void(error_code, std::optional<T>)
        /// @param token The completion token/handler.
        /// @return DEDUCED
        /// @note
        template < class CompletionHandler >
        auto async_wait(CompletionHandler &&token);

        auto operator()() -> awaitable< T>;

        auto get_executor() const -> executor_type { return exec_; }

      private:
        friend promise< T >;

        future(impl_type impl, executor_type exec);

        impl_type     impl_;
        executor_type exec_;
    };

    template < class T>
    struct promise
    {
        using impl_class    = detail::future_state_impl< T >;
        using impl_type     = std::shared_ptr< impl_class >;
        using executor_type = net::executor;

        promise(executor_type const& exec);

        promise(promise &&other) noexcept;

        auto operator=(promise &&other) noexcept -> promise&;

        ~promise() noexcept;

        void set_value(T val);

        void set_error(error_code ec);

        future< T > get_future();

        future< T > get_future(net::executor fe);

        auto get_executor() const -> executor_type;

      private:
        void destroy();

        impl_type     impl_;
        executor_type exec_;
    };

}   // namespace polyfill::net

#include "polyfill/net/future.ipp"
