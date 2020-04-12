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

}