#include "minecraft/utils/base_64.hpp"

#include <catch2/catch.hpp>
#include <string>

TEST_CASE("minecraft::utils::base_64")
{
    using namespace minecraft;

    auto do_check = [](std::string input, std::string expected) {
        INFO("" << input);
        compose_buffer out;
        utils::base64_encode(input.data(), input.data() + input.size(), out);
        auto check = std::string(out.begin(), out.end());
        CHECK(check == expected);
        CHECK(check.size() == expected.size());
    };

    do_check("a", "YQ==");
    do_check("The quick brown fox jumps over the lazy dog.",
             "VGhlIHF1aWNrIGJyb3duIGZveCBqdW1wcyBvdmVyIHRoZSBsYXp5IGRvZy4=");
}