#pragma once

#include "minecraft/protocol/compression/result.hpp"
#include "minecraft/protocol/compression/types.hpp"

namespace minecraft::protocol::compression
{
    struct inflate_impl
    {
        inflate_impl(inflate_impl &&)      = delete;
        inflate_impl(inflate_impl const &) = delete;
        inflate_impl &operator=(inflate_impl &&) = delete;
        inflate_impl &operator=(inflate_impl const &) = delete;

        inflate_impl();
        ~inflate_impl();

        /// Inflate from an input buffer to a vector.
        /// \param source an input_buffer describing the extent of available data
        /// \param dest the dynamic buffer into which to inflate the output
        /// \return an input_buffer representing unconsumed data
        error_code operator()(input_buffer source_buffer, output_buffer target);

      private:
        z_stream stream_;
    };

}   // namespace minecraft::protocol::compression