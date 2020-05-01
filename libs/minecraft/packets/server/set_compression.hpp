//
// Created by rhodges on 17/04/2020.
//

#pragma once

#include "minecraft/packet_id.hpp"
#include "minecraft/types/var.hpp"

#include <fmt/format.h>
#include <fmt/ostream.h>

namespace minecraft::packets::server
{
    struct set_compression
    {
        static constexpr auto id() { return server_login_packet::set_compression; }
        var_int               threshold;
    };

    auto compose(set_compression const &packet, std::vector< char > &buffer) -> void;

    template<class Stream>
    auto operator<<(Stream& os, set_compression const& packet) -> Stream&;

    template < class Iter >
    auto parse(Iter first, Iter last, set_compression &packet, error_code &ec) -> Iter;

}   // namespace minecraft::packets::server

namespace minecraft::packets::server
{
    template < class Iter >
    Iter parse(Iter first, Iter last, set_compression &packet, error_code &ec)
    {
        using minecraft::parse;
        auto next = parse(first, last, packet.threshold, ec);
        return ec.failed() ? first : next;
    }

    template<class Stream>
    auto operator<<(Stream& os, set_compression const& packet) -> Stream&
    {
        fmt::print(os, "[frame [type {}] [threshold {}]", wise_enum::to_string(packet.id()), packet.threshold.value());
        return os;
    }

}   // namespace minecraft::packets::server
