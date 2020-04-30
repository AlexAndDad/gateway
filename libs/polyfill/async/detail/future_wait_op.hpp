//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "future_invoker.hpp"
#include "future_state_impl.hpp"
#include "polyfill/async/future_types.hpp"
#include "polyfill/net.hpp"

#include <memory>

namespace polyfill::async::detail
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


    template < >
    struct future_wait_op<void>
    {
        template < class Self >
        void operator()(Self &self)
        {
            // initial operation
            shared_state_->set_invoker(std::make_unique< future_invoker< void, Self > >(std::move(self)));
        }

        template < class Self >
        void operator()(Self &self, future_result_type< void > &&value)
        {
            self.complete(std::move(value));
        }

        std::shared_ptr< future_state_impl< void > > shared_state_;
    };

}   // namespace polyfill::net::detail
