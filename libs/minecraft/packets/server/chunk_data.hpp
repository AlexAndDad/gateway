#pragma once

#include "minecraft/packets/packet_base.hpp"
#include "minecraft/types.hpp"

#include "play_id.hpp"

#include <span>

namespace minecraft::packets::server
{
    struct palette_type
    {
        var_int                palette_length;
        std::vector< var_int > palette_data;
    };
    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, palette_type &target, error_code &ec);

    struct chunk_section_type
    {
        std::int16_t                  block_count;
        std::uint8_t                  bits_per_block;
        std::optional< palette_type > palette;
        var_int                       data_length;
        std::vector< long >           data;
    };
    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, chunk_section_type &target, error_code &ec);

    struct chunk_data_type
    {
        std::int32_t chunk_x;
        std::int32_t chunk_z;
        bool         full_chunk;
        var_int      primary_bit_mask;
        //nbt::value   heightmaps;
        std::vector< std::int32_t > biomes;
        var_int                           data_size = 0;
        std::vector< chunk_section_type > data;
    };
    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, chunk_data_type &target, error_code &ec);

    struct chunk_data : packets::packet_base< play_id::chunk_data, chunk_data >
    {
        chunk_data_type data;
        template < class Self >
        static auto as_nvps(Self &self)
        {
            return nvp_set(nvp("data", self.data));
        }
    };
}   // namespace minecraft::packets::server