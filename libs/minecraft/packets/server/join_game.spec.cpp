#include "minecraft/packets/packet_tests.spec.hpp"
#include "minecraft/packets/server/join_game.hpp"

#include <catch2/catch.hpp>
#include <sstream>
#include <string>

TEST_CASE("minecraft::packets::server::join_game")
{
    auto packet                  = minecraft::packets::server::join_game();
    packet.entity_id             = 1;
    packet.game_mode             = minecraft::gamemode::survival;
    packet.dimension             = minecraft::dimension::overworld;
    packet.hashed_seed           = 123412341234;
    packet.max_players           = 20;
    packet.level_type            = "default";
    packet.view_distance         = 16;
    packet.reduced_debug_info    = false;
    packet.enable_respawn_screen = true;

    auto expected =
        "[join_game [entity_id 1] [game_mode survival] [dimension overworld] [nashed_seed 123412341234] [max_players "
        "20] [level_type default] [view_distance 16] [reduced_debug_info false] [enable_respawn_screen true]]";

    auto s = to_string(packet);
    CHECK(s == expected);

    auto ss = std::ostringstream();
    ss << packet;
    CHECK(ss.str() == expected);

    minecraft::tests::packet_round_trip(packet);
}