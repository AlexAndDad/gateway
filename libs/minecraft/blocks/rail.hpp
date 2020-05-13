#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct rail
{enum class shape_type : std::uint8_t
{
north_south,
east_west,
ascending_east,
ascending_west,
ascending_north,
ascending_south,
south_east,
south_west,
north_west,
north_east
} shape = shape_type::north_south;
constexpr block_id_type to_id() const {
switch (shape)
{
case shape_type::north_south:
return 3643;
case shape_type::east_west:
return 3644;
case shape_type::ascending_east:
return 3645;
case shape_type::ascending_west:
return 3646;
case shape_type::ascending_north:
return 3647;
case shape_type::ascending_south:
return 3648;
case shape_type::south_east:
return 3649;
case shape_type::south_west:
return 3650;
case shape_type::north_west:
return 3651;
case shape_type::north_east:
return 3652;
}
}
constexpr static rail from_id(block_id_type id)
{
switch (id)
{
case 3643:
return {.shape = shape_type::north_south};
case 3644:
return {.shape = shape_type::east_west};
case 3645:
return {.shape = shape_type::ascending_east};
case 3646:
return {.shape = shape_type::ascending_west};
case 3647:
return {.shape = shape_type::ascending_north};
case 3648:
return {.shape = shape_type::ascending_south};
case 3649:
return {.shape = shape_type::south_east};
case 3650:
return {.shape = shape_type::south_west};
case 3651:
return {.shape = shape_type::north_west};
case 3652:
return {.shape = shape_type::north_east};
}}
constexpr std::string_view to_string() const
{switch (shape)
{
case shape_type::north_south:
return "minecraft:rail:north_south";
case shape_type::east_west:
return "minecraft:rail:east_west";
case shape_type::ascending_east:
return "minecraft:rail:ascending_east";
case shape_type::ascending_west:
return "minecraft:rail:ascending_west";
case shape_type::ascending_north:
return "minecraft:rail:ascending_north";
case shape_type::ascending_south:
return "minecraft:rail:ascending_south";
case shape_type::south_east:
return "minecraft:rail:south_east";
case shape_type::south_west:
return "minecraft:rail:south_west";
case shape_type::north_west:
return "minecraft:rail:north_west";
case shape_type::north_east:
return "minecraft:rail:north_east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
