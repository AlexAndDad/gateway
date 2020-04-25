//
// Created by rhodges on 19/04/2020.
//

#pragma once

#include "minecraft/protocol/compose_area.hpp"
#include "minecraft/protocol/compression/inflate_impl.hpp"
#include "minecraft/protocol/encryption_state.hpp"
#include "minecraft/protocol/frame_data.hpp"
#include "minecraft/protocol/version.hpp"

#include <boost/webclient/internet_session.hpp>
#include <optional>

namespace minecraft::protocol
{
    struct stream_impl_base
    {
        stream_impl_base(net::executor exec)
        : protocol_version_(protocol::version_type::not_set)
        , compression_threshold_(-1)
        , encryption_()
        , compose_area_()
        , tx_compose_buffer_()
        , compressed_rx_data_()
        , inflator_()
        , uncompressed_rx_data_()
        , current_frame_data_()
        , hostname()
        , player_name()
        , port(0)
        , inet_session_(exec)
        {
        }

        auto inet_session() -> boost::webclient::internet_session&
        {
            return inet_session_;
        }

        protocol::version_type protocol_version_;

        int compression_threshold_;

        // has_state if encryption is enabled
        std::optional< encryption_state > encryption_;

        // buffer for composing packet structures into frame extents
        compose_area compose_area_;

        // transmit state
        std::vector< char > tx_compose_buffer_;

        // receive state
        frame_data                compressed_rx_data_;   // data is always read into the compressed buffer
        compression::inflate_impl inflator_;
        frame_data                uncompressed_rx_data_;   // and optionally uncompressed into here
        net::mutable_buffer       current_frame_data_;

        // client parameters / discovered by server
        std::string   hostname;
        std::string   player_name;
        std::uint32_t port;

        // internet session - this will be refactored in line with webclient
        boost::webclient::internet_session inet_session_;
    };

    std::ostream &operator<<(std::ostream &os, stream_impl_base const &base);

}   // namespace minecraft::protocol