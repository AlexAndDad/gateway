//
// Created by rhodges on 13/04/2020.
//

#pragma once
#include "minecraft/parse.hpp"
#include "minecraft/types.hpp"
#include "play_id.hpp"

#include <ostream>
#include <string>
#include <vector>
#include <wise_enum.h>

namespace minecraft::packets::server
{

    struct chat_message
    {
        WISE_ENUM_MEMBER((chat_position, std::uint8_t), (chat_box, 0), (system_message, 1), (game_info, 2))

        static constexpr auto id() { return play_id::chat_message; }

        varchar<32767>  json_data;
        chat_position position;
    };

    std::ostream &operator<<(std::ostream &os, chat_message const &arg);
    std::size_t   compose(chat_message const &arg, std::vector< char > &target);

    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, chat_message& packet, error_code& ec);


}   // namespace minecraft::packets::server