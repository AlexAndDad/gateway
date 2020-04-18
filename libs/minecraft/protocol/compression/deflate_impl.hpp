#pragma once

#include "minecraft/protocol/compression/result.hpp"
#include "minecraft/protocol/compression/types.hpp"

namespace minecraft::protocol::compression
{
    struct deflate_impl
    {
        deflate_impl(deflate_impl &&)      = delete;
        deflate_impl(deflate_impl const &) = delete;
        deflate_impl &operator=(deflate_impl &&) = delete;
        deflate_impl &operator=(deflate_impl const &) = delete;

        deflate_impl()
            : stream_ {}
        {
            throw_if_not_ok(deflateInit(&stream_, Z_DEFAULT_COMPRESSION));
        }

        ~deflate_impl()
        {
            deflateEnd(&stream_);
        }

        /// Inflate from an input buffer to a vector.
        /// \param source an input_buffer describing the extent of available data
        /// \param dest the dynamic buffer into which to inflate the output
        /// \return an input_buffer representing unconsumed data
        error_code operator()(input_buffer source_buffer, output_buffer target)
        {
            return error_code();
        }

        z_stream stream_;
    };

}   // namespace minecraft::protocol::compression