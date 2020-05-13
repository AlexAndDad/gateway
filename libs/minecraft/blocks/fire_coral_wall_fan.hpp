#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct fire_coral_wall_fan
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool waterlogged = true;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (waterlogged)
{
case true:
return 9088;
case false:
return 9089;
}
case facing_type::south:
switch (waterlogged)
{
case true:
return 9090;
case false:
return 9091;
}
case facing_type::west:
switch (waterlogged)
{
case true:
return 9092;
case false:
return 9093;
}
case facing_type::east:
switch (waterlogged)
{
case true:
return 9094;
case false:
return 9095;
}
}
}
constexpr static fire_coral_wall_fan from_id(block_id_type id)
{
switch (id)
{
case 9088:
return {.facing = facing_type::north, .waterlogged = true};
case 9089:
return {.facing = facing_type::north, .waterlogged = false};
case 9090:
return {.facing = facing_type::south, .waterlogged = true};
case 9091:
return {.facing = facing_type::south, .waterlogged = false};
case 9092:
return {.facing = facing_type::west, .waterlogged = true};
case 9093:
return {.facing = facing_type::west, .waterlogged = false};
case 9094:
return {.facing = facing_type::east, .waterlogged = true};
case 9095:
return {.facing = facing_type::east, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (waterlogged)
{
case true:
return "minecraft:fire_coral_wall_fan:north:true";
case false:
return "minecraft:fire_coral_wall_fan:north:false";
}
case facing_type::south:
switch (waterlogged)
{
case true:
return "minecraft:fire_coral_wall_fan:south:true";
case false:
return "minecraft:fire_coral_wall_fan:south:false";
}
case facing_type::west:
switch (waterlogged)
{
case true:
return "minecraft:fire_coral_wall_fan:west:true";
case false:
return "minecraft:fire_coral_wall_fan:west:false";
}
case facing_type::east:
switch (waterlogged)
{
case true:
return "minecraft:fire_coral_wall_fan:east:true";
case false:
return "minecraft:fire_coral_wall_fan:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
