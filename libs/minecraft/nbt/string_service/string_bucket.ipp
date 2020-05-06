#pragma once
#include "string_bucket.hpp"
#include "string_header.hpp"

#include <cassert>
#include <minecraft/nbt/free_block.hpp>

namespace minecraft::nbt
{
    template < class Self >
    auto deref_key(Self *self, hash_bucket< void > *pbucket) -> string_header *
    {
        assert(pbucket);
        assert(not pbucket->empty());
        return self->template from_offset< string_header >(pbucket->value);
    }

    template < class MappedType, class Self >
    auto new_bucket(Self *self, string_header *key) -> hash_bucket< MappedType > *
    {
        auto size    = sizeof(hash_bucket< MappedType >);
        auto blocks  = size_to_blocks(size);
        auto pv      = self->alloc(blocks);
        auto pbucket = new (pv) hash_bucket< MappedType >(self->to_offset(key));
        return pbucket;
    }

}   // namespace minecraft::nbt