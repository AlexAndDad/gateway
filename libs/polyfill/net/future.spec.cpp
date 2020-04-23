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
        f.async_wait([](polyfill::net::future_result_type<std::string> s) {

            REQUIRE(s.has_value());
            CHECK(s.value() == "Hello");
        });

        ioc.run();
    }

    SECTION("value available after wait")
    {
        f.async_wait([](polyfill::net::future_result_type<std::string> s) {
            REQUIRE(s.has_value());
            CHECK(s.value() == "Hello");
        });

        p.set_value("Hello");
        ioc.run();
    }

    SECTION("error available prior to wait")
    {
        p.set_error(polyfill::net::error::operation_aborted);
        f.async_wait([](polyfill::net::future_result_type<std::string> s) {
            REQUIRE(s.has_error());
            CHECK(s.error().message() == "Operation canceled");
        });

        ioc.run();
    }

    SECTION("error available after wait")
    {
        f.async_wait([](polyfill::net::future_result_type<std::string> s) {
            REQUIRE(s.has_error());
            CHECK(s.error().message() == "Operation canceled");
        });

        p.set_error(polyfill::net::error::operation_aborted);
        ioc.run();
    }

    SECTION("broken promise after wait")
    {
        f.async_wait([](polyfill::net::future_result_type<std::string> s) {
            REQUIRE(s.has_error());
            CHECK(s.error().message() == "Operation canceled");
        });

        p = polyfill::net::promise< std::string >(exec);
        ioc.run();
    }
}
