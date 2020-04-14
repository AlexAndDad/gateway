#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/packet_id.hpp"
#include "minecraft/net.hpp"

namespace minecraft::server
{
    struct login_success
    {
        static auto constexpr id() { return server_login_packet::login_success; }

        varchar< 36 > uuid;
        varchar< 16 > username;

        friend std::ostream &operator<<(std::ostream &os, login_success const &arg);

        template < class Iter >
        friend Iter parse(Iter first, Iter last, login_success &target, error_code &ec)
        {
            auto current = parse(first, last, target.uuid, ec);
            if (not ec.failed())
                current = parse(current, last, target.username, ec);
            return ec.failed() ? first : current;
        }
    };

    template < class Container >
    inline void encode(login_success const &packet, Container &target)
    {
        using minecraft::encode;
        thread_local static std::vector< std::uint8_t > buf;
        buf.clear();
        auto i1 = std::back_inserter(buf);
        i1      = encode(variable_length(packet.id()), i1);
        i1      = encode(packet.uuid, i1);
        encode(packet.username, i1);

        return encode_to_container(buf, target);
    }

}   // namespace minecraft::server