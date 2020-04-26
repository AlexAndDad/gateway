#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/parse_error.hpp"
#include "minecraft/types.hpp"
#include "play_id.hpp"

#include <limits>
#include <ostream>
#include <random>
#include "minecraft/packets/packet_base.hpp"

namespace minecraft::packets::server
{
    struct keep_alive : packet_base<play_id::keep_alive, keep_alive>
    {
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

        template < class Self >
        static auto as_nvps(Self &self) { return nvp_set(nvp("keep_alive_id", self.keep_alive_id)); }

        std::int64_t keep_alive_id;
    };


}   // namespace minecraft::packets::server