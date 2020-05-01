#include "minecraft/types/varchar.hpp"
#include <catch2/catch.hpp>
#include <boost/core/ignore_unused.hpp>
#include <sstream>

TEST_CASE("minecraft::varchar")
{
    SECTION("IO")
    {
        auto v = minecraft::varchar< 32 >("Hello");

        boost::ignore_unused(minecraft::print(v));

        SECTION("print_to")
        {
            std::string buf;
            minecraft::print_to(buf, v);
            CHECK(buf == "Hello");
        }

        SECTION("ostream")
        {
            std::ostringstream ss;
            ss << print(v);
            CHECK(ss.str() == "Hello");
        }

        SECTION("to_string")
        {
            auto s = minecraft::to_string(v);
            CHECK(s == "Hello");
        }
    }
}