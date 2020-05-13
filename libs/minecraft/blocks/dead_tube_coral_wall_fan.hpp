#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dead_tube_coral_wall_fan
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
return 9024;
case false:
return 9025;
}
case facing_type::south:
switch (waterlogged)
{
case true:
return 9026;
case false:
return 9027;
}
case facing_type::west:
switch (waterlogged)
{
case true:
return 9028;
case false:
return 9029;
}
case facing_type::east:
switch (waterlogged)
{
case true:
return 9030;
case false:
return 9031;
}
}
}
constexpr static dead_tube_coral_wall_fan from_id(block_id_type id)
{
switch (id)
{
case 9024:
return {.facing = facing_type::north, .waterlogged = true};
case 9025:
return {.facing = facing_type::north, .waterlogged = false};
case 9026:
return {.facing = facing_type::south, .waterlogged = true};
case 9027:
return {.facing = facing_type::south, .waterlogged = false};
case 9028:
return {.facing = facing_type::west, .waterlogged = true};
case 9029:
return {.facing = facing_type::west, .waterlogged = false};
case 9030:
return {.facing = facing_type::east, .waterlogged = true};
case 9031:
return {.facing = facing_type::east, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (waterlogged)
{
case true:
return "minecraft:dead_tube_coral_wall_fan:north:true";
case false:
return "minecraft:dead_tube_coral_wall_fan:north:false";
}
case facing_type::south:
switch (waterlogged)
{
case true:
return "minecraft:dead_tube_coral_wall_fan:south:true";
case false:
return "minecraft:dead_tube_coral_wall_fan:south:false";
}
case facing_type::west:
switch (waterlogged)
{
case true:
return "minecraft:dead_tube_coral_wall_fan:west:true";
case false:
return "minecraft:dead_tube_coral_wall_fan:west:false";
}
case facing_type::east:
switch (waterlogged)
{
case true:
return "minecraft:dead_tube_coral_wall_fan:east:true";
case false:
return "minecraft:dead_tube_coral_wall_fan:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
