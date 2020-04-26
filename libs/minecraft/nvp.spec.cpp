//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#include "minecraft/nvp.hpp"

#include <catch2/catch.hpp>
#include <sstream>

TEST_CASE("minecraft::nvp")
{
    using minecraft::nvp;
    using minecraft::nvp_set;

    int  x = 10;
    auto n = minecraft::nvp{"x", x};

    std::ostringstream ss;
    ss << n;
    CHECK(ss.str() == "[x 10]");

    int y = 20;

    ss.str("");
    ss << nvp_set(nvp("x", x), nvp("y", y));
    CHECK(ss.str() == "[x 10] [y 20]");
}