# include <catch2/catch.hpp>
#include "minecraft/security/bignum.hpp"

TEST_CASE("minecraft::secuity::bignum")
{
    auto b = minecraft::security::bignum();
    BN_free(b.release());

    REQUIRE_THROWS(b.dup());
}