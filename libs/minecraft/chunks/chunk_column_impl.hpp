//
// Created by rhodges on 17/05/2020.
//

#ifndef GATEWAY_CHUNK_COLUMN_IMPL_HPP
#define GATEWAY_CHUNK_COLUMN_IMPL_HPP

#include "bitpack.hpp"
#include "chunk_section_impl.hpp"
#include "minecraft/encode.hpp"
#include "nbt/compound.hpp"
#include "nbt/nvp.hpp"
#include "types/var.hpp"

#include <cstring>

namespace minecraft::chunks
{
    struct chunk_column_impl
    {
        using block_type = minecraft::blocks::block_type;

        // 16 chunks * 16 blocks = 256 height max
        static constexpr int chunk_extent = 16;

        // x is horizontal
        static constexpr int x_extent = chunk_section_impl::x_extent;

        // z is horzontal
        static constexpr int z_extent = chunk_section_impl::z_extent;

        // y is vertical
        static constexpr int y_extent = chunk_section_impl::y_extent;

        struct height_map
        {
            uint8_t &operator[](vector2 horz) { return heights_[horz.z][horz.x]; }

            uint8_t const &operator[](vector2 horz) const { return heights_[horz.z][horz.x]; }

            nbt::compound compose_to_nbt() const
            {
                auto storage = compose_buffer();
                storage.reserve(sizeof(std::uint64_t) * 36);

                auto compressor = bit_compressor(9, storage);
                for (auto &z : heights_)
                {
                    for (auto &x : z)
                    {
                        compressor(x);
                    }
                }
                compressor.flush();

                auto lng_array = nbt::long_array();
                lng_array.reserve(36);
                auto first = storage.data();
                auto last  = first + (36 * sizeof(std::uint64_t));
                while (first != last)
                {
                    std::uint64_t val;
                    std::memcpy(&val, first, sizeof(std::uint64_t));
                    lng_array.emplace_back(val);
                    first += sizeof(std::uint64_t);
                }

                nbt::compound tmp = {};
                tmp.emplace("MOTION_BLOCKING", std::move(lng_array));
                nbt::compound outter = {};
                outter.emplace("",std::move(tmp));
                return outter;
            }

            void parse_from_nbt(nbt::compound & data)
            {
                boost::ignore_unused(data);
            }

            uint8_t heights_[z_extent][x_extent];
        };

        chunk_column_impl();

        chunk_section_impl const &chunk(int n) const
        {
            assert(n < chunk_extent);
            return chunks_[n];
        }

        chunk_section_impl &chunk(int n)
        {
            assert(n < chunk_extent);
            return chunks_[n];
        }

        chunk_section_impl &chunk(vector3 const &vec) { return chunks_[vec.y & 0xff]; }

        chunk_section_impl const &chunk(vector3 const &vec) const { return chunks_[vec.y & 0xff]; }

        static void next(vector3 &pos);

        void recalc_height(vector2 horz);
        void recalc_height();

        void recalc();

        static bool in_bounds(vector3 pos)
        {
            return pos.x >= 0 and pos.x < x_extent and pos.y >= 0 and pos.y < (y_extent * chunk_extent) and pos.z >= 0 and pos.z < z_extent;
        }

        block_type change_block(vector3 pos, block_type b, bool update = true);

        std::uint8_t height(vector2 xz) const { return height_map_[xz]; }

        const height_map &                      get_height_map() const { return height_map_; }
        const std::array< std::int32_t, 1024 > &get_biomes_data() const { return biomes_data_; }
        std::array< std::int32_t, 1024 > &      get_biomes_data() { return biomes_data_; }
        const chunk_section_impl &              get_chunk_section(std::size_t index) const { return chunks_[index]; }
        const std::bitset< 16 > &               get_primary_bit_mask() const { return primary_bit_mask_; }
        void                                    set_primary_bit_mask(std::bitset< 16 > bs) { primary_bit_mask_ = bs; };

      private:
        struct chunk_section_impl        chunks_[chunk_extent];
        std::array< std::int32_t, 1024 > biomes_data_;
        height_map                       height_map_ {};
        std::bitset< 16 >                primary_bit_mask_;
    };
    template < typename Iter >
    Iter encode(chunk_column_impl const &cc, vector2 coords, bool biomes, Iter first)
    {
        first = minecraft::encode(coords.x, first);                                        // encode chunk_x
        first = minecraft::encode(coords.z, first);                                        // encode chunk_z
        first = minecraft::encode(biomes, first);                                          // encode full_chunk
        first = minecraft::encode(var_int(cc.get_primary_bit_mask().to_ulong()), first);   // encode primary_bitmask
        first = minecraft::nbt::encode(cc.get_height_map().compose_to_nbt(), first);       // encode heightmaps

        if (biomes)   // if biomes
        {
            // encode biomes_data
            first = minecraft::encode(cc.get_biomes_data(), first);
        }

        // Encode data to a temp buffer so we can get the size.
        auto tmp_buff = compose_buffer();
        for (std::size_t x = 0; x < 16; x++)
        {
            if (cc.get_primary_bit_mask()[x])
            {
                compose(cc.get_chunk_section(x), tmp_buff);
            }
        }

        first = minecraft::encode(var_int(tmp_buff.size()), first);   // encode data size
        std::copy(tmp_buff.begin(), tmp_buff.end(), first);           // encode data

        first = minecraft::encode(var_int(0), first);   // encode no_block_entities
        // TODO add these - encode block entities
        return first;
    }

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, vector2 &coords, bool &full_chunk, chunk_column_impl &cd);

    struct copyable_chunk_column_impl
    {
        copyable_chunk_column_impl(const chunk_column_impl &other)
        : impl_(new chunk_column_impl(other))
        {
        }

        copyable_chunk_column_impl()
        : impl_(nullptr)
        {
        }

        ~copyable_chunk_column_impl() { delete impl_; }

        copyable_chunk_column_impl(const copyable_chunk_column_impl &other)   // Copy constructor
        : copyable_chunk_column_impl(*other.impl_)
        {
        }
        copyable_chunk_column_impl &operator=(const copyable_chunk_column_impl &other)   // Copy assignment
        {
            auto tmp = other;
            std::swap(impl_, tmp.impl_);

            return *this;
        }

        copyable_chunk_column_impl(copyable_chunk_column_impl &&other) noexcept   // Move constructor
        : impl_(std::exchange(other.impl_, nullptr))
        {
        }

        copyable_chunk_column_impl &operator=(copyable_chunk_column_impl &&other) noexcept   // move assignment
        {
            delete std::exchange(impl_, std::exchange(other.impl_, nullptr));
            return *this;
        }

        chunk_column_impl *operator->() { return impl_; }

        explicit operator bool() const { return impl_ != nullptr; }

        chunk_column_impl &      value() { return *impl_; }
        const chunk_column_impl &value() const { return *impl_; }

        void reset() {}

      private:
        chunk_column_impl *impl_;
    };

}   // namespace minecraft::chunks
#endif   // GATEWAY_CHUNK_COLUMN_IMPL_HPP
