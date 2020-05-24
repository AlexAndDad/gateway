//
// Created by rhodges on 17/05/2020.
//

#ifndef GATEWAY_CHUNK_COLUMN_IMPL_HPP
#define GATEWAY_CHUNK_COLUMN_IMPL_HPP
#include "chunk_section_impl.hpp"

namespace minecraft::chunks
{
    struct chunk_column_impl
    {
        using block_type = minecraft::blocks::block_type;

        // 16 chunks * 16 blocks = 256 height max
        static constexpr int chunk_extent = 16;

        // x is horizontal
        static constexpr int x_extent = chunk_section_impl::x_extent;

        // z is horzontal
        static constexpr int z_extent = chunk_section_impl::z_extent;

        // y is vertical
        static constexpr int y_extent = chunk_section_impl::y_extent;

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

        chunk_column_impl();

        chunk_section_impl const &chunk(int n) const
        {
            assert(n < chunk_extent);
            return chunks_[n];
        }

        chunk_section_impl &chunk(int n)
        {
            assert(n < chunk_extent);
            return chunks_[n];
        }

        chunk_section_impl &chunk(vector3 const &vec) { return chunks_[vec.y & 0xff]; }

        chunk_section_impl const &chunk(vector3 const &vec) const
        {
            return chunks_[vec.y & 0xff];
        }

        static void next(vector3 &pos);

        void recalc_height(vector2 horz);
        void recalc_height();

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
        struct chunk_section_impl chunks_[chunk_extent];
        height_map        height_map_ {};
    };
    void compose(chunk_column_impl const &    cc,
                 vector2                    coords,
                 std::bitset< 16 >          which,
                 bool                       biomes,
                 minecraft::compose_buffer &buf);

    const_buffer_iterator parse(const_buffer_iterator first,
                                const_buffer_iterator last,
                                chunk_column_impl &     cd,
                                std::int32_t          bitmask);
}   // namespace minecraft::chunks
#endif   // GATEWAY_CHUNK_COLUMN_IMPL_HPP
