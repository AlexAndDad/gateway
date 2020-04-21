namespace polyfill::net
{
    template < class T >
    auto future< T >::operator()() -> awaitable< T >
    {
        return co_get();
    }

    template < class T >
    template < class CompletionHandler >
    auto future< T >::async_wait(CompletionHandler &&token)
    {
        return net::async_compose< CompletionHandler, void(error_code, std::optional< T >) >(
            future_wait_op< T > { impl_ }, token, get_executor());
    }

    template < class T >
    auto future< T >::co_get() -> awaitable< T >
    {
        auto ot = co_await async_wait(net::use_awaitable);
        co_return std::move(*ot);
    }

}   // namespace polyfill::net