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
        cmp = i.compound_set(cmp, i.acquire_string("name"), i.make_string_ref(i.acquire_string("Richard")));
        cmp = i.compound_set(cmp, i.acquire_string("age"), i.make_long(400));
        auto foo = i.acquire_string("foo");
        i.acquire_string("foo");
        i.acquire_string("foo");
        i.acquire_string("foo");
        i.release_string(foo);

        auto gst = i.from_offset<hash_table<void>>(i.global_string_table());
        REQUIRE(gst);
        std::ostringstream ss;
        print(ss, &i, gst);
        print(ss, &i, i.from_offset<compound_header>(cmp));
        CHECK(ss.str() == "size      : 4\n"
                          "buckets   : 7\n"
                          "collisions: 0\n"
                          "Compound('') :  entries\n"
                          "{\n"
                          " String('name') : 'Richard'\n"
                          " Long('age') : 400\n"
                          "}\n");
    }
}