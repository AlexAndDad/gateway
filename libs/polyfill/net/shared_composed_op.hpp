//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "polyfill/net.hpp"

namespace polyfill::net
{
    template < class Impl, class Work, class Handler, class Signature>
    struct shared_composed_op
    {
        using composed_op_type = net::detail::composed_op< Impl, Work, Handler, Signature >;

        using allocator_type = typename net::associated_allocator< composed_op_type >::type;
        using executor_type  = typename net::associated_executor< composed_op_type >::type;

        shared_composed_op(composed_op_type &&op)
        : impl_(std::make_shared< composed_op_type >(std::move(op)))
        {
        }

        shared_composed_op(std::shared_ptr< composed_op_type > op)
        : impl_(std::move(op))
        {
        }

        void initial_resume() { impl_->impl_(*this); }

        template < class... Args >
        void operator()(Args &&... args)
        {
            if (impl_->invocations_ < ~unsigned(0))
            {
                ++impl_->invocations_;
                impl_->impl_(*this, std::forward< Args >(args)...);
            }
        }

        template < class... Args >
        void complete(Args &&... args)
        {
            impl_->complete(std::forward< Args >(args)...);
        }

        auto get_allocator() const -> allocator_type { return impl_->get_allocator(); }
        auto get_executor() const -> executor_type { return impl_->get_executor(); }

        std::shared_ptr< composed_op_type > impl_;
    };

    template < class Impl, class Work, class Handler, class Signature >
    auto share(net::detail::composed_op< Impl, Work, Handler, Signature > &composed_op)
    {
        auto op = shared_composed_op< Impl, Work, Handler, Signature >(std::move(composed_op));
        op.initial_resume();
        return op;
    }

    template < class Impl, class Work, class Handler, class Signature >
    auto share(shared_composed_op< Impl, Work, Handler, Signature > shared_thing)
    {
        return shared_thing;
    }

    template < typename Impl, typename Work, typename Handler, typename Signature >
    inline void *asio_handler_allocate(std::size_t                                           size,
                                       shared_composed_op< Impl, Work, Handler, Signature > *this_handler)
    {
        return boost_asio_handler_alloc_helpers::allocate(size, this_handler->impl_->handler_);
    }

    template < typename Impl, typename Work, typename Handler, typename Signature >
    inline void asio_handler_deallocate(void *                                                pointer,
                                        std::size_t                                           size,
                                        shared_composed_op< Impl, Work, Handler, Signature > *this_handler)
    {
        boost_asio_handler_alloc_helpers::deallocate(pointer, size, this_handler->impl_->handler_);
    }

    template < typename Impl, typename Work, typename Handler, typename Signature >
    inline bool asio_handler_is_continuation(shared_composed_op< Impl, Work, Handler, Signature > *this_handler)
    {
        return asio_handler_is_continuation(this_handler->impl_.get());
    }

    template < typename Function, typename Impl, typename Work, typename Handler, typename Signature >
    inline void asio_handler_invoke(Function &                                            function,
                                    shared_composed_op< Impl, Work, Handler, Signature > *this_handler)
    {
        boost_asio_handler_invoke_helpers::invoke(function, this_handler->impl_->handler_);
    }

    template < typename Function, typename Impl, typename Work, typename Handler, typename Signature >
    inline void asio_handler_invoke(const Function &                                      function,
                                    shared_composed_op< Impl, Work, Handler, Signature > *this_handler)
    {
        boost_asio_handler_invoke_helpers::invoke(function, this_handler->impl_->handler_);
    }

}   // namespace polyfill::net
