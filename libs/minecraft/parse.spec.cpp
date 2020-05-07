#include "minecraft/types/var.hpp"

#include <catch2/catch.hpp>
#include <span>
#include <boost/core/ignore_unused.hpp>

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
            CHECK(std::size_t(std::distance(data.begin(), next)) == expected_length);
        };

        auto bad = [](vec v, minecraft::error_code expected, std::size_t expected_length = 0) {
            auto       data   = to_span(v);
            auto       result = var_int();
            error_code ec;
            auto       next = parse(data.begin(), data.end(), result, ec);
            CHECK(ec.failed());
            CHECK(expected.message() == ec.message());
            CHECK(std::size_t(std::distance(data.begin(), next)) == expected_length);
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
            CHECK(std::size_t(std::distance(data.begin(), next)) == expected_length);
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

TEST_CASE("tuple testing")
{
    using namespace minecraft;
    using vec = compose_buffer;

    SECTION("uint32")
    {
        using vec_type = std::vector< std::uint32_t >;
        using tup_type = std::tuple< vec_type &, std::size_t & >;
        auto good      = [](vec v, tup_type result, vec_type expected) {
            auto data = to_span(v);
            error_code ec;
            auto first = parse(std::begin(data),std::end(data),result,ec);
            CHECK(not ec.failed());
            CHECK(expected == std::get<0>(result));
            CHECK(first == std::end(data));
        };

        auto bad      = [](vec v, tup_type result) {
            auto data = to_span(v);
            error_code ec;
            parse(std::begin(data),std::end(data),result,ec);
            CHECK(ec.failed());
        };
        boost::ignore_unused(bad);

        SECTION("05 05 05 05 05 05 05 05")
        {
            std::size_t element_quantity = 2;
            vec_type    data;
            good(
                vec {'\x05','\x05','\x05','\x05','\x05','\x05','\x05','\x05',},
                    std::tie(data, element_quantity),
                    vec_type { 84215045, 84215045 });
        }
        SECTION("1-15")
        {
            auto byte_per_element = 4;

            vec v;
            v.resize(15 * byte_per_element);

            vec_type expected;
            expected.resize(15);

            std::uint8_t val = 1;
            auto offset = 0;
            for (;val != 16;val++)
            {
                v[offset] = 0;
                v[offset+1] = 0;
                v[offset+2] = 0;
                v[offset+3] = val;
                offset += 4;
                expected[val-1] = val;
            }


            std::size_t element_quantity = 15;
            vec_type    data;
            good(
                std::move(v),
                std::tie(data, element_quantity),
                std::move(expected));
        }
    }

}