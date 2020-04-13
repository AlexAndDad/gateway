#include "minecraft/parse.hpp"

#include <catch2/catch.hpp>

TEST_CASE("parse fundamentals")
{
    using vec = std::vector< char >;

    SECTION("int32_t")
    {
        auto good = [](vec data, std::uint32_t expected, std::size_t expected_length) {
            auto result   = std::int32_t();
            auto [n, err] = minecraft::parse2(data.begin(), data.end(), result);
            CHECK(!err.failed());
            CHECK(result == expected);
            CHECK(n == expected_length);
        };

        auto bad = [](vec data, minecraft::error_code expected, std::size_t expected_length = 0) {
            auto result   = std::int32_t();
            auto [n, err] = minecraft::parse2(data.begin(), data.end(), result);
            CHECK(err.failed());
            CHECK(expected.message() == err.message());
            CHECK(n == expected_length);
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
        auto good = [](vec data, std::uint64_t expected, std::size_t expected_length) {
            auto result   = std::int64_t();
            auto [n, err] = minecraft::parse2(data.begin(), data.end(), result);
            CHECK(!err.failed());
            CHECK(result == expected);
            CHECK(n == expected_length);
        };

        auto bad = [](vec data, minecraft::error_code expected, std::size_t expected_length = 0) {
            auto result   = std::int64_t();
            auto [n, err] = minecraft::parse2(data.begin(), data.end(), result);
            CHECK(err.failed());
            CHECK(expected.message() == err.message());
            CHECK(n == expected_length);
        };

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
                 0x8000000000000000LL, // -9223372036854775808
                 10);
        }
    }
}