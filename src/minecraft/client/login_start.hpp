#pragma once

#include "minecraft/net.hpp"
#include "minecraft/parse.hpp"

#include <minecraft/packet_id.hpp>

namespace minecraft::client
{
    struct login_start
    {
        static constexpr auto id() { return client_login_packet ::login_start; }
        std::string           name;
    };

    inline void report_on(std::ostream &os, login_start const &ls) { os << "client::login_start : name=" << ls.name; }

    inline std::ostream &operator<<(std::ostream &os, login_start const &arg)
    {
        report_on(os, arg);
        return os;
    }

    template < class Iter >
    Iter parse(Iter first, Iter last, login_start &ls)
    {
        using minecraft::parse;
        return parse(first, last, ls.name, 16);
    }

    template < class Iter >
    std::size_t parse(Iter first, Iter last, login_start &ls, error_code &ec)
    {
        using minecraft::parse;
        std::size_t n = 0;
        try
        {
            auto current = parse(first, last, ls.name, 16);
            n =  std::distance(first, current);
            ec.clear();
        }
        catch (incomplete)
        {
            ec = error::incomplete_parse;
        }
        catch (error_code &err)
        {
            ec = err;
        }
        return n;
    }
}   // namespace minecraft::client