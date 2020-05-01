#pragma once
#include <string_view>
// DEPENDENCY: ORDER wise_enum after string_view
#include "wise_enum/wise_enum.h"

#include <fmt/format.h>
#include <string>
#include <type_traits>

namespace config
{
    namespace detail
    {
        using std::to_string;

        template < class Arg, class = void >
        struct has_adl_to_string : std::false_type
        {
        };

        template < class Arg >
        struct has_adl_to_string< Arg, std::void_t< decltype(to_string(std::declval< Arg >())) > > : std::true_type
        {
        };

        template < class Stream, class Arg, class = void >
        struct has_stream_out : std::false_type
        {
        };

        template < class Stream, class Arg >
        struct has_stream_out< Stream, Arg, std::void_t< decltype(std::declval< Stream >() << std::declval< Arg >()) > >
        : std::true_type
        {
        };

        template < class Target, class Arg >
        struct via_tag
        {
            template < class A1 = Target, class A2 = Arg >
            constexpr auto operator()(A1 os, A2 arg) const -> decltype(auto)
            {
                return tag_invoke(print_tag< Arg >(), os, arg);
            }
        };

    };   // namespace detail

    template < class T >
    struct print_tag
    {
    };

    template < class Arg >
    struct printer
    {
        Arg const &arg;
    };

    template < class Stream, class Arg >
    Stream &operator<<(Stream &os, printer< Arg > const &p)
    {
        if constexpr (detail::has_stream_out< decltype(os), decltype(p.arg) >::value)
        {
            os << p.arg;
        }
        else
        {
            tag_invoke(print_tag< Arg >(), os, p.arg);
        }

        return os;
    }

    template < class Type >
    [[nodiscard]] printer< Type > print(Type const &arg)
    {
        return printer< Type > { arg };
    }

    template < class Type >
    std::string &print_to(std::string &os, Type const &arg)
    {
        if constexpr (wise_enum::is_wise_enum_v< Type >)
        {
            auto s = wise_enum::to_string(arg);
            os.append(s.begin(), s.end());
        }
        else if constexpr (detail::has_adl_to_string<decltype(arg)>::value)
        {
            auto add = via_to_string(arg);
            os.append(add.begin(), add.end());
        }
        else
        {
            tag_invoke(print_tag< Type >(), os, arg);
        }

        return os;
    }

    template < class T >
    std::string &print_to(std::string &os, printer< T > const &p)
    {
        return print_to(os, p.arg);
    }

    template < class Arg >
    auto to_string(Arg const &arg)
    {
        if constexpr (wise_enum::is_wise_enum_v< Arg >)
            return wise_enum::to_string(arg);
        else if constexpr (detail::has_adl_to_string< decltype(arg) >::value)
        {
            using std::to_string;
            return to_string(arg);
        }
        else
        {
            std::string result;
            print_to(result, print(arg));
            return result;
        }
    }

}   // namespace config

namespace fmt
{
    template < class T >
    struct formatter< config::printer< T > > : formatter< T >
    {
        template < typename FormatContext >
        auto format(config::printer< T > const &p, FormatContext &ctx)
        {
            return formatter< T >::format(p.arg, ctx);
        }
    };

}   // namespace fmt