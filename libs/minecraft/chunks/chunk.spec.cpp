#include "chunk_data_impl.hpp"
#include "chunk_impl.hpp"

#include <catch2/catch.hpp>

using namespace minecraft::chunks;

namespace
{
    chunk_data_impl make_test_chunk()
    {
        auto col        = chunk_data_impl();
        auto fill_layer = [&col](int y, auto blk_id) {
            for (int x = 0; x < chunk_data_impl::x_extent; ++x)
                for (int z = 0; z < chunk_data_impl::z_extent; ++z)
                    col.change_block(vector3(x, y, z), minecraft::blocks::block_type(blk_id), false);
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
        return col;
    }
}   // namespace

TEST_CASE("minecraft::chunks::chunk",
          "[minecraft][minecraft::chunks][minecraft::chunks::chunk]")
{
    auto col = make_test_chunk();
    CHECK(col.chunk(7).palette().size() == 3);
    CHECK(col.height(vector2(6, 4)) == 127);
    auto old = col.change_block(vector3(6, 127, 4),
                                minecraft::blocks::diamond_block());
    CHECK(old == minecraft::blocks::grass_block());
    CHECK(col.chunk(7).palette().size() == 4);
    col.change_block(vector3(6, 128, 4),
                     minecraft::blocks::diamond_block());
    CHECK(col.height(vector2(6, 4)) == 128);
}
