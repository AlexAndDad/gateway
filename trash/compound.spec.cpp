#include "compound.hpp"

#include <catch2/catch.hpp>

using namespace minecraft::nbt;

TEST_CASE("minecraft::nbt::compound")
{
    SECTION("hello_world")
    {
        using namespace minecraft;

        auto val = compound(1, boost::make_shared< impl >(100, 0));
        auto hw  = compound(1, val.ensure_storage());
        hw.set("name", "Bananrama");
        CHECK(hw.size() == 1);
        val.set("hello world", std::move(hw));
        CHECK(val.size() == 1);

        auto output = std::ostringstream();
        output << pretty_print(val);

        const char expected[] = "TAG_Compound(''): 1 entries\n"
                                "{\n"
                                " TAG_Compound('hello world'): 1 entries\n"
                                " {\n"
                                "  TAG_String('name'): 'Bananrama'\n"
                                " }\n"
                                "}";
        CHECK(output.str() == expected);
    }
}