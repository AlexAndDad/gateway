//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

namespace polyfill::async
{
    template < class T >
    promise< T >::promise()
    : impl_(std::make_shared< detail::future_state_impl< T > >())
    , future_impl_(impl_)   // copy to keep the shared state alive until the future has been acquired
    {
    }

    promise< void >::promise()
    : impl_(std::make_shared< detail::future_state_impl< void > >())
    , future_impl_(impl_)   // copy to keep the shared state alive until the future has been acquired
    {
    }

    template < class T >
    promise< T >::promise(promise &&other) noexcept
    : impl_(std::move(other.impl_))
    , future_impl_(
          std::move(other.future_impl_))   // copy to keep the shared state alive until the future has been acquired
    {
    }

    promise< void >::promise(promise &&other) noexcept
    : impl_(std::move(other.impl_))
    , future_impl_(
          std::move(other.future_impl_))   // copy to keep the shared state alive until the future has been acquired
    {
    }

    template < class T >
    auto promise< T >::operator=(promise &&other) noexcept -> promise &
    {
        destroy();
        impl_        = std::move(other.impl_);
        future_impl_ = std::move(other.future_impl_);
        return *this;
    }

    auto promise< void >::operator=(promise &&other) noexcept -> promise &
    {
        destroy();
        impl_        = std::move(other.impl_);
        future_impl_ = std::move(other.future_impl_);
        return *this;
    }

    template < class T >
    promise< T >::~promise() noexcept
    {
        destroy();
    }

    promise< void >::~promise() noexcept { destroy(); }

    template < class T >
    auto promise< T >::set_value(T val) -> void
    {
        assert(impl_);
        impl_->set_value(std::move(val));
        impl_.reset();
    }

    auto promise< void >::set_value() -> void
    {
        assert(impl_);
        auto res = future_result_type< void >(outcome::success());
        impl_->set_value(std::move(res));
        impl_.reset();
    }

    template < class T >
    auto promise< T >::set_error(error_code ec) -> void
    {
        assert(impl_);
        impl_->set_value(ec);
        impl_.reset();
    }

    auto promise< void >::set_error(error_code ec) -> void
    {
        assert(impl_);
        impl_->set_value(ec);
        impl_.reset();
    }

    template < class T >
    auto promise< T >::set_exception(std::exception_ptr ep) -> void
    {
        assert(impl_);
        impl_->set_value(ep);
        impl_.reset();
    }

    auto promise< void >::set_exception(std::exception_ptr ep) -> void
    {
        assert(impl_);
        impl_->set_value(ep);
        impl_.reset();
    }

    template < class T >
    auto promise< T >::get_future() -> future< T >
    {
        assert(future_impl_);
        return future< T >(std::move(future_impl_));
    }

    auto promise< void >::get_future() -> future< void >
    {
        assert(future_impl_);
        return future< void >(std::move(future_impl_));
    }

    template < class T >
    auto promise< T >::destroy() -> void
    {
        if (impl_)
        {
            impl_->set_value(error_code(net::error::operation_aborted));
            impl_.reset();
        }
        future_impl_.reset();
    }

    auto promise< void >::destroy() -> void
    {
        if (impl_)
        {
            impl_->set_value(error_code(net::error::operation_aborted));
            impl_.reset();
        }
        future_impl_.reset();
    }
}   // namespace polyfill::async
