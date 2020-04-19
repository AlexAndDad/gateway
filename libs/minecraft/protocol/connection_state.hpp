#pragma once

#include <wise_enum/wise_enum.h>

namespace minecraft::protocol
{
    WISE_ENUM_CLASS((connection_state, std::int32_t), (initial, 0), (status, 1), (login, 2))
}