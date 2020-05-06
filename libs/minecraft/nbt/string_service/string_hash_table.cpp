#include "string_hash_table.ipp"

#include "minecraft/nbt/impl.hpp"

namespace minecraft::nbt
{
    hash_table< void >::hash_table(std::int32_t nbuckets)
    : collisions_(0)
    , size_(0)
    , nbuckets_(nbuckets)
    {
        for (auto &bucket : buckets())
            new (&bucket) bucket_type ();
    }

    auto hash_table<void>::adjust_size(std::int32_t delta) -> std::int32_t
    {
        size_ += delta;
        assert(size_ >= 0);
        return size_;
    }

    auto hash_table<void>::adjust_collisions(std::int32_t delta) -> std::int32_t
    {
        collisions_ += delta;
        assert(collisions_ >= 0);
        return collisions_;
    }



}   // namespace minecraft::nbt