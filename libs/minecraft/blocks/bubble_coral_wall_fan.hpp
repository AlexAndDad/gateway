#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct bubble_coral_wall_fan
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
return 9080;
case false:
return 9081;
}
case facing_type::south:
switch (waterlogged)
{
case true:
return 9082;
case false:
return 9083;
}
case facing_type::west:
switch (waterlogged)
{
case true:
return 9084;
case false:
return 9085;
}
case facing_type::east:
switch (waterlogged)
{
case true:
return 9086;
case false:
return 9087;
}
}
}
constexpr static bubble_coral_wall_fan from_id(block_id_type id)
{
switch (id)
{
case 9080:
return {.facing = facing_type::north, .waterlogged = true};
case 9081:
return {.facing = facing_type::north, .waterlogged = false};
case 9082:
return {.facing = facing_type::south, .waterlogged = true};
case 9083:
return {.facing = facing_type::south, .waterlogged = false};
case 9084:
return {.facing = facing_type::west, .waterlogged = true};
case 9085:
return {.facing = facing_type::west, .waterlogged = false};
case 9086:
return {.facing = facing_type::east, .waterlogged = true};
case 9087:
return {.facing = facing_type::east, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (waterlogged)
{
case true:
return "minecraft:bubble_coral_wall_fan:north:true";
case false:
return "minecraft:bubble_coral_wall_fan:north:false";
}
case facing_type::south:
switch (waterlogged)
{
case true:
return "minecraft:bubble_coral_wall_fan:south:true";
case false:
return "minecraft:bubble_coral_wall_fan:south:false";
}
case facing_type::west:
switch (waterlogged)
{
case true:
return "minecraft:bubble_coral_wall_fan:west:true";
case false:
return "minecraft:bubble_coral_wall_fan:west:false";
}
case facing_type::east:
switch (waterlogged)
{
case true:
return "minecraft:bubble_coral_wall_fan:east:true";
case false:
return "minecraft:bubble_coral_wall_fan:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
