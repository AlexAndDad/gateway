namespace polyfill::net
{
    template < class T >
    future< T >::future(impl_type impl, executor_type exec)
    : impl_(std::move(impl))
    , exec_(std::move(exec))
    {
    }

    template < class T >
    template < class CompletionHandler >
    auto future< T >::async_wait(CompletionHandler &&token)
    {
        return net::async_compose< CompletionHandler, void(error_code, std::optional< T >) >(
            detail::future_wait_op< T > { impl_ }, token, *this);
    }

    template < class T >
    auto future< T >::operator()() -> awaitable< T >
    {
        auto ot = co_await async_wait(net::use_awaitable);
        co_return std::move(*ot);
    }

    // ------ promise ------

    template < class T >
    promise< T >::promise(executor_type const &exec)
    : impl_(std::make_shared< detail::future_state_impl< T > >())
    , exec_(exec)
    {
    }

    template < class T >
    promise< T >::promise(promise &&other) noexcept
    : impl_(std::move(other.impl_))
    {
    }

    template < class T >
    auto promise< T >::operator=(promise &&other) noexcept -> promise &
    {
        destroy();
        impl_ = std::move(other.impl_);
        return *this;
    }

    template < class T >
    promise< T >::~promise() noexcept
    {
        try
        {
            destroy();
        }
        catch(...)
        {
            // squash any (unlikely) exceptions
        }
    }

    template < class T >
    auto promise< T >::set_value(T val) -> void
    {
        impl_->set_value(std::move(val));
        impl_.reset();
    }

    template < class T >
    auto promise< T >::set_error(error_code ec) -> void
    {
        impl_->set_error(std::move(ec));
        impl_.reset();
    }

    template < class T >
    auto promise< T >::get_future() -> future<T>{ return future< T >(impl_, get_executor()); }

    template < class T >
    auto promise< T >::get_future(net::executor fe) -> future<T>
    {
        return future< T >(impl_, fe);
    }

    template < class T >
    auto promise< T >::get_executor() const -> executor_type { return exec_; }


    template < class T >
    auto promise< T >::destroy() -> void
    {
        if (impl_)
        {
            impl_->set_error(error::operation_aborted);
            impl_.reset();
        }
    }

}   // namespace polyfill::net