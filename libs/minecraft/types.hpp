//
// Created by rhodges on 13/04/2020.
//

#pragma once

#include <bitset>
#include <boost/operators.hpp>
#include <iostream>
#include <polyfill/bitset_tools.hpp>
#include <wise_enum.h>

namespace minecraft
{
    // std::uint8_t <-> Byte
    // std::int32_t <-> VarInt

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
    std::ostream &operator<<(std::ostream &os, var_enum< Enum > const &ve)
    {
        os << wise_enum::to_string< Enum >(static_cast< Enum >(ve));
        return os;
    }

    template < std::size_t Limit >
    struct varchar : std::string
    {
        using std::string::string;

        using std::string::operator=;
    };

    template < class Enum >
    constexpr auto variable_length(Enum e) -> std::enable_if_t< std::is_enum_v< Enum >, var_enum< Enum > >
    {
        return var_enum< Enum >(e);
    }

    template < class Integral >
    constexpr auto variable_length(Integral i) -> std::enable_if_t< std::is_integral_v< Integral >, var< Integral > >
    {
        return var< Integral >(i);
    }

    struct position
    {
        position()
        : x_(0)
        , y_(0)
        , z_(0)
        {
        }

        position(std::int32_t x, std::int32_t y, std::int32_t z)
        : x_(x)
        , y_(y)
        , z_(y)
        {
        }

        friend std::ostream &operator<<(std::ostream &stream, const position &self)
        {
            // All bitsets need to be converted to int32_t, this requires the negative bit to be carried.

            stream << "position.x: " << polyfill::bitset_tools::signedBS_to_signed32(self.x_)
                   << "\nposition.y: " << polyfill::bitset_tools::signedBS_to_signed32(self.y_)
                   << "\nposition.z: " << polyfill::bitset_tools::signedBS_to_signed32(self.z_);
            return stream;
        }

        void set_x(std::int32_t val) { x_ = val; }
        void set_y(std::int32_t val) { y_ = val; }
        void set_z(std::int32_t val) { z_ = val; }

        [[nodiscard]] std::bitset< 26 > x() const { return x_; }
        [[nodiscard]] std::bitset< 12 > y() const { return y_; }
        [[nodiscard]] std::bitset< 26 > z() const { return z_; }

      private:
        std::bitset< 26 > x_;
        std::bitset< 12 > y_;
        std::bitset< 26 > z_;
    };

}   // namespace minecraft
