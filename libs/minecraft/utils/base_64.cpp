//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#include "base_64.hpp"

#include <boost/endian.hpp>

namespace minecraft::utils
{
    inline std::size_t padded_encoded_size(std::size_t message_size)
    {
        auto blocks          = message_size / 3;
        auto remaining_bytes = message_size % 3;
        switch (remaining_bytes)
        {
        case 0:
            // message size fits perfectly into blocks
            break;
        case 1:
            // message is 1 bytes over a block, requires 2 data chars plus 2 padding
            [[fallthrough]];
        case 2:
            // message is 2 bytes over a block, requires 16 bits of data (2.4 chars + 1 padding)
            blocks += 1;
        }

        return blocks * 4;
    }

    constexpr char encoded_char(std::uint64_t input)
    {
        auto index = static_cast< std::uint8_t >(input);
        index &= std::uint8_t(0b111111u);
        if (index < 26)
            return char('A' + index);
        if (index < 52)
            return char('a' + index - 26);
        if (index < 62)
            return char('0' + index - 52);
        if (index == 62)
            return '+';
        return '/';
    }

    constexpr std::array< std::array< char, 2 >, 4096 > make_encoded_pairs()
    {
        auto result = std::array< std::array< char, 2 >, 4096 >();
        for (std::size_t i = 0; i < 4096; ++i)
        {
            std::bitset< 12 > bset;
            bset = result[i][0] = encoded_char(i >> 6);
            result[i][1]        = encoded_char(i);
        }
        return result;
    }

    std::array< char, 2 > encoding2(std::uint64_t index)
    {
        constexpr auto encoded_pairs = make_encoded_pairs();
        return encoded_pairs[index & 0b111111111111u];
    }

    mutable_buffer_iterator encoding2(std::uint64_t index, mutable_buffer_iterator out)
    {
        constexpr auto encoded_pairs = make_encoded_pairs();
        auto &         pair          = encoded_pairs[index & 0b111111111111u];
        std::memcpy(out, pair.data(), 2);
        return out + 2;
    }

    mutable_buffer_iterator encoding4(std::uint64_t index, mutable_buffer_iterator out)
    {
        out = encoding2(index >> 12, out);
        out = encoding2(index, out);
        return out;
    }

    mutable_buffer_iterator encoding8(std::uint64_t index, mutable_buffer_iterator out)
    {
        out = encoding4(index >> 24, out);
        out = encoding4(index, out);
        return out;
    }

    auto encoding4(std::uint64_t val) -> std::array< char, 4 >
    {
        auto low    = encoding2(val >> 12);
        auto high   = encoding2(val);
        auto result = std::array< char, 4 > {};
        std::memcpy(result.data(), low.data(), 2);
        std::memcpy(result.data() + 2, high.data(), 2);
        return result;
    }

    void base64_encode(const_buffer_iterator first, const_buffer_iterator last, compose_buffer &target)
    {
        auto input_size = static_cast< std::size_t >(std::distance(first, last));
        auto op         = target.size();
        target.resize(op + padded_encoded_size(input_size));
        auto out_iter = target.data() + op;

        for (; std::distance(first, last) >= 24; first += 24)
        {
            std::array< unsigned char, 24 > cycle_buffer {};
            std::memcpy(cycle_buffer.data(), first, 24);

            boost::endian::big_uint64_at acc;
            std::memcpy(acc.data() + 2, cycle_buffer.data(), 6);
            out_iter = encoding8(acc.value(), out_iter);
            std::memcpy(acc.data() + 2, cycle_buffer.data() + 6, 6);
            out_iter = encoding8(acc.value(), out_iter);
            std::memcpy(acc.data() + 2, cycle_buffer.data() + 12, 6);
            out_iter = encoding8(acc.value(), out_iter);
            std::memcpy(acc.data() + 2, cycle_buffer.data() + 18, 6);
            out_iter = encoding8(acc.value(), out_iter);
        }

        for (; std::distance(first, last) >= 6; first += 6)
        {
            boost::endian::big_uint64_at acc;
            std::memcpy(acc.data() + 2, first, 6);
            out_iter = encoding8(acc.value(), out_iter);
        }

        for (; std::distance(first, last) >= 3; first += 3)
        {
            boost::endian::big_uint32_at acc;
            std::memcpy(acc.data() + 1, first, 3);
            out_iter = encoding4(acc.value(), out_iter);
            first += 3;
        }
        // "VGhlIHF1aWNrIGJyb3duIGZv2ARhAQAAcyBvdmVyIHRoZSBsYXp5IGRvZy4="
        // "VGhlIHF1aWNrIGJyb3duIGZveCBqdW1wcyBvdmVyIHRoZSBsYXp5IGRvZy4="

        {
            std::array< char, 4 > encode_buffer {};
            auto                  acc      = std::bitset< 24 >();
            auto                  get_byte = [&first] {
                return std::bitset< 24 >(static_cast< std::uint64_t >(static_cast< std::uint8_t >(*first++)));
            };

            switch (std::distance(first, last))
            {
            default:
                break;
            case 1:
                acc              = get_byte() << 16;
                encode_buffer    = encoding4(acc.to_ulong());
                encode_buffer[2] = '=';
                encode_buffer[3] = '=';
                out_iter         = std::copy(encode_buffer.begin(), encode_buffer.end(), out_iter);
                break;
            case 2:
                acc = get_byte() << 16;
                acc |= get_byte() << 8;
                encode_buffer    = encoding4(acc.to_ulong());
                encode_buffer[3] = '=';
                out_iter         = std::copy(encode_buffer.begin(), encode_buffer.end(), out_iter);
                break;
            }
        }
    }

}   // namespace minecraft::utils