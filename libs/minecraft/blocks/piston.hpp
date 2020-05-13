#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct piston
{bool extended = false;
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
switch (extended)
{
case true:
switch (facing)
{
case facing_type::north:
return 1347;
case facing_type::east:
return 1348;
case facing_type::south:
return 1349;
case facing_type::west:
return 1350;
case facing_type::up:
return 1351;
case facing_type::down:
return 1352;
}
case false:
switch (facing)
{
case facing_type::north:
return 1353;
case facing_type::east:
return 1354;
case facing_type::south:
return 1355;
case facing_type::west:
return 1356;
case facing_type::up:
return 1357;
case facing_type::down:
return 1358;
}
}
}
constexpr static piston from_id(block_id_type id)
{
switch (id)
{
case 1347:
return {.extended = true, .facing = facing_type::north};
case 1348:
return {.extended = true, .facing = facing_type::east};
case 1349:
return {.extended = true, .facing = facing_type::south};
case 1350:
return {.extended = true, .facing = facing_type::west};
case 1351:
return {.extended = true, .facing = facing_type::up};
case 1352:
return {.extended = true, .facing = facing_type::down};
case 1353:
return {.extended = false, .facing = facing_type::north};
case 1354:
return {.extended = false, .facing = facing_type::east};
case 1355:
return {.extended = false, .facing = facing_type::south};
case 1356:
return {.extended = false, .facing = facing_type::west};
case 1357:
return {.extended = false, .facing = facing_type::up};
case 1358:
return {.extended = false, .facing = facing_type::down};
}}
constexpr std::string_view to_string() const
{switch (extended)
{
case true:
switch (facing)
{
case facing_type::north:
return "minecraft:piston:true:north";
case facing_type::east:
return "minecraft:piston:true:east";
case facing_type::south:
return "minecraft:piston:true:south";
case facing_type::west:
return "minecraft:piston:true:west";
case facing_type::up:
return "minecraft:piston:true:up";
case facing_type::down:
return "minecraft:piston:true:down";
}
case false:
switch (facing)
{
case facing_type::north:
return "minecraft:piston:false:north";
case facing_type::east:
return "minecraft:piston:false:east";
case facing_type::south:
return "minecraft:piston:false:south";
case facing_type::west:
return "minecraft:piston:false:west";
case facing_type::up:
return "minecraft:piston:false:up";
case facing_type::down:
return "minecraft:piston:false:down";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
