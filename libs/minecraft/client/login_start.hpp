#pragma once

#include "minecraft/net.hpp"
#include "minecraft/parse.hpp"

#include <minecraft/packet_id.hpp>

namespace minecraft::client
{
    struct login_start
    {
        static constexpr auto id() { return client_login_packet ::login_start; }
        varchar< 16 >         name;

        friend auto compose(login_start const &frame, std::vector< char > &target) -> std::size_t;
        friend auto verify(login_start const &frame, error_code &ec) -> error_code &;
    };

    inline void report_on(std::ostream &os, login_start const &ls) { os << "client::login_start : name=" << ls.name; }

    inline std::ostream &operator<<(std::ostream &os, login_start const &arg)
    {
        report_on(os, arg);
        return os;
    }

    template < class Iter >
    Iter parse(Iter first, Iter last, login_start &ls, error_code &ec)
    {
        using minecraft::parse;
        auto current = parse(first, last, std::tie(ls.name), ec);
        if (not ec.failed() and current != last)
            ec = error::invalid_packet;
        return ec.failed() ? first : current;
    }
}   // namespace minecraft::client