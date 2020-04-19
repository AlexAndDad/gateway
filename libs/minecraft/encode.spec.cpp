#include "minecraft/encode.hpp"
#include "minecraft/parse.hpp"

#include <catch2/catch.hpp>
#include <string>
#include <string_view>

using namespace std::literals;
using namespace minecraft;
namespace
{
    std::vector<std::uint8_t> to_bytes(std::string_view sv)
    {
        std::vector<std::uint8_t> result(sv.begin(), sv.end());
        return result;
    }
}   // namespace

TEST_CASE("minecraft encode")
{
    using namespace minecraft;

    SECTION("var_int")
    {
        auto scenario = [](minecraft::var_int initial, compose_buffer expected) {
            INFO("var_int " << initial);
            compose_buffer buffer;
            auto           round_trip = minecraft::var_int(-1);
            encode(initial, std::back_inserter(buffer));
            CHECK(buffer == expected);
            auto ec  = minecraft::error_code();
            auto s   = to_span(buffer);
            auto pos = parse(s.begin(), s.end(), round_trip, ec);
            CHECK(round_trip == initial);
            CHECK(pos == s.end());
        };

        scenario(0, { '\x00' });
        scenario(127, { '\x7f' });
        scenario(128, { '\x80', '\x01' });
        scenario(16384, { '\x80', '\x80', '\x01' });
        scenario(-1, { '\xFF', '\xFF', '\xFF', '\xFF', '\x0F' });
        scenario(-16384, { '\x80', '\x80', '\xFF', '\xFF', '\x0F' });
        scenario(323, { '\xc3', '\x02' });
    }

    SECTION("std::vector<std::uint8_t>")
    {
        compose_buffer buffer;
        auto        initial    = to_bytes("hello"sv);

        encode(initial, back_inserter(buffer));
        REQUIRE(buffer == compose_buffer{'\x05','h','e','l','l','o'});

        auto        round_trip = initial;
        round_trip.clear();
        auto ec   = error_code();
        auto s = to_span(buffer);
        auto iend = minecraft::parse(s.begin(), s.end(), round_trip, ec);
        CHECK(ec == error_code());
        CHECK(round_trip == initial);
        CHECK(iend == s.end());
    }
}