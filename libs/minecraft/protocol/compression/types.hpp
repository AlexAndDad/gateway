#pragma once
#include <zlib.h>
#include "minecraft/net.hpp"

namespace minecraft::protocol::compression
{
    using input_buffer = net::const_buffer;
    using output_buffer = net::mutable_buffer;

}   // namespace minecraft::protocol::compression