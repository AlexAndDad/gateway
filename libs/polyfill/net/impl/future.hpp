namespace polyfill::net
{
    template < class T, class Executor >
    auto future< T, Executor >::operator()() -> awaitable< T, executor_type >
    {
        return co_get();
    }

    template < class T, class Executor >
    template < class CompletionHandler >
    auto future< T, Executor >::async_wait(CompletionHandler &&token)
    {
        return net::async_compose< CompletionHandler, void(error_code, std::optional< T >) >(
            future_wait_op< T > { impl_ }, token, *this);
    }

    template < class T, class Executor >
    auto future< T, Executor >::co_get() -> awaitable< T, executor_type >
    {
        auto ot = co_await async_wait(net::use_awaitable);
        co_return std::move(*ot);
    }

}   // namespace polyfill::net