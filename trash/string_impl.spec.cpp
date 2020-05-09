#include "pretty_printer.hpp"
#include "string_impl.hpp"

#include <catch2/catch.hpp>
#include <sstream>

using namespace minecraft::nbt;

TEST_CASE("minecraft::nbt::string_impl")
{
    storage_provider prov(100, 0);
    auto             sp = &prov;

    auto free_before = prov.free_blocks();
    auto pstr        = string_impl::new_(sp, "Hello, World!");

    CHECK(pstr.to_ref().get_offset() == 0);
    REQUIRE(pstr->size() == 13);
    CHECK(to_string(pstr) == "Hello, World!");

    std::ostringstream ss;
    auto               ppv = pretty_print_visitor { .sp = pstr.storage(), .os = ss };
    ppv(pstr.to_ref());
    CHECK(ss.str() == "TAG_String(''): 'Hello, World!'");

    delete_(pstr);

    auto free_after = prov.free_blocks();
    CHECK(free_before == free_after);
}
