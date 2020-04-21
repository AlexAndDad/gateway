#include "minecraft/parse.hpp"

#include <catch2/catch.hpp>

TEST_CASE("parse fundamentals")
{
    using namespace minecraft;

    using vec = compose_buffer;

    SECTION("int32_t")
    {
        auto good = [](vec v, minecraft::var_int expected, std::size_t expected_length) {
            auto       data   = to_span(v);
            auto       result = var_int();
            error_code ec;
            auto       next = parse(data.begin(), data.end(), result, ec);
            CHECK(!ec.failed());
            CHECK(result == expected);
            CHECK(std::distance(data.begin(), next) == expected_length);
        };

        auto bad = [](vec v, minecraft::error_code expected, std::size_t expected_length = 0) {
            auto       data   = to_span(v);
            auto       result = var_int();
            error_code ec;
            auto       next = parse(data.begin(), data.end(), result, ec);
            CHECK(ec.failed());
            CHECK(expected.message() == ec.message());
            CHECK(std::distance(data.begin(), next) == expected_length);
        };

        SECTION("00") { good(vec { 0x00 }, 0, 1); }
        SECTION("01") { good(vec { 0x01 }, 1, 1); }
        SECTION("02") { good(vec { 0x02 }, 2, 1); }
        SECTION("7f") { good(vec { 0x7f }, 127, 1); }
        SECTION("80 01") { good(vec { '\x80', 0x01 }, 128, 2); }
        SECTION("FF 01") { good(vec { '\xff', 0x01 }, 255, 2); }
        SECTION("ff ff ff ff 07") { good(vec { '\xff', '\xff', '\xff', '\xff', 0x07 }, 2147483647, 5); }
        SECTION("ff ff ff ff ff")
        {
            bad(vec { '\xff', '\xff', '\xff', '\xff', '\xff' }, minecraft::error::invalid_varint);
        }
    }

    SECTION("int64_t")
    {
        auto good = [](vec v, var_long expected, std::size_t expected_length) {
            auto       data   = to_span(v);
            auto       result = var_long();
            error_code ec;
            auto       next = minecraft::parse(data.begin(), data.end(), result, ec);
            CHECK(!ec.failed());
            CHECK(result == expected);
            CHECK(std::distance(data.begin(), next) == expected_length);
        };

        /*
        auto bad = [](vec v, minecraft::error_code expected, std::size_t expected_length = 0) {
            auto data = to_span(v);
            auto result   = minecraft::var_long();
            minecraft::error_code ec;
            auto next =  minecraft::parse(data.begin(), data.end(), result, ec);
            CHECK(ec.failed());
            CHECK(expected.message() == ec.message());
            CHECK(std::distance(data.begin(), next) == expected_length);
        };
*/

        SECTION("00") { good(vec { 0x00 }, 0, 1); }
        SECTION("01") { good(vec { 0x01 }, 1, 1); }
        SECTION("02") { good(vec { 0x02 }, 2, 1); }
        SECTION("7f") { good(vec { 0x7f }, 127, 1); }
        SECTION("80 01") { good(vec { '\x80', 0x01 }, 128, 2); }
        SECTION("FF 01") { good(vec { '\xff', 0x01 }, 255, 2); }
        SECTION("ff ff ff ff 07") { good(vec { '\xff', '\xff', '\xff', '\xff', 0x07 }, 2147483647, 5); }
        SECTION("ff ff ff ff ff ff ff ff 7f")
        {
            good(vec { '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\x7f' },
                 9223372036854775807LL,
                 9);
        }

        SECTION("ff ff ff ff ff ff ff ff ff 01")
        {
            good(vec { '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\x7f' }, -1, 10);
        }
        SECTION("80 80 80 80 f8 ff ff ff ff 01")
        {
            good(vec { '\x80', '\x80', '\x80', '\x80', '\xf8', '\xff', '\xff', '\xff', '\xff', '\x01' },
                 -2147483648LL,
                 10);
        }
        SECTION("80 80 80 80 80 80 80 80 80 01")
        {
            good(vec { '\x80', '\x80', '\x80', '\x80', '\x80', '\x80', '\x80', '\x80', '\x80', '\x01' },
                 0x8000000000000000LL,   // -9223372036854775808
                 10);
        }
    }
}