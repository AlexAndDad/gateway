#include "hash_table_service.hpp"
#include <boost/functional/hash.hpp>

namespace minecraft::nbt
{
    std::uint32_t hash_table_service_base::hash(std::string_view s) const
    {
        // for now, use a naiive hashing function. We can improve it later
        std::size_t seed = 0;
        boost::hash_combine(seed, hash_poison_);
        boost::hash_range(seed, s.begin(), s.end());
        return static_cast< std::uint32_t >(seed);
    }



}