//
// Created by rhodges on 12/04/2020.
//

#pragma once

#include "minecraft/parse.hpp"

#include <iostream>
#include <minecraft/packet_id.hpp>
#include <minecraft/security/private_key.hpp>

namespace minecraft::client
{
    struct encryption_response
    {
        static constexpr auto id() { return client_login_packet ::encryption_response; }

        std::vector< std::uint8_t > shared_secret;
        std::vector< std::uint8_t > verify_token;

        template < class Iter >
        friend auto parse(Iter first, Iter last, encryption_response &arg) -> Iter;

        friend auto                 operator<<(std::ostream &os, encryption_response const &arg) -> std::ostream &;
        friend auto                 report_on(std::ostream &os, encryption_response const &arg) -> void;
        std::vector< std::uint8_t > decrypt_secret(minecraft::security::private_key const &server_key,
                                                   std::vector< std::uint8_t > const &     original_verify_token,
                                                   error_code &                            ec) const;
    };

    template < class Iter >
    auto parse(Iter first, Iter last, encryption_response &arg) -> Iter
    {
        using minecraft::parse;
        first = parse(first, last, arg.shared_secret);
        first = parse(first, last, arg.verify_token);
        return first;
    }

    template < class Iter >
    auto parse(Iter first, Iter last, encryption_response &arg, error_code &ec) -> std::size_t
    {
        std::size_t n = 0;
        try
        {
            using minecraft::parse;
            auto i = parse(first, last, arg.shared_secret);
            i      = parse(i, last, arg.verify_token);
            if (i != last)
                ec = error::invalid_packet;
            if (not ec.failed())
                n = std::distance(first, i);
        }
        catch (incomplete)
        {
            ec = error::incomplete_parse;
        }
        catch (error_code &e)
        {
            ec = e;
        }
        return n;
    }

}   // namespace minecraft::client