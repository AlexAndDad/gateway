#include <catch2/catch.hpp>

#include "minecraft/encode.hpp"
#include "minecraft/parse.hpp"
#include <string_view>
#include <string>

using namespace std::literals;

namespace
{
    std::vector<std::uint8_t> to_bytes(std::string_view sv)
    {
        std::vector<std::uint8_t> result(sv.begin(), sv.end());
        return result;
    }
}

TEST_CASE("minecraft encode")
{
    SECTION("std::int8_t")
    {
        auto scenario = [](std::int32_t initial, std::string_view expected)
        {
            INFO("int32 " << initial);
            std::string buffer;
            auto round_trip = std::int32_t(-1);
            minecraft::encode(initial, std::back_inserter(buffer));
            CHECK(buffer == expected);
            auto pos = minecraft::parse(buffer.begin(), buffer.end(), round_trip);
            CHECK(round_trip == initial);
            CHECK(pos == buffer.end());
        };

        scenario(0, "\x00"sv);
        scenario(127, "\x7f"sv);
        scenario(128, "\x80\x01"sv);
        scenario(16384, "\x80\x80\x01"sv);
        scenario(-1, "\xFF\xFF\xFF\xFF\x0F");
        scenario(-16384, "\x80\x80\xFF\xFF\x0F");
        scenario(323, "\xc3\x02");
    }

    SECTION("std::vector<std::uint8_t>")
    {
        std::string buffer;
        auto initial = to_bytes("hello"sv);
        auto round_trip = initial;
        round_trip.clear();

        minecraft::encode(initial, back_inserter(buffer));
        REQUIRE(buffer == "\x05hello"sv);

        auto iend = minecraft::parse(buffer.begin(), buffer.end(), initial);
    }
}