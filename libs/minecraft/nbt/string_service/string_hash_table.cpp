#include "string_hash_table.ipp"

#include "minecraft/nbt/impl.hpp"
#include <algorithm>
#include <type_traits>

namespace minecraft::nbt
{
    hash_table< void >::hash_table(std::int32_t nbuckets)
    : collisions_(0)
    , size_(0)
    , nbuckets_(nbuckets)
    {
        for (auto &bucket : buckets())
            new (&bucket) bucket_type();
    }

    auto hash_table< void >::adjust_size(std::int32_t delta) -> std::int32_t
    {
        size_ += delta;
        assert(size_ >= 0);
        return size_;
    }

    auto hash_table< void >::adjust_collisions(std::int32_t delta) -> std::int32_t
    {
        collisions_ += delta;
        assert(collisions_ >= 0);
        return collisions_;
    }

    auto next_prime(std::int32_t n) -> std::int32_t
    {
        // Taken from Boost.Intrusive and Boost.MultiIndex code,
        // thanks to Ion Gaztanaga and Joaquin M Lopez Munoz.
        static std::int32_t constexpr list[] = {
            0,        3,        7,        11,        17,        29,        53,        97,
            193,      389,      769,      1543,      3079,      6151,      12289,     24593,
            49157,    98317,    196613,   393241,    786433,    1572869,   3145739,   6291469,
            12582917, 25165843, 50331653, 100663319, 201326611, 402653189, 805306457, 1610612741,
        };
        return *std::lower_bound(&list[0], &list[std::extent_v< decltype(list) >], n);
    };

}   // namespace minecraft::nbt