#pragma once

#include "minecraft/nbt/offset.hpp"
#include "minecraft/nbt/storage_provider.hpp"
#include "minecraft/nbt/string_service/string_header.hpp"
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

        auto empty() const -> bool { return not value; }

        auto clear() -> void
        {
            next.reset();
            value.reset();
        }

        storage_svc::ptr< hash_bucket_base > next;
        storage_svc::ptr< string_header >    value;
    };

    template < class MappedType >
    struct hash_bucket : hash_bucket_base
    {
        using value_type = std::tuple< storage_svc::ptr<string_header>, MappedType >;
        using hash_bucket_base::hash_bucket_base;
    };

    template <>
    struct hash_bucket< void > : hash_bucket_base
    {
        using hash_bucket_base::hash_bucket_base;
        using value_type = offset;
    };

    auto deref_key(storage_provider *self, hash_bucket< void > *pbucket) -> string_header *;

    template < class MappedType >
    auto link(storage_provider *self, hash_bucket< MappedType > *parent, hash_bucket< MappedType > *bucket)
        -> hash_bucket< MappedType > *;

    template < class MappedType, class... Args >
    auto new_bucket(storage_provider *self, Args &&... args) -> hash_bucket< MappedType > *;

    template < class MappedType >
    auto new_bucket(storage_provider *self, string_header *key) -> hash_bucket< MappedType > *;

    template < class MappedType >
    auto unlink(storage_provider *self, hash_bucket< MappedType > *parent) -> hash_bucket< MappedType > *;

}   // namespace minecraft::nbt

#include "string_bucket.ipp"
