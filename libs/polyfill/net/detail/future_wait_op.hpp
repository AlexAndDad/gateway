//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "polyfill/net.hpp"
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
        void operator()(Self &self, std::optional< T > &&value)
        {
            self.complete(error_code(), std::move(value));
        }

        template < class Self >
        void operator()(Self &self, error_code ec)
        {
            self.complete(ec, std::optional< T >());
        }

        std::shared_ptr< future_state_impl< T > > shared_state_;
    };

}   // namespace polyfill::net::detail
