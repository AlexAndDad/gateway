//
// Created by rhodges on 12/04/2020.
//

#pragma once

#include "minecraft/parse.hpp"
#include <iostream>

namespace minecraft::client {

    struct encryption_response
    {
        std::vector<std::uint8_t> shared_secret;
        std::vector<std::uint8_t> verify_token;

        template<class Iter>
        friend auto parse(Iter first, Iter last, encryption_response& arg) -> Iter;

        friend auto operator<<(std::ostream& os, encryption_response const& arg) -> std::ostream&;
        friend auto report_on(std::ostream& os, encryption_response const& arg) -> void;
    };

    template<class Iter>
    auto parse(Iter first, Iter last, encryption_response& arg) -> Iter
    {
        using minecraft::parse;
        first = parse(first, last, arg.shared_secret);
        first = parse(first, last, arg.verify_token);
        return first;
    }

}