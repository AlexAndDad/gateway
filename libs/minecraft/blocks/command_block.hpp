#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct command_block
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
return 5628;
case facing_type::east:
return 5629;
case facing_type::south:
return 5630;
case facing_type::west:
return 5631;
case facing_type::up:
return 5632;
case facing_type::down:
return 5633;
}
case false:
switch (facing)
{
case facing_type::north:
return 5634;
case facing_type::east:
return 5635;
case facing_type::south:
return 5636;
case facing_type::west:
return 5637;
case facing_type::up:
return 5638;
case facing_type::down:
return 5639;
}
}
}
constexpr static command_block from_id(block_id_type id)
{
switch (id)
{
case 5628:
return {.conditional = true, .facing = facing_type::north};
case 5629:
return {.conditional = true, .facing = facing_type::east};
case 5630:
return {.conditional = true, .facing = facing_type::south};
case 5631:
return {.conditional = true, .facing = facing_type::west};
case 5632:
return {.conditional = true, .facing = facing_type::up};
case 5633:
return {.conditional = true, .facing = facing_type::down};
case 5634:
return {.conditional = false, .facing = facing_type::north};
case 5635:
return {.conditional = false, .facing = facing_type::east};
case 5636:
return {.conditional = false, .facing = facing_type::south};
case 5637:
return {.conditional = false, .facing = facing_type::west};
case 5638:
return {.conditional = false, .facing = facing_type::up};
case 5639:
return {.conditional = false, .facing = facing_type::down};
}}
constexpr std::string_view to_string() const
{switch (conditional)
{
case true:
switch (facing)
{
case facing_type::north:
return "minecraft:command_block:true:north";
case facing_type::east:
return "minecraft:command_block:true:east";
case facing_type::south:
return "minecraft:command_block:true:south";
case facing_type::west:
return "minecraft:command_block:true:west";
case facing_type::up:
return "minecraft:command_block:true:up";
case facing_type::down:
return "minecraft:command_block:true:down";
}
case false:
switch (facing)
{
case facing_type::north:
return "minecraft:command_block:false:north";
case facing_type::east:
return "minecraft:command_block:false:east";
case facing_type::south:
return "minecraft:command_block:false:south";
case facing_type::west:
return "minecraft:command_block:false:west";
case facing_type::up:
return "minecraft:command_block:false:up";
case facing_type::down:
return "minecraft:command_block:false:down";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
