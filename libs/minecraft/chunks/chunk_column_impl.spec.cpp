
#include "chunk_column_impl.hpp"
#include "minecraft/posix/mmap.hpp"
#include "minecraft/testing/chunk_data.spec.ipp"
#include "polyfill/explain.hpp"
#include "polyfill/ignore_ws.hpp"
#include "minecraft/chunks/bitpack.hpp"

#include <catch2/catch.hpp>
#include <iostream>

using namespace minecraft;

TEST_CASE("minecraft::chunks::chunk_data_impl",
          "[minecraft::chunks::chunk_data_impl][minecraft::chunks][minecraft]")
{
    auto m = mmap(
        posix::open(fs::path(minecraft::testing::chunk_data_bin_filename)));

    auto first = m.begin();
    auto last  = m.end();

    //first += 0x1279;

    auto cd   = chunks::chunk_column_impl();



    SECTION("parse heightmaps")
    {


        minecraft::var_int id;
        first = minecraft::parse(first, last, id);
        CHECK(id.value() == 0x22);

        minecraft::chunks::vector2 coords;
        first = minecraft::parse(first, last, coords.x);
        first = minecraft::parse(first, last, coords.z);

        // Read the full chunk
        std::uint8_t tmp_bool;
        first      = minecraft::parse(first, last, tmp_bool);

        // read the primary bitmask
        var_int tmp;
        first = minecraft::parse(first, last, tmp);
        cd.set_primary_bit_mask(tmp.value());

        // Read heightmap
        nbt::compound parsed_nbt_val;
        first = nbt::parse(first, last, parsed_nbt_val);
        std::cout << pretty_print(parsed_nbt_val) << std::endl;

        // uncompress the data inside the heightmap
        auto & array = parsed_nbt_val.find("")->second.get_compound().find("MOTION_BLOCKING")->second.get_long_array();
        auto uncompressor = minecraft::compressed_bitfield_iterator(reinterpret_cast<char *>(array.data()),reinterpret_cast<char *>(array.data() + array.size()),9);

        auto val = *uncompressor;
        boost::ignore_unused(val);

        // Generate a hightmap
        cd.recalc();

        auto generated_nbt_val = cd.get_height_map().compose_to_nbt();
        std::cout << pretty_print(generated_nbt_val) << std::endl;
        auto x = 10;
        boost::ignore_unused(x);




        CHECK(parsed_nbt_val.find("")->second.get_compound().find("MOTION_BLOCKING")->second.get_long_array() == generated_nbt_val.find("")->second.get_compound().find("MOTION_BLOCKING")->second.get_long_array());
    }


    /*try
    {
        minecraft::chunks::vector2 coords;
        bool full_chunk;
        cd.set_primary_bit_mask(0x0f);
        next = parse(first, last,coords, full_chunk, cd);
        SUCCEED();
    }
    catch (...)
    {
        FAIL("" << polyfill::explain());
    }

    CHECK(next < last);
    CHECK(next - first == 9325);

    CHECK(cd.chunk(0).palette().size() == 18);
    CHECK(cd.chunk(1).palette().size() == 19);
    CHECK(cd.chunk(2).palette().size() == 13);
    CHECK(cd.chunk(3).palette().size() == 13);

    auto rep = fmt::format("{}", cd.chunk(0));
    auto expected = std::string(R"__chunk(y = 00 :  x = 00  x = 01  x = 02  x = 03  x = 04  x = 05  x = 06  x = 07  x = 08  x = 09  x = 10  x = 11  x = 12  x = 13  x = 14  x = 15
z = 00 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 01 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 02 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 03 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 04 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 05 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 06 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 07 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 08 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 09 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 10 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 11 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 12 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 13 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 14 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
z = 15 : bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock bedrock
y = 01 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :   bedrock    bedrock    bedrock    bedrock     stone     bedrock     stone      stone     bedrock    bedrock     stone      stone     bedrock    bedrock    bedrock    bedrock
z = 01 :   bedrock    bedrock     stone     bedrock     stone     bedrock    bedrock     stone     bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone     bedrock
z = 02 :   bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone     bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock
z = 03 :   bedrock    bedrock   andesite    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock
z = 04 :   bedrock   andesite    bedrock   andesite    bedrock    bedrock    bedrock   andesite    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone     bedrock
z = 05 :    stone    andesite    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone     bedrock     stone     bedrock     stone     bedrock
z = 06 :    stone     bedrock   andesite    bedrock    bedrock   andesite    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone     bedrock    bedrock    bedrock
z = 07 :   bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone     bedrock    bedrock    bedrock    bedrock    bedrock     stone      stone
z = 08 :   bedrock     stone      stone     bedrock    bedrock    bedrock     stone     bedrock    bedrock    bedrock    bedrock   andesite    bedrock    bedrock    bedrock    bedrock
z = 09 :   bedrock    bedrock    bedrock     stone      stone     bedrock    bedrock    bedrock    bedrock  redstone_o   bedrock    bedrock    bedrock    bedrock    bedrock    bedrock
z = 10 :   bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone     bedrock    bedrock    bedrock    bedrock    bedrock   andesite    bedrock
z = 11 :   bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone     bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock
z = 12 :   bedrock    bedrock     stone     bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone     bedrock    bedrock   andesite    bedrock    bedrock    bedrock
z = 13 :   bedrock     stone     bedrock     stone     bedrock    bedrock     stone     bedrock    bedrock    bedrock    bedrock     stone     bedrock   andesite    gravel     bedrock
z = 14 :   bedrock    bedrock   coal_ore    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone      stone     bedrock    bedrock    bedrock    bedrock
z = 15 :   bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock   andesite    bedrock
y = 02 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :    stone      stone     bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone      stone     bedrock    bedrock    bedrock     stone     bedrock     stone
z = 01 :   bedrock    bedrock     stone      stone     bedrock    bedrock     stone     bedrock     stone     bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone
z = 02 :   bedrock     stone     bedrock     stone     bedrock    bedrock    bedrock    bedrock    bedrock     stone      stone      stone     bedrock    bedrock     stone      stone
z = 03 :   bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock   andesite     stone      stone      stone      stone      stone     bedrock     stone     bedrock
z = 04 :   bedrock    bedrock    bedrock   andesite    bedrock   andesite   andesite    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone     bedrock    bedrock
z = 05 :  andesite   andesite    bedrock   andesite    bedrock    bedrock    bedrock   andesite    bedrock   andesite     stone     bedrock    bedrock    bedrock    bedrock    bedrock
z = 06 :   bedrock    bedrock   andesite   andesite    bedrock   andesite    bedrock    bedrock    bedrock    bedrock    bedrock     stone      stone      stone     bedrock    bedrock
z = 07 :   bedrock     stone      stone      stone      stone     bedrock    bedrock    bedrock     stone      stone     bedrock    bedrock     stone     bedrock     stone      stone
z = 08 :    stone     bedrock    bedrock     stone     bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock   andesite    bedrock     stone     bedrock
z = 09 :   bedrock    bedrock    bedrock    bedrock     stone     bedrock    bedrock    bedrock  redstone_o   bedrock    bedrock    bedrock    bedrock    bedrock     stone     bedrock
z = 10 :   bedrock    bedrock     stone      stone     bedrock     stone      stone      stone      stone      stone     bedrock    bedrock    bedrock   andesite    bedrock    bedrock
z = 11 :   bedrock     stone      stone     bedrock    bedrock    bedrock     stone      stone      stone      stone      stone     bedrock    bedrock   andesite    gravel     bedrock
z = 12 :   bedrock    bedrock    bedrock    bedrock     stone      stone     bedrock    bedrock    bedrock     stone     bedrock   andesite    bedrock   andesite    bedrock    bedrock
z = 13 :   bedrock     stone     bedrock     stone      stone     bedrock     stone     bedrock    bedrock     stone     bedrock    bedrock   andesite   andesite    bedrock    bedrock
z = 14 :   bedrock     stone     bedrock    bedrock    bedrock     stone     bedrock    bedrock     stone     bedrock    bedrock    bedrock    bedrock   andesite   andesite    bedrock
z = 15 :   bedrock    bedrock     stone     bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock    bedrock     stone    andesite   andesite    bedrock
y = 03 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :   bedrock    bedrock   andesite    bedrock     stone     bedrock    bedrock     stone      stone      stone      stone      stone     bedrock     stone      stone     bedrock
z = 01 :    stone     bedrock    bedrock    bedrock    bedrock     stone     bedrock    bedrock     stone     bedrock    bedrock     stone      stone     bedrock    bedrock    bedrock
z = 02 :    stone     bedrock     stone      stone      stone     bedrock    bedrock    bedrock    bedrock     stone      stone     bedrock    bedrock     stone      stone     bedrock
z = 03 :    stone     bedrock    bedrock  redstone_o   bedrock   andesite   andesite   andesite     stone     bedrock     stone      stone     bedrock    bedrock     stone     bedrock
z = 04 :   bedrock    bedrock    bedrock  redstone_o  andesite    bedrock   andesite   andesite   andesite   andesite     stone      stone      stone      stone     bedrock     stone
z = 05 :    stone     bedrock   andesite   andesite    bedrock   andesite    bedrock    bedrock   andesite   andesite     stone      stone      stone     bedrock    bedrock    bedrock
z = 06 :   bedrock     stone     bedrock   andesite   andesite   andesite   andesite   andesite    bedrock   andesite     stone      stone     bedrock    bedrock    bedrock     stone
z = 07 :    stone     bedrock     stone      stone     bedrock    bedrock    bedrock     stone      stone      stone     bedrock     stone     bedrock    bedrock     stone      stone
z = 08 :    stone      stone      stone      stone      stone      stone      stone     bedrock     stone     bedrock    bedrock     stone      stone     bedrock     stone      stone
z = 09 :    stone      stone     bedrock    bedrock     stone     bedrock    bedrock   iron_ore     stone      stone      stone     bedrock    bedrock     stone     bedrock    bedrock
z = 10 :   bedrock     stone     bedrock     stone      stone      stone      stone     bedrock     stone      stone     bedrock    bedrock   andesite    bedrock    bedrock     stone
z = 11 :    stone     bedrock     stone     bedrock    bedrock     stone      stone     bedrock    bedrock     stone      stone     bedrock   andesite    bedrock     stone      stone
z = 12 :    stone     bedrock    bedrock     stone      stone      stone     bedrock     stone     bedrock     stone      stone     bedrock     stone     bedrock    bedrock     stone
z = 13 :    stone      stone      stone      stone     bedrock     stone      stone      stone     bedrock    bedrock     stone     bedrock    bedrock     stone    andesite    bedrock
z = 14 :    stone      stone      stone      stone     bedrock    bedrock    bedrock    bedrock     stone      stone      stone      stone      stone      stone     bedrock     stone
z = 15 :   bedrock    bedrock     stone      stone      stone      stone     bedrock     stone      stone     bedrock    bedrock    bedrock    bedrock     stone      stone     bedrock
y = 04 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :   bedrock    bedrock   iron_ore   andesite   andesite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 01 :    stone    andesite   andesite   andesite   andesite     stone      stone      stone     bedrock     stone      stone      stone      stone      stone      stone      stone
z = 02 :    stone     bedrock    bedrock   andesite     stone      stone     bedrock     stone      stone      stone      stone      stone      stone      stone      stone     bedrock
z = 03 :   bedrock     stone    andesite     stone     bedrock   andesite     stone     bedrock     stone      stone      stone      stone     bedrock    bedrock    bedrock     stone
z = 04 :    stone      stone      stone    andesite   andesite   andesite   andesite    bedrock     stone      stone   redstone_o    stone      stone      stone      stone      stone
z = 05 :    stone      stone      stone     bedrock   andesite   andesite   andesite   andesite     stone      stone      stone      stone      stone      stone      stone     bedrock
z = 06 :   bedrock     stone      stone      stone      stone     bedrock    bedrock     stone     bedrock     stone      stone      stone     bedrock     stone      stone      stone
z = 07 :    stone      stone      stone      stone      stone      stone      stone      stone     bedrock     stone     bedrock     stone      stone      stone      stone      stone
z = 08 :   bedrock     stone      stone      stone      stone      stone      stone      stone      stone      stone     bedrock     stone      stone      stone      stone     bedrock
z = 09 :    stone     bedrock     stone      stone      stone      stone      stone    iron_ore     stone      stone      stone      stone      stone      stone      stone     bedrock
z = 10 :    stone     bedrock     stone     bedrock     stone      stone     bedrock   iron_ore     stone      stone      stone      stone      stone      stone      stone      stone
z = 11 :    stone      stone      stone      stone      stone      stone    iron_ore     stone      stone     bedrock     stone      stone     bedrock     stone     bedrock     stone
z = 12 :   bedrock     stone      stone      stone      stone      stone      stone      stone      stone     bedrock    bedrock     stone      stone      stone      stone      stone
z = 13 :    stone      stone      stone      stone      stone      stone      stone      stone      stone     bedrock     stone      stone      stone      stone     bedrock     stone
z = 14 :   bedrock     stone      stone     bedrock     stone      stone     bedrock     stone      stone      stone      stone      stone      stone     bedrock     stone      stone
z = 15 :    stone      stone      stone      stone     bedrock     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
y = 05 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :  andesite   andesite   andesite   andesite   andesite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 01 :    stone    andesite   andesite   andesite   andesite     stone     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone
z = 02 :    stone    andesite   andesite   andesite   andesite    gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone
z = 03 :    stone    andesite   andesite   andesite    gravel     gravel     gravel     gravel     gravel   redstone_o redstone_o    stone      stone      stone      stone      stone
z = 04 :    stone    andesite   andesite    gravel     gravel     gravel     gravel     gravel      stone   redstone_o redstone_o    stone      stone      stone      stone      stone
z = 05 :    stone      stone      stone     gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 06 :    stone      stone      stone     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 07 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 08 :   diorite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 09 :   diorite     stone      stone      stone      stone      stone      stone      stone     granite     stone      stone      stone      stone      stone      stone      stone
z = 10 :   diorite     stone      stone      stone      stone      stone    iron_ore   iron_ore    granite     stone      stone      stone      stone      stone      stone      stone
z = 11 :   diorite     stone      stone      stone      stone     granite   iron_ore   iron_ore    granite     stone      stone      stone      stone      stone      stone      stone
z = 12 :   diorite     stone      stone      stone     granite    granite   iron_ore    granite    granite     stone   redstone_o redstone_o    stone      stone      stone      stone
z = 13 :   diorite     stone      stone      stone     granite    granite    granite    granite     stone      stone   redstone_o redstone_o    stone      stone      stone      stone
z = 14 :    stone      stone      stone     granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 15 :    stone      stone      stone     granite    granite   iron_ore   iron_ore     stone      stone      stone      stone      stone      stone      stone      stone    lapis_ore
y = 06 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :    stone    andesite   andesite   andesite   andesite     stone      stone     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone
z = 01 :  iron_ore   andesite   andesite  redstone_o redstone_o   gravel     gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone
z = 02 :    stone    andesite   andesite  redstone_o   gravel     gravel     gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone
z = 03 :    stone    andesite   andesite    gravel     gravel     gravel     gravel     gravel     gravel   redstone_o    stone      stone      stone      stone      stone      stone
z = 04 :    stone    andesite   andesite    gravel     gravel     gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone
z = 05 :    stone      stone     gravel     gravel     gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone      stone
z = 06 :    stone      stone     gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 07 :    stone      stone     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 08 :   diorite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 09 :   diorite     stone      stone      stone      stone      stone      stone     granite    granite    granite     stone      stone      stone      stone      stone      stone
z = 10 :   diorite    diorite     stone      stone      stone     granite    granite    granite    granite    granite     stone      stone      stone      stone      stone      stone
z = 11 :  iron_ore    diorite     stone      stone     granite    granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone
z = 12 :  iron_ore    diorite     stone      stone     granite    granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone
z = 13 :   diorite     stone      stone     granite    granite    granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone
z = 14 :    stone      stone      stone     granite    granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone
z = 15 :    stone      stone     granite    granite    granite    granite   iron_ore     stone      stone      stone      stone      stone      stone      stone      stone    lapis_ore
y = 07 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :    stone    andesite   andesite   andesite     stone      stone      stone     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone
z = 01 :  iron_ore     stone    andesite  redstone_o redstone_o   gravel     gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone
z = 02 :    stone      stone    andesite  redstone_o   gravel     gravel     gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone
z = 03 :    stone      stone    andesite    gravel     gravel     gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone
z = 04 :    stone      stone      stone     gravel     gravel     gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone
z = 05 :    stone      stone     gravel     gravel     gravel     gravel     gravel     gravel    iron_ore     stone      stone      stone      stone      stone      stone      stone
z = 06 :    stone      stone     gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 07 :    stone      stone     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 08 :   diorite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 09 :   diorite     stone      stone      stone      stone      stone      stone     granite    granite    granite     stone      stone      stone      stone      stone    andesite
z = 10 :   diorite     stone      stone      stone      stone     granite    granite    granite    granite    granite     stone      stone      stone      stone    andesite   andesite
z = 11 :  iron_ore     stone      stone      stone     granite    granite    granite    granite    granite     stone      stone      stone      stone      stone    andesite   andesite
z = 12 :  iron_ore     stone      stone      stone     granite    granite    granite    granite    granite     stone      stone      stone      stone      stone      stone    andesite
z = 13 :    stone      stone      stone     granite    granite    granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone
z = 14 :    stone      stone      stone     granite    granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone
z = 15 :    stone      stone     granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
y = 08 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 01 :    stone      stone      stone      stone      stone      stone     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone
z = 02 :    stone      stone      stone      stone      stone     gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone
z = 03 :    stone      stone      stone      stone     gravel     gravel     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone
z = 04 :    stone      stone      stone     gravel     gravel     gravel     gravel     gravel    iron_ore     stone      stone      stone      stone      stone      stone      stone
z = 05 :    stone      stone      stone     gravel     gravel     gravel     gravel    iron_ore   iron_ore     stone      stone      stone      stone      stone      stone      stone
z = 06 :    stone      stone      stone     gravel     gravel     gravel      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 07 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 08 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone   redstone_o
z = 09 :   diorite     stone      stone      stone      stone      stone      stone      stone     granite     stone      stone      stone    andesite    granite    granite    granite
z = 10 :   granite     stone      stone      stone      stone      stone     granite    granite    granite     stone      stone    andesite   andesite   coal_ore   coal_ore   coal_ore
z = 11 :    stone      stone      stone      stone      stone     granite    granite    granite    granite     stone      stone      stone    andesite   coal_ore   coal_ore   coal_ore
z = 12 :    stone      stone      stone      stone     granite    granite    granite    granite    granite     stone      stone      stone      stone      stone    andesite   andesite
z = 13 :    stone      stone      stone      stone     granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone
z = 14 :    stone      stone      stone     granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 15 :    stone      stone      stone     granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
y = 09 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :    stone      stone      stone      stone      stone      stone      stone   redstone_o redstone_o    stone      stone      stone      stone      stone      stone      stone
z = 01 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 02 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 03 :    stone      stone      stone      stone      stone    coal_ore   coal_ore     stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 04 :    stone      stone      stone    iron_ore   coal_ore   coal_ore   coal_ore   iron_ore     stone      stone      stone      stone      stone      stone      stone      stone
z = 05 :    stone      stone      stone    coal_ore   coal_ore   coal_ore     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 06 :    stone      stone      stone    coal_ore   coal_ore   coal_ore     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 07 :   granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone     granite
z = 08 :   granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone     granite    granite    granite  redstone_o
z = 09 :   granite    granite     stone      stone      stone      stone      stone      stone      stone      stone     granite   andesite    granite    granite    granite  redstone_o
z = 10 :   granite    granite   gold_ore   gold_ore     stone      stone      stone      stone      stone      stone     granite   andesite   coal_ore   coal_ore   coal_ore   coal_ore
z = 11 :   granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone    andesite    granite   coal_ore   coal_ore   coal_ore
z = 12 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone    andesite   andesite
z = 13 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone     granite
z = 14 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 15 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
y = 10 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :    stone      stone    obsidian   obsidian   obsidian   obsidian   obsidian     stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 01 :    stone    obsidian   obsidian   obsidian   obsidian  magma_bloc    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 02 :    stone    obsidian   obsidian   obsidian  magma_bloc    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 03 :    stone    obsidian   obsidian  magma_bloc    stone    coal_ore   coal_ore     stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 04 :    stone      stone    obsidian     stone    coal_ore   coal_ore   coal_ore     stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 05 :    stone      stone      stone    coal_ore   coal_ore   coal_ore     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 06 :    stone      stone      stone    coal_ore   coal_ore   coal_ore     stone      stone      stone      stone      stone      stone      stone    iron_ore   iron_ore     stone
z = 07 :   granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone    iron_ore   iron_ore    granite
z = 08 :   granite     stone      stone      stone      stone      stone      stone      stone      stone      stone     granite     stone     granite    granite    granite    granite
z = 09 :   granite    granite     stone      stone      stone      stone      stone      stone      stone     granite    granite    granite    granite    granite    granite    granite
z = 10 :   granite   gold_ore   gold_ore   gold_ore     stone      stone      stone      stone      stone     granite    granite    granite    granite    granite   coal_ore    granite
z = 11 :   granite   gold_ore   gold_ore     stone      stone      stone      stone      stone      stone      stone     granite   andesite    granite    granite   coal_ore    granite
z = 12 :   granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone     granite   iron_ore
z = 13 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone    iron_ore    granite
z = 14 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 15 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
y = 11 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :    stone      stone      water      water      water      water      water      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 01 :    stone      water      water      water      water   bubble_col    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 02 :    stone      water      water      water   bubble_col    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 03 :    water      water      water   bubble_col    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 04 :    water      water      water      water      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 05 :    water    seagrass     water      stone   redstone_o redstone_o    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 06 :    water      water      stone      stone   redstone_o redstone_o    stone      stone      stone      stone      stone      stone      stone    iron_ore   iron_ore     stone
z = 07 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone    iron_ore   iron_ore     stone
z = 08 :   granite     stone      stone      stone      stone      stone      stone      stone      stone      stone     granite     stone     granite    granite    granite    granite
z = 09 :   granite    granite     stone      stone      stone      stone      stone      stone      stone     granite    granite    granite    granite    granite    granite    granite
z = 10 :   granite    granite    granite     stone      stone      stone      stone      stone      stone     granite    granite    granite    granite    granite    granite    granite
z = 11 :   granite    granite    granite     stone      stone      stone      stone      stone      stone      stone     granite     stone     granite    granite    granite    granite
z = 12 :   granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone    iron_ore
z = 13 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone    iron_ore     stone
z = 14 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 15 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      dirt       stone      stone
y = 12 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :    stone      stone      water      water      water      water      stone      stone      stone      stone      stone     diorite     stone      stone      stone      stone
z = 01 :    stone      water      water      water      water   bubble_col    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 02 :    stone      water      water      water   bubble_col    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 03 :    water      water      water   bubble_col    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 04 :    water      water      water      water      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 05 :    water      water      water      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 06 :    water      water      water      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 07 :    water      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 08 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 09 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone     granite     stone      stone     granite   iron_ore   iron_ore
z = 10 :   granite     stone      stone      stone      stone      stone      stone      stone      stone      stone     granite     stone      stone     granite    granite     stone
z = 11 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 12 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 13 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 14 :    dirt       stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 15 :    dirt       dirt       stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      dirt       stone      stone
y = 13 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone     diorite    diorite    diorite     stone      stone      stone
z = 01 :    stone      stone      stone      water      stone      stone      stone      stone      stone     diorite    diorite    diorite    diorite     stone      stone      stone
z = 02 : redstone_o    water      water      water      stone      stone      stone      stone      stone     diorite    diorite    diorite     stone      stone      stone      stone
z = 03 : redstone_o    water      water      stone      stone      stone      stone      stone     diorite    diorite    diorite    diorite     stone      stone      stone     granite
z = 04 :    water      water      water      stone      stone      stone      stone      stone     diorite    diorite    diorite     stone      stone      stone      stone     granite
z = 05 :    water      water      water      stone      stone      stone      stone      stone      stone     diorite     stone      stone      stone      stone      stone      stone
z = 06 :    water      water      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 07 :    stone      water      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 08 :    water      water      water      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 09 :    water      water      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone    iron_ore   iron_ore   iron_ore
z = 10 :    water    seagrass     stone     granite     stone      stone      stone      stone      stone      stone      stone      stone      stone    iron_ore   iron_ore     stone
z = 11 :    water      stone      stone     granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 12 :    stone      stone      stone     granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 13 :    stone      stone     granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 14 :    dirt       stone     granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 15 :    dirt       dirt       dirt      granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
y = 14 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :    stone      stone      stone      stone      stone      stone      stone      stone      stone     diorite    diorite    diorite   coal_ore   coal_ore   coal_ore     stone
z = 01 :    stone      stone      stone      stone      stone      stone      stone      stone     diorite    diorite    diorite    diorite    diorite   coal_ore   coal_ore     stone
z = 02 : redstone_o    stone      stone      stone      stone      stone      stone      stone     diorite    diorite    diorite    diorite    diorite     stone      stone      stone
z = 03 : redstone_o    stone      stone      stone      stone      stone      stone     diorite    diorite    diorite    diorite    diorite     stone      stone      stone     granite
z = 04 :    stone      stone      stone      stone      stone      stone      stone     diorite    diorite    diorite    diorite    diorite     stone      stone      stone     granite
z = 05 :    stone      stone      stone      stone      stone      stone      stone     diorite    diorite    diorite    diorite     stone      stone      stone      stone      stone
z = 06 :    stone      stone      stone      stone      stone      stone      stone     diorite    diorite     stone      stone      stone      stone      stone      stone      stone
z = 07 :    stone      water      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 08 :    water      water      water      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 09 :    water      water      water     granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 10 :    water      water     granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone    iron_ore     stone      stone
z = 11 :    water      water     granite    granite    granite     stone      stone    gold_ore   gold_ore     stone      stone      stone      stone      stone      stone      stone
z = 12 :    water      stone     granite    granite    granite    granite     stone    gold_ore   gold_ore     stone      stone      stone      stone      stone      stone      stone
z = 13 :    water      stone     granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 14 :    stone      stone     granite    granite    granite    granite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 15 :    dirt       dirt       dirt      diorite    diorite    diorite     stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
y = 15 :   x = 00    x = 01    x = 02    x = 03    x = 04    x = 05    x = 06    x = 07    x = 08    x = 09    x = 10    x = 11    x = 12    x = 13    x = 14    x = 15
z = 00 :   stone     stone     stone     stone     stone     stone     stone     stone     stone    diorite   diorite   diorite   coal_ore  coal_ore  coal_ore   stone
z = 01 :   stone     stone     stone     stone     stone     stone     stone     stone     stone    diorite   diorite   diorite    stone    coal_ore  coal_ore   stone
z = 02 :   stone     stone     stone     stone     stone     stone     stone     stone    diorite   diorite   diorite   diorite    stone     stone     stone     stone
z = 03 :   stone     stone     stone     stone     stone     stone     stone    diorite   diorite   diorite   diorite   diorite    stone     stone     stone     stone
z = 04 :   stone     stone     stone     stone     stone     stone     stone    diorite   diorite   diorite   diorite   diorite    stone     stone     stone     stone
z = 05 :   stone     stone     stone     stone     stone     stone     stone    diorite   diorite   diorite   diorite    stone     stone     stone     stone     stone
z = 06 :   stone     stone     stone     stone     stone     stone     stone    diorite   diorite   diorite    stone     stone     stone     stone     stone     stone
z = 07 :   stone     stone     stone     stone     stone     stone     stone   lapis_ore lapis_ore   stone     stone     stone     stone     stone     stone     stone
z = 08 :   water     water     stone     stone     stone     stone     stone   lapis_ore lapis_ore   stone     stone     stone     stone     stone     stone     stone
z = 09 :   water     water    granite   granite   granite    stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone
z = 10 :   water     water    granite   granite   granite    stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone
z = 11 :   water     water    granite   granite   granite    stone     stone    gold_ore  gold_ore  gold_ore   stone     stone     stone     stone     stone     stone
z = 12 :   water    seagrass  granite   granite   granite   granite    stone    gold_ore  gold_ore   stone     stone     stone     stone     stone     stone     stone
z = 13 :   water     stone    granite   granite   granite   granite    stone     stone     stone     stone     stone     stone     stone     stone     stone     stone
z = 14 :   water    diorite   diorite   diorite   diorite   diorite    stone     stone     stone     stone     stone     stone     stone     stone     stone     stone
z = 15 :  diorite   diorite   gold_ore  gold_ore  diorite   diorite   diorite   diorite    stone     stone     stone     stone     stone     stone     stone     stone)__chunk");
    CHECK(polyfill::strip_ws(rep) == polyfill::strip_ws(expected));

    CHECK(polyfill::strip_ws(fmt::format("{}", cd.chunk(1))) == polyfill::strip_ws(R"__chunk(y = 00 :   x = 00    x = 01    x = 02    x = 03    x = 04    x = 05    x = 06    x = 07    x = 08    x = 09    x = 10    x = 11    x = 12    x = 13    x = 14    x = 15
z = 00 :   stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone
z = 01 :   stone     stone     stone     stone     stone     stone     stone     stone     stone    diorite   diorite    stone     stone     stone     stone     stone
z = 02 :   stone     stone     stone     stone     stone     stone     stone     stone    diorite   diorite   diorite   diorite    stone     stone     stone     stone
z = 03 :   stone     stone     stone     stone     stone     stone     stone    diorite   diorite   diorite   diorite    stone     stone     stone     stone     stone
z = 04 :   stone     stone     stone     stone     stone     stone     stone    diorite   diorite   diorite   diorite    stone     stone     stone     stone     stone
z = 05 :   stone     stone     stone     stone     stone     stone     stone    diorite   diorite   diorite   diorite    stone     stone     stone     stone     stone
z = 06 :   stone     stone     stone     stone     stone     stone     stone    diorite   diorite   diorite   iron_ore  iron_ore   stone     stone     stone     stone
z = 07 :   stone     stone     stone     stone     stone     stone     stone     stone   lapis_ore   stone     stone     stone     stone     stone     stone     stone
z = 08 :   stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone
z = 09 :   stone     water     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone
z = 10 :   water     water     stone    granite    stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone
z = 11 :   water     water     stone    granite    stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone
z = 12 :   water     water     stone    granite   granite    stone     stone     stone     stone     stone     stone     stone     stone     stone     stone     stone
z = 13 :   water     water    granite   diorite   granite   granite    stone     stone     stone     stone     stone     stone     stone     stone     stone     stone
z = 14 :   water     water    diorite   diorite   diorite   diorite   diorite    stone     stone     stone     stone     stone     stone     stone     stone     stone
z = 15 :   water    diorite   diorite   diorite   diorite   diorite   diorite   diorite    stone     stone     stone     stone     stone     stone     stone     stone
y = 01 :  x = 00   x = 01   x = 02   x = 03   x = 04   x = 05   x = 06   x = 07   x = 08   x = 09   x = 10   x = 11   x = 12   x = 13   x = 14   x = 15
z = 00 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 01 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 02 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 03 :   stone    stone    stone    stone    stone    stone    stone    stone    stone   diorite   stone    stone    stone    stone    stone    stone
z = 04 :   stone    stone    stone    stone    stone    stone    stone    stone    stone   diorite   stone    stone    stone    stone    stone    stone
z = 05 :   stone    stone    stone    stone    stone    stone    stone    stone   diorite iron_ore iron_ore   stone    stone    stone    stone    stone
z = 06 :   stone    stone    stone    stone    stone    stone    stone    stone    stone  iron_ore iron_ore iron_ore   stone    stone    stone    stone
z = 07 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 08 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 09 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 10 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 11 :   stone    water    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 12 :   water    water    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 13 :   water    water    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 14 :   water    water   diorite  diorite  diorite  diorite   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 15 :   water    water    water   diorite  diorite  diorite  diorite   stone    stone    stone    stone    stone    stone    stone    stone    stone
y = 02 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 : cobbleston    lava       lava       stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 01 :    lava       lava       stone      lava       lava       stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 02 :    stone      stone      stone      lava       lava       stone      stone      stone      stone      stone      stone      water      water      stone      stone      stone
z = 03 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      water      water      water      water      stone      stone
z = 04 :   diorite     stone      stone      stone      stone      stone      stone      stone      stone      stone      water      water      water      water      stone      stone
z = 05 :   diorite     stone      stone      stone      stone      stone      stone      stone      stone      water      stone      water      water      stone      stone      stone
z = 06 :   diorite     stone      stone      stone      stone      stone      stone      stone      stone      water      water      water      stone      stone      stone      stone
z = 07 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone     diorite    diorite     stone      stone      stone      stone
z = 08 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone     diorite    diorite    diorite     stone      stone      stone
z = 09 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone     diorite     stone      stone      stone      stone
z = 10 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone     diorite    diorite     stone      stone      stone
z = 11 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone     diorite    diorite     stone      stone      stone
z = 12 :    stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 13 :    water      water      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 14 :    water      water      stone      water      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone      stone
z = 15 :    water      water      water      water      water      water      stone      stone      stone      stone     gravel     gravel      stone      stone      stone      stone
y = 03 :   x = 00     x = 01     x = 02     x = 03     x = 04     x = 05     x = 06     x = 07     x = 08     x = 09     x = 10     x = 11     x = 12     x = 13     x = 14     x = 15
z = 00 :  cave_air   cave_air     lava       lava       lava       stone      stone      stone      stone      stone      stone      water      water      water      water    seagrass
z = 01 :  cave_air   cave_air     stone      lava    cobbleston cobbleston cobbleston cobbleston    stone      stone      stone    seagrass     water      water      water      water
z = 02 :    stone      stone      stone    cave_air     lava       stone      stone      stone      water      water      stone      stone      water      water      water      water
z = 03 :   diorite     stone      stone      stone      stone      stone      stone      water      water      water      water      water      stone      stone      water      stone
z = 04 :   diorite     stone      stone      stone      stone      stone      stone      stone      stone      stone      water      water      water      water      stone      stone
z = 05 :   diorite     stone      stone      stone      stone      stone      stone      stone      water      water    seagrass     water      water      water      water      water
z = 06 :   diorite    diorite     stone      stone      stone      stone      stone      stone      water      water      water      water      stone      water      water      water
z = 07 :   diorite    diorite     stone      stone      stone      stone      stone      stone      water      water      water      water     diorite     stone      stone      stone
z = 08 :    stone      stone      stone      stone      stone      stone      stone      water    seagrass     water      water      water     diorite    diorite     stone      stone
z = 09 :    stone      stone      stone      stone      stone      stone      water      water      water      water      water      water     diorite    diorite     stone      stone
z = 10 :    stone      stone      stone      stone      stone      stone      water      water      water      water      water     diorite    diorite    diorite     stone      stone
z = 11 :    stone      stone      stone      stone      stone      water      water      water      water      water     diorite    diorite    diorite    diorite     stone    iron_ore
z = 12 :    stone      stone      stone      stone      water      water      water      water      water      water      stone     diorite    diorite    diorite     stone    iron_ore
z = 13 :    stone      stone      stone      water      water      water      water      water      water      stone      stone      stone     diorite    diorite     stone      stone
z = 14 :    stone      stone      water      water      water      water      water      water      stone      stone      stone      stone      stone      stone      stone      stone
z = 15 :    water      water      water      water      water      water    seagrass     water      water     gravel     gravel     gravel      stone      stone      stone      stone
y = 04 :  x = 00   x = 01   x = 02   x = 03   x = 04   x = 05   x = 06   x = 07   x = 08   x = 09   x = 10   x = 11   x = 12   x = 13   x = 14   x = 15
z = 00 : cave_air cave_air cave_air cave_air   lava     stone    stone    stone    stone    stone    stone    water    water    water    water    water
z = 01 : cave_air cave_air   stone    lava     lava     lava     lava     lava     stone    stone    stone    water    water    water    water    water
z = 02 :   stone    stone    stone  cave_air   lava     lava     lava     lava     water    water    stone    stone    water    water    water    water
z = 03 :  diorite   stone    stone    stone    stone    stone    stone  cave_air   water    water    water    water    stone    stone    water    water
z = 04 :  diorite   stone    stone    stone    stone    stone    stone    stone    stone    water    water    water    water    water    stone    stone
z = 05 :  diorite   stone    stone    stone    stone    stone    stone    stone    water    water    water    water    water    water    water    water
z = 06 :  diorite  diorite   stone    stone    stone    stone    stone    stone    water    water    water    water    water    water    water    water
z = 07 :  diorite  diorite   stone    stone    stone    stone    stone    water    water    water    water    water    water   diorite   stone    stone
z = 08 :   dirt     stone    stone    stone    stone    stone    stone    water    water    water    water    water   diorite  diorite   stone    stone
z = 09 :   dirt     dirt     stone    stone    stone    stone    water    water    water    water    water    water   diorite  diorite   stone    stone
z = 10 :   dirt     stone    stone    stone    stone    stone    water    water    water    water    water   diorite  diorite  diorite  diorite   stone
z = 11 :   stone    stone    stone    stone    stone    water    water    water    water    water    water   diorite  diorite  diorite  diorite iron_ore
z = 12 :   stone    stone    stone    stone    water    water    water    water    water    water   diorite  diorite  diorite  diorite  diorite   stone
z = 13 :   stone    stone    stone    water    water    water    water    water    water    stone    stone   diorite  diorite  diorite  diorite   stone
z = 14 :   stone    stone    water    water    water    water    water    water    water    stone    stone    stone   diorite  diorite   stone    stone
z = 15 :   stone    water    water    water    water    water    water    water    water   gravel   gravel   gravel    stone    stone    stone    stone
y = 05 :  x = 00   x = 01   x = 02   x = 03   x = 04   x = 05   x = 06   x = 07   x = 08   x = 09   x = 10   x = 11   x = 12   x = 13   x = 14   x = 15
z = 00 : cave_air cave_air cave_air cave_air   lava     stone    stone    stone    stone    stone    stone    stone    water    water    water    water
z = 01 : cave_air cave_air   stone  cave_air cave_air   lava   cave_air cave_air   stone    stone    stone    water    water    water    water    water
z = 02 :   stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air   water    stone    stone    water    water    water    water
z = 03 :   stone    stone    stone    stone    stone    stone    stone  cave_air   water    water    water    water    stone    stone    water    water
z = 04 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    water    water    water    water    water    stone    water
z = 05 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    water    water    water    water    water    water
z = 06 :   stone    stone    stone    stone    stone    stone    stone    stone    water    water    water    water    stone    water    water    water
z = 07 :   stone    stone    stone    stone    stone    stone    stone    stone    water    water    water    water   diorite   stone    stone    stone
z = 08 :   dirt     dirt     dirt     stone    stone    stone    stone    water    water    water    water    water   diorite   stone    stone    stone
z = 09 :   dirt     dirt     dirt     stone    stone    stone    water    water    water    water    water   diorite  diorite  diorite   stone  andesite
z = 10 :   dirt     dirt     dirt     stone    stone   granite   water    water    water    water    water   diorite  diorite  diorite  diorite andesite
z = 11 :   dirt     stone    stone    stone    stone    water    water    water    water    water   diorite  diorite  diorite  diorite  diorite andesite
z = 12 :   stone    stone    stone    stone    water    water    water    water    water    water    stone   diorite  diorite  diorite  diorite   stone
z = 13 :   stone    stone    stone    water    water    water    water    water    water    stone    stone   diorite  diorite  diorite  diorite   stone
z = 14 :   stone    stone    stone    water    water    water    water    water    stone    stone    stone    stone   diorite  diorite   stone    stone
z = 15 :   stone    stone    water    water    water    water    water    water    water    stone   gravel   gravel    stone    stone    dirt     dirt
y = 06 :  x = 00   x = 01   x = 02   x = 03   x = 04   x = 05   x = 06   x = 07   x = 08   x = 09   x = 10   x = 11   x = 12   x = 13   x = 14   x = 15
z = 00 : cave_air cave_air cave_air cave_air   lava     stone    stone    stone    stone    stone    stone    stone    stone    water    water    water
z = 01 : cave_air cave_air   stone  cave_air cave_air   lava   cave_air cave_air   stone    stone    stone    stone    water    water    water    water
z = 02 :   stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    water    water    water
z = 03 :   stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air   water    water    stone    water    water
z = 04 :   stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air   water    water    water    stone    water
z = 05 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    water    water    water    water    water
z = 06 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    water    stone    stone    water    water    water
z = 07 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    water    water    stone    stone    stone    stone    stone
z = 08 :   dirt     dirt     dirt     stone    stone   granite  granite   stone    water    water    water   diorite   stone    stone    stone  andesite
z = 09 :   dirt     dirt     dirt     stone   granite  granite  granite   water    water    water    stone    stone   diorite   stone  andesite andesite
z = 10 :   dirt     dirt     dirt     stone   granite  granite  granite   water    water    water    stone   diorite  diorite  diorite andesite andesite
z = 11 :   dirt     stone    stone    stone   granite  granite   water    water    water  andesite   stone   diorite  diorite  diorite andesite andesite
z = 12 :   stone    stone    stone    stone   granite   water    water    water    water  andesite andesite   stone   diorite  diorite   stone    stone
z = 13 :   stone    stone    stone    stone   granite   water    water    water    stone  andesite andesite andesite   stone    stone    stone    stone
z = 14 :   stone    stone    stone    stone    water    water    water   granite   stone  andesite andesite andesite   stone    stone    stone    stone
z = 15 :   stone    stone    stone    stone    water    water    water    stone    stone  andesite andesite andesite andesite   stone    dirt     dirt
y = 07 :  x = 00   x = 01   x = 02   x = 03   x = 04   x = 05   x = 06   x = 07   x = 08   x = 09   x = 10   x = 11   x = 12   x = 13   x = 14   x = 15
z = 00 : cave_air cave_air cave_air cave_air   lava     stone    stone    stone    stone    stone    stone    stone    stone    stone    water    water
z = 01 : cave_air cave_air   stone  cave_air cave_air   lava   cave_air cave_air   stone    stone    stone    stone    stone    stone    water    water
z = 02 :   stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone    water    water
z = 03 :   stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air   stone    water    water
z = 04 :   stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air   water    stone    water
z = 05 :   stone    stone   granite  granite  granite   stone    stone    stone    stone    stone    stone  cave_air cave_air   water    water    water
z = 06 :   stone    stone   granite  granite  granite  granite   stone    stone    stone    stone    stone    stone    stone    water    water    water
z = 07 :   stone    stone    stone   granite  granite  granite  granite  granite   stone    stone    stone    stone    stone    stone    stone    stone
z = 08 :   dirt     stone    stone    stone    stone   granite  granite  granite   stone    stone    stone    stone    stone    stone    stone  andesite
z = 09 :   dirt     dirt     stone    stone   granite  granite  granite  granite   stone    stone    stone    stone    stone    stone  andesite andesite
z = 10 :   dirt     dirt     stone    stone   granite  granite  granite  granite andesite andesite   stone    stone    stone  andesite andesite andesite
z = 11 :   dirt     stone    stone    stone   granite  granite  granite  granite andesite andesite andesite   stone    stone  andesite andesite andesite
z = 12 :   stone    stone    stone    stone   granite  granite  granite  granite andesite andesite andesite andesite   stone    stone    stone    stone
z = 13 :   stone    stone    stone    stone   granite  granite  granite  granite andesite andesite andesite andesite andesite   stone    stone    stone
z = 14 :   stone    stone    stone    stone   granite  granite  granite  granite andesite andesite andesite andesite andesite   stone    stone   diorite
z = 15 :   stone    stone    stone    stone   granite  granite  granite   stone    stone  andesite andesite andesite andesite andesite   stone   diorite
y = 08 :  x = 00   x = 01   x = 02   x = 03   x = 04   x = 05   x = 06   x = 07   x = 08   x = 09   x = 10   x = 11   x = 12   x = 13   x = 14   x = 15
z = 00 : cave_air cave_air cave_air cave_air   lava     stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 01 : cave_air cave_air   stone  cave_air cave_air   lava   cave_air cave_air   stone    stone    stone    stone    stone    stone    stone    water
z = 02 :   stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone    stone    water
z = 03 :   stone   granite   stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    water
z = 04 :  granite  granite  granite  granite  granite   stone    stone    stone  cave_air cave_air cave_air cave_air cave_air   water    water    water
z = 05 :  granite  granite  granite  granite  granite  granite   stone    stone    stone    stone    stone  cave_air cave_air cave_air   water    water
z = 06 :   stone    stone   granite  granite  granite  granite  granite  granite   stone    stone    stone    stone    stone  cave_air cave_air   water
z = 07 :   stone    stone   granite  granite  granite  granite  granite  granite   stone    stone    stone    stone    stone    stone    stone    stone
z = 08 :   stone    stone    stone   granite  granite  granite  granite  granite  granite   stone    stone    stone    stone    stone    stone    stone
z = 09 :   stone    stone    stone    stone   granite  granite  granite  granite   stone    stone    stone    stone    stone    stone    stone  andesite
z = 10 :   stone    stone    stone    stone   granite  granite  granite  granite andesite andesite   stone    stone    stone    stone  andesite andesite
z = 11 :   stone    stone    stone    stone   granite  granite  granite  granite andesite andesite andesite   stone    stone    stone  iron_ore iron_ore
z = 12 :   stone    stone    stone    stone   granite  granite  granite  granite andesite andesite andesite andesite   stone    stone  iron_ore iron_ore
z = 13 :   stone    stone    stone    stone   granite  granite  granite  granite andesite andesite andesite andesite andesite   stone    stone    stone
z = 14 :   stone    stone    stone    stone   granite  granite  granite   stone  andesite andesite andesite andesite andesite andesite   stone   diorite
z = 15 :   stone    stone    stone    stone    stone    stone    stone    stone  andesite andesite andesite andesite andesite andesite   stone   diorite
y = 09 :  x = 00   x = 01   x = 02   x = 03   x = 04   x = 05   x = 06   x = 07   x = 08   x = 09   x = 10   x = 11   x = 12   x = 13   x = 14   x = 15
z = 00 : cave_air cave_air cave_air cave_air   lava     lava   cave_air cave_air   stone    stone    stone    stone    stone    stone    stone    stone
z = 01 : cave_air cave_air cave_air cave_air cave_air   lava   cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone    stone
z = 02 : cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone
z = 03 :   stone   granite   stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone
z = 04 :  granite  granite  granite  granite  granite  granite   stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air   water    water
z = 05 :  granite  granite  granite  granite  granite  granite  granite   stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air   water
z = 06 :   stone   granite  granite  granite  granite  granite  granite  granite   stone    stone    stone  cave_air cave_air cave_air cave_air   water
z = 07 :   stone    stone   granite  granite  granite  granite  granite  granite  granite iron_ore   stone    stone    stone  cave_air cave_air   water
z = 08 :   stone    stone    stone   granite  granite  granite  granite  granite  granite   stone    stone    stone    stone    stone    stone    stone
z = 09 :   stone    stone    stone    stone    stone   granite  granite  granite  granite   stone    stone    stone    stone    stone    stone    stone
z = 10 :   stone    stone    stone    stone    stone   granite  granite  granite   stone    stone    stone    stone    stone    stone    stone    stone
z = 11 :   stone    stone    stone    stone    stone   granite  granite  granite andesite andesite andesite   stone    stone    stone  iron_ore iron_ore
z = 12 :   stone    stone    stone    stone    stone   granite  granite   stone  andesite andesite andesite andesite   stone    stone  iron_ore iron_ore
z = 13 :   stone    stone    stone    stone    stone   granite  granite   stone    stone  andesite andesite andesite andesite   stone    stone    stone
z = 14 :   stone    stone    stone    stone    stone    stone    stone    stone    stone  andesite andesite andesite andesite   stone    stone    stone
z = 15 :   stone    stone    stone    stone    stone    stone    stone    stone    stone  andesite andesite andesite andesite andesite   stone   diorite
y = 10 :  x = 00   x = 01   x = 02   x = 03   x = 04   x = 05   x = 06   x = 07   x = 08   x = 09   x = 10   x = 11   x = 12   x = 13   x = 14   x = 15
z = 00 : cave_air cave_air cave_air cave_air cave_air   lava   cave_air   stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 01 : cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone    stone    stone
z = 02 :   stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone    stone
z = 03 :   stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone
z = 04 :   stone   granite   stone   granite  granite   stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air   water  cave_air
z = 05 :   stone    stone   granite  granite  granite  granite   stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air
z = 06 :   stone    stone   granite  granite  granite  granite  granite  granite   stone    stone    stone    stone  cave_air cave_air cave_air cave_air
z = 07 :   stone    stone   granite  granite  granite  granite  granite  granite  granite iron_ore iron_ore   stone    stone    stone  cave_air cave_air
z = 08 :   stone    stone    stone    stone   granite  granite  granite  granite  granite iron_ore iron_ore iron_ore   stone    stone    stone    stone
z = 09 :   stone    stone    stone    stone    stone   granite  granite  granite  granite   stone    stone    stone    stone    stone    stone    stone
z = 10 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 11 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 12 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 13 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  andesite andesite   stone    stone    stone    stone
z = 14 :   stone    stone    stone    stone    stone    stone    stone    stone    stone  andesite andesite andesite andesite   stone    stone    stone
z = 15 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  andesite andesite andesite   stone    stone    stone
y = 11 :  x = 00   x = 01   x = 02   x = 03   x = 04   x = 05   x = 06   x = 07   x = 08   x = 09   x = 10   x = 11   x = 12   x = 13   x = 14   x = 15
z = 00 : cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 01 : cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone    stone    stone
z = 02 :   stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone    stone
z = 03 :   stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone
z = 04 :   stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air   water  cave_air
z = 05 :   stone    stone    stone   granite  granite   stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air
z = 06 :   stone    stone    stone   granite  granite  granite   stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air
z = 07 :   stone    stone    stone    stone   granite  granite  granite  granite   stone    stone    stone    stone    stone    stone  cave_air cave_air
z = 08 :   stone    stone    stone    stone    stone   granite  granite  granite   stone    stone  iron_ore iron_ore   stone    stone    stone    stone
z = 09 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 10 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 11 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 12 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 13 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 14 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 15 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
y = 12 :  x = 00   x = 01   x = 02   x = 03   x = 04   x = 05   x = 06   x = 07   x = 08   x = 09   x = 10   x = 11   x = 12   x = 13   x = 14   x = 15
z = 00 : cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 01 : cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone    stone    stone
z = 02 :   stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone    stone
z = 03 :   stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone
z = 04 :   stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air   water  cave_air
z = 05 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air
z = 06 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air
z = 07 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air
z = 08 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 09 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 10 : iron_ore   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 11 : iron_ore   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 12 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt     stone
z = 13 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt     dirt     dirt
z = 14 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt     dirt     dirt
z = 15 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt     stone
y = 13 :  x = 00   x = 01   x = 02   x = 03   x = 04   x = 05   x = 06   x = 07   x = 08   x = 09   x = 10   x = 11   x = 12   x = 13   x = 14   x = 15
z = 00 : cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone   diorite  diorite  diorite   stone    stone    stone    stone    stone
z = 01 : cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air  diorite   stone    stone    stone    stone    stone
z = 02 :   stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone    stone
z = 03 :   stone    stone    stone  iron_ore iron_ore cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone
z = 04 :   stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air   water  cave_air
z = 05 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air
z = 06 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air
z = 07 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air
z = 08 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 09 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 10 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 11 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 12 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt     dirt
z = 13 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt     dirt     dirt     dirt
z = 14 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt     dirt     dirt     dirt
z = 15 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt     dirt     dirt
y = 14 :  x = 00   x = 01   x = 02   x = 03   x = 04   x = 05   x = 06   x = 07   x = 08   x = 09   x = 10   x = 11   x = 12   x = 13   x = 14   x = 15
z = 00 : cave_air cave_air cave_air cave_air cave_air cave_air cave_air  diorite  diorite  diorite  diorite  diorite  diorite   stone    stone    stone
z = 01 : cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air  diorite   stone    stone    stone    stone    stone
z = 02 :   stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone    stone    stone
z = 03 :   stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    water    stone
z = 04 :   stone    stone    stone    stone    stone    stone    stone   diorite cave_air cave_air cave_air cave_air cave_air cave_air   water  cave_air
z = 05 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air
z = 06 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air
z = 07 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air
z = 08 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 09 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 10 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 11 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 12 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt     dirt
z = 13 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt     dirt     dirt
z = 14 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt     dirt     dirt
z = 15 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt     dirt
y = 15 :  x = 00   x = 01   x = 02   x = 03   x = 04   x = 05   x = 06   x = 07   x = 08   x = 09   x = 10   x = 11   x = 12   x = 13   x = 14   x = 15
z = 00 : cave_air cave_air cave_air cave_air cave_air cave_air cave_air  diorite  diorite  diorite  diorite  diorite  diorite  diorite   stone    stone
z = 01 : cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air  diorite  diorite  diorite  diorite   stone    stone
z = 02 :   stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air  diorite   stone    stone    stone    stone
z = 03 :   stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air cave_air cave_air   stone    stone    stone
z = 04 :   stone    stone    stone    stone    stone    stone    stone   diorite cave_air cave_air cave_air cave_air cave_air cave_air cave_air iron_ore
z = 05 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air cave_air cave_air
z = 06 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air cave_air cave_air
z = 07 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone  cave_air cave_air
z = 08 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 09 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 10 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 11 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone
z = 12 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     stone    dirt
z = 13 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt
z = 14 :   stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    stone    dirt     dirt     dirt     dirt
z = 15 :   stone    stone    stone    stone    stone  iron_ore iron_ore   stone    stone    stone    stone    stone    stone    dirt     stone    dirt)__chunk"));
//    CHECK(fmt::format("{}", cd.chunk(2)) == R"__chunk()__chunk");
//    CHECK(fmt::format("{}", cd.chunk(3)) == R"__chunk()__chunk");
*/


}
