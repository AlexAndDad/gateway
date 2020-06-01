#pragma once

#include "block_update.hpp"
#include <deque>
#include <cstdint>

namespace minecraft::chunks
{
    struct chunk_service_traits
    {
        using sequence_number = std::uint64_t;
        using update_sequence = std::deque< block_update >;
    };

}