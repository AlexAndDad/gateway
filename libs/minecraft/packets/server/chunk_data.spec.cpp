#include "chunk_data.hpp"
#include "minecraft/filesystem.hpp"
#include "minecraft/packets/server_play_packet.hpp"
#include "minecraft/types/buffer.hpp"

#include <catch2/catch.hpp>
#include <fstream>
#include <iostream>

TEST_CASE("chunk data packet")
{
    static char path[]    = "/home/ahodges/github/gateway/test_data/chunk_data.bin";
    auto        in_stream = std::ifstream(path, std::ofstream::ios_base::in | std::ofstream::ios_base::binary);

    auto size = minecraft::fs::file_size(path);

    auto buf = minecraft::compose_buffer();
    buf.resize(size);
    in_stream.read(buf.data(), size);

    auto span = minecraft::to_span(buf);

    SECTION("parse")
    {
        auto pack_variant = minecraft::packets::server::server_play_packet();

        auto                  first = span.begin();
        auto                  last  = span.end();
        minecraft::error_code ec;

        first = minecraft::packets::parse(first, last, pack_variant, ec);

        visit(
            [](auto &&packet) {
                if constexpr (std::is_same_v< std::decay_t<decltype(packet)>,minecraft::packets::server::chunk_data>)
                {
                    CHECK(true);

                }
                else
                {
                    CHECK(false);
                }

            },
            pack_variant.as_variant());
    }
}
