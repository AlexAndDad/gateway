#pragma once

#include "minecraft/wise_enum.hpp"

namespace minecraft::protocol
{
    WISE_ENUM_CLASS((version_type, std::int32_t), (not_set, 0), (v1_11, 315), (v1_15_2, 578));
    WISE_ENUM_ENABLE_IO(version_type);

    constexpr bool verify(version_type x)
    {
        switch (x)
        {
        case version_type::not_set:
            return false;
        case version_type::v1_11:
        case version_type::v1_15_2:
            return true;
        }
        return false;
    }
}   // namespace minecraft