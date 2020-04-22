//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "minecraft/packets/client/keep_alive.hpp"
#include "minecraft/packets/client/play_id.hpp"
#include "minecraft/types.hpp"

#include <variant>

namespace minecraft::packets::client
{
    // DEPENDENCY: std::monostate muct be first as a default-constructed variant contains the first type in the list
    using play_packet_variant = std::variant< std::monostate, keep_alive >;

    struct play_packet
    {
        inline auto id() const -> play_id;
        auto        as_variant() const -> play_packet_variant const & { return var_; }
        auto        as_variant() -> play_packet_variant & { return var_; }

      private:
        play_packet_variant var_;
    };

    inline auto play_packet::id() const -> play_id
    {
        return std::visit(
            [](auto &&pkt) {
                if constexpr (std::is_same_v< std::decay_t< decltype(pkt) >, std::monostate >)
                    return play_id::invalid;
                else
                    return pkt.id();
            },
            as_variant());
    }

    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, play_packet& pkt, error_code& ec);

}   // namespace minecraft::packets::client