#include "co_future.hpp"

#include <catch2/catch.hpp>

TEST_CASE("polyfill::async::co_future")
{
    using namespace polyfill;
    using namespace std::literals;

    auto ioc1 = net::io_context();
    auto ioc2 = net::io_context();
    auto wg1  = make_work_guard(ioc1);
    auto wg2  = make_work_guard(ioc2);
    auto t1   = std::thread([&] { ioc1.run(); });
    auto t2   = std::thread([&] { ioc2.run(); });

    std::promise< void > p;
    auto                 f = p.get_future();

    ::config::net::co_spawn(
        ioc1,
        [&]() -> net::awaitable< void > {
            //
            // test starts here
            //

            auto f = async::co_future< std::string >(bind_executor(ioc2, []() -> net::awaitable< std::string > {
                auto t = net::system_timer(co_await net::this_coro::executor);
                t.expires_after(1s);
                co_await t.async_wait(net::use_awaitable);
                co_return std::string("Hello");
            }));

            auto s = co_await f();

            CHECK(s == "Hello");

            //
            // test ends here
            //

            p.set_value();
        },
        ::config::net::detached);

    f.get();

    wg1.reset();
    wg2.reset();
    t1.join();
    t2.join();
}