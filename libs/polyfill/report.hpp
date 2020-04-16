#pragma once
#include "polyfill/net.hpp"

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <ostream>
#include <string>

namespace polyfill
{
    //
    // common types
    //

    template < class Stream, class Executor >
    Stream &operator<<(Stream &os, net::basic_socket_acceptor< net::ip::tcp, Executor > const &acceptor);

    template < class Stream, class Executor >
    Stream &operator<<(Stream &os, net::basic_stream_socket< net::ip::tcp, Executor > const &acceptor);

    template < class Stream >
    Stream &operator<<(Stream &os, error_code const &ec);

    //
    // reporting
    //

    template < class Type >
    struct reporter
    {
        Type const &arg;
    };

    template < class T >
    auto report(T const &arg)
    {
        return reporter< T > { arg };
    }

    template < class Stream, class Type >
    Stream &operator<<(Stream &os, reporter< Type > const &rep)
    {
        os << rep.arg;
        return os;
    }

    template < class Type >
    std::string to_string(reporter< Type > const &rep)
    {
        return fmt::format("{}", rep.arg);
    }
}   // namespace polyfill

namespace polyfill
{
    template < class Stream, class Executor >
    Stream &operator<<(Stream &os, net::basic_socket_acceptor< net::ip::tcp, Executor > const &acceptor)
    {
        auto ec = error_code();
        auto ep = acceptor.local_endpoint(ec);
        os << "[acceptor ";
        if (ec)
            os << ec.message();
        else
            os << ep;
        os << ']';
        return os;
    }

    template < class Stream, class Executor >
    Stream &operator<<(Stream &os, net::basic_stream_socket< net::ip::tcp, Executor > const &sock)
    {
        os << "[socket ";
        auto ec = error_code();
        auto ep = sock.local_endpoint(ec);

        auto write = [&] {
            if (ec)
                os << ec.message();
            else
                os << ep;
        };

        write();
        os << "->";
        ep = sock.remote_endpoint(ec);
        write();

        os << ']';

        return os;
    }

    template < class Stream >
    Stream &operator<<(Stream &os, error_code const &ec)
    {
        if (ec.failed())
        {
            os << "[error_code ";
            os << ec.message();
            os << ", code=";
            os << ec.value();
            os << ", cat=";
            os << ec.category().name();
            os << ']';
        }
        else
        {
            os << "[success]";
        }
        return os;
    }

}   // namespace polyfill
