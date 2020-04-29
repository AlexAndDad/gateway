#pragma once

#include "minecraft/packets/packet_base.hpp"
#include "minecraft/variant.hpp"
#include "minecraft/packets/play_packet.hpp"

namespace minecraft
{
    namespace client
    {
        WISE_ENUM_CLASS((status_packet_id, std::int32_t), (request, 0), (ping, 1), (invalid, 255))
        WISE_ENUM_ENABLE_IO(status_packet_id)

        struct status_request : packets::packet_base< status_packet_id::request, status_request >
        {
            template < class Self >
            static auto as_nvps(Self &)
            {
                return nvp_set();
            }
        };

        struct status_ping : packets::packet_base< status_packet_id::ping, status_ping >
        {
            std::int64_t payload;

            template < class Self >
            static auto as_nvps(Self &self)
            {
                return nvp_set(nvp("payload", self.payload));
            }
        };

        using status_packet_variant = variant< monostate, status_request, status_ping >;

        using status_packet = packets::play_packet<status_packet_id, status_packet_variant >;


    }   // namespace client

    namespace server
    {
        WISE_ENUM_CLASS((status_packet_id, std::int32_t), (response, 0), (pong, 1), (invalid, 255))
        WISE_ENUM_ENABLE_IO(status_packet_id)

        struct status_response : packets::packet_base< status_packet_id::response, status_response >
        {
            varchar< 32767 > json;

            template < class Self >
            static auto as_nvps(Self &self)
            {
                return nvp_set(nvp("json", self.json));
            }
        };

        struct status_pong : packets::packet_base< status_packet_id::pong, status_pong >
        {
            std::int64_t payload;

            template < class Self >
            static auto as_nvps(Self &self)
            {
                return nvp_set(nvp("payload", self.payload));
            }
        };

        using status_packet_variant = variant< monostate, status_response, status_pong >;

        using status_packet = packets::play_packet<status_packet_id, status_packet_variant >;


    }   // namespace server
}   // namespace minecraft