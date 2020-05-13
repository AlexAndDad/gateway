#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct repeating_command_block
{bool conditional = false;
enum class facing_type : std::uint8_t
{
north,
east,
south,
west,
up,
down
} facing = facing_type::north;
constexpr block_id_type to_id() const {
switch (conditional)
{
case true:
switch (facing)
{
case facing_type::north:
return 8689;
case facing_type::east:
return 8690;
case facing_type::south:
return 8691;
case facing_type::west:
return 8692;
case facing_type::up:
return 8693;
case facing_type::down:
return 8694;
}
case false:
switch (facing)
{
case facing_type::north:
return 8695;
case facing_type::east:
return 8696;
case facing_type::south:
return 8697;
case facing_type::west:
return 8698;
case facing_type::up:
return 8699;
case facing_type::down:
return 8700;
}
}
}
constexpr static repeating_command_block from_id(block_id_type id)
{
switch (id)
{
case 8689:
return {.conditional = true, .facing = facing_type::north};
case 8690:
return {.conditional = true, .facing = facing_type::east};
case 8691:
return {.conditional = true, .facing = facing_type::south};
case 8692:
return {.conditional = true, .facing = facing_type::west};
case 8693:
return {.conditional = true, .facing = facing_type::up};
case 8694:
return {.conditional = true, .facing = facing_type::down};
case 8695:
return {.conditional = false, .facing = facing_type::north};
case 8696:
return {.conditional = false, .facing = facing_type::east};
case 8697:
return {.conditional = false, .facing = facing_type::south};
case 8698:
return {.conditional = false, .facing = facing_type::west};
case 8699:
return {.conditional = false, .facing = facing_type::up};
case 8700:
return {.conditional = false, .facing = facing_type::down};
}}
constexpr std::string_view to_string() const
{switch (conditional)
{
case true:
switch (facing)
{
case facing_type::north:
return "minecraft:repeating_command_block:true:north";
case facing_type::east:
return "minecraft:repeating_command_block:true:east";
case facing_type::south:
return "minecraft:repeating_command_block:true:south";
case facing_type::west:
return "minecraft:repeating_command_block:true:west";
case facing_type::up:
return "minecraft:repeating_command_block:true:up";
case facing_type::down:
return "minecraft:repeating_command_block:true:down";
}
case false:
switch (facing)
{
case facing_type::north:
return "minecraft:repeating_command_block:false:north";
case facing_type::east:
return "minecraft:repeating_command_block:false:east";
case facing_type::south:
return "minecraft:repeating_command_block:false:south";
case facing_type::west:
return "minecraft:repeating_command_block:false:west";
case facing_type::up:
return "minecraft:repeating_command_block:false:up";
case facing_type::down:
return "minecraft:repeating_command_block:false:down";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
