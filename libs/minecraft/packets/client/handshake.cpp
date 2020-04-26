#include "handshake.hpp"

namespace minecraft::packets::client
{
    error_code &handshake::validate(error_code &ec) const
    {
        if (not verify(protocol_version))
            ec = error::invalid_protocol;
        else if (not verify(next_state))
            ec = error::invalid_packet;
        return ec;
    }

    auto verify(handshake const &packet, error_code &ec) -> error_code &
    {
        packet.validate(ec);
        return ec;
    }

}   // namespace minecraft::packets::client