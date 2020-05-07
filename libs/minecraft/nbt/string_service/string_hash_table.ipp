#pragma once

#include "string_hash_table.hpp"
#include "string_header.hpp"

#include <cassert>
#include <fmt/ostream.h>
#include <ostream>
namespace minecraft::nbt
{
    template < class MappedType >
    auto insert(storage_provider *self, hash_table< MappedType > *table, string_header *key)
        -> std::tuple< hash_table< MappedType > *, hash_bucket< MappedType > * >
    {
        using value_type = typename hash_table< MappedType >::value_type;

        // @todo: rehash here
        table = maybe_rehash(self, table);

        auto pbucket = table->get_bucket(key->hash);
        if (pbucket->empty())
        {
            // bucket is empty so no collision.
            // simply copy value into bucket
            pbucket->value = value_type(self->to_offset(key));
            table->adjust_size(1);
        }
        else
        {
            // collision - link a new bucket extension and increment collision count
            auto nbucket  = new_bucket< MappedType >(self, key);
            nbucket->next = pbucket->next;
            pbucket->next = self->to_offset(nbucket);
            table->adjust_size(1);
            table->adjust_collisions(1);
            pbucket = nbucket;
        }
        return std::tuple(table, pbucket);
    }

    template < class MappedType >
    auto link(storage_provider *self, hash_table< MappedType > *table, hash_bucket< MappedType > *bucket)
        -> hash_bucket< MappedType > *
    {
        string_header *            key         = deref_key(self, bucket);
        hash_bucket< MappedType > &root_bucket = *table->get_bucket(key->hash);
        if (root_bucket.empty())
        {
            root_bucket = std::move(*bucket);
            table->adjust_size(1);
            self->free(bucket, size_to_blocks(sizeof(*bucket)));
            return &root_bucket;
        }
        else
        {
            link(self, &root_bucket, bucket);
            table->adjust_size(1);
            table->adjust_collisions(1);
            return bucket;
        }
    }

    template < class MappedType >
    auto link(storage_provider *self, hash_table< MappedType > *table, hash_bucket< MappedType > &&src)
        -> hash_bucket< MappedType > *
    {
        string_header *            key         = deref_key(self, &src);
        hash_bucket< MappedType > &root_bucket = *table->get_bucket(key->hash);
        if (root_bucket.empty())
        {
            root_bucket = std::move(src);
            table->adjust_size(1);
            return &root_bucket;
        }
        else
        {
            table->adjust_size(1);
            table->adjust_collisions(1);
            return link(self, &root_bucket, new_bucket< MappedType >(self, std::move(src)));
        }
    }

    template < class MappedType >
    auto lookup(storage_provider *self, hash_table< MappedType > *table, std::uint32_t hash, std::string_view str)
        -> std::tuple< std::int32_t, hash_bucket< MappedType > * >
    {
        auto  index   = hash % table->nbuckets();
        auto *pbucket = table->get_bucket(index);

        auto match = [&]() {
            string_header *candidate = deref_key(self, pbucket);
            assert(candidate->is_valid());
            return std::string_view(candidate->data(), candidate->size()) == str;
        };

        if (pbucket->empty())
            pbucket = nullptr;
        else
        {
            while (not match())
            {
                pbucket = self->template from_offset< hash_bucket< MappedType > >(pbucket->next);
                if (pbucket == nullptr)
                    break;
            }
        }

        return std::tuple(index, pbucket);
    }

    template < class MappedType >
    auto maybe_rehash(storage_provider *self, hash_table< MappedType > *table) -> hash_table< MappedType > *
    {
        if (table->collisions())
        {
            auto collision_factor = double(table->collisions() / double(table->size()));
            if (collision_factor > 0.05)
            {
                const auto bucket_ratio = 1.5;
                const auto new_buckets  = table->size() * bucket_ratio;
                const auto as_prime     = next_prime(static_cast< std::int32_t >(new_buckets));
                table                   = rehash(self, table, std::max(7, as_prime));
            }
        }
        return table;
    }

    template < class MappedType >
    auto new_hash_table(storage_provider *self, std::uint32_t buckets) -> hash_table< MappedType > *
    {
        auto extent = hash_table< MappedType >::extent(buckets);
        auto blocks = size_to_blocks(extent);
        auto p      = self->alloc(blocks);
        return new (p) hash_table< MappedType >(buckets);
    }

    template < class MappedType >
    auto unlink(storage_provider *         self,
                hash_table< MappedType > * table,
                std::int32_t               index,
                hash_bucket< MappedType > *bucket) -> hash_bucket< MappedType > *
    {
        hash_bucket< MappedType > *prev = table->get_bucket(index);
        if (prev == bucket)
        {
            if (not invalid_offset(prev->next))
            {
                table->adjust_size(-1);
                bucket = self->template from_offset< hash_bucket< MappedType > >(prev->next);
                prev->clear();
                *prev = std::move(*bucket);
                return bucket;
            }
            else
            {
                table->adjust_size(-1);
                prev->clear();
                bucket = nullptr;
            }
        }
        else
        {
            while (prev)
            {
                if (prev->next == self->to_offset(bucket))
                {
                    table->adjust_size(-1);
                    prev->next = bucket->next;
                    bucket->clear();
                    break;
                }
                prev = self->template from_offset< hash_bucket< MappedType > >(prev->next);
            }
        }
        return bucket;
    }

    template < class MappedType >
    auto rehash(storage_provider *self, hash_table< MappedType > *table, std::uint32_t new_buckets)
        -> hash_table< MappedType > *
    {
        hash_table< MappedType > *new_table = new_hash_table< MappedType >(self, new_buckets);

        // iterate through the old table's buckets, unlink them and link them into the new table;

        for (hash_bucket< MappedType > &root_bucket : table->buckets())
        {
            if (root_bucket.empty())
                continue;

            // first deal with all the leaves
            while (auto leaf = unlink(self, &root_bucket))
            {
                link(self, new_table, leaf);
                table->adjust_size(-1);
            }

            link(self, new_table, std::move(root_bucket));
            table->adjust_size(-1);
        }

        assert(table->size() == 0);
        self->free(table, size_to_blocks(table->extent()));

        return new_table;
    }

    template < class MappedType >
    auto print(std::ostream &os, storage_provider *self, hash_table< MappedType > *table) -> void
    {
        fmt::print(os, "size      : {}\n", table->size());
        fmt::print(os, "buckets   : {}\n", table->nbuckets());
        fmt::print(os, "collisions: {}\n", table->collisions());
        std::int32_t i = 0;
        for (auto &bucket : table->buckets())
        {
            if (not bucket.empty())
            {
                auto shdr = deref_key(self, &bucket);
                fmt::print("  bucket {} : {}", i, shdr);
                auto next = self->template from_offset< hash_bucket< MappedType > >(bucket.next);
                while (next)
                {
                    shdr = deref_key(self, next);
                    fmt::print(", {}", shdr);
                    next = self->template from_offset< hash_bucket< MappedType > >(next->next);
                }
            }
            ++i;
        }
    }

}   // namespace minecraft::nbt