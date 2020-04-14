#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/packet_id.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/protocol_version.hpp"
#include "minecraft/types.hpp"

namespace minecraft::client
{
    struct handshake
    {
        static constexpr auto             id() { return packet_id::client_handshake; }
        var_enum< protocol_version_type > protocol_version =
            var_enum< protocol_version_type >(protocol_version_type::v1_15_2);
        varchar< 255 >           server_address;
        std::uint16_t            server_port;
        var_enum< client_state > next_state = var_enum< client_state >(client_state::login);

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

    template < class Container >
    void encode(handshake const &arg, Container &target)
    {
        using minecraft::encode;
        thread_local static std::vector< std::uint8_t > buf;
        buf.clear();
        auto i1 = std::back_inserter(buf);
        i1      = encode(variable_length(arg.id()), i1);
        i1      = encode(arg.protocol_version, i1);
        i1      = encode(arg.server_address, i1);
        i1      = encode(arg.server_port, i1);
        i1      = encode(arg.next_state, i1);

        return encode_to_container(buf, target);
    }

    inline
    std::size_t compose(handshake const &arg, std::vector< char > &target)
    {
        using minecraft::encode;
        auto original_size = target.size();
        auto i1 = std::back_inserter(target);
        i1      = encode(variable_length(arg.id()), i1);
        i1      = encode(arg.protocol_version, i1);
        i1      = encode(arg.server_address, i1);
        i1      = encode(arg.server_port, i1);
        i1      = encode(arg.next_state, i1);
        return target.size() - original_size;

    }

}   // namespace minecraft::client