#include "chunk_data.hpp"

#include "nbt/pretty_print.hpp"
#include "parse.hpp"

#include <bit>

namespace minecraft::packets::server
{
    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, palette_type &target, error_code &ec)
    {
        if (not ec.failed())
        {
            first            = minecraft::parse(first, last, target.palette_length, ec);
            std::size_t size = static_cast< std::size_t >(target.palette_length.value());
            first            = minecraft::parse(first, last, std::tie(target.palette_data, size), ec);
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
                    first = parse(first, last, *target.palette, ec);
                }
            }

            first = minecraft::parse(first, last, target.data_length, ec);
            if (not ec)
            {
                std::size_t size = static_cast< std::size_t >(target.data_length.value());
                first            = minecraft::parse(first, last, std::tie(target.data, size), ec);
            }
        }
        return first;
    }

    const_buffer_iterator parse(const_buffer_iterator                        first,
                                const_buffer_iterator                        last,
                                std::tuple< chunk_column_type &, var_int & > target,
                                error_code &                                 ec)
    {
        if (not ec.failed())
        {
            auto &column = std::get< 0 >(target);

            std::bitset< 16 > bitmask = get< 1 >(target).value();

            for (auto column_id = 0; column_id != 16; column_id++)
            {
                if (bitmask[column_id])
                {
                    column.chunk_sections.emplace_back(std::make_pair(column_id, chunk_section_type()));
                    first = parse(first, last, column.chunk_sections.back().second, ec);
                    if (ec.failed())
                        break;
                }
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

            {
                // Parse heightmaps using a prettyprint handler
                auto pretty_print_han = nbt::pretty_print_handler();
                auto ctx              = nbt::parse_context(pretty_print_han);
                first                 = nbt::parse(first, last, ctx, ec);
                spdlog::info(pretty_print_han.buffer);
            }

            // first = nbt::parse(first, last, target.heightmaps, ec);

            if (target.full_chunk)
            {
                std::size_t size = 1024;
                first            = minecraft::parse(first, last, std::tie(target.biomes, size), ec);
            }

            first = minecraft::parse(first, last, target.data_size, ec);

            if (std::distance(first, last) < target.data_size.value())
            {
                ec = error::incomplete_parse;
                return first;
            }
            first = parse(first, last, std::tie(target.column, target.primary_bit_mask), ec);

            first            = parse(first, last, target.no_block_entities, ec);
            std::size_t size = static_cast< std::size_t >(target.no_block_entities.value());
            for (std::size_t x = 0; x < size; x++)
            {
                auto pretty_print_han = nbt::pretty_print_handler();
                auto ctx              = nbt::parse_context(pretty_print_han);

                first = nbt::parse(first, last, ctx, ec);
                spdlog::info(pretty_print_han.buffer);
                ec = ctx.error();
            }
            // first = minecraft::parse(first,last,std::tie(target.block_entities,size),ec);
        }
        return first;
    }

}   // namespace minecraft::packets::server