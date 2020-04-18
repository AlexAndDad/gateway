#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/net.hpp"
#include "minecraft/packet_id.hpp"
#include <fmt/ostream.h>
#include "minecraft/multibyte.hpp"
#include "minecraft/report.hpp"

namespace minecraft::server
{
    struct login_success
    {
        static auto constexpr id() { return server_login_packet::login_success; }

        varchar< 36 > uuid;
        varchar< 16 > username;

        template < class Stream >
        friend auto operator<<(Stream &os, login_success const &packet) -> Stream &;

        template < class Iter >
        friend Iter parse(Iter first, Iter last, login_success &target, error_code &ec)
        {
            auto current = parse(first, last, target.uuid, ec);
            if (not ec.failed())
                current = parse(current, last, target.username, ec);
            return ec.failed() ? first : current;
        }
    };

}

namespace minecraft::server
{
    template < class Stream >
    auto operator<<(Stream &os, login_success const &packet) -> Stream &
    {
        fmt::print(os,
                   "[frame [type {}] [uuid {}] [username {}]",
                   wise_enum::to_string(packet.id()),
                   packet.uuid,
                   packet.username);
        return os;
    }

    inline void compose(login_success const &packet, std::vector< char > &target)
    {
        auto i1 = std::back_inserter(target);
        i1      = encode(variable_length(packet.id()), i1);
        i1      = encode(packet.uuid, i1);
        encode(packet.username, i1);
    }

    template < class Container >
    inline void encode(login_success const &packet, Container &target)
    {
        using minecraft::encode;
        thread_local static std::vector< char > buf;
        buf.clear();
        compose(packet, buf);
        return encode_to_container(buf, target);
    }

}   // namespace minecraft::server