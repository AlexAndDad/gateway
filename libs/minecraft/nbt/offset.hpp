#pragma once
#include <cstdint>

namespace minecraft::nbt
{
    using offset = std::int32_t;

    static constexpr auto invalid_offset(offset o) -> bool
    {
        return o < 0;
    }

    static constexpr auto invalid_offset() -> offset
    {
        return -1;
    }
}
