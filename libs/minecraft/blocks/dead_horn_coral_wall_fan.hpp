#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dead_horn_coral_wall_fan
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
return 9056;
case false:
return 9057;
}
case facing_type::south:
switch (waterlogged)
{
case true:
return 9058;
case false:
return 9059;
}
case facing_type::west:
switch (waterlogged)
{
case true:
return 9060;
case false:
return 9061;
}
case facing_type::east:
switch (waterlogged)
{
case true:
return 9062;
case false:
return 9063;
}
}
}
constexpr static dead_horn_coral_wall_fan from_id(block_id_type id)
{
switch (id)
{
case 9056:
return {.facing = facing_type::north, .waterlogged = true};
case 9057:
return {.facing = facing_type::north, .waterlogged = false};
case 9058:
return {.facing = facing_type::south, .waterlogged = true};
case 9059:
return {.facing = facing_type::south, .waterlogged = false};
case 9060:
return {.facing = facing_type::west, .waterlogged = true};
case 9061:
return {.facing = facing_type::west, .waterlogged = false};
case 9062:
return {.facing = facing_type::east, .waterlogged = true};
case 9063:
return {.facing = facing_type::east, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (waterlogged)
{
case true:
return "minecraft:dead_horn_coral_wall_fan:north:true";
case false:
return "minecraft:dead_horn_coral_wall_fan:north:false";
}
case facing_type::south:
switch (waterlogged)
{
case true:
return "minecraft:dead_horn_coral_wall_fan:south:true";
case false:
return "minecraft:dead_horn_coral_wall_fan:south:false";
}
case facing_type::west:
switch (waterlogged)
{
case true:
return "minecraft:dead_horn_coral_wall_fan:west:true";
case false:
return "minecraft:dead_horn_coral_wall_fan:west:false";
}
case facing_type::east:
switch (waterlogged)
{
case true:
return "minecraft:dead_horn_coral_wall_fan:east:true";
case false:
return "minecraft:dead_horn_coral_wall_fan:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
