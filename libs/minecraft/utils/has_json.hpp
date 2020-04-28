//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include <boost/mp11/tuple.hpp>
#include <minecraft/nvp.hpp>

namespace minecraft::utils
{
    template < class Derived >
    struct has_json
    {
        auto to_json(boost::json::value &jv) const -> void
        {
            auto &self   = static_cast< Derived const & >(*this);
            jv = boost::json::to_value(Derived::as_nvps(self), jv.storage());
        }
    };
}   // namespace minecraft::utils
