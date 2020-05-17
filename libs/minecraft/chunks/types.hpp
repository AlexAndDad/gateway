#pragma once

#include <cstdint>

namespace minecraft::chunks
{
    template < class X, class Z >
    struct basic_vector2
    {
        basic_vector2(X x, Z z)
            : x(x)
            , z(z)
        {
        }

        X x;
        Z z;
    };

    template < class X, class Y, class Z >
    struct basic_vector3
    {
        basic_vector3(X x, Y y, Z z)
            : x(x)
            , z(z)
            , y(y)
        {
        }

        X x;
        Z z;
        Y y;
    };

    using world_vector3      = basic_vector3< int, std::uint8_t, int >;
    using chunk_vector3      = basic_vector3< std::uint8_t, std::uint8_t, std::uint8_t >;
    using vector3            = basic_vector3< int, int, int >;
    using world_position_vec = basic_vector2< int, int >;
    using vector2            = basic_vector2< int, int >;

    template < class X, class Y, class Z >
    auto to_horizontal(basic_vector3< X, Y, Z > const &v3) -> basic_vector2< X, Z >
    {
        return basic_vector2< X, Z >(v3.x, v3.z);
    }

    inline auto to_chunk(world_vector3 w) -> chunk_vector3 { return chunk_vector3(w.x & 0x0f, w.y & 0xff, w.z & 0x0f); }

}