#pragma once

#include "minecraft/wise_enum.hpp"

namespace minecraft
{
    // not connected
    WISE_ENUM_CLASS((packet_id, std::int32_t), (client_handshake, 0));
    WISE_ENUM_ENABLE_IO(packet_id);


    // login state
    WISE_ENUM_CLASS((client_login_packet, std::int32_t), (login_start, 0), (encryption_response, 1))
    WISE_ENUM_ENABLE_IO(client_login_packet);

    WISE_ENUM_CLASS((server_login_packet, std::int32_t),
                    (disconnect, 0),
                    (encryption_request, 1),
                    (login_success, 2),
                    (set_compression, 3))
    WISE_ENUM_ENABLE_IO(server_login_packet);

}   // namespace minecraft