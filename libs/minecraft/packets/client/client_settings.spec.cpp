#include "minecraft/packets/client/client_settings.hpp"
#include "minecraft/packets/packet_tests.spec.hpp"

#include <catch2/catch.hpp>
#include <sstream>
#include <string>

TEST_CASE("minecraft::packets::client::client_settings")
{
    auto pkt          = minecraft::packets::client::client_settings();
    pkt.locale        = "en_GB";
    pkt.view_distance = 30;
    pkt.chat_mode     = minecraft::packets::client::chat_mode_type::enabled;
    pkt.chat_colours  = true;
    pkt.skin_parts    = 0x7e;
    pkt.main_hand     = minecraft::packets::client::main_hand_type::right;

    auto expected = "[client_settings [locale en_GB] [view_distance 30] [chat_mode enabled] [chat_colours true] "
                    "[skin_parts 126] [main_hand right]]";
    auto s = to_string(pkt);
    CHECK(s == expected);

    auto ss = std::ostringstream();
    ss << pkt;
    CHECK(ss.str() == expected);

    minecraft::tests::packet_round_trip(pkt);
}