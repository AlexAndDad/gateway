#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/net.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/security/private_key.hpp"

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

namespace minecraft::server
{
    struct encryption_request
    {
        static constexpr auto       id() -> server_login_packet { return server_login_packet::encryption_request; }
        varchar< 20 >               server_id;
        std::vector< std::uint8_t > public_key;
        std::vector< std::uint8_t > verify_token;

        friend std::ostream &operator<<(std::ostream &os, encryption_request const &arg);

        friend void prepare(encryption_request &req, minecraft::security::private_key const &ppk);

        template < class Self >
        static auto as_tuple(Self &self)
        {
            return std::tie(self.server_id, self.public_key, self.verify_token);
        }
    };

    inline void compose(encryption_request const &packet, std::vector< char > &compose_buffer)
    {
        auto i1 = std::back_inserter(compose_buffer);
        i1      = encode(variable_length(packet.id()), i1);
        i1      = encode(packet.server_id, i1);
        i1      = encode(packet.public_key, i1);
        encode(packet.verify_token, i1);
    }

    template < class Iter >
    Iter encode(encryption_request const &packet, Iter first)
    {
        using minecraft::encode;
        thread_local static std::vector< char > buf;
        buf.clear();
        compose(packet, buf);
        return encode(buf, first);
    }

    template < class Iter >
    Iter parse(Iter first, Iter last, encryption_request &packet, error_code &ec)
    {
        using minecraft::parse;

        auto current = parse(first, last, encryption_request::as_tuple(packet), ec);
        if (not ec.failed() and current != last)
            ec = error::invalid_packet;
        return current;
    }

}   // namespace minecraft::server