#include "chunk.hpp"

namespace minecraft::chunks
{
    chunk_column::chunk_column()
    : palette_()
    {
    }
    void chunk_column::next(vector3 &pos)
    {
        if (++pos.x > x_extent)
            if (pos.x = 0; ++pos.z > z_extent)
                pos.z = 0, ++pos.y;
    }
    void chunk_column::recalc_height(vector2 horz)
    {
        int y = 256;
        for (; y--;)
            if (!blocks::is_transparent(slices_[y][horz]))
                break;
        height_map_[horz] = y;
    }

    void chunk_column::recalc()
    {
        for (int z = 0; z < z_extent; ++z)
            for (int x = 0; x < x_extent; ++x)
            {
                auto xz = vector2(x, z);
                recalc_height(xz);

                palette_.clear();
                for (int y = 0; y < y_extent * columns; ++y)
                {
                    palette_[slices_[y][xz]] += 1;
                }
            }
    }

    blocks::block_id_type chunk_column::change_block(vector3               pos,
                                                     blocks::block_id_type b,
                                                     bool update)
    {
        assert(in_bounds(pos));
        auto &slice    = slices_[pos.y];
        auto  horz     = to_horizontal(pos);
        auto  oldblock = std::exchange(slice[horz], b);
        if (oldblock != b)
        {
            if (update)
            {
                recalc_height(horz);
                palette_[b] += 1;
                if (--palette_[oldblock] <= 0)
                    palette_.erase(oldblock);
            }
        }
        return oldblock;
    }
}   // namespace minecraft::chunks
