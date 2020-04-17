#pragma once

#include <wise_enum/wise_enum.h>

namespace minecraft
{
    // not connected
    WISE_ENUM_CLASS((packet_id, std::int32_t), (client_handshake, 0));

    // login state
    WISE_ENUM_CLASS((client_login_packet, std::int32_t), (login_start, 0), (encryption_response, 1))

    WISE_ENUM_CLASS((server_login_packet, std::int32_t),
                    (disconnect, 0),
                    (encryption_request, 1),
                    (login_success, 2),
                    (set_compression, 3))

    WISE_ENUM_CLASS((client_state, std::int32_t), (initial, 0), (status, 1), (login, 2))

}   // namespace minecraft