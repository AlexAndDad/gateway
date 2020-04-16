#pragma once
#include "polyfill/net.hpp"

#include <ostream>
#include <string>

namespace polyfill
{
    //
    // common types
    //

    void report_on(std::string &os, error_code const &ec);

    void report_on(std::string &os, net::ip::tcp::endpoint const &ep);

    template < class Executor >
    void report_on(std::string &os, net::basic_stream_socket< net::ip::tcp, Executor > &sock);

    //
    // reporting
    //

    inline
    std::string &temp_report_buffer()
    {
        static thread_local std::string buf;
        buf.clear();
        return buf;
    }

    template < class X, class = void >
    struct is_to_stringable : std::false_type
    {
    };

    namespace detail
    {
        using std::to_string;
    }   // namespace detail

    template < class X >
    struct is_to_stringable< X, std::void_t< decltype(detail::to_string(std::declval< X & >())) > >
    : std::true_type
    {
    };

    template < class T >
    auto report_on(std::string &os, T &x) -> std::enable_if_t<is_to_stringable<T>::value>
    {
        os += detail::to_string(x);
    }

    template < class T >
    auto report_on(std::string &os, T &x) -> decltype(std::void_t< decltype(to_string(x)) >())
    {
        os += to_string(x);
    }

    template < class X, class = void >
    struct is_ostreamable : std::false_type
    {
    };

    template < class X >
    struct is_ostreamable< X, std::void_t< decltype(std::declval< std::ostream & >() << std::declval< X & >()) > >
    : std::true_type
    {
    };

    template < class T >
    auto report_on(std::ostream &os, T &x) -> std::enable_if_t< is_ostreamable< T >::value >
    {
        os << x;
    }

    template < class T >
    auto report_on(std::ostream &os, T &x) -> std::enable_if_t< not is_ostreamable< T >::value >
    {
        auto &buf = temp_report_buffer();
        report_on(buf, x);
        os << buf;
    }

    template < class Type >
    struct reporter
    {
        Type &arg;
    };

    template < class T >
    auto operator<<(std::ostream &os, reporter< T > const &r)
        -> std::enable_if_t< is_ostreamable< T >::value, std::ostream & >
    {
        os << r.arg;
        return os;
    }

    template < class T >
    auto operator<<(std::ostream &os, reporter< T > const &r)
        -> std::enable_if_t< not is_ostreamable< T >::value, std::ostream & >
    {
        report_on(os, r.arg);
        return os;
    }

    template<class T>
    auto to_string(const reporter<T> &r) -> decltype(auto)
    {
        auto &buf = temp_report_buffer();
        report_on(buf, r.arg);
        return buf;
    };

    template < class T >
    auto report(T &&x)
    {
        return reporter< T > { x };
    }


}   // namespace polyfill

namespace polyfill
{
    template < class Executor >
    void report_on(std::string &os, net::basic_stream_socket< net::ip::tcp, Executor > &sock)
    {
        auto ec = error_code();
        auto ep = sock.local_endpoint(ec);

        auto write = [&] {
            if (ec)
                os += ec.message();
            else
                report_on(os, ep);
        };

        write();
        os += " -> ";
        ep = sock.remote_endpoint(ec);
        write();
    }

}   // namespace polyfill