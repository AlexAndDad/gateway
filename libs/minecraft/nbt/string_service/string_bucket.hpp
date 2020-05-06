#pragma once

#include "minecraft/nbt/offset.hpp"
#include "string_header.hpp"

namespace minecraft::nbt
{
    struct hash_bucket_base
    {
        hash_bucket_base();

        explicit hash_bucket_base(offset value);

        // moves are destructive to the source
        hash_bucket_base(hash_bucket_base &&other) noexcept;

        hash_bucket_base &operator=(hash_bucket_base &&other) noexcept;

        auto empty() const -> bool { return invalid_offset(value); }

        auto clear() -> void
        {
            next = invalid_offset();
            value = invalid_offset();
        }

        offset next;   // position of the next bucket in case of a collision
        offset value;
    };

    template<class MappedType>
    struct hash_bucket : hash_bucket_base
    {
        using value_type = std::tuple<offset, MappedType>;
        using hash_bucket_base::hash_bucket_base;
    };


    template<>
    struct hash_bucket<void> : hash_bucket_base
    {
        using hash_bucket_base::hash_bucket_base;
        using value_type = offset;
    };

    template<class Self>
    auto deref_key(Self*self, hash_bucket<void>* pbucket) -> string_header*;

    template<class MappedType, class Self>
    auto new_bucket(Self* self, string_header* key) -> hash_bucket<MappedType>*;


}   // namespace minecraft::nbt

#include "string_bucket.ipp"
