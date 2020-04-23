#pragma once
#include "polyfill/outcome.hpp"
#include "polyfill/net/future_types.hpp"

namespace polyfill::net::detail
{
    template < class T >
    struct future_invoker_base
    {
        virtual ~future_invoker_base() = default;

        virtual void notify_value(future_result_type<T>&& result) = 0;
    };

}