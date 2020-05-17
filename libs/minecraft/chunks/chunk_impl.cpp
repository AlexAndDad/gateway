#include "chunk_impl.hpp"

#include "bitpack.hpp"
#include "chunk_data_impl.hpp"
#include "minecraft/parse.hpp"
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

    void chunk_impl::clear()
    {
        palette_.clear();
        for (int y = 0; y < y_extent; ++y)
            slices_[y].clear();
    }

    auto parse(const_buffer_iterator first,
               const_buffer_iterator last,
               chunk_impl &          chunk) -> const_buffer_iterator
    {
        using minecraft::parse;

        std::uint16_t blk_count;
        auto          next = parse(first, last, blk_count);

        std::uint8_t bits_per_block;
        next = parse(next, last, bits_per_block);

        realised_palette          rp;
        null_palette              np;
        realised_palette_concept &pal =
            (bits_per_block >= 9)
                ? static_cast< realised_palette_concept & >(np)
                : static_cast< realised_palette_concept & >(rp);
        next = parse(next, last, pal);

        auto iter = compressed_bitfield_iterator(
            next, last, std::max(bits_per_block, std::uint8_t(4)));

        chunk.clear();
        for (int y = 0; y < chunk_impl::y_extent; ++y)
            for (int z = 0; z < chunk_impl::z_extent; ++z)
                for (int x = 0; x < chunk_impl::x_extent; ++x)
                    chunk.change_block(vector3(x, y, z), pal[*iter], false);
        chunk.recalc_palette();

        next = iter.next_iter();

        return next;
    }

}   // namespace minecraft::chunks
