//
// Created by rhodges on 17/05/2020.
//

#ifndef GATEWAY_SLICE_IMPL_HPP
#define GATEWAY_SLICE_IMPL_HPP

#include "minecraft/blocks/block_info.hpp"
#include "types.hpp"

namespace minecraft::chunks
{
    struct slice_impl
    {
        using block_type = minecraft::blocks::block_type;

        static constexpr int x_extent = 16;   // x is horizontal
        static constexpr int z_extent = 16;   // z is horzontal

        slice_impl();

        void clear()
        {
            for (int z = 0; z < z_extent; ++z)
                for (int x = 0; x < x_extent; ++x)
                    zx[z][x] = blocks::air();
        }

        block_type &operator[](vector2 pos) { return zx[pos.z][pos.x]; }

        block_type const &operator[](vector2 pos) const
        {
            return zx[pos.z][pos.x];
        }

      private:
        block_type zx[z_extent][x_extent];
    };
}   // namespace minecraft::chunks
#endif   // GATEWAY_SLICE_IMPL_HPP
