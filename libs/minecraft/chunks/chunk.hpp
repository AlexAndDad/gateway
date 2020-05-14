#pragma once
#include "blocks/block_info.hpp"

#include <algorithm>
#include <boost/functional/hash.hpp>
#include <span>
#include <unordered_map>

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

    /// The state of a block on the map

    struct chunk_column
    {
        static constexpr int x_extent     = 16;   // x is horizontal
        static constexpr int z_extent     = 16;   // z is horzontal
        static constexpr int y_extent     = 16;   // y is vertical
        static constexpr int columns      = 16;   // 16 columns * 16 blocks = 256 height max
        static constexpr int total_extent = x_extent * z_extent * y_extent * columns;

        using palette_map =
            std::unordered_map< blocks::block_id_type, int, boost::hash< blocks::block_id_type >, std::equal_to<> >;

        struct slice
        {
            blocks::block_id_type &operator[](vector2 pos) { return zx[pos.z][pos.x]; }

            blocks::block_id_type const &operator[](vector2 pos) const { return zx[pos.z][pos.x]; }

            blocks::block_id_type zx[z_extent][x_extent];
        };

        using chunk_view = std::span< slice, y_extent >;

        struct height_map
        {
            std::uint8_t &operator[](vector2 horz) { return heights_[horz.z][horz.x]; }

            std::uint8_t const &operator[](vector2 horz) const { return heights_[horz.z][horz.x]; }

            std::uint8_t heights_[z_extent][x_extent];
        };

        chunk_column();

        static void next(vector3 &pos);

        void recalc_height(vector2 horz);

        void recalc();

        static bool in_bounds(vector3 pos)
        {
            return pos.x >= 0 and pos.x < x_extent and pos.y >= 0 and pos.y < (y_extent * columns) and pos.z >= 0 and
                   pos.z < z_extent;
        }

        blocks::block_id_type change_block(vector3 pos, blocks::block_id_type b, bool update = true);

        auto palette() const -> palette_map const & { return palette_; }

        std::uint8_t height(vector2 xz) const
        {
            return height_map_[xz];
        }

      private:
        slice      slices_[y_extent * columns] {};
        height_map height_map_ {};

        // a count of each block state id used in this section
        palette_map palette_;
    };

}   // namespace minecraft::chunks
