#include "async_queue.hpp"

#include <catch2/catch.hpp>

using namespace polyfill;
using namespace polyfill::async;

TEST_CASE("async_queue")
{
    auto ioc = net::io_context(1);
    auto e   = ioc.get_executor();
    auto q   = basic_async_queue< std::string, decltype(e) >(e);

    auto run = [](net::io_context &ioc) {
        if (ioc.stopped())
            ioc.restart();
        auto s = ioc.run();
        return s;
    };

    auto poll = [](net::io_context &ioc) {
        if (ioc.stopped())
            ioc.restart();
        auto s = ioc.poll();
        return s;
    };

    SECTION("different executors")
    {
        auto ioc2 = net::io_context(1);
        auto e2   = ioc2.get_executor();

        error_code  error;
        std::string value;

        auto make_handler = [&]() {
            return bind_executor(e2, [&](error_code ec, std::string s) {
                error = ec;
                value = s;
            });
        };

        SECTION("stop")
        {
            q.async_pop(make_handler());
            q.stop();

            CHECK(poll(ioc) == 2);
            CHECK(run(ioc2) == 1);
            CHECK(run(ioc) == 0);

            CHECK(error.message() == "Operation canceled");
        }

        SECTION("3 values")
        {
            q.push("a");
            q.push("b");
            q.push("c");
            CHECK(poll(ioc) == 3);

            q.async_pop(make_handler());
            CHECK(poll(ioc) == 1);
            CHECK(run(ioc2) == 1);
            CHECK(error.message() == "Success");
            CHECK(value == "a");

            q.async_pop(make_handler());
            CHECK(poll(ioc) == 1);
            CHECK(run(ioc2) == 1);
            CHECK(error.message() == "Success");
            CHECK(value == "b");

            q.stop();
            CHECK(poll(ioc) == 1);
            q.async_pop(make_handler());
            CHECK(poll(ioc) == 1);
            CHECK(run(ioc2) == 1);
            CHECK(error.message() == "Operation canceled");
            CHECK(value == "");
        }
    }

    SECTION("same executor")
    {
        error_code  error;
        std::string value;

        auto make_handler = [&]() {
            return [&](error_code ec, std::string s) {
                error = ec;
                value = s;
            };
        };

        SECTION("stop")
        {
            q.async_pop(make_handler());
            q.stop();

            CHECK(poll(ioc) == 2);
            CHECK(run(ioc) == 0);

            CHECK(error.message() == "Operation canceled");
        }

        SECTION("3 values")
        {
            q.push("a");
            q.push("b");
            q.push("c");
            CHECK(poll(ioc) == 3);

            q.async_pop(make_handler());
            CHECK(poll(ioc) == 1);
            CHECK(error.message() == "Success");
            CHECK(value == "a");

            q.async_pop(make_handler());
            CHECK(poll(ioc) == 1);
            CHECK(error.message() == "Success");
            CHECK(value == "b");

            q.stop();
            CHECK(poll(ioc) == 1);
            q.async_pop(make_handler());
            CHECK(poll(ioc) == 1);
            CHECK(error.message() == "Operation canceled");
            CHECK(value == "");
        }
    }
}