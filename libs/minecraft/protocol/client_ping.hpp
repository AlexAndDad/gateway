#pragma once

#include "minecraft/easy_io.hpp"
#include "minecraft/net.hpp"
#include "minecraft/to_json.hpp"

#include <string>

namespace minecraft::protocol
{
    struct ping_result : has_easy_io< ping_result >
    {
        static constexpr auto classname() { return "ping_result"; }

        template < class Self >
        static constexpr auto as_nvps(Self &self)
        {
            return nvp_set(nvp("", self.json), nvp("ping_time", self.ping_time));
        }

        boost::json::value        json;
        std::chrono::microseconds ping_time;
    };

    auto ping(std::string const &hostname, std::string const &port) -> net::awaitable< ping_result >;

}   // namespace minecraft::protocol