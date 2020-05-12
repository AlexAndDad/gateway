#pragma once
#include "parse_context.hpp"

namespace minecraft::nbt
{
    template < class Handler >
    void basic_parse_context< Handler >::on_compound_start()
    {
        if (++depth > 255)
            raise(parsing::compound_too_deep());
        try
        {
            this->handler_.on_compound_start();
        }
        catch (parsing::parse_failure &f)
        {
            reraise(parsing::parse_failure(f.code(), "While handling Compound start"));
        }
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_key(std::string_view key)
    try
    {
        this->handler_.on_key(key);
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While handling key '{}'", key)));
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_string(std::string_view value)
    try
    {
        this->handler_.on_string(value);
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While handling string '{}'", value)));
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_byte(std::int8_t value)
    try
    {
        this->handler_.on_byte(value);
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While handling Byte {}", int(value))));
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_short(std::int16_t value)
    try
    {
        this->handler_.on_short(value);
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While handling Short {}", value)));
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_int(std::int32_t value)
    try
    {
        this->handler_.on_int(value);
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While handling Int {}", value)));
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_long(std::int64_t value)
    try
    {
        this->handler_.on_long(value);
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While handling Long {}", value)));
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_float(float value)
    try
    {
        this->handler_.on_float(value);
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While handling Float {}", value)));
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_double(double value)
    try
    {
        this->handler_.on_double(value);
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While handling Double {}", value)));
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_list(tag_type tag, std::int32_t length)
    try
    {
        if (++depth > 255)
            raise(parsing::list_too_deep());
        this->handler_.on_list(tag, length);
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While handling List")));
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_list_end(std::size_t length)
    try
    {
        --depth;
        this->handler_.on_list_end(length);
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While handling List end")));
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_end(std::size_t elements)

    try
    {
        this->handler_.on_end(elements);
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While handling End")));
    }

    template < class Handler >
    void basic_parse_context< Handler >::on_integral_list(tag_type tag, const_byte_span extent)
    try
    {
        this->handler_.on_integral_list(tag, extent);
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While handling Byte_Array")));
    }

    // public parsing functions

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first, const_buffer_iterator last, tag_type &tag)
        -> const_buffer_iterator
    try
    {
        auto val  = std::uint8_t();
        auto next = parse(first, last, val);
        tag       = static_cast< tag_type >(val);
        if (tag > tag_type::Long_Array)
            raise(parsing::invalid_tag(val));
        return next;
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing Tag")));
    }

    template < class Handler >
    template < class Fundamental, auto Align, std::size_t Bits >
    auto basic_parse_context< Handler >::parse(
        const_buffer_iterator                                                                first,
        const_buffer_iterator                                                                last,
        boost::endian::endian_buffer< boost::endian::order::big, Fundamental, Bits, Align > &target)
        -> const_buffer_iterator
    try
    {
        constexpr auto size = sizeof(Fundamental);
        if (std::distance(first, last) < static_cast< std::ptrdiff_t >(size))
            raise(parsing::incomplete());
        std::memcpy(target.data(), first, size);
        first += size;
        return first;
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing fundamental type")));
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first, const_buffer_iterator last, int16_t &target)
        -> const_buffer_iterator
    try
    {
        boost::endian::big_int16_buf_at conv;
        first  = parse(first, last, conv);
        target = conv.value();
        return first;
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing Short")));
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first,
                                               const_buffer_iterator last,
                                               uint16_t &            target) -> const_buffer_iterator
    try
    {
        boost::endian::big_uint16_buf_at conv;
        first  = parse(first, last, conv);
        target = conv.value();
        return first;
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing size")));
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first, const_buffer_iterator last, int32_t &target)
        -> const_buffer_iterator
    try
    {
        boost::endian::big_int32_buf_at conv;
        first  = parse(first, last, conv);
        target = conv.value();
        return first;
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing Int")));
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first, const_buffer_iterator last, int64_t &target)
        -> const_buffer_iterator
    try
    {
        boost::endian::big_int64_buf_at conv;
        first  = parse(first, last, conv);
        target = conv.value();
        return first;
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing Long")));
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first, const_buffer_iterator last, float &target)
        -> const_buffer_iterator
    try
    {
        boost::endian::big_float32_buf_at conv;
        first  = parse(first, last, conv);
        target = conv.value();
        return first;
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing Float")));
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first, const_buffer_iterator last, double &target)
        -> const_buffer_iterator
    try
    {
        boost::endian::big_float64_buf_at conv;
        first  = parse(first, last, conv);
        target = conv.value();
        return first;
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing Double")));
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse(const_buffer_iterator first,
                                               const_buffer_iterator last,
                                               std::string_view &    target) -> const_buffer_iterator
    try
    {
        std::uint16_t length;
        auto          next = parse(first, last, length);
        if (std::distance(next, last) < std::ptrdiff_t(length))
            raise(parsing::incomplete());
        target = std::string_view(next, length);
        next += length;
        return next;
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing String")));
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse_array(tag_type              tag,
                                                     const_buffer_iterator first,
                                                     const_buffer_iterator last) -> const_buffer_iterator
    try
    {
        auto length = std::int32_t();
        first       = parse(first, last, length);
        if (length < 0)
            raise(parsing::invalid_length(length));
        auto extent = std::ptrdiff_t(length);
        switch (tag)
        {
        default: assert(!"logic error");
        case tag_type::Byte_Array: break;
        case tag_type::Int_Array: extent *= 4; break;
        case tag_type::Long_Array: extent *= 8; break;
        }
        if (std::distance(first, last) < extent)
            raise(parsing::incomplete());
        on_integral_list(tag, const_byte_span(first, first + extent));
        first += extent;
        return first;
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing {}", tag)));
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse_atom(tag_type              tag,
                                                    const_buffer_iterator first,
                                                    const_buffer_iterator last) -> const_buffer_iterator
    try
    {
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
        case tag_type::End: raise(parsing::invalid_tag(tag));

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
        case tag_type::Compound: first = parse_compound(first, last); break;
        case tag_type::List: first = parse_list(first, last); break;
        case tag_type::Byte_Array:
        case tag_type::Int_Array:
        case tag_type::Long_Array: first = parse_array(tag, first, last); break;
        default: raise(parsing::invalid_tag(tag));
        }
        return first;
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing atom {}", wise_enum::to_string(tag))));
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse_compound(const_buffer_iterator first, const_buffer_iterator last)
        -> const_buffer_iterator
    try
    {
        on_compound_start();
        auto elements = std::int32_t(0);
        while (first != last)
        {
            auto tag = tag_type();
            first    = parse(first, last, tag);
            if (tag == tag_type::End)
            {
                break;
            }
            else
            {
                first = parse_nvp(tag, first, last);
                ++elements;
            }
        }
        on_end(elements);
        return first;
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing Compound")));
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse_list(const_buffer_iterator first, const_buffer_iterator last)
        -> const_buffer_iterator
    try
    {
        auto tag    = tag_type();
        auto length = std::int32_t();

        first = parse(first, last, tag);
        try
        {
            first  = parse(first, last, length);
            length = (std::max)(0, length);
            on_list(tag, length);
            for (auto count = length; not error() && count; --count)
                first = parse_atom(tag, first, last);
            on_list_end(length);

            return first;
        }
        catch (parsing::parse_failure &f)
        {
            reraise(parsing::parse_failure(f.code(), fmt::format("While parsing List of {}", tag)));
        }
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing List")));
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse_nvp(tag_type              tag,
                                                   const_buffer_iterator first,
                                                   const_buffer_iterator last) -> const_buffer_iterator
    try
    {
        auto name = std::string_view();
        first     = parse(first, last, name);
        on_key(name);
        try
        {
            first = parse_atom(tag, first, last);
            return first;
        }
        catch (parsing::parse_failure &f)
        {
            reraise(parsing::parse_failure(f.code(), fmt::format("While parsing value for '{}'", name)));
        }
    }
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing Compound Element of type {}", wise_enum::to_string(tag))));
    }

    template < class Handler >
    auto basic_parse_context< Handler >::parse_value(const_buffer_iterator first, const_buffer_iterator last)
        -> const_buffer_iterator
    try
    {
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
    catch (parsing::parse_failure &f)
    {
        reraise(parsing::parse_failure(f.code(), fmt::format("While parsing value")));
    }

    // free functions

    template < class Handler >
    const_buffer_iterator parse(const_buffer_iterator           first,
                                const_buffer_iterator           last,
                                basic_parse_context< Handler > &context,
                                error_code &                    ec)
    {
        if (ec)
        {
            context.error(ec);
            context.exception(std::make_exception_ptr(system_error(ec)));
            return first;
        }

        try
        {
            auto next = context.parse_value(first, last);
            return next;
        }
        catch (system_error &se)
        {
            context.error(se.code());
            context.exception(std::current_exception());
            ec = se.code();
            return first;
        }
    }

    template < class Handler >
    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, basic_parse_context< Handler > &context)
    {
        try
        {
            auto next = context.parse_value(first, last);
            return next;
        }
        catch (system_error &se)
        {
            context.error(se.code());
            context.exception(std::current_exception());
            throw;
        }
        catch (std::exception &)
        {
            context.error(error::other);
            context.exception(std::current_exception());
            throw;
        }
    }

}   // namespace minecraft::nbt