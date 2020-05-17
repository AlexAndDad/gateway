#include "chunk_impl.hpp"

#include <boost/core/ignore_unused.hpp>

namespace minecraft::chunks
{
    slice_impl::slice_impl() {}

    chunk_impl::chunk_impl()
    : slices_ {}
    , palette_()
    {
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

    chunk_section_impl::chunk_section_impl()
    : chunks_ {}
    , height_map_ {}
    {
    }

    void chunk_section_impl::next(vector3 &pos)
    {
        if (++pos.x > x_extent)
            if (pos.x = 0; ++pos.z > z_extent)
                pos.z = 0, ++pos.y;
    }

    void chunk_section_impl::recalc_height(vector2 horz)
    {
        int y = 256;
        for (; y--;)
            if (!blocks::is_transparent(
                    chunks_[y / chunk_extent][y % chunk_extent][horz]))
                break;
        height_map_[horz] = y;
    }

    void chunk_section_impl::recalc()
    {
        for (int z = 0; z < z_extent; ++z)
            for (int x = 0; x < x_extent; ++x)
            {
                auto xz = vector2(x, z);
                recalc_height(xz);
            }
        for (auto ch = 0; ch < chunk_extent; ++ch)
            chunks_[ch].recalc_palette();
    }

    blocks::block_type chunk_section_impl::change_block(vector3            pos,
                                                        blocks::block_type b,
                                                        bool update)
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

    void compose(const chunk_section_impl &cc, compose_buffer &buf)
    {
        boost::ignore_unused(cc, buf);
    }
}   // namespace minecraft::chunks
