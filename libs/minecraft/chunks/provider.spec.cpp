#include "chunk_column_impl.hpp"
#include "provider.hpp"

#include <catch2/catch.hpp>

using namespace std::literals;
using namespace minecraft;

namespace
{
    chunks::chunk_column_impl make_test_chunk()
    {
        auto col        = chunks::chunk_column_impl();
        auto fill_layer = [&col](int y, auto blk_id) {
            for (int x = 0; x < chunks::chunk_column_impl::x_extent; ++x)
                for (int z = 0; z < chunks::chunk_column_impl::z_extent; ++z)
                    col.change_block(chunks::vector3(x, y, z), blk_id, false);
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

    std::size_t run(net::io_context &ioc)
    {
        auto spins = ioc.run();
        ioc.restart();
        return spins;
    }
}   // namespace

TEST_CASE("minecraft::chunks::provider",
          "[minecraft::chunks::provider][minecraft::chunks][minecraft]")
{
    SECTION("Destroy provider")
    {
        auto ioc      = net::io_context();
        auto provider = chunks::provider(ioc.get_executor());
        auto consumer =
            provider.connect(net::make_strand(net::system_executor()));   // 1

        auto f   = consumer.async_wait(net::use_future);   // 2
        provider = chunks::provider(ioc.get_executor());   // 3
        CHECK(run(ioc) == 3);
        auto state = f.wait_for(1s);
        REQUIRE(state == std::future_status::ready);
        CHECK(f.valid());
        CHECK_THROWS_AS(f.get(), system_error);
    }

    SECTION("Cancel consumer")
    {
        auto ioc      = net::io_context();
        auto provider = chunks::provider(ioc.get_executor());
        auto consumer =
            provider.connect(net::make_strand(net::system_executor()));   // 1

        auto f = consumer.async_wait(net::use_future);   // 2
        consumer.cancel();                               // 3
        CHECK(run(ioc) == 3);
        auto state = f.wait_for(1s);   // 2
        REQUIRE(state == std::future_status::ready);
        CHECK(f.valid());
        CHECK_THROWS_AS(f.get(), system_error);

        SECTION("Next wait should not fail")
        {
            f = consumer.async_wait(net::use_future);   // 1
            provider.notify(make_test_chunk());         // 2
            CHECK(run(ioc) == 2);
            auto state = f.wait_for(1s);
            REQUIRE(state == std::future_status::ready);
            CHECK(f.valid());
            auto update = chunks::chunk_update();
            CHECK_NOTHROW(update = f.get());
            CHECK(holds_alternative< std::unique_ptr< chunks::chunk_column_impl > >(
                update.as_variant()));
        }
    }

    SECTION("Snapshot ordering")
    {
        auto ioc      = net::io_context();
        auto provider = chunks::provider(ioc.get_executor());
        auto consumer = provider.connect(
            net::make_strand(net::system_executor()));   // 1 post

        auto f = consumer.async_wait(net::use_future);   // 1 post
        provider.notify(make_test_chunk());              // 1 post
        CHECK(run(ioc) == 3);
        auto state = f.wait_for(1s);
        REQUIRE(state == std::future_status::ready);
        CHECK(f.valid());
        auto update = chunks::chunk_update();
        CHECK_NOTHROW(update = f.get());
        CHECK(holds_alternative< std::unique_ptr< chunks::chunk_column_impl > >(
            update.as_variant()));

        f = consumer.async_wait(net::use_future);   // 1 post
        provider.notify(chunks::vector3(0, 128, 0),
                        blocks::birch_wood());   // 1 post
        CHECK(run(ioc) == 2);

        state = f.wait_for(1s);
        REQUIRE(state == std::future_status::ready);
        CHECK(f.valid());
        CHECK_NOTHROW(update = f.get());
        REQUIRE(holds_alternative< chunks::block_update >(update.as_variant()));
        auto &u = get< chunks::block_update >(update.as_variant());
        CHECK(u.new_state == blocks::birch_wood());

        for (int x = 0; x < 16; ++x)
            for (int y = 0; y < 16; ++y)
                provider.notify(chunks::vector3(x, 128, y),
                                blocks::birch_wood());

        CHECK(run(ioc) == 256);
        f = consumer.async_wait(net::use_future);   // 1 post
        CHECK(run(ioc) == 1);
        state = f.wait_for(1s);
        REQUIRE(state == std::future_status::ready);
        CHECK(f.valid());
        CHECK_NOTHROW(update = f.get());
        REQUIRE(holds_alternative< std::vector< chunks::block_update > >(
            update.as_variant()));
        auto &v =
            get< std::vector< chunks::block_update > >(update.as_variant());
        CHECK(v.size() == 256);
    }

}   // namespace minecraft::chunks