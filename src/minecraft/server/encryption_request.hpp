#pragma once

#include "minecraft/encode.hpp"
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
        std::string                 server_id;
        std::vector< std::uint8_t > public_key;
        std::vector< std::uint8_t > verify_token;

        friend std::ostream &operator<<(std::ostream &os, encryption_request const &arg);

        friend void prepare(encryption_request &req, minecraft::security::private_key const &ppk);
    };

    template < class Iter >
    inline Iter encode(encryption_request const &packet, Iter first)
    {
        using minecraft::encode;
        thread_local static std::vector< std::uint8_t > buf;
        buf.clear();
        auto i1 = std::back_inserter(buf);
        i1      = encode(packet.id(), i1);
        i1      = encode(packet.server_id, i1);
        i1      = encode(packet.public_key, i1);
        i1      = encode(packet.verify_token, i1);

        return encode(buf, first);
    }

}   // namespace minecraft::server