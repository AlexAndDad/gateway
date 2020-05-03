#pragma once

#include "minecraft/net.hpp"
#include "minecraft/types/buffer.hpp"
#include "tag_type.hpp"

#include <boost/core/ignore_unused.hpp>
#include <string_view>

namespace minecraft::nbt
{
    struct parse_handler
    {
        virtual void on_compound_start() {}
        virtual void on_key(std::string_view key) { boost::ignore_unused(key); }
        virtual void on_string(std::string_view value) { boost::ignore_unused(value); }
        virtual void on_byte(std::int8_t value) { boost::ignore_unused(value); }
        virtual void on_short(std::int16_t value) { boost::ignore_unused(value); }
        virtual void on_int(std::int32_t value) { boost::ignore_unused(value); }
        virtual void on_long(std::int64_t value) { boost::ignore_unused(value); }
        virtual void on_float(float value) { boost::ignore_unused(value); }
        virtual void on_double(double value) { boost::ignore_unused(value); }
        virtual void on_end(std::size_t elements) { boost::ignore_unused(elements); }
        virtual void on_list(tag_type tag, std::size_t length) { boost::ignore_unused(tag, length); }
        virtual void on_list_end(std::size_t length) { boost::ignore_unused(length); }
        virtual void on_integral_list(tag_type tag, const_byte_span extent) { boost::ignore_unused(tag, extent); }
    };



    struct parse_context
    {
        parse_context(const_buffer_iterator storage, parse_handler &handler)
        : storage_(storage)
        , handler_(handler)
        {
        }

        error_code &error(error_code ec)
        {
            if (not ec_)
                ec_ = ec;
            return ec_;
        }

        error_code const &error() const { return ec_; }
        error_code &      error() { return ec_; }

        std::int32_t to_index(const void *p) { return reinterpret_cast< const_buffer_iterator >(p) - storage_; }

        const_buffer_iterator storage() const { return storage_; }

        auto on_compound_start() -> error_code const &
        {
            if (not ec_)
            {
                compound_depth += 1;
                if (compound_depth > 255)
                    ec_ = error::compound_too_deep;
                else
                    handler_.on_compound_start();
            }
            return ec_;
        }

        void on_key(std::string_view key)
        {
            if (not ec_)
                handler_.on_key(key);
        }

        void on_string(std::string_view value)
        {
            if (not ec_)
                handler_.on_string(value);
        }

        void on_byte(std::int8_t value)
        {
            if (not ec_)
                handler_.on_byte(value);
        }
        void on_short(std::int16_t value)
        {
            if (not ec_)
                handler_.on_short(value);
        }
        void on_int(std::int32_t value)
        {
            if (not ec_)
                handler_.on_int(value);
        }
        void on_long(std::int64_t value)
        {
            if (not ec_)
                handler_.on_long(value);
        }
        void on_float(float value)
        {
            if (not ec_)
                handler_.on_float(value);
        }
        void on_double(double value)
        {
            if (not ec_)
                handler_.on_double(value);
        }

        void on_list(tag_type tag, std::int32_t length)
        {
            if (not ec_)
                handler_.on_list(tag, length);
        }

        void on_list_end(std::size_t length /*check*/)
        {
            if (not ec_)
                handler_.on_list_end(length);
        }

        void on_end(std::size_t elements)
        {
            if (not ec_)
                handler_.on_end(elements);
        }

        void on_integral_list(tag_type tag, const_byte_span extent)
        {
            if (not ec_)
                handler_.on_integral_list(tag, extent);
        }

        int compound_depth = 0;

      private:
        const_buffer_iterator storage_;
        parse_handler &       handler_;
        error_code            ec_;
    };
}   // namespace minecraft::nbt