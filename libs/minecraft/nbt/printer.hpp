#pragma once

#include "config.hpp"
#include "minecraft/variant.hpp"

#include <boost/core/ignore_unused.hpp>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <ostream>

namespace minecraft::nbt
{
    struct print_visitor
    {
        std::ostream &os;

        void operator()(compound const &value);
        void operator()(list const &value);
        void operator()(byte_array const &value);
        void operator()(int_array const &value);
        void operator()(long_array const &value);
        void operator()(string const &value);
        void operator()(monostate const &);
        void operator()(value const& v);

        template < class T >
        void operator()(const T &value);

        template<class T>
        void operator()(std::string_view name, T const& val);

    };

}   // namespace minecraft::nbt

namespace minecraft::nbt
{
    template < class T >
    void print_visitor::operator()(const T &value)
    {
        fmt::print(os, "[{} {}]", wise_enum::to_string(to_tag_v<T>), value);
    }

    template < class T >
    void print_visitor::operator()(std::string_view name, const T &val)
    {
        if (name.empty())
        {
            (*this)(val);
        }
        else
        {
            fmt::print(os,"[[name '{}'] ", name);
            (*this)(val);
            fmt::print(os,"]");
        }
    }

}   // namespace minecraft::nbt