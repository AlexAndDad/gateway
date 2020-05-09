#pragma once

#include "error.hpp"
#include "minecraft/net.hpp"
#include "minecraft/types/buffer.hpp"
#include "tag_type.hpp"

#include <boost/core/ignore_unused.hpp>
#include <boost/endian/buffers.hpp>
#include <string_view>

namespace minecraft::nbt
{
    struct parse_handler
    {
        virtual void on_compound_start() {}
        virtual void on_key(std::string_view key) { boost::ignore_unused(key); }
        virtual void on_string(std::string_view value) { boost::ignore_unused(value); }
        virtual void on_byte(std::int8_t const& value) { boost::ignore_unused(value); }
        virtual void on_short(std::int16_t const& value) { boost::ignore_unused(value); }
        virtual void on_int(std::int32_t const& value) { boost::ignore_unused(value); }
        virtual void on_long(std::int64_t const& value) { boost::ignore_unused(value); }
        virtual void on_float(float const& value) { boost::ignore_unused(value); }
        virtual void on_double(double const& value) { boost::ignore_unused(value); }
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

        // parsing functions

        auto parse(const_buffer_iterator first, const_buffer_iterator last, std::uint8_t &target)
            -> const_buffer_iterator;

        auto parse(const_buffer_iterator first, const_buffer_iterator last, std::int8_t &target)
            -> const_buffer_iterator;

        template < class Fundamental, auto Align, std::size_t Bits = sizeof(Fundamental) * 8 >
        auto parse(const_buffer_iterator                                                                first,
                   const_buffer_iterator                                                                last,
                   boost::endian::endian_buffer< boost::endian::order::big, Fundamental, Bits, Align > &target)
            -> const_buffer_iterator;

        auto
        parse(const_buffer_iterator first, const_buffer_iterator last, std::int16_t &target) -> const_buffer_iterator;

        auto
        parse(const_buffer_iterator first, const_buffer_iterator last, std::uint16_t &target) -> const_buffer_iterator;

        auto
        parse(const_buffer_iterator first, const_buffer_iterator last, std::int32_t &target) -> const_buffer_iterator;

        auto
        parse(const_buffer_iterator first, const_buffer_iterator last, std::int64_t &target) -> const_buffer_iterator;

        auto parse(const_buffer_iterator first, const_buffer_iterator last, float &target) -> const_buffer_iterator;

        auto parse(const_buffer_iterator first, const_buffer_iterator last, double &target) -> const_buffer_iterator;

        auto parse(const_buffer_iterator first, const_buffer_iterator last, std::string_view &target)
            -> const_buffer_iterator;

        auto parse(const_buffer_iterator first, const_buffer_iterator last, tag_type &tag) -> const_buffer_iterator;

        auto parse_atom(tag_type tag, const_buffer_iterator first, const_buffer_iterator last) -> const_buffer_iterator;

        auto parse_array(tag_type tag, const_buffer_iterator first, const_buffer_iterator last)
            -> const_buffer_iterator;

        auto parse_compound(const_buffer_iterator first, const_buffer_iterator last) -> const_buffer_iterator;

        auto parse_list(const_buffer_iterator first, const_buffer_iterator last) -> const_buffer_iterator;

        auto parse_nvp(tag_type tag, const_buffer_iterator first, const_buffer_iterator last) -> const_buffer_iterator;

        // parse a value, expecting it to be a compound
        auto parse_value(const_buffer_iterator first, const_buffer_iterator last) -> const_buffer_iterator;

      private:
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
        error_code ec_;
    };

    template < class Handler >
    const_buffer_iterator parse(const_buffer_iterator           first,
                                const_buffer_iterator           last,
                                basic_parse_context< Handler > &context,
                                error_code &                    ec);

    using parse_context = basic_parse_context< parse_handler & >;

    template<class Handler>
    auto make_parse_context(Handler h) -> basic_parse_context<Handler>
    {
        return basic_parse_context<Handler>(std::move(h));
    }
}   // namespace minecraft::nbt

#include "parse_context_impl.hpp"
