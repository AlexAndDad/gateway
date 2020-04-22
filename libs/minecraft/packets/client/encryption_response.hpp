//
// Created by rhodges on 12/04/2020.
//

#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/packet_id.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/protocol/shared_secret.hpp"
#include "minecraft/security/private_key.hpp"

#include <iostream>

namespace minecraft::packets::client
{
    struct encryption_response
    {
        static constexpr auto id() { return client_login_packet ::encryption_response; }

        std::vector< std::uint8_t > shared_secret;
        std::vector< std::uint8_t > verify_token;

        template < class Iter >
        friend auto parse(Iter first, Iter last, encryption_response &arg) -> Iter;

        friend auto             operator<<(std::ostream &os, encryption_response const &arg) -> std::ostream &;
        friend auto             report_on(std::ostream &os, encryption_response const &arg) -> void;
        protocol::shared_secret decrypt_secret(minecraft::security::private_key const &server_key,
                                               std::vector< std::uint8_t > const &     original_verify_token,
                                               error_code &                            ec) const;
    };

    inline void compose(encryption_response const &packet, std::vector< char > &buffer)
    {
        using minecraft::encode;
        auto iter = back_inserter(buffer);
        iter      = encode(variable_length(packet.id()), iter);
        iter      = encode(packet.shared_secret, iter);
        encode(packet.verify_token, iter);
    }

    template < class Iter >
    auto parse(Iter first, Iter last, encryption_response &arg, error_code &ec) -> Iter
    {
        using minecraft::parse;
        auto current = parse(first, last, std::tie(arg.shared_secret, arg.verify_token), ec);
        if (not ec.failed() and current != last)
            ec = error::invalid_packet;
        return ec.failed() ? first : current;
    }

}   // namespace minecraft::packets::client