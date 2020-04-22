#pragma once

#include "minecraft/net.hpp"
#include "minecraft/parse.hpp"
#include "play_id.hpp"

namespace minecraft::packets::client
{
    struct keep_alive
    {
        static constexpr auto id() { return play_id::keep_alive; }

        std::int64_t keep_alive_ID;


    };

    inline std::ostream &operator<<(std::ostream &os, keep_alive const &arg)
    {
        os << "keep_alive_id: " << arg.keep_alive_ID;
        return os;
    }

    template < class Iter >
    Iter parse(Iter first, Iter last, keep_alive &pac, error_code &ec)
    {
        using minecraft::parse;
        auto current = parse(first, last, std::tie(pac.keep_alive_ID), ec);
        if (not ec.failed() and current != last)
            ec = error::invalid_packet;
        return ec.failed() ? first : current;
    }
}



