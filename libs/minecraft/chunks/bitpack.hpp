#pragma once
#include "minecraft/types/buffer.hpp"
#include "minecraft/parse_error.hpp"
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
        }

        std::uint16_t operator*()
        {
            auto [accum, got] = get_next(field_size_);

            if (got < field_size_)
            {
                auto [a2, got2] = get_next(field_size_);
                accum |= (a2 << got);
            }

            return accum;
        }

        auto next_iter() const -> const_buffer_iterator { return next_; }

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

}   // namespace minecraft