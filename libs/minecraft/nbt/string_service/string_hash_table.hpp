#pragma once

#include "minecraft/nbt/string_service/string_header.hpp"
#include "string_bucket.hpp"

#include <iosfwd>
#include <span>
#include <string_view>

namespace minecraft::nbt
{
    template < class MappedType >
    struct hash_table;

    /// Allocate and construct a hash table in self
    /// \tparam MappedType
    /// \tparam Self
    /// \param self
    /// \param buckets
    /// \return
    template < class MappedType, class Self >
    auto new_hash_table(Self *self, std::uint32_t buckets) -> hash_table< MappedType > *;

    /// Lookup the bucket index and optionally the matching bucket for a given value and hash
    /// \tparam Self
    /// \tparam MappedType
    /// \param self
    /// \param table
    /// \param hash
    /// \param str
    /// \return
    template < class Self, class MappedType >
    auto lookup(Self *self, hash_table< MappedType > *table, std::uint32_t hash, std::string_view str)
        -> std::tuple< std::int32_t, hash_bucket< MappedType > * >;

    /// Insert a new entry into the hash table, possibly rehashing as a result
    /// \tparam Self
    /// \tparam MappedType
    /// \param self
    /// \param table
    /// \param index
    /// \param key
    /// \return a tuple of the (possibly new) address of the hash table and the address of the hash bucket that received
    /// the value
    template < class Self, class MappedType >
    auto insert(Self *self, hash_table< MappedType > *table, string_header *key)
        -> std::tuple< hash_table< MappedType > *, hash_bucket< MappedType > * >;

    /// Unlink a bucket from a slot. If the bucket was an owned allocated bucket, return it's address otherwise return
    /// nullptr \tparam Self \tparam MappedType \param self \param table \param index \param bucket \return
    template < class Self, class MappedType >
    auto unlink(Self *self, hash_table< MappedType > *table, std::int32_t index, hash_bucket< MappedType > *bucket)
        -> hash_bucket< MappedType > *;

    template <>
    struct hash_table< void >
    {
        using mapped_type = void;
        using bucket_type = hash_bucket< mapped_type >;
        using value_type  = typename bucket_type ::value_type;

        hash_table(std::int32_t nbuckets);

        // services

        static constexpr auto extent(std::int32_t buckets)
        {
            return sizeof(hash_table) + (sizeof(bucket_type) * (buckets ? buckets - 1 : buckets));
        }

        auto extent() const -> std::size_t { return extent(nbuckets_); }
        auto buckets() -> std::span< bucket_type >
        {
            return std::span< bucket_type >(first_bucket_, first_bucket_ + nbuckets_);
        }
        auto get_bucket(std::uint32_t hash) -> bucket_type * { return &(buckets()[hash % nbuckets_]); }

        auto is_valid() const -> bool { return size_ <= nbuckets_; }

        auto collisions() const -> std::int32_t { return collisions_; }
        auto adjust_collisions(std::int32_t delta) -> std::int32_t ;

        auto nbuckets() const -> std::int32_t { return nbuckets_; }

        auto size() const -> std::int32_t { return size_; }

        auto adjust_size(std::int32_t delta) -> std::int32_t ;

      private:
        std::int32_t collisions_;   // number of detected collisions.
        std::int32_t size_;         // number of items in the structure
        std::int32_t nbuckets_;     // number of buckets
        bucket_type  first_bucket_[1];

        // management
    };

    template < class Self, class MappedType >
    auto print(std::ostream &os, Self *self, hash_table< MappedType > *table) -> void;

}   // namespace minecraft::nbt

#include "string_hash_table.ipp"
