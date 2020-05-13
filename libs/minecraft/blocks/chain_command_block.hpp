#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct chain_command_block
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
return 8701;
case facing_type::east:
return 8702;
case facing_type::south:
return 8703;
case facing_type::west:
return 8704;
case facing_type::up:
return 8705;
case facing_type::down:
return 8706;
}
case false:
switch (facing)
{
case facing_type::north:
return 8707;
case facing_type::east:
return 8708;
case facing_type::south:
return 8709;
case facing_type::west:
return 8710;
case facing_type::up:
return 8711;
case facing_type::down:
return 8712;
}
}
}
constexpr static chain_command_block from_id(block_id_type id)
{
switch (id)
{
case 8701:
return {.conditional = true, .facing = facing_type::north};
case 8702:
return {.conditional = true, .facing = facing_type::east};
case 8703:
return {.conditional = true, .facing = facing_type::south};
case 8704:
return {.conditional = true, .facing = facing_type::west};
case 8705:
return {.conditional = true, .facing = facing_type::up};
case 8706:
return {.conditional = true, .facing = facing_type::down};
case 8707:
return {.conditional = false, .facing = facing_type::north};
case 8708:
return {.conditional = false, .facing = facing_type::east};
case 8709:
return {.conditional = false, .facing = facing_type::south};
case 8710:
return {.conditional = false, .facing = facing_type::west};
case 8711:
return {.conditional = false, .facing = facing_type::up};
case 8712:
return {.conditional = false, .facing = facing_type::down};
}}
constexpr std::string_view to_string() const
{switch (conditional)
{
case true:
switch (facing)
{
case facing_type::north:
return "minecraft:chain_command_block:true:north";
case facing_type::east:
return "minecraft:chain_command_block:true:east";
case facing_type::south:
return "minecraft:chain_command_block:true:south";
case facing_type::west:
return "minecraft:chain_command_block:true:west";
case facing_type::up:
return "minecraft:chain_command_block:true:up";
case facing_type::down:
return "minecraft:chain_command_block:true:down";
}
case false:
switch (facing)
{
case facing_type::north:
return "minecraft:chain_command_block:false:north";
case facing_type::east:
return "minecraft:chain_command_block:false:east";
case facing_type::south:
return "minecraft:chain_command_block:false:south";
case facing_type::west:
return "minecraft:chain_command_block:false:west";
case facing_type::up:
return "minecraft:chain_command_block:false:up";
case facing_type::down:
return "minecraft:chain_command_block:false:down";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
