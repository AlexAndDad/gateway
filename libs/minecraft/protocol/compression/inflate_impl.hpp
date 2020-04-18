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

        inflate_impl()
        : stream_ {}
        {
            throw_if_not_ok(inflateInit(&stream_));
        }

        /// Inflate from an input buffer to a vector.
        /// \param source an input_buffer describing the extent of available data
        /// \param dest the dynamic buffer into which to inflate the output
        /// \return an input_buffer representing unconsumed data
        error_code operator()(input_buffer source_buffer, output_buffer target)
        {
            int        err;
            const uInt max = (uInt)-1;
            uLong      len, left;
            Byte       buf[1]; /* for detection of incomplete stream when *destLen == 0 */

            auto dest      = reinterpret_cast< Bytef * >(target.data());
            auto destLen   = target.size();
            auto source    = reinterpret_cast< z_const Bytef * >(source_buffer.data());
            auto sourceLen = source_buffer.size();

            len = sourceLen;
            if (destLen)
            {
                left    = destLen;
                destLen = 0;
            }
            else
            {
                left = 1;
                dest = buf;
            }

            stream_.next_in   = (z_const Bytef *)source;
            stream_.avail_in  = 0;
            stream_.next_out  = dest;
            stream_.avail_out = 0;

            do
            {
                if (stream_.avail_out == 0)
                {
                    stream_.avail_out = left > (uLong)max ? max : (uInt)left;
                    left -= stream_.avail_out;
                }
                if (stream_.avail_in == 0)
                {
                    stream_.avail_in = len > (uLong)max ? max : (uInt)len;
                    len -= stream_.avail_in;
                }
                err = inflate(&stream_, Z_NO_FLUSH);
            } while (err == Z_OK);

            sourceLen -= len + stream_.avail_in;
            if (dest != buf)
                destLen = stream_.total_out;
            else if (stream_.total_out && err == Z_BUF_ERROR)
                left = 1;

            auto result = to_error_code(
                err == Z_STREAM_END
                    ? Z_OK
                    : err == Z_NEED_DICT ? Z_DATA_ERROR
                                         : err == Z_BUF_ERROR && left + stream_.avail_out ? Z_DATA_ERROR : err);
            inflateReset(&stream_);
            return result;
        }

        z_stream stream_;
    };

}   // namespace minecraft::protocol::compression