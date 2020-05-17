#pragma once
#include "blocks/block_info.hpp"
#include "minecraft/types/buffer.hpp"
#include "palette.hpp"
#include "types.hpp"

#include <algorithm>
#include <boost/functional/hash.hpp>
#include <span>
#include <unordered_map>

namespace minecraft::chunks
{
    /// The state of a block on the map

    struct slice
    {
        static constexpr int x_extent = 16;   // x is horizontal
        static constexpr int z_extent = 16;   // z is horzontal

        slice();

        blocks::block_id_type &operator[](vector2 pos)
        {
            return zx[pos.z][pos.x];
        }

        blocks::block_id_type const &operator[](vector2 pos) const
        {
            return zx[pos.z][pos.x];
        }

      private:
        blocks::block_id_type zx[z_extent][x_extent];
    };

    struct chunk
    {
        static constexpr int x_extent = slice::x_extent;   // x is horizontal
        static constexpr int z_extent = slice::z_extent;   // z is horzontal
        static constexpr int y_extent = 16;                // y is vertical

        chunk();

        slice const &operator[](int y) const
        {
            assert(y >= 0);
            assert(y < y_extent);
            return slices_[y];
        }

        blocks::block_id_type change_block(vector3               pos,
                                           blocks::block_id_type blk,
                                           bool update_palette = true);

        void recalc_palette();

        auto palette() const -> const struct palette & { return palette_; };

      private:
        slice   slices_[y_extent];
        struct palette palette_;
    };

    struct chunk_column
    {
        static constexpr int columns =
            16;   // 16 columns * 16 blocks = 256 height max
        static constexpr int x_extent = chunk::x_extent;   // x is horizontal
        static constexpr int z_extent = chunk::z_extent;   // z is horzontal
        static constexpr int y_extent = chunk::y_extent;   // y is vertical

        struct height_map
        {
            std::uint8_t &operator[](vector2 horz)
            {
                return heights_[horz.z][horz.x];
            }

            std::uint8_t const &operator[](vector2 horz) const
            {
                return heights_[horz.z][horz.x];
            }

            std::uint8_t heights_[z_extent][x_extent];
        };

        chunk_column();

        struct chunk const &chunk(int n)
        {
            assert(n < columns);
            return chunks_[n];
        }

        static void next(vector3 &pos);

        void recalc_height(vector2 horz);

        void recalc();

        static bool in_bounds(vector3 pos)
        {
            return pos.x >= 0 and pos.x < x_extent and pos.y >= 0 and
                   pos.y < (y_extent * columns) and pos.z >= 0 and
                   pos.z < z_extent;
        }

        blocks::block_id_type
        change_block(vector3 pos, blocks::block_id_type b, bool update = true);

        std::uint8_t height(vector2 xz) const { return height_map_[xz]; }

      private:
        struct chunk chunks_[columns];
        height_map   height_map_ {};
    };

    void compose(chunk_column const &cc,
                 vector2             coords,
                 std::bitset< 16 >   which,
                 bool                biomes,
                 compose_buffer &    buf);

}   // namespace minecraft::chunks
