#include "chunk_data.hpp"

#include "parse.hpp"

namespace minecraft::packets::server
{
    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, palette_type &target, error_code &ec)
    {
        if (not ec.failed())
        {
            first = minecraft::parse(first, last, target.palette_length, ec);
            std::size_t size = static_cast<std::size_t>(target.palette_length.value());
            first = minecraft::parse(first, last, std::tie(target.palette_data, size), ec);
        }
        return first;
    }

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, chunk_section_type &target, error_code &ec)
    {
        if (not ec.failed())
        {
            first = minecraft::parse(first, last, target.block_count, ec);
            first = minecraft::parse(first, last, target.bits_per_block, ec);

            // palette
            if (not ec.failed())
            {
                if (target.bits_per_block < 9)   // parse the palette
                {
                    target.palette.emplace();
                    parse(first, last, *target.palette, ec);
                }
            }

            first = minecraft::parse(first, last, target.data_length, ec);
            if (not ec)
            {
                std::size_t size = static_cast<std::size_t>(target.data_length.value());
                first = minecraft::parse(first, last, std::tie(target.data, size), ec);
            }
        }
        return first;
    }

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, chunk_data_type &target, error_code &ec)
    {
        if (not ec.failed())
        {
            first = minecraft::parse(first, last, target.chunk_x, ec);
            first = minecraft::parse(first, last, target.chunk_z, ec);
            first = minecraft::parse(first, last, target.full_chunk, ec);
            first = minecraft::parse(first, last, target.primary_bit_mask, ec);
            // first = minecraft::parse(first, last, target.heightmaps, ec);

            if (target.full_chunk)
            {
                std::size_t size = 1024;
                first            = minecraft::parse(first, last, std::tie(target.biomes, size), ec);
            }

            first = minecraft::parse(first, last, target.data_size, ec);
            // data.resize(16);   // there can max be 16 chunk_sections
            // first = parse(first, last, std::span< char, 16 >(std::begin(target.data), std::end(target.data)), ec);
        }
        return first;
    }

}   // namespace minecraft::packets::server