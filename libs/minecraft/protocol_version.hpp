#pragma once

#include <wise_enum/wise_enum.h>

namespace minecraft
{
    WISE_ENUM((protocol_version_type, std::int32_t), (v1_15_2, 578));

    constexpr bool verify(protocol_version_type x)
    {
        for (auto nv : wise_enum::range<protocol_version_type>)
        {
            if(nv.value == x)
                return true;
        }
        return false;
    }
}