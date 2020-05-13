#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct hopper
{bool enabled = true;
enum class facing_type : std::uint8_t
{
down,
north,
south,
west,
east
} facing = facing_type::down;
constexpr block_id_type to_id() const {
switch (enabled)
{
case true:
switch (facing)
{
case facing_type::down:
return 6192;
case facing_type::north:
return 6193;
case facing_type::south:
return 6194;
case facing_type::west:
return 6195;
case facing_type::east:
return 6196;
}
case false:
switch (facing)
{
case facing_type::down:
return 6197;
case facing_type::north:
return 6198;
case facing_type::south:
return 6199;
case facing_type::west:
return 6200;
case facing_type::east:
return 6201;
}
}
}
constexpr static hopper from_id(block_id_type id)
{
switch (id)
{
case 6192:
return {.enabled = true, .facing = facing_type::down};
case 6193:
return {.enabled = true, .facing = facing_type::north};
case 6194:
return {.enabled = true, .facing = facing_type::south};
case 6195:
return {.enabled = true, .facing = facing_type::west};
case 6196:
return {.enabled = true, .facing = facing_type::east};
case 6197:
return {.enabled = false, .facing = facing_type::down};
case 6198:
return {.enabled = false, .facing = facing_type::north};
case 6199:
return {.enabled = false, .facing = facing_type::south};
case 6200:
return {.enabled = false, .facing = facing_type::west};
case 6201:
return {.enabled = false, .facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (enabled)
{
case true:
switch (facing)
{
case facing_type::down:
return "minecraft:hopper:true:down";
case facing_type::north:
return "minecraft:hopper:true:north";
case facing_type::south:
return "minecraft:hopper:true:south";
case facing_type::west:
return "minecraft:hopper:true:west";
case facing_type::east:
return "minecraft:hopper:true:east";
}
case false:
switch (facing)
{
case facing_type::down:
return "minecraft:hopper:false:down";
case facing_type::north:
return "minecraft:hopper:false:north";
case facing_type::south:
return "minecraft:hopper:false:south";
case facing_type::west:
return "minecraft:hopper:false:west";
case facing_type::east:
return "minecraft:hopper:false:east";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
