#pragma once
#include "string_bucket.hpp"
#include "string_header.hpp"

#include <cassert>
#include <minecraft/nbt/free_block.hpp>

namespace minecraft::nbt
{

    template<class MappedType>
    auto link(storage_provider* self, hash_bucket<MappedType>* parent, hash_bucket<MappedType>* bucket)-> hash_bucket<MappedType>*
    {
        assert(invalid_offset(bucket->next));
        bucket->next = parent->next;
        parent->next = self->to_offset(bucket);
        return bucket;
    }

    template < class MappedType >
    auto new_bucket(storage_provider *self, string_header *key) -> hash_bucket< MappedType > *
    {
        return new_bucket<MappedType>(self, self->to_offset(key));
    }

    template < class MappedType, class...Args >
    auto new_bucket(storage_provider *self, Args&&...args) -> hash_bucket< MappedType > *
    {
        auto size    = sizeof(hash_bucket< MappedType >);
        auto blocks  = size_to_blocks(size);
        auto pv      = self->alloc(blocks);
        auto pbucket = new (pv) hash_bucket< MappedType >(std::forward<Args>(args)...);
        return pbucket;
    }

    template<class MappedType>
    auto unlink(storage_provider* self, hash_bucket<MappedType>* parent) -> hash_bucket<MappedType>*
    {
        assert(parent);
        hash_bucket<MappedType>* result = self->template from_offset<hash_bucket<MappedType>>(parent->next);
        if (result)
        {
            parent->next = std::exchange(result->next, invalid_offset());
            assert(invalid_offset(result->next));
        }

        return result;
    }


}   // namespace minecraft::nbt