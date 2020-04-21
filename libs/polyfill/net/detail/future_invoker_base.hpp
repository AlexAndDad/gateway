//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "polyfill/net.hpp"

#include <optional>

namespace polyfill::net::detail
{
    template < class T >
    struct future_invoker_base
    {
        virtual ~future_invoker_base() = default;

        virtual void notify_value(std::optional< T > &&val) = 0;
        virtual void notify_error(error_code ec)            = 0;
    };

}   // namespace polyfill::net::detail
