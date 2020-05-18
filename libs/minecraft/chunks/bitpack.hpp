#pragma once
#include "minecraft/parse_error.hpp"
#include "minecraft/types/buffer.hpp"

#include <boost/endian/buffers.hpp>
#include <cstddef>
#include <cstdint>

namespace minecraft
{
    struct compressed_bitfield_iterator
    {
        static constexpr auto bits_per_word  = 64;
        static constexpr auto bytes_per_word = bits_per_word / 8;

        compressed_bitfield_iterator(const_buffer_iterator first,
                                     const_buffer_iterator last,
                                     int                   field_size)
        : next_(first)
        , last_(last)
        , field_size_(field_size)
        {
            if (field_size_ > 16)
                throw system_error(minecraft::error::out_of_range,
                                   "compressed_bitfield_iterator");
        }

        std::uint16_t operator*()
        {
            auto [accum, got] = get_next(field_size_);

            if (got < field_size_)
            {
                auto [a2, got2] = get_next(field_size_ - got);
                accum |= (a2 << got);
            }

            return accum;
        }

      private:
        static auto ones(int bits) -> std::uint16_t
        {
            static const std::uint16_t btab[] = {
                0x0000, 0x0001, 0x0003, 0x0007, 0x000f, 0x001f,
                0x003f, 0x007f, 0x00ff, 0x01ff, 0x03ff, 0x07ff,
                0x0fff, 0x1fff, 0x3fff, 0x7fff, 0xffff,
            };
            assert(bits <= 16);
            return btab[bits];
        }

        auto get_next(int to_get) -> std::tuple< std::uint16_t, int >
        {
            if (!available_)
            {
                if (std::distance(next_, last_) < bytes_per_word)
                    throw system_error(minecraft::error::incomplete_parse,
                                       "compressed_bitfield_iterator");
                auto buf = boost::endian::big_uint64_buf_at();
                std::memcpy(buf.data(), next_, bytes_per_word);
                accum_ = buf.value();
                next_ += bytes_per_word;
                available_ = bits_per_word;
            }

            const auto take = std::min(available_, to_get);
            auto result     = static_cast< std::uint16_t >(accum_) & ones(take);
            available_ -= take;
            accum_ >>= take;
            return std::tuple(result, take);
        }

        const_buffer_iterator next_, last_;
        int                   field_size_;
        int                   available_ = 0;
        std::uint64_t         accum_;
    };

    struct bit_compressor
    {
        static constexpr auto bits_per_word  = 64;
        static constexpr auto bytes_per_word = bits_per_word / 8;

        bit_compressor(int field_size, compose_buffer &target)
        : target_(target)
        , field_size_(field_size)
        {
        }

        void operator()(std::uint64_t data)
        {
            for(auto n = field_size_ ; n ; )
            {
                accum_ |= (data << bits_accumulated_);
                auto written =
                    std::min(n, (bits_per_word - bits_accumulated_));
                assert(written != 0);
                data >>= written;
                bits_accumulated_ += written;
                if (bits_accumulated_ == bits_per_word)
                    flush();
                n -= written;
            }
        }

        // return the number of longwords required to write n payloads
        std::int32_t size(int n) const
        {
            auto bits  = field_size_ * n;
            auto words = (bits + bits_per_word - 1) / bits_per_word;
            return words;
        }

        std::size_t extent(int words_to_write) const
        {
            return size(words_to_write) * bytes_per_word;
        }

        void flush()
        {
            if (bits_accumulated_)
            {
                auto pos = target_.size();
                target_.resize(pos + bytes_per_word);
                auto conv = boost::endian::big_uint64_buf_at(std::exchange(accum_, 0));
                std::memcpy(&target_[pos], conv.data(), bytes_per_word);
                bits_accumulated_ = 0;
            }
        }


        compose_buffer &target_;
        std::uint64_t   accum_ = 0;
        int             field_size_;
        int             bits_accumulated_ = 0;
    };

}   // namespace minecraft