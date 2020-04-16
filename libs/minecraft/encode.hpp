#pragma once

#include "packet_id.hpp"
#include "types.hpp"

#include <boost/assert.hpp>
#include <cstring>
#include <string>
#include <vector>

namespace minecraft
{
    template < class Iter, class Integral >
    Iter write_x_bytes(Iter first, Integral val)
    {
        auto size = sizeof(Integral);
        while (size--)
        {
            *first++ = static_cast< std::uint8_t >(val >> (size * 8));
        }
        return first;
    }

    //
    // floating point
    //

    template < class Iter >
    Iter encode(const float &in, Iter first)
    {
        BOOST_ASSERT(sizeof(float) == sizeof(std::uint32_t));

        std::uint32_t storage = 0;
        std::memcpy(&storage, &in, sizeof(float));
        return write_x_bytes(first, storage);
    }

    template < class Iter >
    Iter encode(const double &in, Iter first)
    {
        BOOST_ASSERT(sizeof(double) == sizeof(std::uint64_t));

        std::uint64_t storage = 0;
        std::memcpy(&storage, &in, sizeof(double));
        return write_x_bytes(first, storage);
    }


    //
    // position
    //
    template < class Iter >
    Iter encode(const position &in, Iter first)
    {
        std::uint64_t value = 0;
        value |= in.x().to_ulong();
        value <<= 26;
        value |= in.z().to_ulong();
        value <<= 26;
        value |= in.y().to_ulong();

        return write_x_bytes(first, value);
    }

    //
    // fixed length integers
    //
    template < class Iter >
    Iter encode(std::uint8_t const &arg, Iter first)
    {
        *first++ = arg;
        return first;
    }

    template < class Iter >
    Iter encode(std::uint16_t const &arg, Iter first)
    {
        *first++ = static_cast< std::uint8_t >(arg >> 8);
        *first++ = static_cast< std::uint8_t >(arg);
        return first;
    }

    //
    // variable length integers
    //
    template < class Iter >
    Iter encode_var(std::int32_t const &in, Iter first)
    {
        auto value = static_cast< std::uint32_t >(in);
        do
        {
            auto b = static_cast< std::uint8_t >(value & 0x7f);
            value >>= 7;
            if (value != 0)
                b |= 0x80;
            *first++ = b;
        } while (value);
        return first;
    }

    template < class Integral, class Iter >
    Iter encode(var< Integral > const &arg, Iter first)
    {
        return encode_var(arg.value(), first);
    }

    template < class Enum, class Iter >
    auto encode(var_enum< Enum > const &arg, Iter iter) -> std::enable_if_t< std::is_enum_v< Enum >, Iter >
    {
        using underlying_type = std::underlying_type_t< Enum >;
        auto temp             = static_cast< underlying_type >(arg.value());
        return encode_var(temp, iter);
    }

    template < class Enum, class Iter >
    auto encode(Enum const &in, Iter first) -> std::enable_if_t< std::is_enum_v< Enum >, Iter >
    {
        auto val = static_cast< std::underlying_type_t< Enum > >(in);
        return encode(val, first);
    }

    template < class I1, class I2, class Iter >
    Iter encode_bytes(I1 first, I2 last, Iter target)
    {
        auto len = static_cast< std::int32_t >(std::distance(first, last));
        target   = encode(variable_length(len), target);
        return std::copy(first, last, target);
    }

    template < class Iter >
    Iter encode(std::string const &in, Iter first)
    {
        return encode_bytes(in.begin(), in.end(), first);
    }

    template < class Iter >
    Iter encode(std::vector< std::uint8_t > const &in, Iter first)
    {
        return encode_bytes(in.begin(), in.end(), first);
    }

    template < class Container >
    void encode_to_container(std::vector< uint8_t > const &source, Container &dest)
    {
        auto i = std::back_inserter(dest);
        encode(variable_length(std::uint32_t(source.size())), i);
        dest.insert(dest.end(), source.begin(), source.end());
    }

    template < class Frame, class Container >
    void encode_frame(Frame const &frame, Container &target)
    {
        thread_local std::string length;
        thread_local std::string data;
        data.clear();
        encode(frame, std::back_inserter(data));

        length.clear();
        encode(var_int(data.size()), std::back_inserter(length));
        target.insert(target.end(), length.begin(), length.end());
        target.insert(target.end(), data.begin(), data.end());
    }

    template < class Integral, class Iter >
    Iter var_encode(Integral in, Iter first)
    {
        auto value = static_cast< std::make_unsigned_t< Integral > >(in);
        do
        {
            auto b = static_cast< std::uint8_t >(value & 0x7f);
            value >>= 7;
            if (value != 0)
                b |= 0x80;
            *first++ = b;
        } while (value);
        return first;
    }

    template < class T, class Iter >
    Iter encode(std::optional< T > const &arg, Iter iter)
    {
        std::uint8_t present = arg.has_value() ? 1 : 0;
        iter                 = encode(present, iter);
        if (present)
        {
            iter = encode(*arg, iter);
        }
        return iter;
    }

}   // namespace minecraft