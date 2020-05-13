#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct carved_pumpkin
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
return 4002;
case facing_type::south:
return 4003;
case facing_type::west:
return 4004;
case facing_type::east:
return 4005;
}
}
constexpr static carved_pumpkin from_id(block_id_type id)
{
switch (id)
{
case 4002:
return {.facing = facing_type::north};
case 4003:
return {.facing = facing_type::south};
case 4004:
return {.facing = facing_type::west};
case 4005:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:carved_pumpkin:north";
case facing_type::south:
return "minecraft:carved_pumpkin:south";
case facing_type::west:
return "minecraft:carved_pumpkin:west";
case facing_type::east:
return "minecraft:carved_pumpkin:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
