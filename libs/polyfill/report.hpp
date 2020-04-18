#pragma once
#include "polyfill/net.hpp"

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <ostream>
#include <iomanip>
#include <string>

#include <utf8cpp/utf8.h>

namespace polyfill
{
    //
    // reporting
    //

    template < class Type >
    struct reporter
    {
        template < class Stream, class T >
        Stream &operator()(Stream &s, T &&x) const
        {
            s << x;
            return s;
        }
    };

    template < class T >
    struct report_wrapper
    {
        T arg_;
    };

    template < class T >
    struct report_wrapper< T & >
    {
        T &arg_;
    };

    template < class Stream, class T >
    Stream &operator<<(Stream &os, report_wrapper< T > wrapper)
    {
        auto op = reporter< std::decay_t< T > >();
        op(os, std::forward< T >(wrapper.arg_));
        return os;
    }

    template < class T >
    auto report(T &&arg)
    {
        return report_wrapper< T > { std::forward< T >(arg) };
    }
}   // namespace polyfill

namespace polyfill
{
    template <>
    struct reporter< error_code >
    {
        template < class Stream >
        void operator()(Stream &os, error_code const &ec) const
        {
            if (ec.failed())
                fmt::print(os, "[error_code {},{},{}]", std::quoted(ec.message()), ec.value(), std::quoted(ec.category().name()));
            else
                fmt::print(os, "[success]");
        }
    };

    template < class Executor >
    struct reporter< net::basic_socket_acceptor< net::ip::tcp, Executor > >
    {
        template < class Stream, class T >
        void operator()(Stream &os, T &&acceptor) const
        {
            auto ec = error_code();
            auto ep = acceptor.local_endpoint(ec);
            os << "[acceptor ";
            if (ec)
                os << report(ec.message());
            else
                os << ep;
            os << ']';
        }
    };

    template < class Protocol, class Executor >
    struct reporter< net::basic_stream_socket< Protocol, Executor > >
    {
        template < class Stream, class T >
        void operator()(Stream &os, T &&sock) const
        {
            os << "[socket ";
            auto ec = error_code();
            auto ep = sock.local_endpoint(ec);

            auto write = [&] {
                if (ec)
                    os << report(ec);
                else
                    os << ep;
            };

            write();
            os << "->";
            ep = sock.remote_endpoint(ec);
            write();

            os << ']';
        }
    };

    template<>
    struct reporter<std::u8string>
    {
        template<class Stream>
        void operator()(Stream& os, std::u8string const& s) const
        {
            auto first = reinterpret_cast<const char*>(s.data());
            os.write(first, s.size());
        }

        void operator()(std::wostream& os, std::u8string const& s) const
        {
            auto first = s.data();
            auto last = first + s.size();
            static thread_local std::wstring w;
            w.clear();
            utf8::utf8to32(reinterpret_cast<const char *>(first), reinterpret_cast<const char*>(last), std::back_inserter(w));
            os << w;
        }
    };

}   // namespace polyfill
