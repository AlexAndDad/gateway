//
// Created by rhodges on 19/04/2020.
//
#include "minecraft/protocol/compression/deflate_impl.hpp"

namespace minecraft::protocol::compression
{

    deflate_impl::deflate_impl()
        : stream_ {}
    {
        throw_if_not_ok(deflateInit(&stream_, Z_DEFAULT_COMPRESSION));
    }

    deflate_impl::~deflate_impl() { deflateEnd(&stream_); }

    std::size_t deflate_impl::compress_bound(std::size_t input_size)
    {
        return static_cast< std::size_t >(::compressBound(input_size));
    }

    std::size_t deflate_impl::compress_bound(input_buffer input) { return compress_bound(input.size()); }

    std::size_t deflate_impl::operator()(input_buffer source_buffer, output_buffer target, error_code &ec)
    {
        assert(compress_bound(source_buffer.size()) <= target.size());

        Bytef *      dest      = reinterpret_cast< Bytef * >(target.data());
        uLongf       destLen   = target.size();
        const Bytef *source    = reinterpret_cast< const Bytef * >(source_buffer.data());
        uLong        sourceLen = source_buffer.size();

        int        err;
        const uInt max = (uInt)-1;
        uLong      left;

        left    = destLen;
        destLen = 0;

        stream_.next_out  = dest;
        stream_.avail_out = 0;
        stream_.next_in   = (z_const Bytef *)source;
        stream_.avail_in  = 0;

        do
        {
            if (stream_.avail_out == 0)
            {
                stream_.avail_out = left > (uLong)max ? max : (uInt)left;
                left -= stream_.avail_out;
            }
            if (stream_.avail_in == 0)
            {
                stream_.avail_in = sourceLen > (uLong)max ? max : (uInt)sourceLen;
                sourceLen -= stream_.avail_in;
            }
            err = ::deflate(&stream_, sourceLen ? Z_NO_FLUSH : Z_FINISH);
        } while (err == Z_OK);

        destLen = stream_.total_out;
        deflateReset(&stream_);
        if (err == Z_STREAM_END)
            ec.clear();
        else
            ec = to_error_code(err);

        return destLen;
    }

    error_code deflate_impl::operator()(input_buffer input, compose_buffer &out)
    {
        error_code ec;
        auto       original = out.size();
        out.resize(original + compress_bound(input));
        auto ob = net::buffer(out);
        ob += original;
        out.resize(original + operator()(input, ob, ec));
        return ec;
    }

}