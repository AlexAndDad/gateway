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

    struct atom;
    struct nvp;

    struct byte_array
    {
        std::int32_t length;
        std::int32_t data_offset;
    };

    struct int_array
    {
        std::int32_t length;
        std::int32_t data_offset;
    };

    struct long_array
    {
        std::int32_t length;
        std::int32_t data_offset;
    };

    struct string_atom
    {
        std::int32_t offset;

      private:
        friend const_buffer_iterator
        parse(const_buffer_iterator first, const_buffer_iterator last, string_atom &target, parse_context &ctx);

        friend std::string_view to_string(string_atom const &atom, const_buffer_iterator storage);

        friend std::size_t size(string_atom const &atom, const_buffer_iterator storage);
    };

    struct list_atom
    {
        std::list< atom > l;
    };

    struct compound_atom
    {
        std::list< nvp > l;
    };

    struct empty
    {
    };

    using atom_variant = variant< empty,
                                  std::int8_t,
                                  std::int16_t,
                                  std::int32_t,
                                  std::int64_t,
                                  float,
                                  double,
                                  byte_array,
                                  int_array,
                                  string_atom,
                                  long_array,
                                  list_atom,
                                  compound_atom >;

    struct atom
    {
        atom(tag_type type = tag_type::End)
        : var_()
        {
            switch (type)
            {
            case tag_type::End:
                var_.emplace< empty >();
                break;
            case tag_type::Byte:
                var_.emplace< std::int8_t >();
                break;
            case tag_type::Short:
                var_.emplace< std::int16_t >();
                break;
            case tag_type::Int:
                var_.emplace< std::int32_t >();
                break;
            case tag_type::Long:
                var_.emplace< std::int64_t >();
                break;
            case tag_type::Float:
                var_.emplace< float >();
                break;
            case tag_type::Double:
                var_.emplace< double >();
                break;
            case tag_type::Byte_Array:
                var_.emplace< byte_array >();
                break;
            case tag_type::String:
                var_.emplace< string_atom >();
                break;
            case tag_type::List:
                var_.emplace< list_atom >();
                break;
            case tag_type::Compound:
                var_.emplace< compound_atom >();
                break;
            case tag_type::Int_Array:
                var_.emplace< int_array >();
                break;
            case tag_type::Long_Array:
                var_.emplace< long_array >();
                break;
            }
        }

      private:
        atom_variant var_;
    };

    struct nvp : atom
    {
        using atom::atom;

        string_atom name;
    };

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, nvp &target, parse_context &ctx);

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