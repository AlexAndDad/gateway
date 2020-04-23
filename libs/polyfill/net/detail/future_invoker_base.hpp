#pragma once
#include "polyfill/outcome.hpp"

namespace polyfill::net::detail
{
    template < class T >
    struct future_invoker_base
    {
        virtual ~future_invoker_base() = default;

        virtual void notify_value(outcome::result<T>&& result) = 0;
    };

}