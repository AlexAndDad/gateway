#pragma once

#include "config.hpp"
#include "minecraft/variant.hpp"

#include <boost/core/ignore_unused.hpp>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <ostream>

namespace minecraft::nbt
{
    struct depth_printer
    {
        std::size_t depth;

        friend std::ostream &operator<<(std::ostream &os, depth_printer const &dp);
    };

    inline auto indent(std::size_t d) -> depth_printer { return depth_printer { d }; }

    struct pretty_print_visitor
    {
        std::ostream &os;
        std::size_t   depth = 0;
        const char *  sep   = "";

        auto deeper() -> pretty_print_visitor;

        template < class T >
        void operator()(T &&value);
        void operator()(std::string_view name, compound const &value);
        void operator()(std::string_view name, list const &value);
        void operator()(std::string_view name, byte_array const &value);
        void operator()(std::string_view name, int_array const &value);
        void operator()(std::string_view name, long_array const &value);
        void operator()(std::string_view name, string const &value);
        void operator()(std::string_view name, monostate const &);
        void operator()(std::string_view name, std::int8_t const &value) { print_value(name, "TAG_Byte", value); }
        void operator()(std::string_view name, std::int16_t const &value) { print_value(name, "TAG_Short", value); }
        void operator()(std::string_view name, std::int32_t const &value) { print_value(name, "TAG_Int", value); }
        void operator()(std::string_view name, std::int64_t const &value) { print_value(name, "TAG_Long", value); }
        void operator()(std::string_view name, float const &value) { print_value(name, "TAG_Float", value); }
        void operator()(std::string_view name, double const &value) { print_value(name, "TAG_Double", value); }

      private:
        template < class T >
        void print_value(std::string_view name, std::string_view rep, T const &value);
    };

    struct pretty_printer
    {
        value const &vref;

        friend std::ostream &operator<<(std::ostream &os, pretty_printer const &p);
    };

}   // namespace minecraft::nbt

namespace minecraft::nbt
{
    template < class T >
    void pretty_print_visitor::operator()(T &&value)
    {
        (*this)(std::string_view(), std::forward< T >(value));
    }

    template < class T >
    void pretty_print_visitor::print_value(std::string_view name, std::string_view rep, const T &value)
    {
        fmt::print(os, "{0}{1}{4}('{2}'): {3}", sep, indent(depth), name, value, rep);
        sep = "\n";
    }

}   // namespace minecraft::nbt