#pragma once
#include "storage_provider.hpp"

namespace minecraft::nbt
{
    template<class Derived>
    auto hash_table_service<Derived>::construct_hash_table(int32_t buckets) -> hash_table *
    {
        return new (self()->alloc(size_to_blocks(hash_table::extent(buckets)))) hash_table(buckets);
    }

    template<class Derived>
    std::int32_t *hash_table_service<Derived>::reverse_lookup(hash_table *ht, std::uint32_t hash, offset id)
    {
        auto bucket = ht->at(hash);

        while (bucket)
        {
            for (auto &soffset : bucket->locations)
                if (soffset == id)
                    return &soffset;
            bucket = self()->template from_offset< hash_bucket >(bucket->next_bucket);
        }
        return nullptr;
    }

    template<class Derived>
    auto hash_table_service<Derived>::find_empty_slot(hash_table *ht, std::uint32_t hash) -> offset *
    {
        for (auto hb = ht->at(hash); hb; hb = self()-> template from_offset< hash_bucket >(hb->next_bucket))
        {
            for (auto &entry : hb->locations)
                if (entry == -1)
                    return &entry;
        }
        return nullptr;
    }



}