#include "minecraft/nbt/impl.hpp"

#include <catch2/catch.hpp>

using namespace minecraft::nbt;

TEST_CASE("minecraft::nbt::impl")
{
    SECTION("string")
    {
        auto sp = boost::make_shared<impl>();
        auto so = sp->acquire_string("hello");

        auto sh = sp->from_offset<string_header>(so);
        CHECK(*sh == "hello");
    }

    SECTION("compound")
    {
        auto i = impl();
        auto cmp = i.to_offset(i.new_compound(1));
        i.compound_set(cmp, i.acquire_string("name"), i.make_string_ref(i.acquire_string("Richard")));
        i.compound_set(cmp, i.acquire_string("age"), i.make_long(400));
    }
}