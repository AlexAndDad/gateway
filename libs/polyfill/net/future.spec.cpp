#include "polyfill/net/future.hpp"

#include <catch2/catch.hpp>

TEST_CASE("polyfill::net::future")
{
    auto ioc = polyfill::net::io_context();
    auto exec = ioc.get_executor();

    auto p = polyfill::net::promise< std::string >(exec);
    auto f = p.get_future();

    SECTION("coroutines")
    {
        polyfill::net::co_spawn(exec, [&]()->polyfill::net::awaitable<std::string>{
            co_return * co_await f.co_wait();
        }, [](std::exception_ptr ep, std::string s){
            CHECK(bool(ep));
        });
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