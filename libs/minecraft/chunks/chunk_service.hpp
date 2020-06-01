#pragma once
#include "chunk_section_impl.hpp"
#include "minecraft/net.hpp"
#include "minecraft/variant.hpp"
#include "polyfill/async/async_task.hpp"
#include "types.hpp"

#include <forward_list>

namespace minecraft::chunks
{
    // One created per world.
    // Currently, it holds the canonical mutable view of the world.
    // Map views use this to construct subscriptions and views of the world
    struct chunk_service
    {

    };

}   // namespace minecraft::chunks