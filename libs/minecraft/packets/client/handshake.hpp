#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/packet_id.hpp"
#include "minecraft/packets/packet_base.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/protocol/connection_state.hpp"
#include "minecraft/protocol/version.hpp"
#include "minecraft/types.hpp"

namespace minecraft::packets::client
{
    struct handshake : packet_base< packet_id::client_handshake, handshake >
    {
        var_enum< protocol::version_type >     protocol_version;
        varchar< 255 >                         server_address;
        std::uint16_t                          server_port;
        var_enum< protocol::connection_state > next_state;

        error_code &validate(error_code &ec) const;

        template < class Self >
        static auto as_nvps(Self &self)
        {
            return nvp_set(nvp("protocol_version", self.protocol_version),
                           nvp("server_address", self.server_address),
                           nvp("server_port", self.server_port),
                           nvp("next_state", self.next_state));
        }

        friend auto verify(handshake const &packet, error_code &ec) -> error_code &;
    };
}   // namespace minecraft::packets::client