//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "minecraft/to_json.hpp"
#include <boost/operators.hpp>

namespace minecraft
{
    template < class Integral, class U = Integral >
    constexpr int max_var_encoded_bytes()
    {
        static_assert(not std::is_same_v< Integral, U >);
        return 0;
    };

    template <>
    constexpr int max_var_encoded_bytes< std::int32_t >()
    {
        return 5;
    };

    template <>
    constexpr int max_var_encoded_bytes< std::int64_t >()
    {
        return 10;
    };

    template < class Integral >
    struct var : boost::operators< var< Integral > >
    {
        using value_type       = Integral;
        using const_value_type = Integral const;

        constexpr var(value_type v = value_type {})
        : value_(v)
        {
        }

        constexpr var &operator=(var const &r)
        {
            value_ = r.value_;
            return *this;
        }
        constexpr var &operator+=(var const &r)
        {
            value_ += r.value_;
            return *this;
        }
        constexpr var &operator-=(var const &r)
        {
            value_ -= r.value_;
            return *this;
        }
        constexpr var &operator*=(var const &r)
        {
            value_ *= r.value_;
            return *this;
        }
        constexpr var &operator/=(var const &r)
        {
            value_ /= r.value_;
            return *this;
        }
        constexpr bool operator==(var const &r) const { return value_ == r.value_; }
        constexpr bool operator<(var const &r) const { return value_ < r.value_; }

        //        constexpr operator value_type() const { return value_; }
        explicit constexpr operator value_type &() { return value_; }
        explicit constexpr operator const_value_type &() const { return value_; }

        constexpr value_type &      value() { return value_; }
        constexpr value_type const &value() const { return value_; }

      private:
        Integral value_;
    };

    template < class Integral >
    constexpr std::size_t max_encoded_bytes(var< Integral > const &)
    {
        return max_var_encoded_bytes< Integral >();
    }

    template < class Integral >
    std::ostream &operator<<(std::ostream &os, var< Integral > const &v)
    {
        os << static_cast< Integral const & >(v);
        return os;
    }

    using var_int  = var< std::int32_t >;
    using var_long = var< std::int64_t >;

    template < class Integral >
    constexpr auto variable_length(Integral i) -> std::enable_if_t< std::is_integral_v< Integral >, var< Integral > >
    {
        return var< Integral >(i);
    }

}   // namespace minecraft

namespace boost::json
{
    template < class Integral >
    struct to_value_traits< minecraft::var< Integral > >
    {
        static void assign(value &jv, minecraft::var< Integral > const &vi)
        {
            jv = static_cast<Integral>(vi);
        }
    };
}