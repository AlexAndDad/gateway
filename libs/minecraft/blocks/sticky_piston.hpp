#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct sticky_piston
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
return 1328;
case facing_type::east:
return 1329;
case facing_type::south:
return 1330;
case facing_type::west:
return 1331;
case facing_type::up:
return 1332;
case facing_type::down:
return 1333;
}
case false:
switch (facing)
{
case facing_type::north:
return 1334;
case facing_type::east:
return 1335;
case facing_type::south:
return 1336;
case facing_type::west:
return 1337;
case facing_type::up:
return 1338;
case facing_type::down:
return 1339;
}
}
}
constexpr static sticky_piston from_id(block_id_type id)
{
switch (id)
{
case 1328:
return {.extended = true, .facing = facing_type::north};
case 1329:
return {.extended = true, .facing = facing_type::east};
case 1330:
return {.extended = true, .facing = facing_type::south};
case 1331:
return {.extended = true, .facing = facing_type::west};
case 1332:
return {.extended = true, .facing = facing_type::up};
case 1333:
return {.extended = true, .facing = facing_type::down};
case 1334:
return {.extended = false, .facing = facing_type::north};
case 1335:
return {.extended = false, .facing = facing_type::east};
case 1336:
return {.extended = false, .facing = facing_type::south};
case 1337:
return {.extended = false, .facing = facing_type::west};
case 1338:
return {.extended = false, .facing = facing_type::up};
case 1339:
return {.extended = false, .facing = facing_type::down};
}}
constexpr std::string_view to_string() const
{switch (extended)
{
case true:
switch (facing)
{
case facing_type::north:
return "minecraft:sticky_piston:true:north";
case facing_type::east:
return "minecraft:sticky_piston:true:east";
case facing_type::south:
return "minecraft:sticky_piston:true:south";
case facing_type::west:
return "minecraft:sticky_piston:true:west";
case facing_type::up:
return "minecraft:sticky_piston:true:up";
case facing_type::down:
return "minecraft:sticky_piston:true:down";
}
case false:
switch (facing)
{
case facing_type::north:
return "minecraft:sticky_piston:false:north";
case facing_type::east:
return "minecraft:sticky_piston:false:east";
case facing_type::south:
return "minecraft:sticky_piston:false:south";
case facing_type::west:
return "minecraft:sticky_piston:false:west";
case facing_type::up:
return "minecraft:sticky_piston:false:up";
case facing_type::down:
return "minecraft:sticky_piston:false:down";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
