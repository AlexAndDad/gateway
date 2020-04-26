#include "minecraft/packets/server/login_success.hpp"

#include <catch2/catch.hpp>
#include <sstream>
#include <string>
#include "minecraft/packets/packet_tests.spec.hpp"

TEST_CASE("minecraft::packets::server::login_success")
{
    auto pkt     = minecraft::packets::server::login_success();
    pkt.username = "bob";
    pkt.uuid     = "12345678-1234-1234-1234-123456789012";
    auto s       = to_string(pkt);
    CHECK(s == "[login_success [uuid 12345678-1234-1234-1234-123456789012] [username bob]]");

    auto ss = std::ostringstream();
    ss << pkt;
    CHECK(ss.str() == "[login_success [uuid 12345678-1234-1234-1234-123456789012] [username bob]]");

    minecraft::tests::packet_round_trip(pkt);
}