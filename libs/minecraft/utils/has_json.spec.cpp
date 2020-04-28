#include "minecraft/utils/has_json.hpp"
#include <boost/json.hpp>
#include <catch2/catch.hpp>
#include <iostream>

namespace minecraft
{
    struct X : minecraft::utils::has_json< X >
    {
        int    a = 10;
        double b = 11.1;

        template < class Self >
        static auto as_nvps(Self &self)
        {
            return minecraft::nvp_set(nvp("a", self.a), nvp("b", self.b));
        }
    };
}   // namespace minecraft

TEST_CASE("minecraft::utils::has_json")
{
    auto x        = minecraft::X();
    auto json     = boost::json::to_value(x);
    auto s        = to_string(json);
    auto expected = "{\"a\":10,\"b\":1.11E1}";
    CHECK(s == expected);
}