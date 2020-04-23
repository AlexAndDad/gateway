//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "minecraft/types.hpp"
#include "minecraft/parse_error.hpp"

#include <variant>

namespace minecraft::packets
{
    // DEPENDENCY: std::monostate muct be first as a default-constructed variant contains the first type in the list
    // using play_packet_variant = std::variant< std::monostate, client::keep_alive >;

    template < class PlayID, class PlayPacketVariant >
    struct play_packet
    {
        inline auto id() const -> PlayID;
        auto        as_variant() const -> PlayPacketVariant const & { return var_; }
        auto        as_variant() -> PlayPacketVariant & { return var_; }

      private:
        PlayPacketVariant var_;
    };

    template < class PlayID, class PlayPacketVariant >
    inline auto play_packet< PlayID, PlayPacketVariant >::id() const -> PlayID
    {
        return std::visit(
            [](auto &&pkt) {
                if constexpr (std::is_same_v< std::decay_t< decltype(pkt) >, std::monostate >)
                    return PlayID::invalid;
                else
                    return pkt.id();
            },
            as_variant());
    }

    template < class T >
    struct identity
    {
    };

    template < class... Ts >
    struct for_all_types_impl;

    template <>
    struct for_all_types_impl<>
    {
        template < class... Args >
        bool operator()(Args &&...) const
        {
            return false;
        };
    };

    template < class T, class... Rest >
    struct for_all_types_impl< T, Rest... >
    {
        template < class F, class... Args >
        bool operator()(F &&f, Args &&... args) const
        {
            return f(identity< T >(), args...) or for_all_types_impl< Rest... >()(f, args...);
        }
    };

    template < class F, class... Ts >
    bool for_all_types(F &&f, std::variant< Ts... > &var)
    {
        return for_all_types_impl< Ts... >()(f, var);
    }

    template < class PlayID, class PlayPacketVariant >
    const_buffer_iterator parse(const_buffer_iterator                     first,
                                const_buffer_iterator                     last,
                                play_packet< PlayID, PlayPacketVariant > &pkt,
                                error_code &                              ec)
    {
        auto res = first;
        if (not ec)
        {
            auto id    = var_enum< PlayID >();
            first      = parse(first, last, id, ec);
            auto found = for_all_types(
                [&]< class Type >(identity< Type >, PlayPacketVariant &var) {
                    if constexpr (std::is_same_v< Type, std::monostate >)
                        return false;
                    else if (Type::id() == id.value())
                    {
                        Type &actual = var.template emplace< Type >();
                        first        = parse(first, last, actual, ec);
                        return true;
                    }
                    else
                        return false;
                },
                pkt.as_variant());
            if (not ec and not found)
                ec = error::invalid_packet;
            if (not ec)
                res = first;
        }

        return res;
    }

    template < class PlayID, class PlayPacketVariant >
    void compose(play_packet< PlayID, PlayPacketVariant > const &pkt, compose_buffer &buf)
    {
        std::visit(
            [&buf]< class T >(T const &actual) {
            if constexpr (std::is_same_v< T, std::monostate >)
                assert(!"logic error - composing an empty packet");
            else
                compose(actual, buf);
        },
        pkt.as_variant());
    }

}   // namespace minecraft::packets