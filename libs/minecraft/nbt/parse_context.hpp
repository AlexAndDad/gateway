#pragma once

#include "error.hpp"
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

    template < class Handler >
    struct handler_owner
    {
        handler_owner(Handler handler = Handler())
        : handler_(std::move(handler))
        {
        }

        auto handler() -> Handler & { return handler_; }

      protected:
        Handler handler_;
    };

    template < class Handler >
    struct handler_owner< Handler & >
    {
        handler_owner(Handler &handler)
        : handler_(handler)
        {
        }

        auto handler() -> Handler & { return handler_; }

      protected:
        Handler &handler_;
    };

    template < class Handler >
    struct basic_parse_context : handler_owner< Handler >
    {
        using handler_owner< Handler >::handler_owner;

        error_code &error(error_code ec);

        error_code const &error() const { return ec_; }
        error_code &      error() { return ec_; }

        auto on_compound_start() -> error_code const &;

        void on_key(std::string_view key);

        void on_string(std::string_view value);

        void on_byte(std::int8_t value);
        void on_short(std::int16_t value);
        void on_int(std::int32_t value);
        void on_long(std::int64_t value);
        void on_float(float value);
        void on_double(double value);

        void on_list(tag_type tag, std::int32_t length);

        void on_list_end(std::size_t length /*check*/);

        void on_end(std::size_t elements);

        void on_integral_list(tag_type tag, const_byte_span extent);

        int depth = 0;

      private:
        error_code     ec_;
    };

    using parse_context = basic_parse_context< parse_handler & >;
}   // namespace minecraft::nbt

#include "parse_context_impl.hpp"
