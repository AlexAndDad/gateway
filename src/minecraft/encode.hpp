#pragma once

#include "packet_id.hpp"
#include "types.hpp"

#include <string>
#include <vector>

namespace minecraft
{
    template < class Iter >
    Iter encode(std::int32_t in, Iter first)
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

    template < class Enum, class Iter >
    auto encode(Enum in, Iter first) -> std::enable_if_t< std::is_enum_v< Enum >, Iter >
    {
        return encode(static_cast< std::underlying_type_t< Enum > >(in), first);
    }

    template < class I1, class I2, class Iter >
    Iter encode_bytes(I1 first, I2 last, Iter target)
    {
        return std::copy(first, last, encode(static_cast< std::int32_t >(std::distance(first, last)), target));
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

    template<class Container>
    void encode_to_container(std::vector< uint8_t > const &source, Container &dest) {

        auto i = std::back_inserter(dest);
        encode(std::uint32_t(source.size()), i);
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
        encode(std::int32_t(data.size()), std::back_inserter(length));
        target.insert(target.end(), length.begin(), length.end());
        target.insert(target.end(), data.begin(), data.end());
    }

    template < class Integral, class Iter >
    Iter var_encode(Integral in, Iter first)
    {
        auto value = static_cast< std::make_unsigned_t<Integral> >(in);
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

    template<class Iter, class Underlying>
    Iter encode(var<Underlying> arg, Iter iter)
    {
        return var_encode(static_cast<Underlying>(arg), iter);
    }


}   // namespace minecraft