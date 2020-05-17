#pragma once
#include "blocks/block.hpp"
#include "types.hpp"

namespace minecraft::chunks
{
    struct block_update
    {
        vector3            pos;
        blocks::block_type new_state;
    };

}   // namespace minecraft::chunks