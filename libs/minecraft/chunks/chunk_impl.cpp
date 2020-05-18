#include "chunk_impl.hpp"

#include "bitpack.hpp"
#include "chunk_data_impl.hpp"
#include "minecraft/encode.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/types/var.hpp"
#include "slice_impl.hpp"

#include <boost/core/ignore_unused.hpp>
#include <fmt/ostream.h>

using namespace std::literals;

namespace minecraft::chunks
{
    chunk_impl::chunk_impl()
    : slices_ {}
    , palette_()
    {
    }

    std::uint16_t chunk_impl::count_non_air() const
    {
        return palette_.count_if([](blocks::block_type type) {
            if (type == blocks::air())
                return false;
            if (type == blocks::cave_air())
                return false;
            if (type == blocks::void_air())
                return false;
            return true;
        });
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
            palette_.add(blk);
            palette_.subtract(old);
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

        std::int16_t blk_count;
        auto         next = parse(first, last, blk_count);

        std::uint8_t bits_per_block;
        next = parse(next, last, bits_per_block);

        auto pal = realised_palette_concept(bits_per_block);
        next     = parse(next, last, pal);

        var_int data_array_length;
        next = parse(next, last, data_array_length);

        auto iter = compressed_bitfield_iterator(
            next, last, std::max(bits_per_block, std::uint8_t(4)));
        next = next + data_array_length.value() * sizeof(std::uint64_t);

        chunk.clear();
        for (int y = 0; y < chunk_impl::y_extent; ++y)
            for (int z = 0; z < chunk_impl::z_extent; ++z)
                for (int x = 0; x < chunk_impl::x_extent; ++x)
                {
                    auto tmp = pal[*iter];
                    chunk.change_block(vector3(x, y, z), tmp, false);
                }

        chunk.recalc_palette();

        return next;
    }

    void compose(chunk_impl const &c, compose_buffer &buf)
    {
        encode(c.count_non_air(), back_inserter(buf));
        auto bits_per_block = compose(c.palette(), buf);
        if (bits_per_block >= 9)
        {
            bits_per_block = 14;
            auto    comp   = bit_compressor(bits_per_block, buf);
            var_int alen =
                comp.size(chunk_impl::y_extent * chunk_impl::z_extent *
                          chunk_impl::z_extent);
            encode(alen, back_inserter(buf));

            for (int y = 0; y < chunk_impl::y_extent; ++y)
                for (int z = 0; z < chunk_impl::z_extent; ++z)
                    for (int x = 0; x < chunk_impl::x_extent; ++x)
                        comp(c[y][vector2(x, z)].value());
            comp.flush();
        }
        else
        {
            if (bits_per_block < 4)
                bits_per_block = 4;
            auto    comp = bit_compressor(bits_per_block, buf);
            var_int alen =
                comp.size(chunk_impl::y_extent * chunk_impl::z_extent *
                          chunk_impl::z_extent);
            encode(alen, back_inserter(buf));

            for (int y = 0; y < chunk_impl::y_extent; ++y)
                for (int z = 0; z < chunk_impl::z_extent; ++z)
                    for (int x = 0; x < chunk_impl::x_extent; ++x)
                        comp(c.palette().to_index(c[y][vector2(x, z)]));
            comp.flush();
        }

    }   // namespace minecraft::chunks

    std::ostream &operator<<(std::ostream &os, chunk_impl const &c)
    {
        auto sep = ""sv;
        for (int y = 0; y < chunk_impl::y_extent; ++y)
        {
            fmt::print(os, "{}{}", sep, pretty_print(c.slices_[y], y));
            sep = "\n"sv;
        }
        return os;
    }

    bool operator==(chunk_impl const &a, chunk_impl const &b)
    {
        for (int y = 0; y < chunk_impl::y_extent; ++y)
        {
            if (a.slices_[y] != b.slices_[y])
                return false;
        }
        return true;
    }

}   // namespace minecraft::chunks
