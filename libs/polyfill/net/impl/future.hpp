namespace polyfill::net
{
    template < class T >
    template < class CompletionHandler >
    auto future< T >::async_wait(CompletionHandler &&token)
    {
        return net::async_compose< CompletionHandler, void(outcome::result< T >) >(
            detail::future_wait_op< T > { impl_ }, token, *this);
    }

    template < class T >
    auto future< T >::operator()() -> awaitable< T >
    {
        auto r = co_await async_wait(net::use_awaitable);
        if (r.has_value())
            co_return std::move(r).assume_value();
        else
            throw system_error(r.assume_error());
    }

}   // namespace polyfill::net