#pragma once
#include "offset.hpp"
#include "tag_type.hpp"
#include <string_view>
#include <cstdint>
#include <memory>


#include "hash_table_service.hpp"

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

        auto is_valid() const -> bool
        {
            return type == tag_type::String;
        }

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

    template < class Derived >
    struct string_service
    {
        string_service()
        : global_hash_table_(-1)
        {
        }

        string_header *lookup_string(hash_table *ht, std::uint32_t hash, std::string_view);
        string_header *new_string(std::uint32_t hash, std::string_view s);

        /// find space in the hash table (causing a rehash if necessary). Then allocate storage for the string. Then
        /// store the string in the hash table.
        /// If any of that fails, return nullptr, possibly having expanded the hash table.
        /// \param ht
        /// \param hash
        /// \return address of emplaced string
        string_header *emplace_string(hash_table *ht, std::uint32_t hash, std::string_view);

        bool string_equal(offset a, std::string_view b) const;

        /// return the hash of a stored string.
        /// \param id May be invalid() in which case an empty string is assumed
        /// \return hash value
        auto string_get_hash(offset id) -> std::uint32_t;

        auto release_string(offset id) -> std::uint8_t;

        /// emplace the string into the data store, reusing existing string data if possible
        /// @param str is the string to emplace
        /// @returns the offset of the string atom in the storage. If not enough free space, -1
        offset acquire_string(std::string_view str);

      private:
        hash_table *expect_global_hash_table()
        {
            auto ht = self()->template from_offset< hash_table >(global_hash_table_);
            assert(ht);
            return ht;
        }

        hash_table *acquire_global_hash_table()
        {
            if (invalid_offset(global_hash_table_))
            {
                auto ht            = self()->construct_hash_table(7);
                global_hash_table_ = self()->to_offset(ht);
                return ht;
            }
            else
            {
                return self()->template from_offset< hash_table >(global_hash_table_);
            }
        }
        auto hash_service() -> hash_table_service< Derived > * { return self(); }


      private:
        auto self() -> Derived * { return static_cast< Derived * >(this); }

        auto self() const -> Derived const * { return static_cast< Derived const * >(this); }

      private:
        std::int32_t global_hash_table_;   // position of the global string hash table
    };

}   // namespace minecraft::nbt

