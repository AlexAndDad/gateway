#include "chunk_impl.hpp"

#include "chunk_data_impl.hpp"
#include "slice_impl.hpp"

#include <boost/core/ignore_unused.hpp>

namespace minecraft::chunks
{

    chunk_impl::chunk_impl()
    : slices_ {}
    , palette_()
    {
    }

    std::uint16_t chunk_impl::count_non_air() const
    {
        return palette_.count_if(
            overloaded { [](blocks::void_air) { return false; },
                         [](blocks::cave_air) { return false; },
                         [](blocks::air) { return false; },
                         [](auto) { return true; } });
    }

    void chunk_impl::recalc_palette()
    {
        palette_.clear();
        for (int y = 0; y < y_extent; ++y)
            for (int z = 0; z < z_extent; ++z)
                for (int x = 0; x < x_extent; ++x)
                    palette_.add(slices_[y][vector2(x, z)]);
    }

    blocks::block_type chunk_impl::change_block(vector3            pos,
                                                blocks::block_type blk,
                                                bool update_palette)
    {
        auto old = std::exchange(
            slices_[pos.y % y_extent][vector2(pos.x, pos.z)], blk);

        if (update_palette and old != blk)
        {
            palette_.subtract(old);
            palette_.add(blk);
        }
        return old;
    }

}   // namespace minecraft::chunks
