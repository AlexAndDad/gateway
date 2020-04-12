#pragma once

#include "minecraft/parse.hpp"
#include "minecraft/packet_id.hpp"

namespace minecraft::client
{
    struct handshake
    {
        std::int32_t protocol_version;
        std::string server_address;
        std::uint16_t server_port;
        client_state next_state;

        friend void
        report_on(std::ostream &os, handshake const &);

        template<class Iter>
        friend auto
        parse(Iter first, Iter last, handshake &target) -> Iter;
    };

    template<class Iter>
    auto
    parse(Iter first, Iter last, handshake &target) -> Iter
    {
        using minecraft::parse;
        first = parse(first, last, target.protocol_version);
        first = parse(first, last, target.server_address, 255);
        first = parse(first, last, target.server_port);
        first = parse(first, last, target.next_state);
        return first;
    }

}