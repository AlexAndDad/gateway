#pragma once
#include <string>
#include <type_traits>

namespace config
{
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
        auto via_tag = [](auto &&os, auto &&arg) { tag_invoke(print_tag< Arg >(), os, arg); };

        if constexpr (std::is_invocable_v< decltype(via_tag), decltype(os), decltype(p.arg) >)
        {
            via_tag(os, p.arg);
        }
        else
        {
            os << p.arg;
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
        auto via_tag = [](auto &&os, auto &&arg) { tag_invoke(print_tag< Type >(), os, arg); };

        auto via_to_string = [](auto &&arg) {
            using std::to_string;
            using wise_enum::to_string;
            return to_string(arg);
        };

        if constexpr (std::is_invocable_v< decltype(via_tag), decltype(os), decltype(arg) >)
        {
            via_tag(os, arg);
        }
        else if constexpr (std::is_invocable_v< dectype(via_to_string), decltype(arg) >)
        {
            auto add = via_to_string(arg);
            os.append(add.begin(), add.end());
        }
        else
        {
            os += arg;
        }

        return os;
    }

    template < class T >
    std::string &print_to(std::string &os, printer< T > const &p)
    {
        return print_to(os, p.arg);
    }

    namespace detail
    {
        template < class Arg, class = void >
        struct has_std_to_string : std::false_type {};

        template < class Arg >
        struct has_std_to_string< Arg, std::void_t< decltype(std::to_string(std::declval< Arg >())) > > : std::true_type
        {
        };

    };   // namespace detail

    template < class Arg >
    auto to_string(Arg const &arg)
    {
        auto via_to_string = [](auto &&a) { return std::to_string(a); };

        if constexpr (wise_enum::is_wise_enum_v< Arg >)
            return wise_enum::to_string(arg);
        else if constexpr (detail::has_std_to_string<decltype(arg)>::value)
            return via_to_string(arg);
        else
        {
            std::string result;
            print_to(result, print(arg));
            return result;
        }
    }

}   // namespace config