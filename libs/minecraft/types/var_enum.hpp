//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "minecraft/to_json.hpp"
#include "minecraft/types/integral.hpp"
#include "minecraft/wise_enum.hpp"
#include <boost/operators.hpp>
#include "minecraft/parse.hpp"

namespace minecraft
{
    template < class Enum >
    struct var_enum
    : boost::equality_comparable< var_enum< Enum >, boost::equality_comparable< var_enum< Enum >, Enum > >
    {
        using value_type = Enum;

        constexpr explicit var_enum(Enum e = Enum())
        : value_(e)
        {
        }

        constexpr var_enum &operator=(var_enum r)
        {
            value_ = r.value_;
            return *this;
        }
        constexpr var_enum &operator=(Enum r)
        {
            value_ = r;
            return *this;
        }

        constexpr bool operator==(Enum r) const { return value_ == r; }
        constexpr bool operator==(var_enum r) const { return value_ == r; }

        constexpr operator Enum &() { return value_; }
        constexpr operator Enum() const { return value_; }

        constexpr value_type &      value() { return value_; }
        constexpr value_type const &value() const { return value_; }

      private:
        Enum value_;
    };

    template < class Enum >
    wise_enum::string_type to_string(var_enum< Enum > const &ve)
    {
        return to_string(static_cast< Enum >(ve));
    }

    template < class Enum >
    std::ostream &operator<<(std::ostream &os, var_enum< Enum > const &ve)
    {
        os << to_string(static_cast< Enum >(ve));
        return os;
    }

    template < class Enum >
    constexpr auto variable_length(Enum e) -> std::enable_if_t< std::is_enum_v< Enum >, var_enum< Enum > >
    {
        return var_enum< Enum >(e);
    }

    template < class Enum >
    [[nodiscard]] const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator second, var_enum< Enum > &target, error_code &ec)
    {
        if (not ec.failed())
        {
            using underlying = std::underlying_type_t< Enum >;
            auto accum       = underlying();
            first            = parse_var(first, second, accum, ec);
            if (not ec.failed())
                target = static_cast< Enum >(accum);
        }
        return first;
    }

}   // namespace minecraft

namespace boost::json
{
    template<class Enum>
    struct to_value_traits<minecraft::var_enum<Enum>>
    {
        static void assign(value& jv, minecraft::var_enum<Enum> const& ve)
        {
            auto&str = jv.emplace_string();
            auto ps = wise_enum::to_string(ve.value());
            str.assign(ps.begin(), ps.end());
        }
    };
}