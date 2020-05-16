#pragma once
#include "connection_impl.hpp"

namespace minecraft::chunks
{
    struct provider;

    struct connection
    {
        using executor_type = connection_impl::executor_type;
        using value_type    = connection_impl::value_type;

        connection(connection&&) = default;
        connection& operator=(connection&& other);
        ~connection();

        template < class CompletionToken >
        auto async_wait(CompletionToken &&token) ->
            typename net::async_result< std::decay_t< CompletionToken >,
                                        void(error_code,
                                             value_type) >::return_type;

        [[nodiscard]] auto wait() -> net::awaitable< value_type >;

        void cancel();

      private:
        connection(std::shared_ptr< connection_impl > impl)
        : impl_(std::move(impl))
        {
        }

        friend provider;

        std::shared_ptr< connection_impl > impl_;
    };
}   // namespace minecraft::chunks

namespace minecraft::chunks
{
    template < class CompletionToken >
    auto connection::async_wait(CompletionToken &&token) ->
    typename net::async_result< std::decay_t< CompletionToken >,
        void(error_code,
             value_type) >::return_type
    {
        assert(impl_);
        return impl_->async_wait(std::forward<CompletionToken>(token));
    }

}