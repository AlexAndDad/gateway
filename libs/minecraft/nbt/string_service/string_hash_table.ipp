#pragma once

#include "string_hash_table.hpp"
#include "string_header.hpp"
#include <fmt/ostream.h>

#include <cassert>
#include <ostream>
namespace minecraft::nbt
{
    template < class Self, class MappedType >
    auto insert(Self *self, hash_table< MappedType > *table, string_header *key)
        -> std::tuple< hash_table< MappedType > *, hash_bucket< MappedType > * >
    {
        using value_type = typename hash_table< MappedType >::value_type;

        // @todo: rehash here

        auto pbucket     = table->get_bucket(key->hash);
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
            auto nbucket = new_bucket<MappedType>(self, key);
            nbucket->next = pbucket->next;
            pbucket->next = self->to_offset(nbucket);
            table->adjust_size(1);
            table->adjust_collisions(1);
            pbucket = nbucket;
        }
        return std::tuple(table, pbucket);
    }

    template < class Self, class MappedType >
    auto lookup(Self *self, hash_table< MappedType > *table, std::uint32_t hash, std::string_view str)
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

    template < class MappedType, class Self >
    auto new_hash_table(Self *self, std::uint32_t buckets) -> hash_table< MappedType > *
    {
        auto extent = hash_table< MappedType >::extent(buckets);
        auto blocks = size_to_blocks(extent);
        auto p      = self->alloc(blocks);
        return new (p) hash_table< MappedType >(buckets);
    }

    template < class Self, class MappedType >
    auto unlink(Self* self, hash_table< MappedType > *table, std::int32_t index, hash_bucket<MappedType>* bucket) -> hash_bucket<MappedType>*
    {
        hash_bucket<MappedType>* prev = table->get_bucket(index);
        if (prev == bucket)
        {
            if (not invalid_offset(prev->next))
            {
                table->adjust_size(-1);
                bucket = self->template from_offset<hash_bucket<MappedType>>(prev->next);
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
            while(prev)
            {
                if (prev->next == self->to_offset(bucket))
                {
                    table->adjust_size(-1);
                    prev->next = bucket->next;
                    bucket->clear();
                    break;
                }
                prev = self->template from_offset<hash_bucket<MappedType>>(prev->next);
            }
        }
        return bucket;
    }

    template<class Self, class MappedType>
    auto print(std::ostream& os, Self* self, hash_table<MappedType>* table) -> void
    {
        fmt::print(os, "size      : {}\n", table->size());
        fmt::print(os, "buckets   : {}\n", table->nbuckets());
        fmt::print(os, "collisions: {}\n", table->collisions());
        std::int32_t i = 0;
        for (auto& bucket : table->buckets())
        {
            if (not bucket.empty())
            {
                auto shdr = deref_key(self, &bucket);
                fmt::print("  bucket {} : {}", i, shdr);
                auto next = self->template from_offset<hash_bucket<MappedType>>(bucket.next);
                while (next)
                {
                    shdr = deref_key(self, next);
                    fmt::print(", {}", shdr);
                    next = self->template from_offset<hash_bucket<MappedType>>(next->next);
                }
            }
            ++i;
        }
    }

}   // namespace minecraft::nbt