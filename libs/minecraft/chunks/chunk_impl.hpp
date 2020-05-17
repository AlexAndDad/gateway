#pragma once
#include "blocks/block_info.hpp"
#include "minecraft/types/buffer.hpp"
#include "palette.hpp"
#include "slice_impl.hpp"
#include "types.hpp"

#include <algorithm>
#include <boost/functional/hash.hpp>
#include <span>
#include <unordered_map>

namespace minecraft::chunks
{
    /// The state of a block on the map

    struct chunk_impl
    {
        using block_type = blocks::block_type;

        static constexpr int x_extent =
            slice_impl::x_extent;   // x is horizontal
        static constexpr int z_extent =
            slice_impl::z_extent;             // z is horzontal
        static constexpr int y_extent = 16;   // y is vertical

        chunk_impl();

        slice_impl const &operator[](int y) const
        {
            assert(y >= 0);
            assert(y < y_extent);
            return slices_[y];
        }

        block_type
        change_block(vector3 pos, block_type blk, bool update_palette = true);

        void recalc_palette();

        auto palette() const -> const struct palette & { return palette_; };

        /// Return the number of non-air blocks in the chunk
        /// \return number of non-air chunks
        std::uint16_t count_non_air() const;

      private:
        slice_impl     slices_[y_extent];
        struct palette palette_;
    };

}   // namespace minecraft::chunks
