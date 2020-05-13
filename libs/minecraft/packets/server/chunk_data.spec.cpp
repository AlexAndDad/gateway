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
            [&ec](auto &&packet) {
                CHECK(not ec.failed());
                if constexpr (std::is_same_v< std::decay_t<decltype(packet)>,minecraft::packets::server::chunk_data>)
                {
                    std::cout << "Heightmaps:\n" << minecraft::nbt::pretty_print(packet.data.heightmaps) << std::endl;


                    CHECK(packet.data.chunk_x == -8);
                    CHECK(packet.data.chunk_z == -10);
                    CHECK(packet.data.full_chunk == true);
                    CHECK(packet.data.primary_bit_mask.value() == 15);
                    //CHECK(packet.data.heighmaps ) TODO
                    CHECK(packet.data.biomes.size() == 1024);
                    /*
                    for (auto & biome : packet.data.biomes)
                    {
                     // todo check biomes
                    }
                    */
                    CHECK(packet.data.data_size.value() == 9323);

                    // Check parts of the column
                    CHECK(packet.data.column.chunk_sections.size() == 4);
                    CHECK(packet.data.column.chunk_sections[0].first == 0);
                    CHECK(packet.data.column.chunk_sections[0].second.block_count == 4199);
                    CHECK(packet.data.column.chunk_sections[0].second.bits_per_block == 5);
                    CHECK(packet.data.column.chunk_sections[0].second.palette);
                    CHECK(packet.data.column.chunk_sections[0].second.data_length == 320);

                    // Check block entities
                    CHECK(packet.data.block_entities.size() == 0);

                }
                else
                {
                    CHECK(false);
                }

            },
            pack_variant.as_variant());
    }

    SECTION("compose")
    {

    }
}
