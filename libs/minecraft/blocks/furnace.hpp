#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct furnace
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool lit = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (lit)
{
case true:
return 3371;
case false:
return 3372;
}
case facing_type::south:
switch (lit)
{
case true:
return 3373;
case false:
return 3374;
}
case facing_type::west:
switch (lit)
{
case true:
return 3375;
case false:
return 3376;
}
case facing_type::east:
switch (lit)
{
case true:
return 3377;
case false:
return 3378;
}
}
}
constexpr static furnace from_id(block_id_type id)
{
switch (id)
{
case 3371:
return {.facing = facing_type::north, .lit = true};
case 3372:
return {.facing = facing_type::north, .lit = false};
case 3373:
return {.facing = facing_type::south, .lit = true};
case 3374:
return {.facing = facing_type::south, .lit = false};
case 3375:
return {.facing = facing_type::west, .lit = true};
case 3376:
return {.facing = facing_type::west, .lit = false};
case 3377:
return {.facing = facing_type::east, .lit = true};
case 3378:
return {.facing = facing_type::east, .lit = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (lit)
{
case true:
return "minecraft:furnace:north:true";
case false:
return "minecraft:furnace:north:false";
}
case facing_type::south:
switch (lit)
{
case true:
return "minecraft:furnace:south:true";
case false:
return "minecraft:furnace:south:false";
}
case facing_type::west:
switch (lit)
{
case true:
return "minecraft:furnace:west:true";
case false:
return "minecraft:furnace:west:false";
}
case facing_type::east:
switch (lit)
{
case true:
return "minecraft:furnace:east:true";
case false:
return "minecraft:furnace:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
