#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct activator_rail
{bool powered = false;
enum class shape_type : std::uint8_t
{
north_south,
east_west,
ascending_east,
ascending_west,
ascending_north,
ascending_south
} shape = shape_type::north_south;
constexpr block_id_type to_id() const {
switch (powered)
{
case true:
switch (shape)
{
case shape_type::north_south:
return 6287;
case shape_type::east_west:
return 6288;
case shape_type::ascending_east:
return 6289;
case shape_type::ascending_west:
return 6290;
case shape_type::ascending_north:
return 6291;
case shape_type::ascending_south:
return 6292;
}
case false:
switch (shape)
{
case shape_type::north_south:
return 6293;
case shape_type::east_west:
return 6294;
case shape_type::ascending_east:
return 6295;
case shape_type::ascending_west:
return 6296;
case shape_type::ascending_north:
return 6297;
case shape_type::ascending_south:
return 6298;
}
}
}
constexpr static activator_rail from_id(block_id_type id)
{
switch (id)
{
case 6287:
return {.powered = true, .shape = shape_type::north_south};
case 6288:
return {.powered = true, .shape = shape_type::east_west};
case 6289:
return {.powered = true, .shape = shape_type::ascending_east};
case 6290:
return {.powered = true, .shape = shape_type::ascending_west};
case 6291:
return {.powered = true, .shape = shape_type::ascending_north};
case 6292:
return {.powered = true, .shape = shape_type::ascending_south};
case 6293:
return {.powered = false, .shape = shape_type::north_south};
case 6294:
return {.powered = false, .shape = shape_type::east_west};
case 6295:
return {.powered = false, .shape = shape_type::ascending_east};
case 6296:
return {.powered = false, .shape = shape_type::ascending_west};
case 6297:
return {.powered = false, .shape = shape_type::ascending_north};
case 6298:
return {.powered = false, .shape = shape_type::ascending_south};
}}
constexpr std::string_view to_string() const
{switch (powered)
{
case true:
switch (shape)
{
case shape_type::north_south:
return "minecraft:activator_rail:true:north_south";
case shape_type::east_west:
return "minecraft:activator_rail:true:east_west";
case shape_type::ascending_east:
return "minecraft:activator_rail:true:ascending_east";
case shape_type::ascending_west:
return "minecraft:activator_rail:true:ascending_west";
case shape_type::ascending_north:
return "minecraft:activator_rail:true:ascending_north";
case shape_type::ascending_south:
return "minecraft:activator_rail:true:ascending_south";
}
case false:
switch (shape)
{
case shape_type::north_south:
return "minecraft:activator_rail:false:north_south";
case shape_type::east_west:
return "minecraft:activator_rail:false:east_west";
case shape_type::ascending_east:
return "minecraft:activator_rail:false:ascending_east";
case shape_type::ascending_west:
return "minecraft:activator_rail:false:ascending_west";
case shape_type::ascending_north:
return "minecraft:activator_rail:false:ascending_north";
case shape_type::ascending_south:
return "minecraft:activator_rail:false:ascending_south";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
