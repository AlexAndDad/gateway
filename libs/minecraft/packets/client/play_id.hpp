#pragma once

#include <wise_enum/wise_enum.h>


namespace minecraft::packets::client
{
    WISE_ENUM_CLASS((play_id, std::int32_t),
                    (keep_alive, 0x0F));
}