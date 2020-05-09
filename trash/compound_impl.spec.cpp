#include "compound_impl.hpp"

#include <catch2/catch.hpp>

using namespace minecraft::nbt;

TEST_CASE("minecraft::nbt::compound_impl")
{
    auto store = storage_provider(100, 0);
    auto initial_report = store.report();
    auto sp    = &store;

    auto comp = compound_impl::new_(sp, 1);
    REQUIRE(comp);
    comp->set(sp, string_impl::new_(sp, "name").to_ref(), string_impl::new_(sp, "bob").to_ref());
//    auto pval = comp->get("name");

    delete_(comp);
    CHECK(sp->report() == initial_report);
}
