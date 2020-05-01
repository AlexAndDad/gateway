//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "minecraft/wise_enum.hpp"

#include <boost/json.hpp>

namespace minecraft
{
    template < class T >
    auto to_json(T &&arg, boost::json::storage_ptr sp = {})
        -> decltype(boost::json::to_value(std::forward< T >(arg), std::move(sp)))
    {
        return boost::json::to_value(std::forward< T >(arg), std::move(sp));
    }

    inline auto to_json(std::string_view s, boost::json::storage_ptr sp = {})
    {
        auto rs = boost::json::string(s.data(), s.size(), sp);
        return boost::json::value(std::move(rs));
    }

    inline auto to_json(boost::string_view s, boost::json::storage_ptr sp = {})
    {
        auto rs = boost::json::string(s.data(), s.size(), sp);
        return boost::json::value(std::move(rs));
    }

    template < class Enum, std::enable_if_t< wise_enum::is_wise_enum_v< std::decay_t< Enum > > > * = nullptr >
    auto to_json(Enum &&e, boost::json::storage_ptr sp = {})
    {
        return to_json(wise_enum::to_string(e), std::move(sp));
    }

}   // namespace minecraft