#include "minecraft/client/handshake.hpp"

namespace minecraft::client
{
    void report_on(std::ostream &os, handshake const &ch)
    {
        os << "client handshake : "
              "protocol version="
           << wise_enum::to_string(ch.protocol_version) << " : server_address=" << ch.server_address << " : server_port=" << ch.server_port
           << " : next_state=" << wise_enum::to_string(ch.next_state);
    }

    std::ostream &operator<<(std::ostream &os, handshake const &arg)
    {
        report_on(os, arg);
        return os;
    }

    error_code &handshake::validate(error_code &ec) const
    {
        if (not verify(protocol_version))
            ec = error::invalid_protocol;
        else if (next_state != client_state::login)
            ec = error::invalid_packet;
        return ec;
    }

}   // namespace minecraft::client