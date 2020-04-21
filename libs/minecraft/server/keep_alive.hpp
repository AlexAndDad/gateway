#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/server/play_id.hpp"

#include <limits>
#include <ostream>
#include <random>

namespace minecraft::server
{
    struct keep_alive
    {
        static constexpr auto id() { return play_id::keep_alive; }

        void prepare()
        {
            static thread_local auto [eng, dist] = [] {
                auto rng  = std::random_device();
                auto seq  = std::seed_seq { rng(), rng(), rng(), rng(), rng() };
                auto eng  = std::default_random_engine(seq);
                auto dist = std::uniform_int_distribution< std::int64_t >(std::numeric_limits< std::int64_t >::min(),
                                                                          std::numeric_limits< std::int64_t >::max());
                return std::tuple(eng, dist);
            }();

            keep_alive_id = dist(eng);
        }

        std::int64_t keep_alive_id;
    };

    std::ostream &operator<<(std::ostream &os, keep_alive const &arg);
    void          compose(keep_alive const &arg, std::vector< char > &target);

}   // namespace minecraft::server