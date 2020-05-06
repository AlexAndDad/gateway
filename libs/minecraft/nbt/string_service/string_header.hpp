#pragma once
#include "minecraft/nbt/tag_type.hpp"

#include <cstdint>
#include <iosfwd>

namespace minecraft::nbt
{
    struct string_header
    {
        tag_type      type;
        std::uint8_t  use_count;   // usage counter. becomes sticky at 255 (i.e. string is assumed to never be deleted
        std::uint16_t length;
        std::uint32_t hash;

        string_header(std::uint32_t hash, std::string_view src)
        : type(tag_type::String)
        , use_count(1)
        , length(static_cast< std::uint16_t >(src.size()))
        , hash(hash)
        {
            if (src.size())
                std::memcpy(data(), src.data(), src.size());
        }

        static constexpr auto max_string_size() -> std::size_t { return 65535; }

        static std::size_t extent(std::uint16_t string_length) { return sizeof(string_header) + string_length; }

        std::size_t extent() const { return extent(size()); }

        auto is_valid() const -> bool { return type == tag_type::String; }

        auto data() const -> const char * { return reinterpret_cast< const char * >(this + 1); }
        auto data() -> char * { return reinterpret_cast< char * >(this + 1); }
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

    std::ostream& operator<<(std::ostream& os, string_header* phdr);
    std::ostream &operator<<(std::ostream &os, string_header const &phdr);

}   // namespace minecraft::nbt