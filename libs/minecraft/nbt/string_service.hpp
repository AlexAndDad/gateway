#pragma once
#include "hash_table_service.hpp"
#include "offset.hpp"
#include "string_service/string_bucket.hpp"
#include "tag_type.hpp"

#include <cstdint>
#include <memory>
#include <minecraft/nbt/string_service/string_header.hpp>
#include <minecraft/nbt/string_service/string_hash_table.hpp>
#include <string_view>

namespace minecraft::nbt
{

    template < class Derived >
    struct string_service
    {
        string_service()
        : global_hash_table_(-1)
        {
        }

        /// emplace the string into the data store, reusing existing string data if possible
        /// @param str is the string to emplace
        /// @returns the offset of the string atom in the storage. If not enough free space, -1
        offset acquire_string(std::string_view str);

        auto global_string_table() -> offset { return global_hash_table_; }

        /// reduce the refcount of a string, if zero destroy the string
        /// \param id id of string
        /// \return resulting refcount
        auto release_string(offset id) -> std::uint8_t;

      private:

        using string_hash_table = hash_table<void>;

        auto acquire_global_hash_table() -> string_hash_table *;

        auto new_string(std::uint32_t hash, std::string_view s) -> string_header *;

        auto resolve(offset string_id) -> string_header *;

        /*

        string_header *lookup_string(hash_table *ht, std::uint32_t hash, std::string_view);

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

         */

      private:
        auto self() -> Derived *;
        auto self() const -> Derived const *;

      private:
        std::int32_t global_hash_table_;   // position of the global string hash table
    };

}   // namespace minecraft::nbt
