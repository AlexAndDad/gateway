#include "minecraft/nbt/fundamental.hpp"

#include <boost/core/ignore_unused.hpp>
#include <boost/endian/buffers.hpp>

namespace minecraft::nbt
{
    // -- string_atom


    // - nvp


    auto parse_atom(tag_type tag, const_buffer_iterator first, const_buffer_iterator last, parse_context &ctx)
        -> const_buffer_iterator
    {
        if (ctx.error())
            return first;

        switch (tag)
        {
        case tag_type::End:
            assert(!"logic error");
            return first;
        case tag_type::Byte:
        {
            auto val = std::int8_t();
            first    = parse(first, last, val, ctx);
            ctx.on_byte(val);
            break;
        };
        case tag_type::Short:
        {
            auto val = std::int16_t();
            first    = parse(first, last, val, ctx);
            ctx.on_short(val);
            break;
        };
        case tag_type::Int:
        {
            auto val = std::int32_t();
            first    = parse(first, last, val, ctx);
            ctx.on_int(val);
            break;
        };
        case tag_type::Long:
        {
            auto val = std::int64_t();
            first    = parse(first, last, val, ctx);
            ctx.on_long(val);
            break;
        };
        case tag_type::Float:
        {
            auto val = float();
            first    = parse(first, last, val, ctx);
            ctx.on_float(val);
            break;
        };
        case tag_type::Double:
        {
            auto val = double();
            first    = parse(first, last, val, ctx);
            ctx.on_double(val);
            break;
        };
        case tag_type::String:
        {
            std::string_view value;
            first = parse(first, last, value, ctx);
            ctx.on_string(value);
            break;
        }
        case tag_type::Compound:
            first = parse_compound(first, last, ctx);
            break;
        case tag_type::List:
            first = parse_list(first, last, ctx);
            break;
        case tag_type::Byte_Array:
        case tag_type::Int_Array:
        case tag_type::Long_Array:
            first = parse_array(tag, first, last, ctx);
            break;
        default:
            assert(!"not implemented");
            ctx.error(error::not_implemented);
        }
        return first;
    }

    auto parse_array(tag_type tag, const_buffer_iterator first, const_buffer_iterator last, parse_context& ctx) -> const_buffer_iterator
    {
        if(ctx.error())
            return first;

        auto length = std::int32_t();
        first = parse(first, last, length, ctx);
        if (length < 0)
            ctx.error(error::invalid_length);
        if (ctx.error())
            return first;
        auto extent = std::ptrdiff_t (length);
        switch(tag)
        {
        default:
            assert(!"logic error");
        case tag_type::Byte_Array:
            break;
        case tag_type::Int_Array:
            extent *= 4;
            break;
        case tag_type::Long_Array:
            extent *= 8;
            break;
        }
        if (std::distance(first, last) < extent)
        {
            ctx.error(error::incomplete);
            return first;
        }
        ctx.on_integral_list(tag, const_byte_span (first, first + extent));
        first += extent;
        return first;
    }

    auto parse_nvp(tag_type tag, const_buffer_iterator first, const_buffer_iterator last, parse_context &ctx)
        -> const_buffer_iterator
    {
        auto name = std::string_view();
        first     = parse(first, last, name, ctx);
        ctx.on_key(name);
        first = parse_atom(tag, first, last, ctx);
        return first;
    }

    auto parse_compound(const_buffer_iterator first, const_buffer_iterator last, parse_context &ctx)
        -> const_buffer_iterator
    {
        if (ctx.error())
            return first;
        ctx.on_compound_start();
        auto elements = std::int32_t(0);
        while (not ctx.error() && first != last)
        {
            auto tag = tag_type();
            first    = parse(first, last, tag, ctx);
            if (tag == tag_type::End)
                break;
            first = parse_nvp(tag, first, last, ctx);
            ++elements;
        }
        ctx.on_end(elements);
        return first;
    }

    auto parse_list(const_buffer_iterator first, const_buffer_iterator last, parse_context &ctx)
        -> const_buffer_iterator
    {
        if (ctx.error())
            return first;

        auto tag    = tag_type();
        auto length = std::int32_t();

        first = parse(first, last, tag, ctx);
        first = parse(first, last, length, ctx);
        if (ctx.error())
            return first;

        length = (std::max)(0, length);
        ctx.on_list(tag, length);
        for (auto count = length; not ctx.error() && count; --count)
            first = parse_atom(tag, first, last, ctx);
        ctx.on_list_end(length);

        return first;
    }

    // a value os some type
    auto parse_value(const_buffer_iterator first, const_buffer_iterator last, parse_context &ctx)
        -> const_buffer_iterator
    {
        if (ctx.error())
            return first;

        auto tag = tag_type();
        first    = parse(first, last, tag, ctx);
        if (not ctx.error())
        {
            if (tag == tag_type::End)
                ctx.on_end(0);
            else
                first = parse_nvp(tag, first, last, ctx);
        }
        return first;
    }

}   // namespace minecraft::nbt