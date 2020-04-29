//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "config.hpp"
#include "minecraft/protocol/stream.hpp"
#include "polyfill/async/has_error.hpp"
#include "polyfill/async/has_resolver.hpp"
#include "polyfill/async/has_timeout.hpp"
#include "polyfill/net/shared_composed_op.hpp"

#include <boost/asio/compose.hpp>
#include <boost/asio/coroutine.hpp>

namespace bot
{
    template < class NextLayer >
    struct ping_op
    : boost::asio::coroutine
    , polyfill::async::has_error
    , polyfill::async::has_timeout< ping_op< NextLayer > >
    , polyfill::async::has_resolver< ping_op< NextLayer > >
    {
        using has_timeout  = polyfill::async::has_timeout< ping_op< NextLayer > >;
        using has_resolver = polyfill::async::has_resolver< ping_op< NextLayer > >;

        ping_op(minecraft::protocol::stream< NextLayer > &stream, std::string hostname, std::string service)
        : coroutine()
        , has_error()
        , has_timeout(stream.get_executor())
        , has_resolver(stream.get_executor())
        , stream_(stream)
        , hostname_(std::move(hostname))
        , service_(std::move(service))
        {
        }

        using has_resolver ::operator();
        using has_timeout :: operator();

        template < class Self >
        using shared = polyfill::net::shared< Self >;
        template < class Self >
        void operator()(Self &self)
        {
            polyfill::net::share(std::move(self));
        }

        void on_timeout() { this->cancel_resolver(); }

        void on_resolve() { this->cancel_timeout(); }

        void on_connect() { this->cancel_timeout(); }

        struct connect_event
        {
        };
        bool connecting_ = false;

        template < class Self >
        void operator()(shared< Self > self, connect_event, error_code ec)
        {
            connecting_ = false;
            on_connect();
            (*this)(std::move(self), this->set_error(ec));
        }

        auto connecting() -> bool { return connecting_; }

        template < class Self >
        void operator()(shared< Self > self, error_code ec = {})
        {
#include <boost/asio/yield.hpp>
            reenter(this)
            {
                yield
                {
                    this->start_timeout(10s, self);
                    this->start_resolver(hostname_, service_, self);
                }

                while (this->resolving() or this->timing_out())
                    yield;
                if (ec)
                    goto done;

                for (iter = this->resolve_results().begin(); iter != this->resolve_results().end(); ++iter)
                {
                    yield
                    {
                        this->start_timeout(5s, self);
                        stream_.next_layer().async_connect(
                            iter->endpoint(), boost::beast::bind_front_handler(std::move(self), connect_event()));
                        connecting_ = true;
                    }
                    while (this->connecting() or this->timing_out())
                        yield;
                    if (not ec)
                        break;
                    else if (iter != this->resolve_results().end())
                        ec = this->clear_error();
                }
                if (ec)
                    goto done;

            done:
                self.complete(ec);
            }
#include <boost/asio/unyield.hpp>
        }

      private:
        minecraft::protocol::stream< NextLayer > &          stream_;
        std::string                                         hostname_, service_;
        typename has_resolver::results_type::const_iterator iter;
    };
}   // namespace bot