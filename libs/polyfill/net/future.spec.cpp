#include "polyfill/net/future.hpp"

#include <catch2/catch.hpp>

TEST_CASE("polyfill::net::future")
{
    auto ioc  = polyfill::net::io_context();
    auto exec = ioc.get_executor();

    auto p = polyfill::net::promise< std::string >(exec);
    auto f = p.get_future();

    SECTION("coroutines")
    {
        polyfill::net::co_spawn(
            exec,
            [&]() -> polyfill::net::awaitable< void > {
                std::string s;
                try
                {
                    s = co_await f();
                    FAIL();
                }
                catch (polyfill::system_error &)
                {
                }
                catch (...)
                {
                    FAIL();
                }
            },
            polyfill::net::detached);
        p = polyfill::net::promise< std::string >(exec);
        ioc.run();
    }

    SECTION("value available prior to wait")
    {
        p.set_value("Hello");
        f.async_wait([](polyfill::error_code ec, std::optional< std::string > s) {
            CHECK(ec.message() == "Success");
            REQUIRE(s.has_value());
            CHECK(*s == "Hello");
        });

        ioc.run();
    }

    SECTION("value available after wait")
    {
        f.async_wait([](polyfill::error_code ec, std::optional< std::string > s) {
            CHECK(ec.message() == "Success");
            REQUIRE(s.has_value());
            CHECK(*s == "Hello");
        });

        p.set_value("Hello");
        ioc.run();
    }

    SECTION("error available prior to wait")
    {
        p.set_error(polyfill::net::error::operation_aborted);
        f.async_wait([](polyfill::error_code ec, std::optional< std::string > s) {
            CHECK(ec.message() == "Operation canceled");
            CHECK(not s.has_value());
        });

        ioc.run();
    }

    SECTION("error available after wait")
    {
        f.async_wait([](polyfill::error_code ec, std::optional< std::string > s) {
            CHECK(ec.message() == "Operation canceled");
            CHECK(not s.has_value());
        });

        p.set_error(polyfill::net::error::operation_aborted);
        ioc.run();
    }

    SECTION("broken promise after wait")
    {
        f.async_wait([](polyfill::error_code ec, std::optional< std::string > s) {
            CHECK(ec.message() == "Operation canceled");
            CHECK(not s.has_value());
        });

        p = polyfill::net::promise< std::string >(exec);
        ioc.run();
    }
}
TEST_CASE("polyfill::net::future2")
{
    auto ioc  = polyfill::net::io_context();
    auto exec = ioc.get_executor();

    auto ioc2  = polyfill::net::io_context();
    auto exec2 = ioc2.get_executor();

    SECTION("correct executors")
    {
        auto p = polyfill::net::promise< std::string >(exec);

        polyfill::net::post(polyfill::net::bind_executor(exec, [&] { p.set_value("Hello"); }));

        auto f        = p.get_future(exec2);
        auto tid      = std::this_thread::get_id();
        bool happened = false;
        f.async_wait([&](polyfill::error_code ec, std::optional< std::string > os) {
            CHECK(os.has_value());
            CHECK(ec.message() == "Success");
            CHECK(std::this_thread::get_id() == tid);
            happened = true;
        });

        auto t1 = std::thread([&] { ioc.run(); });

        ioc2.run();

        CHECK(happened);

        t1.join();
    }
}