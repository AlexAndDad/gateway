//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include <boost/json/to_value.hpp>
#include "minecraft/wise_enum.hpp"

namespace minecraft
{
    template < class T>
    auto to_json(T &&arg, boost::json::storage_ptr sp = {})
    -> decltype(boost::json::to_value(std::forward< T >(arg), std::move(sp)))
    {
        return boost::json::to_value(std::forward< T >(arg), std::move(sp));
    }

    template < class Enum, std::enable_if_t< wise_enum::is_wise_enum_v< std::decay_t< Enum > > > * = nullptr >
    auto to_json(Enum &&e, boost::json::storage_ptr sp = {})
    {
        return boost::json::to_value(wise_enum::to_string(e), std::move(sp));
    }
}   // namespace minecraft