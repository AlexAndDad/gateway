#pragma once

#include "minecraft/net.hpp"
#include "minecraft/parse.hpp"

namespace minecraft::client
{
    struct login_start
    {
        std::string name;

    };

    inline void report_on(std::ostream& os, login_start const& ls)
    {
        os << "client::login_start : name=" << ls.name;
    }

    template<class Iter>
    Iter parse(Iter first, Iter last, login_start& ls)
    {
        using minecraft::parse;
        return parse(first, last, ls.name, 16);
    }
}