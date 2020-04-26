#include "minecraft/wise_enum.hpp"
#include <catch2/catch.hpp>

WISE_ENUM_CLASS(Clock, tick, tock);
WISE_ENUM_ENABLE_IO(Clock)

TEST_CASE("minecraft::wise_enum")
{
    auto a = Clock::tock;

    CHECK(to_string(a) == "tock");
}