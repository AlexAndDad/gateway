#include "config/net.hpp"
#include "ticker.hpp"

#include <catch2/catch.hpp>

namespace
{
    [[maybe_unused]] auto time_in_ms() -> std::chrono::milliseconds
    {
        auto time_now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast< std::chrono::milliseconds >(time_now.time_since_epoch());
    }
}   // namespace

TEST_CASE("minecraft::time::ticker")
{
    using namespace config;
    using namespace minecraft::time;
    auto ioc     = net::io_context(1);
    auto strand_ = net::io_context::strand(ioc);

    SECTION("fast delta time = 20ms")
    {
        ticker ticker_ = ticker(strand_, std::chrono::milliseconds(20));

        net::co_spawn(strand_, [&ticker_]() -> net::awaitable< void > {
            ticker_.start();   // Start the ticker

            for (auto i = 0; i < 20; i++)
            {
                tick_result res        = co_await ticker_.await_next_tick();

                INFO("delta: ")
                INFO(res.delta_time.count());
                CHECK(res.delta_time == std::chrono::milliseconds(20));
                CHECK_FALSE(res.slow);
            }
        },net::detached);

        ioc.run();
    }
}