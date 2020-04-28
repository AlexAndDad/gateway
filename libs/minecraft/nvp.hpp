//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include <boost/mp11/tuple.hpp>
#include <cstddef>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <string_view>
#include <tuple>
#include "minecraft/to_json.hpp"

namespace minecraft
{
    /// @brief A name-value pair, designed to live until the end of the current statement in order to facilitate
    /// printing or parsing
    /// @tparam N A reference to the characters yielding the name of the element
    /// @tparam T a reference to the value of the element
    template < std::size_t N, class T >
    struct nvp
    {
        constexpr nvp(const char (&name)[N], T &value)
        : name(name)
        , value(value)
        {
        }

        const char (&name)[N];
        T &value;
    };

    template < std::size_t N, class T >
    nvp(const char (&)[N], const T &) -> nvp< N, const T >;

    template < std::size_t N, class T >
    nvp(const char (&)[N], T &) -> nvp< N, T >;

    template < std::size_t N, class T >
    constexpr auto operator==(nvp< N, T > const &a, nvp< N, T > const &b) -> bool
    {
        return a.value == b.value;
    }

    template < std::size_t N, class T >
    constexpr auto operator!=(nvp< N, T > const &a, nvp< N, T > const &b) -> bool
    {
        return a.value != b.value;
    }

    template < std::size_t N, class T >
    std::ostream &operator<<(std::ostream &os, nvp< N, T > n)
    {
        fmt::print(os, "{}", n);
        return os;
    }

    template < std::size_t N, class T >
    auto to_string(nvp< N, T > const &n)
    {
        return fmt::format("{}", n);
    }

    template < class... NVPs >
    struct nvp_set
    {
        constexpr nvp_set(NVPs... nvps)
        : tuple_(std::move(nvps)...)
        {
        }

        friend constexpr auto operator==(nvp_set const &l, nvp_set const &r) { return l.tuple_ == r.tuple_; }

        friend constexpr auto operator!=(nvp_set const &l, nvp_set const &r) { return l.tuple_ != r.tuple_; }

        using tuple_type = std::tuple< NVPs... >;
        tuple_type tuple_;
    };

    template < class... NVPs >
    std::ostream &operator<<(std::ostream &os, nvp_set< NVPs... > const &nvps)
    {
        fmt::print(os, "{}", nvps);
        return os;
    }

    template < class... NVPs >
    auto to_string(nvp_set< NVPs... > const &nvps)
    {
        return fmt::format("{}", nvps);
    }

    template < class... NVPs >
    auto json_value(nvp_set< NVPs... > const &nvps) -> boost::json::value
    {
        auto  result = boost::json::value(boost::json::object_kind);
        auto &object = result.as_object();

        boost::mp11::tuple_for_each(nvps.tuple_, [&object](auto &&nvp) {
            object.emplace(nvp.name, to_json(nvp.value, object.storage()));
        });

        return result;
    }

}   // namespace minecraft

namespace boost::json
{
    template < class... NVPs >
    struct to_value_traits< minecraft::nvp_set< NVPs... > >
    {
        static void assign(value &jv, minecraft::nvp_set< NVPs... > const &nvps)
        {
            auto &object = jv.emplace_object();
            object.reserve(sizeof...(NVPs));
            boost::mp11::tuple_for_each(nvps.tuple_,
                                        [&object](auto &&nvp) { object.emplace(nvp.name, to_value(nvp.value)); });
        }
    };
}   // namespace boost::json

namespace fmt
{
    template < std::size_t N, class T >
    struct formatter< minecraft::nvp< N, T > >
    {
        using nvp = minecraft::nvp< N, T >;

        template < typename ParseContext >
        constexpr auto parse(ParseContext &ctx)
        {
            auto iclose = std::find(ctx.begin(), ctx.end(), '}');
            return iclose;
        }

        template < typename FormatContext >
        auto format(nvp const &n, FormatContext &ctx)
        {
            return fmt::format_to(ctx.out(), "[{} {}]", n.name, n.value);
        }
    };

    template < class... NVPs >
    struct formatter< minecraft::nvp_set< NVPs... > >
    {
        using nvps = minecraft::nvp_set< NVPs... >;

        template < typename ParseContext >
        constexpr auto parse(ParseContext &ctx)
        {
            auto iclose = std::find(ctx.begin(), ctx.end(), '}');
            return iclose;
        }

        template < typename FormatContext >
        auto format(nvps const &n, FormatContext &ctx)
        {
            const char *format = "{}";

            auto iter    = ctx.out();
            auto visitor = [&](auto &&nvp) {
                iter   = fmt::format_to(iter, format, nvp);
                format = " {}";
            };

            boost::mp11::tuple_for_each(n.tuple_, visitor);
            return iter;
        }
    };
}   // namespace fmt