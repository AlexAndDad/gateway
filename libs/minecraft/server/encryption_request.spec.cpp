#include <catch2/catch.hpp>
#include "minecraft/server/encryption_request.hpp"

#include <string_view>
#include <string>

using namespace std::literals;

namespace
{
    std::vector<std::uint8_t> to_bytes(std::string_view sv)
    {
        std::vector<std::uint8_t> result(sv.begin(), sv.end());
        return result;
    }
}

TEST_CASE("minecraft::server::encryption_request")
{
    std::vector<char> buffer;

    auto req = minecraft::server::encryption_request();
    req.server_id = "hello world";
    req.public_key = to_bytes("my public key"sv);
    req.verify_token = to_bytes("abdc"sv);

    compose(req, buffer);
    auto expected1 = "\001\vhello world\rmy public key\004abdc"sv;
    auto expected = std::vector<char>(expected1.begin(), expected1.end());
    REQUIRE(buffer == expected);
}