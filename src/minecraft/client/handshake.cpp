#include "minecraft/client/handshake.hpp"

namespace minecraft::client
{

    void report_on(std::ostream& os, handshake const& ch)
    {
        os << "client handshake : "
              "protocol version=" << ch.protocol_version
           << " : server_address=" << ch.server_address
           << " : server_port=" << ch.server_port
           << " : next_state=" << wise_enum::to_string(ch.next_state);
    }

    error_code& handshake::validate(error_code& ec) const
    {
        if (protocol_version != 200)
            ec = error::invalid_protocol;
        if (next_state != client_state::login)
            ec = error::invalid_packet;
        return ec;
    }

}