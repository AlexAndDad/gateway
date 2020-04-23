//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "polyfill/net.hpp"
#include "polyfill/net/detail/future_invoker_base.hpp"

#include <boost/beast/core/bind_handler.hpp>
#include <cassert>
#include <optional>
#include <utility>

namespace polyfill::net::detail
{
    template < class T, class Handler >
    struct future_invoker : detail::future_invoker_base< T >
    {
        explicit future_invoker(Handler &&handler)
        : handler_(std::move(handler))
        {
        }

        virtual void notify_value(future_result_type<T> &&value) override
        {
            net::post(boost::beast::bind_front_handler(std::move(*handler_), std::move(value)));
            handler_.reset();
        }

        std::optional< Handler > handler_;
    };

}   // namespace polyfill::net::detail
