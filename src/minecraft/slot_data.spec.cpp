#include <catch2/catch.hpp>

#include "minecraft/slot_data.hpp"
#include "minecraft/encode.hpp"

TEST_CASE("minecraft::slot_data")
{
    using namespace minecraft;
    using vec = std::vector<char>;

    auto opt = optional_slot_data();
    auto buffer = vec();

    SECTION("empty")
    {
        encode(opt, back_inserter(buffer));
        CHECK(buffer == vec { '\0' });
    }

    SECTION("default not empty")
    {
        opt.emplace(slot_data());
        encode(opt, back_inserter(buffer));
        CHECK(buffer == vec { '\x1', '\x0', '\x0', '\x0' });

        auto back = optional_slot_data();

        auto ec = error_code();
        auto iter = parse(buffer.begin(), buffer.end(), back, ec);
        REQUIRE(back.has_value());
        CHECK(back->item_id == 0);
        CHECK(back->count == 0);
        CHECK(back->nbt_data == nbt::value(nbt::nbt_end()));

    }



}