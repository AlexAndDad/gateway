#include "cheap_work_guard.hpp"
#include "polyfill/net.hpp"

#include <catch2/catch.hpp>

using namespace polyfill::async;
using namespace polyfill;

TEST_CASE("polyfill::async::cheap_work_guard")
{
    using T = cheapest_work_guard_t< net::io_context::executor_type >;
    auto b = std::is_same_v<cheap_work_guard<net::io_context::executor_type>, T>;
    CHECK(b);

}   // namespace polyfill::async