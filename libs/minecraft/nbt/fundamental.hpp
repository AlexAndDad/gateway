#pragma once

#include "minecraft/nbt/error.hpp"
#include "minecraft/nbt/parse_context.hpp"
#include "minecraft/types/buffer.hpp"
#include "minecraft/variant.hpp"
#include "tag_type.hpp"

#include <boost/endian/buffers.hpp>
#include <list>

namespace minecraft::nbt
{


    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, std::uint8_t &target, parse_context &ctx)
    {
        if (ctx.error())
            return first;

        if (first == last)
        {
            ctx.error(error::incomplete);
            return first;
        }

        target = static_cast< std::uint8_t >(*first++);

        return first;
    }

    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, std::int8_t &target, parse_context &ctx)
    {
        if (ctx.error())
            return first;

        if (first == last)
        {
            ctx.error(error::incomplete);
            return first;
        }

        target = static_cast< std::int8_t >(*first++);

        return first;
    }

    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, tag_type &tag, parse_context &ctx)
    {
        auto val  = std::uint8_t();
        auto next = parse(first, last, val, ctx);
        if (ctx.error())
            return first;
        tag = static_cast< tag_type >(val);
        if (tag > tag_type::Long_Array)
        {
            ctx.error(error::invalid_tag);
            return first;
        }
        return next;
    }

    template < class Fundamental, auto Align, std::size_t Bits = sizeof(Fundamental) * 8 >
    auto parse(const_buffer_iterator                                                                first,
               const_buffer_iterator                                                                last,
               boost::endian::endian_buffer< boost::endian::order::big, Fundamental, Bits, Align > &target,
               parse_context &ctx) -> const_buffer_iterator
    {
        if (not ctx.error())
        {
            auto error = [first, &ctx](auto code) {
                ctx.error(code);
                return first;
            };

            constexpr auto size = sizeof(Fundamental);

            if (std::distance(first, last) < static_cast< std::ptrdiff_t >(size))
                return error(error::incomplete);

            std::memcpy(target.data(), first, size);
            first += size;
        }

        return first;
    }

    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, std::int16_t &target, parse_context &ctx)
    {
        boost::endian::big_int16_buf_at conv;
        first  = parse(first, last, conv, ctx);
        target = conv.value();
        return first;
    }

    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, std::uint16_t &target, parse_context &ctx)
    {
        boost::endian::big_uint16_buf_at conv;
        first  = parse(first, last, conv, ctx);
        target = conv.value();
        return first;
    }

    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, std::int32_t &target, parse_context &ctx)
    {
        boost::endian::big_int32_buf_at conv;
        first  = parse(first, last, conv, ctx);
        target = conv.value();
        return first;
    }

    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, std::int64_t &target, parse_context &ctx)
    {
        boost::endian::big_int64_buf_at conv;
        first  = parse(first, last, conv, ctx);
        target = conv.value();
        return first;
    }

    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, float &target, parse_context &ctx)
    {
        boost::endian::big_float32_buf_at conv;
        first  = parse(first, last, conv, ctx);
        target = conv.value();
        return first;
    }

    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, double &target, parse_context &ctx)
    {
        boost::endian::big_float64_buf_at conv;
        first  = parse(first, last, conv, ctx);
        target = conv.value();
        return first;
    }

    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, std::string_view &target, parse_context &ctx)
    {
        auto next = first;
        std::uint16_t length;
        next = parse(next, last, length, ctx);
        if (not ctx.error())
        {
            if (std::distance(next, last) < std::ptrdiff_t(length))
                ctx.error(error::incomplete);
            else
            {
                target = std::string_view(next, length);
                next += length;
                return next;
            }
        }
        return first;
    }

    /// Parse an array of either Byte, Int or Long.
    ///
    /// Tag and extents will be forwwarded to the parser as a span. The parser must check endian-ness and alignment
    /// but may trust that the span's length is correct
    auto parse_array(tag_type tag, const_buffer_iterator first, const_buffer_iterator last, parse_context& ctx) -> const_buffer_iterator;
    auto parse_nvp(tag_type tag, const_buffer_iterator first, const_buffer_iterator last, parse_context& ctx) -> const_buffer_iterator;
    auto parse_compound(const_buffer_iterator first, const_buffer_iterator last, parse_context& ctx) -> const_buffer_iterator;
    auto parse_list(const_buffer_iterator first, const_buffer_iterator last, parse_context& ctx) -> const_buffer_iterator;
    auto parse_value(const_buffer_iterator first, const_buffer_iterator last, parse_context& ctx) -> const_buffer_iterator;
}   // namespace minecraft::nbt