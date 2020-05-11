#pragma once

#include "entities/entity.hpp"
#include "minecraft/blocks/blocks.hpp"

namespace minecraft::chunk
{
    struct chunk_section

        struct chunk
    {
        std::int32_t                    x_;
        std::int32_t                    z_;
        std::vector< std::int32_t >     biomes;
        std::array< chunk_section, 16 > sections_;
        std::vector< entities::entity > entities_;
    };
}   // namespace minecraft::chunk