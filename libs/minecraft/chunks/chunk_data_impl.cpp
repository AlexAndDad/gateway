//
// Created by rhodges on 17/05/2020.
//

#include "chunk_data_impl.hpp"

#include "minecraft/parse.hpp"
#include "minecraft/types/var.hpp"

#include <boost/core/ignore_unused.hpp>

namespace minecraft::chunks
{
    chunk_data_impl::chunk_data_impl()
    : chunks_ {}
    , height_map_ {}
    {
    }

    void chunk_data_impl::next(vector3 &pos)
    {
        if (++pos.x > x_extent)
            if (pos.x = 0; ++pos.z > z_extent)
                pos.z = 0, ++pos.y;
    }

    void chunk_data_impl::recalc_height(vector2 horz)
    {
        int y = 256;
        for (; y--;)
            if (!blocks::is_transparent(
                    chunks_[y / chunk_extent][y % chunk_extent][horz]))
                break;
        height_map_[horz] = y;
    }

    void chunk_data_impl::recalc_height()
    {
        for (auto &horz : slice_impl::all())
            recalc_height(horz);
    }

    void chunk_data_impl::recalc()
    {
        recalc_height();
        for (auto ch = 0; ch < chunk_extent; ++ch)
            chunks_[ch].recalc_palette();
    }

    blocks::block_type chunk_data_impl::change_block(vector3            pos,
                                                     blocks::block_type b,
                                                     bool               update)
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

    void compose(const chunk_data_impl &cc, compose_buffer &buf)
    {
        boost::ignore_unused(cc, buf);
    }

    const_buffer_iterator parse(const_buffer_iterator first,
                                const_buffer_iterator last,
                                chunk_data_impl &     cd,
                                std::int32_t          bitmask)
    {
        // starts at : Size	VarInt	Size of Data in bytes
        // ends after: Data	Byte array	See data structure below

        var_int extent;
        first             = parse(first, last, extent);
        auto expected_end = first + extent.value();
        if (expected_end > last)
            throw system_error(error::incomplete_parse, "chunk_data_impl");
        last = expected_end;

        for (int cy = 0; cy < chunk_data_impl::chunk_extent; ++cy)
            if (bitmask & (1 << cy))
                first = parse(first, last, cd.chunk(cy));
        cd.recalc_height();

        if (first != last)
            throw system_error(error::invalid_payload, "chunk_data_impl");
        return first;
    }
}   // namespace minecraft::chunks