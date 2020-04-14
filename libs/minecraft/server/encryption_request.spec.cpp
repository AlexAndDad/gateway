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
    std::string buffer;

    auto req = minecraft::server::encryption_request();
    req.server_id = "hello world";
    req.public_key = to_bytes("my public key"sv);
    req.verify_token = to_bytes("abdc"sv);

    minecraft::encode_frame(req, buffer);
    REQUIRE(buffer == "! \001\vhello world\rmy public key\004abdc"sv);
}