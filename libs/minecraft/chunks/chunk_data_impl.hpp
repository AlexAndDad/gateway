//
// Created by rhodges on 17/05/2020.
//

#ifndef GATEWAY_CHUNK_DATA_IMPL_HPP
#define GATEWAY_CHUNK_DATA_IMPL_HPP
#include "chunk_impl.hpp"

namespace minecraft::chunks
{
    struct chunk_data_impl
    {
        using block_type = minecraft::blocks::block_type;

        // 16 chunks * 16 blocks = 256 height max
        static constexpr int chunk_extent = 16;

        // x is horizontal
        static constexpr int x_extent = chunk_impl::x_extent;

        // z is horzontal
        static constexpr int z_extent = chunk_impl::z_extent;

        // y is vertical
        static constexpr int y_extent = chunk_impl::y_extent;

        struct height_map
        {
            uint8_t &operator[](vector2 horz)
            {
                return heights_[horz.z][horz.x];
            }

            uint8_t const &operator[](vector2 horz) const
            {
                return heights_[horz.z][horz.x];
            }

            uint8_t heights_[z_extent][x_extent];
        };

        chunk_data_impl();

        struct chunk_impl const &chunk(int n)
        {
            assert(n < chunk_extent);
            return chunks_[n];
        }

        static void next(vector3 &pos);

        void recalc_height(vector2 horz);

        void recalc();

        static bool in_bounds(vector3 pos)
        {
            return pos.x >= 0 and pos.x < x_extent and pos.y >= 0 and
                   pos.y < (y_extent * chunk_extent) and pos.z >= 0 and
                   pos.z < z_extent;
        }

        block_type change_block(vector3 pos, block_type b, bool update = true);

        std::uint8_t height(vector2 xz) const { return height_map_[xz]; }

      private:
        struct chunk_impl chunks_[chunk_extent];
        height_map        height_map_ {};
    };
    void compose(chunk_data_impl const & cc,
                 vector2                    coords,
                 std::bitset< 16 >          which,
                 bool                       biomes,
                 minecraft::compose_buffer &buf);
}   // namespace minecraft::chunks
#endif   // GATEWAY_CHUNK_DATA_IMPL_HPP
