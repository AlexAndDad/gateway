//
// Created by rhodges on 13/04/2020.
//

#pragma once
#include "minecraft/wise_enum.hpp"
#include "minecraft/packets/packet_base.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/types.hpp"
#include "play_id.hpp"

#include <ostream>
#include <string>
#include <vector>
#include <wise_enum.h>

namespace minecraft::packets::server
{
    struct chat_message : packet_base< play_id::chat_message, chat_message >
    {
        WISE_ENUM_MEMBER((chat_position, std::uint8_t), (chat_box, 0), (system_message, 1), (game_info, 2))
        WISE_ENUM_MEMBER_ENABLE_IO(chat_position)

        static constexpr auto id() { return play_id::chat_message; }

        varchar< 32767 > json_data;
        chat_position    position;

        template < class Self >
        static auto as_nvps(Self &self)
        {
            return nvp_set(nvp("json_data", self.json_data), nvp("position", self.position));
        }
    };

}   // namespace minecraft::packets::server