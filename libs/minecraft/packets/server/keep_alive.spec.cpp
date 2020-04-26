#include "minecraft/packets/server/keep_alive.hpp"

#include <catch2/catch.hpp>
#include <sstream>
#include <string>
#include "minecraft/packets/packet_tests.spec.hpp"

TEST_CASE("minecraft::packets::server::keep_alive")
{
    auto pkt     = minecraft::packets::server::keep_alive();
    pkt.keep_alive_id = 1234567;

    auto expected = "[keep_alive [keep_alive_id 1234567]]";

    auto s       = to_string(pkt);
    CHECK(s == expected);

    auto ss = std::ostringstream();
    ss << pkt;
    CHECK(ss.str() == expected);

    minecraft::tests::packet_round_trip(pkt);
}