#pragma once
#include "blocks/block.hpp"
#include "minecraft/overloaded.hpp"

namespace minecraft::blocks
{
    inline
    bool is_transparent(block_id_type id)
    {
        return visit_block_id(overloaded { [](air) { return true; },
                                           [](void_air) { return true; },
                                           [](cave_air) { return true; },
                                           [](auto) { return false; } },
                              id);
    }
}   // namespace minecraft::blocks
