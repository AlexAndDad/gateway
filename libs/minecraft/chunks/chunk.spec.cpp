#include "chunk.hpp"

#include <catch2/catch.hpp>

using namespace minecraft::chunks;

TEST_CASE("minecraft::chunks::chunk", "[minecraft][minecraft::chunks][minecraft::chunks::chunk]")
{

    auto col = chunk_column();
    auto fill_layer = [&col](int y , auto blk_id)
    {
        for(int x = 0 ; x < chunk_column::x_extent; ++x)
            for (int z = 0 ; z < chunk_column::z_extent ; ++z)
                col.change_block(vector3(x, y, z), blk_id.to_id(), false);
    };

    for (int y = 0; y < 256; ++y)
    {
        if (y < 10)
        {
            fill_layer(y, minecraft::blocks::granite());
        }
        else if (y < 100)
            fill_layer(y, minecraft::blocks::stone());
        else if (y < 127)
            fill_layer(y, minecraft::blocks::dirt());
        else if (y == 127)
            fill_layer(y, minecraft::blocks::grass_block());
        else
            fill_layer(y, minecraft::blocks::air());
    }
    col.recalc();
    CHECK(col.palette().size() == 5);
    CHECK(col.height(vector2(6,4)) == 127);
    auto old = col.change_block(vector3(6, 128, 4), minecraft::blocks::diamond_block().to_id());
    CHECK(old == minecraft::blocks::air().to_id());
    CHECK(col.palette().size() == 6);
    CHECK(col.height(vector2(6,4)) == 128);
}
