//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

namespace polyfill::async
{
    template < class T >
    template < class CompletionHandler >
    auto future< T >::async_wait(CompletionHandler &&token)
    {
        return net::async_compose< CompletionHandler, void(result_type) >(
            detail::future_wait_op< T > { impl_ }, token);
    }

    template < class T >
    auto future< T >::operator()() -> net::awaitable< T >
    {
        auto r = co_await async_wait(net::use_awaitable);
        if (r.has_value())
            co_return std::move(r).assume_value();
        else if (r.has_error())
            throw system_error(r.assume_error());
        else
            throw r.exception();
    }

}   // namespace polyfill::net