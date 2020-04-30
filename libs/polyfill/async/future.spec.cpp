//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#include "future.hpp"

#include <catch2/catch.hpp>

using namespace polyfill;

TEST_CASE("polyfill::async::future")
{
    auto ioc  = net::io_context();

    auto p = async::promise< std::string >();
    auto f = p.get_future();

    SECTION("value available prior to wait")
    {
        p.set_value("Hello");
        f.async_wait([](polyfill::async::future_result_type<std::string> s) {

            REQUIRE(s.has_value());
            CHECK(s.value() == "Hello");
        });

        ioc.run();
    }

    SECTION("value available after wait")
    {
        f.async_wait([](async::future_result_type<std::string> s) {
            REQUIRE(s.has_value());
            CHECK(s.value() == "Hello");
        });

        p.set_value("Hello");
        ioc.run();
    }

    SECTION("error available prior to wait")
    {
        p.set_error(net::error::operation_aborted);
        f.async_wait([](async::future_result_type<std::string> s) {
            REQUIRE(s.has_error());
            CHECK(s.error().message() == "Operation canceled");
        });

        ioc.run();
    }

    SECTION("error available after wait")
    {
        f.async_wait([](async::future_result_type<std::string> s) {
            REQUIRE(s.has_error());
            CHECK(s.error().message() == "Operation canceled");
        });

        p.set_error(polyfill::net::error::operation_aborted);
        ioc.run();
    }

    SECTION("broken promise after wait")
    {
        f.async_wait([](async::future_result_type<std::string> s) {
            REQUIRE(s.has_error());
            CHECK(s.error().message() == "Operation canceled");
        });

        p = async::promise< std::string >();
        ioc.run();
    }

}
TEST_CASE("polyfill::async::future<void>")
{
    auto ioc  = net::io_context();

    auto p = async::promise< void>();
    auto f = p.get_future();

    SECTION("test void return")
    {
        p.set_value();
        f.async_wait([](polyfill::async::future_result_type<void> s) {

            REQUIRE(s.has_value());
        });

        ioc.run();
    }


}