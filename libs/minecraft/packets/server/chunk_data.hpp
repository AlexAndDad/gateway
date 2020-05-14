#pragma once

#include "minecraft/nbt/nvp.hpp"
#include "minecraft/packets/packet_base.hpp"
#include "minecraft/types.hpp"
#include "play_id.hpp"
#include "polyfill/printers/vector_printer.hpp"

#include <span>

namespace minecraft::packets::server
{
    struct palette_type
    {
        var_int                palette_length;
        std::vector< var_int > palette_data;

        template < class Stream >
        friend Stream &operator<<(Stream &stream, const palette_type &self);
    };

    template < class Stream >
    Stream &operator<<(Stream &stream, const palette_type &self)
    {
        stream << "palette_length: " << self.palette_length << "\n";
        stream << "palette_data: " << polyfill::printers::print(self.palette_data) << "\n";
        return stream;
    }

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, palette_type &target, error_code &ec);

    template < class Iter >
    Iter encode(const palette_type &in, Iter first)
    {
        first = minecraft::encode(in.palette_length, first);
        first = minecraft::encode(in.palette_data, first);
        return first;
    }

    struct chunk_section_type
    {
        std::int16_t                  block_count;
        std::uint8_t                  bits_per_block;
        std::optional< palette_type > palette;
        var_int                       data_length;
        std::vector< long >           data;

        template < class Stream >
        friend Stream &operator<<(Stream &stream, const chunk_section_type &self);
    };

    template < class Stream >
    Stream &operator<<(Stream &stream, const chunk_section_type &self)
    {
        stream << "block_count: " << self.block_count << "\n";
        stream << "bits_per_block: " << self.bits_per_block << "\n";
        if (self.palette)
        {
            stream << "using section palette?: true\n";
            stream << "palette:\n" << *self.palette;
        }
        else
        {
            stream << "using section palette?: false\n";
        }

        stream << "data_len:" << self.data_length.value() << "\n";
        return stream;
    }

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, chunk_section_type &target, error_code &ec);

    template < class Iter >
    Iter encode(const chunk_section_type &in, Iter first)
    {
        first = minecraft::encode(in.block_count, first);
        first = minecraft::encode(in.bits_per_block, first);

        if (in.palette)
        {
            first = encode(in.palette.value(), first);
        }

        first = minecraft::encode(in.data_length, first);
        first = minecraft::encode(in.data, first);

        return first;
    }

    struct chunk_column_type
    {
        std::vector< std::pair< std::size_t, chunk_section_type > > chunk_sections;

        template < class Stream >
        friend Stream &operator<<(Stream &stream, const chunk_column_type &self);
    };
    template < class Stream >
    Stream &operator<<(Stream &stream, const chunk_column_type &self)
    {
        stream << "chunk_column:\n";
        for (auto &pair : self.chunk_sections)
        {
            stream << "section_index: " << pair.first << "\n";
            stream << "section: " << pair.second << "\n";
        }
        return stream;
    }
    const_buffer_iterator parse(const_buffer_iterator                      first,
                                const_buffer_iterator                      last,
                                std::tuple< chunk_column_type &, var_int > target,
                                error_code &                               ec);

    template < class Iter >
    Iter encode(const chunk_column_type &in, Iter first)
    {
        for (auto &pair : in.chunk_sections)
        {
            first = encode(pair.second, first);
        }
        return first;
    }

    struct chunk_data_type
    {
        std::int32_t                         chunk_x;
        std::int32_t                         chunk_z;
        bool                                 full_chunk;
        var_int                              primary_bit_mask;
        nbt::nvp< nbt::Compound >            heightmaps;
        std::vector< std::int32_t >          biomes;
        var_int                              data_size;
        chunk_column_type                    column;
        var_int                              no_block_entities;
        std::vector< minecraft::nbt::value > block_entities;

        template < class Stream >
        friend Stream &operator<<(Stream &stream, const chunk_data_type &self);
    };

    template < class Stream >
    Stream &operator<<(Stream &stream, const chunk_data_type &self)
    {
        stream << "chunk_data:\n";
        stream << "chunk_x: " << self.chunk_x << "\n";
        stream << "chunk_z: " << self.chunk_z << "\n";
        stream << "full_chunk: " << self.full_chunk << "\n";
        stream << "primary_bit_mask: " << std::bitset< 16 >(self.primary_bit_mask.value()).to_string() << "\n";
        stream << "heightmaps: " << self.heightmaps.value << "\n";
        stream << "biomes: " << polyfill::printers::print(self.biomes) << "\n";
        stream << "chunk_column: " << self.column << "\n";
        stream << "block_entities: " << polyfill::printers::print(self.block_entities) << "\n";
        return stream;
    }

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, chunk_data_type &target, error_code &ec);

    template < class Iter >
    Iter encode(const chunk_data_type &in, Iter first)
    {
        first = minecraft::encode(in.chunk_x, first);
        first = minecraft::encode(in.chunk_z, first);
        first = minecraft::encode(in.full_chunk, first);
        first = minecraft::encode(in.primary_bit_mask, first);
        first = encode(in.heightmaps, first);

        if (in.full_chunk)
        {
            first = minecraft::encode(in.biomes, first);
        }
        first = minecraft::encode(in.data_size, first);
        first = encode(in.column, first);

        first = minecraft::encode(in.no_block_entities, first);
        first = minecraft::encode(in.block_entities, first);
        return first;
    }

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