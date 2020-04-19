#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/types.hpp"

#include <fmt/ostream.h>
#include <wise_enum/wise_enum.h>

namespace minecraft
{
    namespace client
    {
        WISE_ENUM_CLASS((status_packet_id, std::int32_t), (request, 0), (ping, 1))

        struct status_request
        {
            static constexpr auto id() { return status_packet_id::request; }
        };

        template < class Stream >
        Stream &operator<<(Stream &os, status_request const &packet)
        {
            fmt::print(os, "[status [from client] [type {}]]", wise_enum::to_string(packet.id()));
            return os;
        }

        inline void compose(status_request const &packet, compose_buffer &buffer)
        {
            auto first = back_inserter(buffer);
            encode_var(static_cast< std::int32_t >(packet.id()), first);
        }

        inline const_buffer_iterator
        parse(const_buffer_iterator first, const_buffer_iterator last, status_request &, error_code &ec)
        {
            if (not ec.failed())
            {
                if (first != last)
                    ec = error::invalid_packet;
            }
            return first;
        }

        struct status_ping
        {
            static constexpr auto id() { return status_packet_id::ping; }
            std::int64_t          payload;
        };

        template < class Stream >
        Stream &operator<<(Stream &os, status_ping const &packet)
        {
            fmt::print(
                os, "[status [from client] [type {}] [payload {}]", wise_enum::to_string(packet.id()), packet.payload);
            return os;
        }

        inline void compose(status_ping const &packet, compose_buffer &buffer)
        {
            using minecraft::encode;
            auto first = back_inserter(buffer);
            first      = encode_var(static_cast< std::int32_t >(packet.id()), first);
            encode(packet.payload, first);
        }

        inline const_buffer_iterator
        parse(const_buffer_iterator first, const_buffer_iterator last, status_ping &packet, error_code &ec)
        {
            using minecraft::parse;
            auto ret = first;
            first    = parse(first, last, packet.payload, ec);
            if (not ec.failed() and first != last)
                ec = error::invalid_packet;
            if (not ec.failed())
                ret = first;
            return ret;
        }

    }   // namespace client

    namespace server
    {
        WISE_ENUM_CLASS((status_packet_id, std::int32_t), (response, 0), (pong, 1))

        struct status_response
        {
            static constexpr auto id() { return status_packet_id::response; }
            varchar< 32767 >      json;
        };

        template < class Stream >
        Stream &operator<<(Stream &os, status_response const &packet)
        {
            fmt::print(os, "[status [from server] [type {}] [json {}]", wise_enum::to_string(packet.id()), packet.json);
            return os;
        }

        inline void compose(status_response const &packet, compose_buffer &buffer)
        {
            auto first = back_inserter(buffer);
            first      = encode_var(static_cast< std::int32_t >(packet.id()), first);
            encode(packet.json, first);
        }

        inline const_buffer_iterator
        parse(const_buffer_iterator first, const_buffer_iterator last, status_response &packet, error_code &ec)
        {
            using minecraft::parse;
            auto ret = first;
            first    = parse(first, last, packet.json, ec);
            if (not ec.failed() and first != last)
                ec = error::invalid_packet;
            if (not ec.failed())
                ret = first;
            return ret;
        }

        struct status_pong
        {
            static constexpr auto id() { return status_packet_id::response; }
            std::int64_t          payload;
        };

        template < class Stream >
        Stream &operator<<(Stream &os, status_pong const &packet)
        {
            fmt::print(
                os, "[status [from server] [type {}] [payload {}]", wise_enum::to_string(packet.id()), packet.payload);
            return os;
        }

        inline void compose(status_pong const &packet, compose_buffer &buffer)
        {
            using minecraft::encode;
            auto first = back_inserter(buffer);
            first      = encode_var(static_cast< std::int32_t >(packet.id()), first);
            encode(packet.payload, first);
        }

        inline const_buffer_iterator
        parse(const_buffer_iterator first, const_buffer_iterator last, status_pong &packet, error_code &ec)
        {
            using minecraft::parse;
            auto ret = first;
            first    = parse(first, last, packet.payload, ec);
            if (not ec.failed() and first != last)
                ec = error::invalid_packet;
            if (not ec.failed())
                ret = first;
            return ret;
        }

    }   // namespace server
}   // namespace minecraft