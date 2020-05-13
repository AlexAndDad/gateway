#pragma once
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
        return basic_vector2< X, Z >(v3.x, v3.y);
    }

    auto to_chunk(world_vector3 w) -> chunk_vector3 { return chunk_vector3(w.x & 0x0f, w.y & 0xff, w.z & 0x0f); }

    /// The state of a block on the map
    struct block
    {
        block()
        : state_(0)
        {
        }

        bool transparent() const { return state_ == 0; }

        std::uint16_t type() const { return state_; }

        friend auto operator==(block const &a, block const &b) -> bool { return a.state_ == b.state_; }
        friend auto operator!=(block const &a, block const &b) -> bool { return a.state_ != b.state_; }
        friend auto hash_value(block const &a) -> std::size_t { return boost::hash_value(a.state_); }

      private:
        std::uint16_t state_;
    };

    struct chunk_column
    {
        static constexpr int x_extent = 16;   // x is horizontal
        static constexpr int z_extent = 16;   // z is horzontal
        static constexpr int y_extent = 16;   // y is vertical
        static constexpr int columns  = 16;   // 16 columns * 16 blocks = 256 height max

        static constexpr int total_extent = x_extent * z_extent * y_extent * columns;

        struct slice
        {
            block &operator[](vector2 pos) { return zx[pos.z][pos.x]; }

            block const &operator[](vector2 pos) const { return zx[pos.z][pos.x]; }

            block zx[z_extent][x_extent];
        };

        using chunk_view = std::span<slice, y_extent>;

        struct height_map
        {
            std::uint8_t &operator[](vector2 horz) { return heights_[horz.z][horz.x]; }

            std::uint8_t const &operator[](vector2 horz) const { return heights_[horz.z][horz.x]; }

            std::uint8_t heights_[z_extent][x_extent];
        };

        chunk_column()
        : palette_()
        {
        }

        static void next(vector3 &pos)
        {
            if (++pos.x > x_extent)
                if (pos.x = 0; ++pos.z > z_extent)
                    pos.z = 0, ++pos.y;
        }

        void bulk_load(std::span< block, total_extent > blocks)
        {
            auto pos = vector3(0, 0, 0);
            for (auto b : blocks)
            {
                change_block(pos, b, false);
                next(pos);
                ++palette_[b];
            }

            recalc_height();
        }

        void recalc_height(vector2 horz)
        {
            int y = 256;
            for (; y--;)
                if (!slices_[y][horz].transparent())
                    break;
            height_map_[horz] = y;
        }

        void recalc_height()
        {
            for (int z = 0; z < z_extent; ++z)
                for (int x = 0; x < x_extent; ++x)
                    recalc_height(vector2(x, z));
        }

        static bool in_bounds(vector3 pos)
        {
            return pos.x >= 0 and pos.y < x_extent and pos.y >= 0 and pos.y < (y_extent * columns) and pos.z >= 0 and
                   pos.z < z_extent;
        }

        block change_block(vector3 pos, block b, bool update = true)
        {
            assert(in_bounds(pos));
            auto &slice    = slices_[pos.y];
            auto  horz     = to_horizontal(pos);
            auto  oldblock = std::exchange(slice[horz], b);
            if (oldblock != b)
            {
                if (update)
                {
                    recalc_height(horz);
                    palette_[b] += 1;
                    palette_[oldblock] -= 1;
                }
            }
            return oldblock;
        }

      private:
        slice              slices_[y_extent * columns];
        height_map         height_map_;

        // a count of each block state id used in this section
        std::unordered_map< block, int, boost::hash< block >, std::equal_to<> > palette_;
    };

}   // namespace minecraft::chunks
