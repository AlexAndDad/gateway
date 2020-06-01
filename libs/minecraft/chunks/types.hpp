#pragma once

#include <boost/container_hash/hash.hpp>
#include <cstddef>
#include <cstdint>
#include <cfenv>
#include <cmath>

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

        basic_vector2()
        : x(static_cast< X >(0))
        , z(static_cast< Z >(0))
        {
        }

        template < class X1, class Z1 >
        bool operator==(basic_vector2< X1, Z1 > const &other) const
        {
            return x == other.x and z == other.z;
        }

        template < class X1, class Z1 >
        bool operator!=(basic_vector2< X1, Z1 > const &other) const
        {
            return !(*this == other);
        }

        friend std::size_t hash_value(basic_vector2< X, Z > const &bv)
        {
            std::size_t seed = 0;
            boost::hash_combine(seed, bv.x);
            boost::hash_combine(seed, bv.z);
            return seed;
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
    using chunk_coord_type   = vector2;

    template < class X, class Y, class Z >
    auto to_horizontal(basic_vector3< X, Y, Z > const &v3) -> basic_vector2< X, Z >
    {
        return basic_vector2< X, Z >(v3.x, v3.z);
    }

    inline auto to_chunk(world_vector3 w) -> chunk_vector3 { return chunk_vector3(w.x & 0x0f, w.y & 0xff, w.z & 0x0f); }

    inline chunk_coord_type to_chunk_coords(world_vector3 w)
    {
        return chunk_coord_type (w.x>>4,w.z>>4);
    }

}   // namespace minecraft::chunks

namespace std
{
    template < typename X, typename Z >
    struct hash< minecraft::chunks::basic_vector2< X, Z > > : boost::hash< minecraft::chunks::basic_vector2< X, Z > >
    {
    };
}   // namespace std