#pragma once

#include <wise_enum.h>

namespace minecraft
{
    WISE_ENUM_CLASS((packet_id, std::int32_t), (client_handshake, 0));
    WISE_ENUM_CLASS((login_packet_id, std::int32_t), (login_start, 0), (encryption_request, 1));

    WISE_ENUM_CLASS((client_state, std::int32_t), (initial, 0), (status, 1), (login, 2));

}