#include "generic_list_impl.hpp"

#include <catch2/catch.hpp>

using namespace minecraft::nbt;

TEST_CASE("minecraft::nbt::generic_list")
{
    constexpr auto storage_blocks = 100;
    auto           mysp           = storage_provider(storage_blocks);
    auto           initial_report = mysp.report();

    CHECK(initial_report == storage_provider::storage_report { .free_blocks = 100, .fragments = 1 });

    auto l = generic_list_impl::new_(&mysp, tag_type::Byte, 100);
    REQUIRE(l.get());

    delete_(l);

    CHECK(mysp.report() == initial_report);
}