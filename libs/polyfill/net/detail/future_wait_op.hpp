//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "polyfill/net.hpp"
#include "polyfill/net/future_types.hpp"
#include "polyfill/net/detail/future_invoker.hpp"
#include "polyfill/net/detail/future_state_impl.hpp"

#include <memory>

namespace polyfill::net::detail
{
    template < class T >
    struct future_wait_op
    {
        template < class Self >
        void operator()(Self &self)
        {
            // initial operation
            shared_state_->set_invoker(std::make_unique< future_invoker< T, Self > >(std::move(self)));
        }

        template < class Self >
        void operator()(Self &self, future_result_type< T > &&value)
        {
            self.complete(std::move(value));
        }

        std::shared_ptr< future_state_impl< T > > shared_state_;
    };

}   // namespace polyfill::net::detail
