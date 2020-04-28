#include "minecraft/packets/client/teleport_confirm.hpp"
#include "minecraft/packets/packet_tests.spec.hpp"

#include <boost/json.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <string>

TEST_CASE("minecraft::packets::client::teleport_confirm")
{
    auto pkt        = minecraft::packets::client::teleport_confirm();
    pkt.teleport_id = 100;

    SECTION("IO")
    {
        auto expected = "[teleport_confirm [teleport_id 100]]";

        SECTION("to_string")
        {
            auto s = to_string(pkt);
            CHECK(s == expected);
        }

        SECTION("ostream")
        {
            auto ss = std::ostringstream();
            ss << pkt;
            CHECK(ss.str() == expected);
        }
    }

    SECTION("encoding") { minecraft::tests::packet_round_trip(pkt); }

    SECTION("json")
    {
        auto expected = R"_json({"type":"teleport_confirm","data":{"teleport_id":100}})_json";
        auto json     = boost::json::to_value(pkt);
        auto s        = to_string(json);
        CHECK(s == expected);
    }
}