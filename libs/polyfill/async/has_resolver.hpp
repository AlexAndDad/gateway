#include "polyfill/net.hpp"

#include <boost/beast/core/bind_handler.hpp>
#include <cassert>

#pragma once
namespace polyfill::async
{
    template < class Derived >
    struct has_resolver
    {
        using protocol_type = net::ip::tcp;
        using resolver_type = protocol_type ::resolver;
        using endpoint_type = protocol_type ::endpoint;
        using results_type  = resolver_type ::results_type;

        has_resolver(net::executor exec)
        : resolver_(exec)
        , results_()
        , running_(false)
        {
        }

        template < class SharedSelf >
        void start_resolver(std::string const &hostname, std::string const &service, SharedSelf self)
        {
            assert(!this->running_);
            this->resolver_.async_resolve(hostname, service, boost::beast::bind_front_handler(std::move(self)));
            this->running_ = true;
        }

        void cancel_resolver() { this->resolver_.cancel(); }

        template < class SharedSelf >
        void operator()(SharedSelf self, error_code ec, results_type results)
        {
            assert(this->running_);
            this->running_ = false;
            this->results_ = std::move(results);

            auto &this_ = *static_cast< Derived * >(this);
            this_.on_resolve();
            this_(std::move(self), this_.set_error(ec));
        }

        void on_resolve() { assert(!"implement me in the derived class"); }

        bool resolving() const { return running_; }
        bool resolved() const { return not running_; }

        auto resolve_results() -> const results_type & { return results_; }

      private:
        resolver_type resolver_;
        results_type  results_;
        bool          running_;
    };
}   // namespace polyfill::async