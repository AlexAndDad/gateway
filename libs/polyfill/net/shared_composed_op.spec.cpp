#include "polyfill/net/shared_composed_op.hpp"

#include <boost/beast/_experimental/test/handler.hpp>
#include <boost/beast/core/bind_handler.hpp>
#include <catch2/catch.hpp>
#include <iostream>

using namespace polyfill;
using namespace std::literals;

using boost::beast::bind_front_handler;

struct has_error
{
    error_code error;

    error_code &assign_error(error_code &ec)
    {
        if (not error.failed() and ec.failed())
            error = ec;
        return error;
    }
};

template < class Derived >
struct has_timeout
{
    has_timeout(net::executor e, std::chrono::milliseconds to)
    : timer_(e)
    , to_(to)
    {
    }

    struct timer_event
    {
    };

    template < class Self >
    void start_timeout(Self &self)
    {
        timer_.expires_after(to_);
        timer_.async_wait(bind_front_handler(net::share(self), timer_event()));
    }

    void cancel_timeout() { timer_.cancel(); }

    template < class Self >
    void operator()(Self &self, timer_event, error_code ec)
    {
        auto &this_ = *static_cast< Derived * >(this);
        timeout     = true;
        if (ec == net::error::operation_aborted)
            ec.clear();
        else if (ec == error_code())
        {
            ec = net::error::timed_out;
            this_.on_timeout();
        }
        this_(self, this_.assign_error(ec));
    }

    bool timeout = false;

    net::high_resolution_timer           timer_;
    net::high_resolution_timer::duration to_;
};

template < class Protocol, class Derived >
struct has_resolver
{
    using resolver         = typename Protocol::resolver;
    using resolver_results = typename resolver::results_type;

    has_resolver(net::executor e)
    : resolver_(e)
    {
    }

    void cancel_resolver() { resolver_.cancel(); }

    template < class Self >
    void start_resolving(Self &self, std::string const &hostname, std::string const &service)
    {
        resolver_.async_resolve(hostname, service, net::share(self));
    }

    template < class Self >
    void operator()(Self &self, error_code ec, typename resolver::results_type results)
    {
        auto &this_ = *static_cast< Derived * >(this);
        resolved    = true;
        if (ec == net::error::operation_aborted)
            ec.clear();
        else if (ec.failed())
            this_.cancel_timeout();
        else
            endpoints = results;
        this_(self, this_.assign_error(ec));
    }

    resolver         resolver_;
    resolver_results endpoints;
    bool             resolved = false;
};

template < class Protocol, class Derived >
struct has_multiconnect
{
    has_multiconnect(net::executor e) {}

  private:
    using protocol         = Protocol;
    using socket_type      = typename protocol::socket;
    using endpoint_type    = typename protocol::endpoint;
    using resolver         = typename protocol::resolver;
    using resolver_results = typename resolver::results_type;

    struct socket_id
    {
        std::size_t sock;
    };

  public:
    void cancel_connects()
    {
        if (not sockets_canceled)
        {
            sockets_canceled = true;
            for (auto &s : socks)
                s.cancel();
        }
    }

    template < class Self >
    void operator()(Self &self, socket_id id, error_code ec)
    {
        auto &this_ = *static_cast< Derived * >(this);
        --sockets_remaining;
        if (not ec.failed() and not sockets_canceled)   // we are first socket to complete
        {
            this->cancel_connects();
            this_.on_socket_connect(std::move(socks[id.sock]));
        }
        else if (ec == net::error::operation_aborted)
            ec.clear();

        if (sockets_remaining)
            ec.clear();

        this_(self, this_.assign_error(ec));
    }

    template < class Self >
    void initiate_connects(Self &self, resolver_results const &endpoints)
    {
        std::transform(endpoints.begin(), endpoints.end(), std::back_inserter(socks), [&](auto iter) {
            return socket_type(self.get_executor());
        });
        auto i = std::size_t(0);
        for (auto &&epi : endpoints)
        {
            socks[i].async_connect(epi.endpoint(), boost::beast::bind_front_handler(net::share(self), socket_id { i }));
            ++i;
        }
        sockets_remaining = i;
    }

    std::vector< socket_type > socks;
    std::size_t                sockets_remaining = 0;
    bool                       sockets_canceled  = false;
};

template < class Socket >
struct mass_connect_op
: net::coroutine
, has_error
, has_timeout< mass_connect_op< Socket > >
, has_resolver< typename Socket::protocol_type, mass_connect_op< Socket > >
, has_multiconnect< typename Socket::protocol_type, mass_connect_op< Socket > >
{
    using protocol      = typename Socket::protocol_type;
    using socket_type   = typename protocol::socket;
    using endpoint_type = typename protocol::endpoint;
    using resolver      = typename protocol::resolver;

    mass_connect_op(Socket &sock, std::string hostname, std::string port, std::chrono::milliseconds timeout)
    : net::coroutine()
    , has_error()
    , has_timeout< mass_connect_op< Socket > >(sock.get_executor(), timeout)
    , has_resolver< protocol, mass_connect_op< Socket > >(sock.get_executor())
    , has_multiconnect< protocol, mass_connect_op< Socket > >(sock.get_executor())
    , sock_(sock)
    , hostname_(std::move(hostname))
    , port_(std::move(port))
    {
    }

    using has_timeout< mass_connect_op< Socket > >::           operator();
    using has_resolver< protocol, mass_connect_op< Socket > >::operator();
    using has_multiconnect< protocol, mass_connect_op< Socket > >::operator();

    void on_timeout()
    {
        this->cancel_resolver();
        this->cancel_connects();
    }

    void on_resolved() { this->cancel_timeout(); }

    void on_socket_connect(Socket s)
    {
        this->cancel_timeout();
        sock_ = std::move(s);
    }

    template < class Self >
    void operator()(Self &self, error_code ec = {})
    {
#include <boost/asio/yield.hpp>
        reenter(this) for (;;)
        {
            // transform this coroutine into a shared coroutine
            yield net::share(self);

            // start the timer and a resolve operation
            yield
            {
                this->start_timeout(self);
                this->start_resolving(self, hostname_, port_);
            }

            // wait for the resolve to complete one way or another
            while (not this->resolved)
                yield;

            // if we have a failure, complete...
            if (ec.failed())
            {
                // ... after ensuring that the timer completion handler has been invoked
                while (not this->timeout)
                    yield;
            }
            else
            {
                // otherwise, simulatenously connect to all endpoints
                yield this->initiate_connects(self, this->endpoints);

                // yield until all connect completion handlers have been invoked
                while (this->sockets_remaining)
                    yield;

                // and yield until the timer completion handler has been invoked
                while (not this->timeout)
                    yield;
            }

            // return the result of the connect
            return self.complete(ec);
        }

#include <boost/asio/unyield.hpp>
    }

    Socket &    sock_;
    std::string hostname_, port_;
};

template < class Socket, class CompletionToken >
auto async_mass_connect(Socket &                  sock,
                        std::string               host,
                        std::string               port,
                        std::chrono::milliseconds timeout,
                        CompletionToken &&        token)
{
    return net::async_compose< CompletionToken, void(error_code) >(
        mass_connect_op< Socket >(sock, std::move(host), std::move(port), timeout), token, sock);
}

TEST_CASE("polyfill::net::shared_composed_op")
{
    auto ioc = net::io_context();

    auto s = net::ip::tcp::socket(ioc);

    async_mass_connect(s, "www.example.com", "http", 10s, [&](error_code ec) {
        std::cout << ec.message() << std::endl;
        auto ep = s.remote_endpoint(ec);
        std::cout << ep << std::endl;
    });

    boost::beast::test::run(ioc);
}