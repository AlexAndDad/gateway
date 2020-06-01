//
// Created by rhodges on 17/05/2020.
//

#include "chunk_column_impl.hpp"

#include "minecraft/nbt/compound.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/types/var.hpp"

#include <boost/core/ignore_unused.hpp>

namespace minecraft::chunks
{
    chunk_column_impl::chunk_column_impl()
    : chunks_ {}
    , biomes_data_()
    , height_map_ {}
    {
        biomes_data_.fill(4);
    }

    void chunk_column_impl::next(vector3 &pos)
    {
        if (++pos.x > x_extent)
            if (pos.x = 0; ++pos.z > z_extent)
                pos.z = 0, ++pos.y;
    }

    void chunk_column_impl::recalc_height(vector2 horz)
    {
        int y = 256;
        for (; y--;)
            if (!blocks::is_transparent(chunks_[y / chunk_extent][y % chunk_extent][horz]))
                break;
        height_map_[horz] = y;
    }

    void chunk_column_impl::recalc_height()
    {
        for (auto &horz : slice_impl::all())
            recalc_height(horz);
    }

    void chunk_column_impl::recalc()
    {
        recalc_height();
        for (auto ch = 0; ch < chunk_extent; ++ch)
            chunks_[ch].recalc_palette();
    }

    blocks::block_type chunk_column_impl::change_block(vector3 pos, blocks::block_type b, bool update)
    {
        assert(in_bounds(pos));
        auto chunk_idx   = pos.y / y_extent;
        auto chunk_coord = vector3(pos.x, pos.y & 0x0f, pos.z);
        auto horz        = to_horizontal(pos);

        auto oldblock = chunks_[chunk_idx].change_block(chunk_coord, b, update);
        if (oldblock != b)
        {
            if (update)
                recalc_height(horz);
        }
        return oldblock;
    }

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, vector2 &coords, bool &full_chunk, chunk_column_impl &cd)
    {
        // read the x and z chunk coord
        first = minecraft::parse(first, last, coords.x);
        first = minecraft::parse(first, last, coords.z);

        // Read the full chunk
        std::uint8_t tmp_bool;
        first      = minecraft::parse(first, last, tmp_bool);
        full_chunk = static_cast< bool >(tmp_bool);

        // read the primary bitmask
        var_int tmp;
        first = minecraft::parse(first, last, tmp);
        cd.set_primary_bit_mask(tmp.value());

        // Read heightmaps
        nbt::compound nbt_val;
        first = nbt::parse(first, last, nbt_val);

        if (full_chunk)
        {
            first = minecraft::parse(first, last, cd.get_biomes_data());
        }

        var_int extent;
        first             = parse(first, last, extent);
        auto expected_end = first + extent.value();
        if (expected_end > last)
            throw system_error(error::incomplete_parse, "chunk_data_impl");
        last = expected_end;

        for (int cy = 0; cy < chunk_column_impl::chunk_extent; ++cy)
            if (static_cast< std::int32_t >(cd.get_primary_bit_mask().to_ulong()) & (1 << cy))
                first = parse(first, last, cd.chunk(cy));
        cd.recalc_height();

        if (first != last)
            throw system_error(error::invalid_payload, "chunk_data_impl");
        return first;
    }
}   // namespace minecraft::chunks