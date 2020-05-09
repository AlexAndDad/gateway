#pragma once
#include "parse_context.hpp"

namespace minecraft::nbt
{
    template < class Handler >
    auto basic_parse_context< Handler >::error(error_code ec) -> error_code &
    {
        if (not ec_)
            ec_ = ec;
        return ec_;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::on_compound_start() -> error_code const &
    {
        if (not ec_)
        {
            if (++depth > 255)
                ec_ = error::compound_too_deep;
            else
                this->handler_.on_compound_start();
        }
        return ec_;
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_key(std::string_view key)
    {
        if (not ec_)
            this->handler_.on_key(key);
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_string(std::string_view value)
    {
        if (not ec_)
            this->handler_.on_string(value);
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_byte(std::int8_t value)
    {
        if (not ec_)
            this->handler_.on_byte(value);
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_short(std::int16_t value)
    {
        if (not ec_)
            this->handler_.on_short(value);
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_int(std::int32_t value)
    {
        if (not ec_)
            this->handler_.on_int(value);
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_long(std::int64_t value)
    {
        if (not ec_)
            this->handler_.on_long(value);
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_float(float value)
    {
        if (not ec_)
            this->handler_.on_float(value);
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_double(double value)
    {
        if (not ec_)
            this->handler_.on_double(value);
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_list(tag_type tag, std::int32_t length)
    {
        if (not ec_)
        {
            if (++depth > 255)
                ec_ = error::compound_too_deep;
            else
                this->handler_.on_list(tag, length);
        }
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_list_end(std::size_t length)
    {
        if (not ec_)
        {
            --depth;
            this->handler_.on_list_end(length);
        }
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_end(std::size_t elements)
    {
        if (not ec_)
            this->handler_.on_end(elements);
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_integral_list(tag_type tag, const_byte_span extent)
    {
        if (not ec_)
            this->handler_.on_integral_list(tag, extent);
    }

    // public parsing functions

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first,
                                               const_buffer_iterator last,
                                               std::uint8_t &        target) -> const_buffer_iterator
    {
        if (error())
            return first;

        if (first == last)
        {
            error(error::incomplete);
            return first;
        }

        target = static_cast< std::uint8_t >(*first++);

        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first,
                                               const_buffer_iterator last,
                                               std::int8_t &         target) -> const_buffer_iterator
    {
        if (error())
            return first;

        if (first == last)
        {
            error(error::incomplete);
            return first;
        }

        target = static_cast< std::int8_t >(*first++);

        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first, const_buffer_iterator last, tag_type &tag)
        -> const_buffer_iterator
    {
        auto val  = std::uint8_t();
        auto next = parse(first, last, val);
        if (error())
            return first;
        tag = static_cast< tag_type >(val);
        if (tag > tag_type::Long_Array)
        {
            error(error::invalid_tag);
            return first;
        }
        return next;
    }

    template < class Handler >
    template < class Fundamental, auto Align, std::size_t Bits >
    auto basic_parse_context< Handler >::parse(
        const_buffer_iterator                                                                first,
        const_buffer_iterator                                                                last,
        boost::endian::endian_buffer< boost::endian::order::big, Fundamental, Bits, Align > &target)
        -> const_buffer_iterator
    {
        if (not error())
        {
            constexpr auto size = sizeof(Fundamental);
            if (std::distance(first, last) < static_cast< std::ptrdiff_t >(size))
            {
                error(error::incomplete);
                return first;
            }
            std::memcpy(target.data(), first, size);
            first += size;
        }
        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first, const_buffer_iterator last, int16_t &target)
    -> const_buffer_iterator
    {
        boost::endian::big_int16_buf_at conv;
        first  = parse(first, last, conv);
        target = conv.value();
        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first,
                                               const_buffer_iterator last,
                                               uint16_t &            target) -> const_buffer_iterator
    {
        boost::endian::big_uint16_buf_at conv;
        first  = parse(first, last, conv);
        target = conv.value();
        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first, const_buffer_iterator last, int32_t &target)
    -> const_buffer_iterator
    {
        boost::endian::big_int32_buf_at conv;
        first  = parse(first, last, conv);
        target = conv.value();
        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first, const_buffer_iterator last, int64_t &target)
    -> const_buffer_iterator
    {
        boost::endian::big_int64_buf_at conv;
        first  = parse(first, last, conv);
        target = conv.value();
        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first, const_buffer_iterator last, float &target)
    -> const_buffer_iterator
    {
        boost::endian::big_float32_buf_at conv;
        first  = parse(first, last, conv);
        target = conv.value();
        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first, const_buffer_iterator last, double &target)
    -> const_buffer_iterator
    {
        boost::endian::big_float64_buf_at conv;
        first  = parse(first, last, conv);
        target = conv.value();
        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first,
                                               const_buffer_iterator last,
                                               std::string_view &    target) -> const_buffer_iterator
    {
        auto          next = first;
        std::uint16_t length;
        next = parse(next, last, length);
        if (not error())
        {
            if (std::distance(next, last) < std::ptrdiff_t(length))
                error(error::incomplete);
            else
            {
                target = std::string_view(next, length);
                next += length;
                return next;
            }
        }
        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse_array(tag_type              tag,
                                                     const_buffer_iterator first,
                                                     const_buffer_iterator last) -> const_buffer_iterator
    {
        if (error())
            return first;

        auto length = std::int32_t();
        first       = parse(first, last, length);
        if (length < 0)
            error(error::invalid_length);
        if (error())
            return first;
        auto extent = std::ptrdiff_t(length);
        switch (tag)
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
            error(error::incomplete);
            return first;
        }
        on_integral_list(tag, const_byte_span(first, first + extent));
        first += extent;
        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse_atom(tag_type              tag,
                                                    const_buffer_iterator first,
                                                    const_buffer_iterator last) -> const_buffer_iterator
    {
        if (error())
            return first;

        union
        {
            std::int8_t      byte_;
            std::int16_t     short_;
            std::int32_t     int_;
            std::int64_t     long_;
            float            float_;
            double           double_;
            std::string_view string_ = std::string_view();
        };

        switch (tag)
        {
        case tag_type::End:
            assert(!"logic error");
            return first;
        case tag_type::Byte:
            first = parse(first, last, byte_);
            on_byte(byte_);
            break;
        case tag_type::Short:
            first = parse(first, last, short_);
            on_short(short_);
            break;
        case tag_type::Int:
            first = parse(first, last, int_);
            on_int(int_);
            break;
        case tag_type::Long:
            first = parse(first, last, long_);
            on_long(long_);
            break;
        case tag_type::Float:
            first = parse(first, last, float_);
            on_float(float_);
            break;
        case tag_type::Double:
            first = parse(first, last, double_);
            on_double(double_);
            break;
        case tag_type::String:
            first = parse(first, last, string_);
            on_string(string_);
            break;
        case tag_type::Compound:
            first = parse_compound(first, last);
            break;
        case tag_type::List:
            first = parse_list(first, last);
            break;
        case tag_type::Byte_Array:
        case tag_type::Int_Array:
        case tag_type::Long_Array:
            first = parse_array(tag, first, last);
            break;
        default:
            error(error::invalid_tag);
        }
        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse_compound(const_buffer_iterator first, const_buffer_iterator last)
        -> const_buffer_iterator
    {
        if (error())
            return first;
        on_compound_start();
        auto elements = std::int32_t(0);
        while (not error() && first != last)
        {
            auto tag = tag_type();
            first    = parse(first, last, tag);
            if (tag == tag_type::End)
                break;
            first = parse_nvp(tag, first, last);
            ++elements;
        }
        on_end(elements);
        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse_list(const_buffer_iterator first, const_buffer_iterator last)
        -> const_buffer_iterator
    {
        if (error())
            return first;

        auto tag    = tag_type();
        auto length = std::int32_t();

        first = parse(first, last, tag);
        first = parse(first, last, length);
        if (error())
            return first;

        length = (std::max)(0, length);
        on_list(tag, length);
        for (auto count = length; not error() && count; --count)
            first = parse_atom(tag, first, last);
        on_list_end(length);

        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse_nvp(tag_type              tag,
                                                   const_buffer_iterator first,
                                                   const_buffer_iterator last) -> const_buffer_iterator
    {
        auto name = std::string_view();
        first     = parse(first, last, name);
        on_key(name);
        first = parse_atom(tag, first, last);
        return first;
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse_value(const_buffer_iterator first, const_buffer_iterator last)
        -> const_buffer_iterator
    {
        if (error())
            return first;

        auto tag = tag_type();
        first    = parse(first, last, tag);
        if (not error())
        {
            if (tag == tag_type::End)
                on_end(0);
            else
                first = parse_nvp(tag, first, last);
        }
        return first;
    }

    // free functions

    template < class Handler >
    const_buffer_iterator parse(const_buffer_iterator           first,
                                const_buffer_iterator           last,
                                basic_parse_context< Handler > &context,
                                error_code &                    ec)
    {
        auto next = context.parse_value(first, last);
        ec        = context.error();
        return next;
    }

}   // namespace minecraft::nbt