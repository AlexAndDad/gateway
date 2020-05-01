//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "minecraft/to_json.hpp"
#include <string>
#include <cstddef>
#include "minecraft/print.hpp"

namespace minecraft
{
    template < std::size_t Limit >
    struct varchar : std::string
    {
        using std::string::string;
        using std::string::operator=;

        static constexpr std::size_t max_size() { return Limit; }
    };

    template<std::size_t Limit>
    void tag_invoke(print_tag<varchar<Limit>>, std::ostream& os, varchar<Limit> const& arg)
    {
        os << static_cast<std::string const&>(arg);
    }

    template<std::size_t Limit>
    void tag_invoke(print_tag<varchar<Limit>>, std::string& os, varchar<Limit> const& arg)
    {
        os += static_cast<std::string const&>(arg);
    }
}

namespace boost::json
{
    template<std::size_t N>
    struct to_value_traits<minecraft::varchar<N>>
    {
        static void assign(value& jv, minecraft::varchar<N> const& vc)
        {
            jv.emplace_string().assign(static_cast<const std::string&>(vc));
        }
    };

}
