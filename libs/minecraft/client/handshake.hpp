#pragma once

#include "minecraft/packet_id.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/protocol_version.hpp"
#include "minecraft/types.hpp"

namespace minecraft::client
{
    struct handshake
    {
        static constexpr auto             id() { return packet_id::client_handshake; }
        var_enum< protocol_version_type > protocol_version;
        varchar< 255 >                    server_address;
        std::uint16_t                     server_port;
        var_enum< client_state >          next_state;

        error_code &validate(error_code &ec) const;

        friend void          report_on(std::ostream &os, handshake const &);
        friend std::ostream &operator<<(std::ostream &os, handshake const &arg);

        template < class Iter >
        friend auto parse(Iter first, Iter last, handshake &target, error_code &ec) -> Iter
        {
            using minecraft::parse;
            auto current =
                parse(first,
                      last,
                      std::tie(target.protocol_version, target.server_address, target.server_port, target.next_state),
                      ec);
            if (!ec.failed() && current != last)
                ec = error::invalid_packet;
            if (ec.failed())
            {
                return first;
            }
            return current;
        }
    };

}   // namespace minecraft::client