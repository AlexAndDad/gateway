//
// Created by ahodges on 26/05/2020.
//

#pragma once

#include "minecraft/wise_enum.hpp"

namespace minecraft
{
    struct dimension
    {
        WISE_ENUM_MEMBER((dimension_type, std::int32_t), (nether, -1), (overworld, 0), (end, 1))
        WISE_ENUM_MEMBER_ENABLE_IO(dimension_type)
    };
}