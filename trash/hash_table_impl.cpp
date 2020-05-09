#include "hash_table_impl.hpp"

namespace minecraft::nbt
{
    auto hash_table_base::estimate_bucket_count(std::int32_t entries) -> std::int32_t
    {
        if (entries < 2)
            return 1;

        auto next_prime = [](std::int32_t n) {
            static const std::int32_t primes[] = {
                5,        11,       17,       29,        37,        53,        67,        79,        97,      131,
                193,      257,      389,      521,       769,       1031,      1543,      2053,      3079,    6151,
                12289,    24593,    49157,    98317,     196613,    393241,    786433,    1572869,   3145739, 6291469,
                12582917, 25165843, 50331653, 100663319, 201326611, 402653189, 805306457, 1610612741
            };

            const auto first = primes;
            const auto last  = primes + std::extent_v< decltype(primes) >;
            auto       bound = std::lower_bound(first, last, n);
            if (bound == last)
                return std::numeric_limits< std::int32_t >::max();
            else
                return *bound;
        };

        return next_prime((entries * 3) / 2);
    }

}   // namespace minecraft::nbt