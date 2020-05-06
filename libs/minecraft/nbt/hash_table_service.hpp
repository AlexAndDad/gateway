#pragma once
#include "offset.hpp"

#include <cstddef>
#include <string_view>

namespace minecraft::nbt
{
    /*
    struct hash_bucket
    {
        offset next_bucket  = -1;                   // location of next bucket if this bucket is full
        offset locations[4] = { -1, -1, -1, -1 };   // locations of items in the bucket
    };

    struct hash_table
    {
        hash_table(std::size_t nbuckets)
        : nbuckets_(static_cast< std::uint32_t >(nbuckets))
        {
            for (auto p = buckets(); nbuckets--; ++p)
                new (p) hash_bucket {};
        }

        std::uint32_t size() const { return nbuckets_; }

        std::uint32_t nbuckets_;
        // followed by
        // hash_bucket [entries]

        hash_bucket &operator[](std::int32_t i) { return buckets()[i % nbuckets_]; }
        hash_bucket *at(std::int32_t i) { return &buckets()[i % nbuckets_]; }

        static auto extent(std::size_t buckets) -> std::size_t
        {
            return sizeof(hash_table) + (sizeof(hash_bucket) * buckets);
        }

        auto extent() const -> std::size_t { return extent(nbuckets_); }

        hash_bucket *buckets()
        {
            auto pself = this;
            pself += 1;
            auto pbucket = reinterpret_cast< hash_bucket * >(pself);
            return pbucket;
        }
    };
*/
    struct hash_table_service_base
    {
        hash_table_service_base(std::uint32_t hash_poison)
        : hash_poison_(hash_poison)
        {
        }

        std::uint32_t hash(std::string_view s) const;

      protected:
        std::uint32_t hash_poison_;   // poison to mix into all hash values
    };

    template < class Derived >
    struct hash_table_service : hash_table_service_base
    {
        using hash_table_service_base::hash_table_service_base;

        /*
        auto construct_hash_table(int32_t buckets) -> hash_table *;

        auto          find_empty_slot(hash_table *ht, std::uint32_t hash) -> offset *;
        std::int32_t *reverse_lookup(hash_table *ht, std::uint32_t hash, offset id);

      private:
        auto self() -> Derived * { return static_cast< Derived * >(this); }
         */
    };

}   // namespace minecraft::nbt

#include "hash_table_service.ipp"
