#include "minecraft/chunks/palette.hpp"
#include "minecraft/posix/mmap.hpp"
#include "minecraft/testing/chunk_data.spec.ipp"

#include <catch2/catch.hpp>

using namespace minecraft::chunks;
namespace posix = minecraft::posix;
namespace fs    = minecraft::fs;

TEST_CASE("minecraft::chunks::palette",
          "[minecraft::chunks::palette][minecraft::chunks][minecraft]")
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

    SECTION("realised palette")
    {
        auto m = mmap(
            posix::open(fs::path(minecraft::testing::chunk_data_bin_filename)));

        auto first = m.begin();
        auto last  = m.end();

        first += 0x127d;
        std::uint8_t bits_per_block = *first++;
        CHECK(bits_per_block == 5);
        auto rp   = realised_palette();
        auto next = first;
        REQUIRE_NOTHROW([&] {
            // clang-format off
            next = parse(first, last, rp);
            // clang-format on
        }());

        REQUIRE(rp.size() == 18);
        CHECK(rp[0] == 0);
        CHECK(rp[1] == 33);
        CHECK(rp[2] == 1);
        CHECK(rp[3] == 6);
        CHECK(rp[4] == 3884);
        CHECK(rp[5] == 68);
        CHECK(rp[6] == 71);
        CHECK(rp[7] == 70);
        CHECK(rp[8] == 4);
        CHECK(rp[9] == 2);
        CHECK(rp[10] == 231);
        CHECK(rp[11] == 69);
        CHECK(rp[12] == 1433);
        CHECK(rp[13] == 8717);
        CHECK(rp[14] == 34);
        CHECK(rp[15] == 9131);
        CHECK(rp[16] == 1344);
        CHECK(rp[17] == 10);
    }

}   // namespace minecraft::chunks