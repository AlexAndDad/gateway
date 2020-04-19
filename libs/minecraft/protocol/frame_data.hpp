//
// Created by rhodges on 19/04/2020.
//

#pragma once

#include "minecraft/types.hpp"
#include "minecraft/net.hpp"

namespace minecraft::protocol
{
    /// A class for receiving and possibly inflating frames
    struct frame_data
    {
        std::size_t payload_size  = 0;   //! the size of the frame read from the input stream
        std::size_t data_position = 0;   //! position in input stream where the frame's data starts
        compose_buffer  payload;             //! the input stream

        /// remove one frame's worth of data from the stream.
        /// If the stram is empty, this is a no-op
        void remove_one();

        /// erase the stream and metadata
        void reset();

        /// decode the frame length from the stream and update the data_position accordingly.
        /// If the parse fails, state is left unchanged.
        /// @pre payload_size and data_position must be zero
        auto decode_frame_length(error_code &ec) -> error_code &;

        /// create a net buffer bounding the frame's data
        auto get_data() -> net::mutable_buffer;

        /// point to the first byte of the frame's data
        auto begin() const -> const char *;

        /// point to the last byte+1 of the frame's data
        auto end() const -> const char *;

        /// Consume bytes from the front of the frame area, reducing the length of the frame.
        /// The main purpose of this function is during compressed mode, when an uncompressed frame is encountered.
        /// \param n The number of bytes to consume
        void consume(std::size_t n);

        /// How many bytes we are short of having a complete payload
        /// \return
        auto shortfall() const -> std::size_t;
    };

}   // namespace minecraft::protocol