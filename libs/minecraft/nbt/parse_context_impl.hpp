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
}   // namespace minecraft::nbt