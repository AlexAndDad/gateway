#pragma once

#include "minecraft/packet_id.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/protocol_version.hpp"

namespace minecraft::client
{
    struct handshake
    {
        static constexpr auto id() { return packet_id::client_handshake; }
        protocol_version_type protocol_version;
        std::string           server_address;
        std::uint16_t         server_port;
        client_state          next_state;

        error_code &validate(error_code &ec) const;

        friend void          report_on(std::ostream &os, handshake const &);
        friend std::ostream &operator<<(std::ostream &os, handshake const &arg);

        template < class Iter >
        friend auto parse(Iter first, Iter last, handshake &target) -> Iter;

        template < class Iter >
        friend auto parse(Iter first, Iter last, handshake &target, error_code &ec) -> std::size_t;
    };

    template < class Iter >
    auto parse(Iter first, Iter last, handshake &target) -> Iter
    {
        using minecraft::parse;
        first = parse(first, last, target.protocol_version);
        first = parse(first, last, target.server_address, 255);
        first = parse(first, last, target.server_port);
        first = parse(first, last, target.next_state);
        return first;
    }

    template < class Iter >
    auto parse(Iter first, Iter last, handshake &target, error_code &ec) -> std::size_t
    {
        using minecraft::parse;
        ec.clear();
        try
        {
            auto current = parse(first, last, target.protocol_version);
            current      = parse(current, last, target.server_address, 255);
            current      = parse(current, last, target.server_port);
            current      = parse(current, last, target.next_state);
            if (current != last)
                ec = error::invalid_packet;
            return std::distance(first, current);
        }
        catch (incomplete)
        {
            ec = error::incomplete_parse;
            return 0;
        }
        catch (error_code &err)
        {
            ec = err;
            return 0;
        }
        catch (system_error &e)
        {
            ec = e.code();
            return 0;
        }
    }

}   // namespace minecraft::client