//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "minecraft/parse.hpp"
#include "minecraft/print.hpp"
#include "minecraft/to_json.hpp"

#include <cstddef>
#include <string>

namespace minecraft
{
    template < std::size_t Limit >
    struct varchar : std::string
    {
        using std::string::string;
        using std::string::operator=;

        static constexpr std::size_t max_size() { return Limit; }
    };

    template < std::size_t Limit >
    void tag_invoke(print_tag< varchar< Limit > >, std::ostream &os, varchar< Limit > const &arg)
    {
        os << static_cast< std::string const & >(arg);
    }

    template < std::size_t Limit >
    void tag_invoke(print_tag< varchar< Limit > >, std::string &os, varchar< Limit > const &arg)
    {
        os += static_cast< std::string const & >(arg);
    }

    template < std::size_t Limit >
    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, varchar< Limit > &result, error_code &ec)
    {
        auto ret = first;

        auto size = std::int32_t();
        first     = parse_var(first, last, size, ec);
        if (not ec.failed())
        {
            constexpr auto byte_limit = static_cast< int >(Limit) * 4;
            auto           available  = std::distance(first, last);
            if (size > byte_limit)
                ec = error::invalid_string;
            else if (size > available)
                ec = error::incomplete_parse;
            else
            {
                result.append(first, first + size);
                first += size;
            }
        }
        if (not ec.failed())
            ret = first;
        return ret;
    }

}   // namespace minecraft

namespace boost::json
{
    template < std::size_t N >
    struct to_value_traits< minecraft::varchar< N > >
    {
        static void assign(value &jv, minecraft::varchar< N > const &vc)
        {
            jv.emplace_string().assign(static_cast< const std::string & >(vc));
        }
    };

}   // namespace boost::json
