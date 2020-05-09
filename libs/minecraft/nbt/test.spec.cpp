#include "minecraft/nbt/value.hpp"

#include <catch2/catch.hpp>

using namespace minecraft::nbt;

TEST_CASE("minecraft::nbt::test")
{

    auto l = list(tag_type::String);
    l.push_back(string("Hello"));
    auto c = compound();
    c.emplace("some list", std::move(l));

}