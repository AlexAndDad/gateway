//
// Created by rhodges on 19/04/2020.
//

#pragma once

#include "minecraft/protocol/compose_area.hpp"
#include "minecraft/protocol/encryption_state.hpp"
#include "minecraft/protocol/frame_data.hpp"
#include "minecraft/protocol/version.hpp"
#include "minecraft/protocol/compression/inflate_impl.hpp"

#include <optional>

namespace minecraft::protocol
{
    struct stream_impl_base
    {
        protocol::version_type protocol_version_ = protocol::version_type::not_set;

        int compression_threshold_ = -1;

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
        net::mutable_buffer       current_frame_data_ = {};

        // client parameters / discovered by server
        std::string   hostname;
        std::string   player_name;
        std::uint32_t port = 0;
    };

    std::ostream &operator<<(std::ostream &os, stream_impl_base const &base);

}   // namespace minecraft::protocol