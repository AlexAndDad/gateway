#include "minecraft/security/private_key.hpp"
#include "minecraft/security/rsa.hpp"

#include <catch2/catch.hpp>
#include <random>

TEST_CASE("minecraft::security::private_key")
{
    auto rng = std::random_device();

    auto ppk = minecraft::security::private_key();
    auto rsa = minecraft::security::rsa(1024);
    ppk.assign(std::move(rsa));
    auto asn1  = ppk.public_asn1();
    CHECK(asn1.size() == 162);
}