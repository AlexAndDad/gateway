#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jigsaw
{enum class facing_type : std::uint8_t
{
north,
east,
south,
west,
up,
down
} facing = facing_type::up;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
return 11272;
case facing_type::east:
return 11273;
case facing_type::south:
return 11274;
case facing_type::west:
return 11275;
case facing_type::up:
return 11276;
case facing_type::down:
return 11277;
}
}
constexpr static jigsaw from_id(block_id_type id)
{
switch (id)
{
case 11272:
return {.facing = facing_type::north};
case 11273:
return {.facing = facing_type::east};
case 11274:
return {.facing = facing_type::south};
case 11275:
return {.facing = facing_type::west};
case 11276:
return {.facing = facing_type::up};
case 11277:
return {.facing = facing_type::down};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:jigsaw:north";
case facing_type::east:
return "minecraft:jigsaw:east";
case facing_type::south:
return "minecraft:jigsaw:south";
case facing_type::west:
return "minecraft:jigsaw:west";
case facing_type::up:
return "minecraft:jigsaw:up";
case facing_type::down:
return "minecraft:jigsaw:down";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
