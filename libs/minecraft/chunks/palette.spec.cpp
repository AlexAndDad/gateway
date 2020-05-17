#include "minecraft/chunks/palette.hpp"
#include <catch2/catch.hpp>

using namespace minecraft::chunks;
TEST_CASE("minecraft::chunks::palette", "[minecraft::chunks::palette][minecraft::chunks][minecraft]")
{
    auto p = palette();

    p.add(minecraft::blocks::air().to_id());
    p.add(minecraft::blocks::grass_block().to_id());

    SECTION("basic ops")
    {
        CHECK(p.size() == 2);
        CHECK(p.to_block(0) == minecraft::blocks::air().to_id());
        CHECK(p.to_index(minecraft::blocks::air().to_id()) == 0);
        CHECK(p.count(minecraft::blocks::air().to_id()) == 1);
        CHECK(p.to_block(1) == minecraft::blocks::grass_block().to_id());
        CHECK(p.to_index(minecraft::blocks::grass_block().to_id()) == 1);
        CHECK(p.count(minecraft::blocks::grass_block().to_id()) == 1);

        p.add(minecraft::blocks::air().to_id());
        CHECK(p.size() == 2);
        CHECK(p.to_block(0) == minecraft::blocks::air().to_id());
        CHECK(p.to_index(minecraft::blocks::air().to_id()) == 0);
        CHECK(p.count(minecraft::blocks::air().to_id()) == 2);
        CHECK(p.to_block(1) == minecraft::blocks::grass_block().to_id());
        CHECK(p.to_index(minecraft::blocks::grass_block().to_id()) == 1);
        CHECK(p.count(minecraft::blocks::grass_block().to_id()) == 1);

    }

    SECTION("removal")
    {
        p.subtract(minecraft::blocks::air().to_id());
        CHECK(p.size() == 1);
        CHECK(p.to_block(0) == minecraft::blocks::grass_block().to_id());
        CHECK_THROWS(p.to_index(minecraft::blocks::air().to_id()));
        CHECK(p.count(minecraft::blocks::air().to_id()) == 0);
        CHECK_THROWS(p.to_block(1));
        CHECK(p.to_index(minecraft::blocks::grass_block().to_id()) == 0);
        CHECK(p.count(minecraft::blocks::grass_block().to_id()) == 1);
    }

}   // namespace minecraft::chunks