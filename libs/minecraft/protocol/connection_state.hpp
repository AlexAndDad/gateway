#pragma once

#include <wise_enum/wise_enum.h>

namespace minecraft::protocol
{
    WISE_ENUM_CLASS((connection_state, std::int32_t), (initial, 0), (status, 1), (login, 2))

    inline constexpr bool verify(connection_state x)
    {
        switch (x)
        {
        case connection_state::initial:
            return false;
        case connection_state::status:
        case connection_state::login:
            return true;
        }
        return false;
    }

    inline bool is_status(connection_state e) { return e == connection_state::status; }

    inline bool is_login(connection_state e) { return e == connection_state::login; }

}   // namespace minecraft::protocol