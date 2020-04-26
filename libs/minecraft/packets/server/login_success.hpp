#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/net.hpp"
#include "minecraft/packet_id.hpp"
#include <fmt/ostream.h>
#include "minecraft/multibyte.hpp"
#include "minecraft/report.hpp"
#include "minecraft/packets/packet_base.hpp"
#include "minecraft/nvp.hpp"
#include "minecraft/types.hpp"

namespace minecraft::packets::server
{
    struct login_success : packet_base<server_login_packet::login_success, login_success>
    {
        login_success() = default;

        varchar< 36 > uuid;
        varchar< 16 > username;

        template<class Self>
        static auto as_nvps(Self& self)
        {
            return nvp_set(nvp("uuid", self.uuid), nvp("username", self.username));
        }
    };

}

