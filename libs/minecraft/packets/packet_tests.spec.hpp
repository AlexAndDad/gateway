#pragma once

#include <catch2/catch.hpp>

#include "minecraft/parse.hpp"
#include "minecraft/encode.hpp"
#include "minecraft/to_json.hpp"
#include <boost/json/serializer.hpp>

namespace minecraft::tests
{
    template<class Packet>
    void packet_round_trip(Packet const& source)
    {
        std::vector<char> composed;
        compose(source, composed);

        error_code ec;
        auto parsed = Packet();
        auto first = composed.data();
        auto last = first + composed.size();

        auto pid = var_enum<decltype(Packet::id())>();
        auto next = minecraft::parse(first, last, pid, ec);
        CHECK(pid == source.id());
        CHECK(ec.message() == "Success");
        next = parse(next, last, parsed, ec);
        CHECK(ec.message() == "Success");
        CHECK(next == last);
        CHECK(parsed == source);
    }

    template<class Packet>
    void packet_to_json(Packet const& pkt, boost::json::string expected)
    {
        using boost::json::to_string;
        auto json = boost::json::to_value(pkt);
        auto rep = to_string(json);
        CHECK(rep == expected);
    }
}