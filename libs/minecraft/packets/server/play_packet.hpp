#pragma once

#include "chat_message.hpp"
#include "player_position_and_look.hpp"
#include "spawn_position.hpp"

#include <variant>

namespace minecraft::packets::server
{
    using play_packet_variant = std::variant< std::monostate, chat_message, player_position_and_look, spawn_position >;

    struct play_packet
    {
        explicit play_packet()
        : variant_()
        {
        }

        play_id id() const
        {
            auto visitor = [](auto &&actual) {
                if constexpr (std::is_same_v< std::decay_t< decltype(actual) >, std::monostate >)
                {
                    assert(!"id of empty packet");
                    return static_cast< play_id >(-1);
                }
                else
                {
                    return actual.id();
                }
            };

            return std::visit(visitor, as_variant());
        }

        template < class Packet >
        Packet &construct()
        {
            variant_.emplace< Packet >();
            return std::get< Packet >(variant_);
        }

        auto as_variant() -> play_packet_variant & { return variant_; }

        auto as_variant() const -> play_packet_variant const & { return variant_; }

        template < class Stream >
        friend Stream &operator<<(Stream &os, play_packet const &arg)
        {
            auto visitor = [&os](auto &&actual) {
                if constexpr (std::is_same_v< std::monostate, std::decay_t< decltype(actual) > >)
                    os << "empty";
                else
                    os << actual;
            };

            std::visit(visitor, arg.as_variant());
            return os;
        }

        play_packet_variant variant_;
    };

    inline void compose(play_packet const &p, std::vector< char > &buf)
    {
        auto visitor = [&buf](auto &&actual) {
            if constexpr (std::is_same_v< std::decay_t< decltype(actual) >, std::monostate >)
            {
                assert(!"composing empty packet");
            }
            else
            {
                compose(actual, buf);
            }
        };

        std::visit(visitor, p.as_variant());
    }

    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, play_packet &pp, error_code &ec)
    {
        var_enum< play_id > which;
        auto                next = parse(first, last, which, ec);
        if (not ec.failed())
        {
            switch (which.value())
            {
            case play_id::chat_message:
                next = parse(next, last, pp.construct< chat_message >(), ec);
                break;
            case play_id::player_position_and_look:
                next = parse(next, last, pp.construct< player_position_and_look >(), ec);
                break;
            case play_id::spawn_position:
                next = parse(next, last, pp.construct< spawn_position >(), ec);
                break;
            default:
                ec = error::unexpected_packet;
            }
            if (not ec.failed())
                return next;
        }
        return first;
    }

    using unique_play_packet = std::unique_ptr< play_packet >;

    inline void compose(unique_play_packet const &p, std::vector< char > &buf)
    {
        assert(p);
        compose(*p, buf);
    }

    using shared_play_packet = std::shared_ptr< play_packet >;
    inline void compose(shared_play_packet const &p, std::vector< char > &buf)
    {
        assert(p);
        compose(*p, buf);
    }

}   // namespace minecraft::packets::server