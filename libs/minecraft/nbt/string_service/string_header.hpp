#pragma once
#include "minecraft/nbt/tag_type.hpp"

#include <algorithm>
#include <cstdint>
#include <iosfwd>

namespace minecraft::nbt
{
    struct string_header
    {
        std::uint16_t length;
        std::uint32_t hash;
        std::uint8_t  use_count;   // usage counter. becomes sticky at 255 (i.e. string is assumed to never be deleted
        char          first_data_[1];

        string_header(std::uint32_t hash, std::string_view src)
        : length(static_cast< std::uint16_t >(src.size()))
        , hash(hash)
        , use_count(1)
        {
            if (src.size())
                std::memcpy(data(), src.data(), src.size());
        }

        static constexpr auto max_string_size() -> std::size_t { return 65535; }

        static std::size_t extent(std::uint16_t string_length)
        {
            return sizeof(string_header) + sizeof(char) * ((std::max)(std::uint16_t(1), string_length) - 1);
        }

        std::size_t extent() const { return extent(size()); }

        auto is_valid() const -> bool { return true; }   // type == tag_type::String; }

        auto data() const -> const char * { return first_data_; }
        auto data() -> char * { return first_data_; }
        auto size() const -> std::size_t { return length; }
        auto operator==(std::string_view b) const -> bool
        {
            return size() == b.size() and std::memcmp(data(), b.data(), size()) == 0;
        }
        auto addref() -> std::uint8_t
        {
            if (use_count < 255)
                ++use_count;
            return use_count;
        }
        auto release() -> std::uint8_t
        {
            if (use_count != 255)
                --use_count;
            return use_count;
        }
    };

    std::ostream &operator<<(std::ostream &os, string_header *phdr);
    std::ostream &operator<<(std::ostream &os, string_header const &phdr);

}   // namespace minecraft::nbt