#include "minecraft/nbt/string.hpp"

#include <catch2/catch.hpp>

using namespace minecraft::nbt;

TEST_CASE("minecraft::nbt::string")
{
    SECTION("create")
    {
        auto s1 = string();
        CHECK(s1.empty());

        auto s2 = string();
        CHECK(s1 == s2);

        s1.assign("Hello");
        CHECK(s1 != s2);
        CHECK(s1 == "Hello");
        s2 = s1;
        CHECK(s1 == s2);

        CHECK(s1.get_storage()->from_offset< string_header >(s1.get_offset())->use_count == 2);

        s2.assign("Hello");
        CHECK(s1.get_storage()->from_offset< string_header >(s1.get_offset())->use_count == 2);

        s2.assign("Goodbye");
        CHECK(s1.get_storage()->from_offset< string_header >(s1.get_offset())->use_count == 1);
        CHECK(s2.get_storage()->from_offset< string_header >(s2.get_offset())->use_count == 1);
        auto store = s1.get_storage();
        s1.assign("");
        s2.assign("");
        /*
        CHECK(store->free_blocks() ==
              impl::initial_size() - size_to_blocks(sizeof(hash_table) + sizeof(hash_bucket) * 7));
              */
    }
}