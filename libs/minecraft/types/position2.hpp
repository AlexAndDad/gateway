#pragma once

#include "minecraft/compose.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/types.hpp"

#include <fmt/ostream.h>

namespace minecraft
{
    struct position2
    {
        position2()
        : x(0)
        , y(0)
        , z(0)
        {
        }

        position2(int x, int y, int z)
        : x(x)
        , y(y)
        , z(z)
        {
        }

        int x, y, z;
    };

    template < class Iter >
    inline Iter encode(position2 const &arg, Iter first)
    {
        auto [x, y, z] = arg;

        auto packed = ((static_cast< std::uint64_t >(x) & 0x3FFFFFF) << 38) | ((static_cast< std::uint64_t >(z) & 0x3FFFFFF) << 12) |
                      (static_cast< std::uint64_t >(y) & 0xFFF);

        return encode(packed, first);
    }

    template < class Stream >
    Stream &operator<<(Stream &os, position2 const &arg)
    {
        auto [x, y, z] = arg;
        fmt::print(os, "{}, {}, {}", x, y, z);
        return os;
    }

    inline const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, position2 &target, error_code &ec)
    {
        using minecraft::parse;

        // note: signed buffer helps with sign-extension of z
        std::int64_t buffer;

        auto &[x, y, z] = target;

        // parse the big-endian buffer
        first = parse(first, last, buffer, ec);
        if (not ec.failed())
        {
            auto pow2 = [](auto x) { return 1 << x; };

            // x will already be sign-extended
            x = buffer >> 38;

            // y will need to be sign-extended
            y = buffer & 0xfff;
            if (y >= pow2(11))
                y -= pow2(12);

            // z will need to be sign-extended
            // so lets zet all the bits above it. We will and them off later
            buffer |= 0xffffffc000000000;
            z = (buffer >> 12) & 0x3ffffff;
        }
        return first;
    }

}   // namespace minecraft