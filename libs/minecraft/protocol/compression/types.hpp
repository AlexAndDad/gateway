#pragma once
#include <zlib.h>
#include "minecraft/net.hpp"

namespace minecraft::protocol::compression
{
#ifdef ZLIB_CONST
    using input_buffer = net::const_buffer;
#else
    using input_buffer = net::mutable_buffer;
#endif

    using output_buffer = net::mutable_buffer;

}   // namespace minecraft::protocol::compression