#pragma once

#include "minecraft/protocol/compression/result.hpp"
#include "minecraft/protocol/compression/types.hpp"
#include "minecraft/types.hpp"

namespace minecraft::protocol::compression
{
    struct deflate_impl
    {
        deflate_impl(deflate_impl &&)      = delete;
        deflate_impl(deflate_impl const &) = delete;
        deflate_impl &operator=(deflate_impl &&) = delete;
        deflate_impl &operator=(deflate_impl const &) = delete;

        deflate_impl();
        ~deflate_impl();

        static std::size_t compress_bound(std::size_t input_size);

        static std::size_t compress_bound(input_buffer input);

        /// Deflate the input to the output.
        /// @pre target.size() shall be >= compress_bound(source_buffer.size())
        /// \param source_buffer The data extent to deflate
        /// \param target the area into which to deflate
        /// \param ec error code on which errors will be reported
        /// \return the number of bytes written to target, such that target.size() - retval represents the position of
        /// the unused portion of target
        std::size_t operator()(input_buffer source_buffer, output_buffer target, error_code &ec);

        error_code operator()(input_buffer input, compose_buffer &out);

      private:
        z_stream stream_;
    };

}   // namespace minecraft::protocol::compression