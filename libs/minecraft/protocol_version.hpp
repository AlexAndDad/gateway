#pragma once

#include <wise_enum/wise_enum.h>

namespace minecraft
{
    WISE_ENUM_CLASS((protocol_version_type, std::int32_t), (not_set, 0), (v1_11, 315), (v1_15_2, 578));

    constexpr bool verify(protocol_version_type x)
    {
        switch (x)
        {
        case protocol_version_type::not_set:
            return false;
        case protocol_version_type::v1_11:
        case protocol_version_type::v1_15_2:
            return true;
        }
        return false;
    }
}   // namespace minecraft