//
// Created by rhodges on 11/04/2020.
//

#pragma once

#include "net.hpp"

namespace polyfill {

    struct address_hasher
    {
        auto
        operator()(net::ip::address const &ep) const -> std::size_t;
    };

    struct endpoint_hasher
    {
        auto
        operator()(net::ip::tcp::endpoint const &ep) const -> std::size_t;

    };

}