//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#include <catch2/catch.hpp>
#include "minecraft/protocol/daft_hash.hpp"

using namespace minecraft;

TEST_CASE("minecraft::protocol::daft_hash")
{

    protocol::daft_hash_impl hasher;

    //
    // Check class Notch
    //

    hasher.update(net::buffer(std::string("Notch")));
    auto result = hasher.finalise();

    CHECK(result == "4ed1f46bbe04bc756bcb17c0c7ce3e4632f06a48");


    //
    // Check repeatable
    //

    hasher.update(net::buffer(std::string("Notch")));
    result = hasher.finalise();

    CHECK(result == "4ed1f46bbe04bc756bcb17c0c7ce3e4632f06a48");

    //
    // Negative hash
    //

    hasher.update(net::buffer(std::string("jeb_")));
    result = hasher.finalise();

    CHECK(result == "-7c9d5b0044c130109a5d7b5fb5c317c02b4e28c1");

    hasher.update(net::buffer(std::string("j")));
    hasher.update(net::buffer(std::string("e")));
    hasher.update(net::buffer(std::string("b")));
    hasher.update(net::buffer(std::string("_")));
    result = hasher.finalise();

    CHECK(result == "-7c9d5b0044c130109a5d7b5fb5c317c02b4e28c1");

    //
    // simon
    //

    hasher.update(net::buffer(std::string("simon")));
    result = hasher.finalise();

    CHECK(result == "88e16a1019277b15d58faf0541e11910eb756f6");
}