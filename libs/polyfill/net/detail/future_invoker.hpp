//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "polyfill/net.hpp"

#include <optional>
#include <boost/beast/core/bind_handler.hpp>
#include <cassert>
#include <utility>

namespace polyfill::net::detail
{
    template < class T >
    struct future_invoker_base
    {
        virtual ~future_invoker_base() = default;

        virtual void notify_value(std::optional< T > &&val) = 0;
        virtual void notify_error(error_code ec)            = 0;
    };

    template < class T, class Handler >
    struct future_invoker : detail::future_invoker_base< T >
    {
        explicit future_invoker(Handler &&handler)
            : handler_(std::move(handler))
        {
        }

        virtual void notify_value(std::optional< T > &&value) override
        {
            assert(handler_.has_value());
            net::post(boost::beast::bind_front_handler(std::move(*handler_), std::move(value)));
            handler_.reset();
        }

        virtual void notify_error(error_code ec) override
        {
            assert(handler_.has_value());
            net::post(boost::beast::bind_front_handler(std::move(*handler_), std::move(ec)));
            handler_.reset();
        }

        std::optional< Handler > handler_;
    };


}   // namespace polyfill::net::detail
