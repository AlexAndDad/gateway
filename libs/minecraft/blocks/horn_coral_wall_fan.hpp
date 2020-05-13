#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct horn_coral_wall_fan
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
return 9096;
case false:
return 9097;
}
case facing_type::south:
switch (waterlogged)
{
case true:
return 9098;
case false:
return 9099;
}
case facing_type::west:
switch (waterlogged)
{
case true:
return 9100;
case false:
return 9101;
}
case facing_type::east:
switch (waterlogged)
{
case true:
return 9102;
case false:
return 9103;
}
}
}
constexpr static horn_coral_wall_fan from_id(block_id_type id)
{
switch (id)
{
case 9096:
return {.facing = facing_type::north, .waterlogged = true};
case 9097:
return {.facing = facing_type::north, .waterlogged = false};
case 9098:
return {.facing = facing_type::south, .waterlogged = true};
case 9099:
return {.facing = facing_type::south, .waterlogged = false};
case 9100:
return {.facing = facing_type::west, .waterlogged = true};
case 9101:
return {.facing = facing_type::west, .waterlogged = false};
case 9102:
return {.facing = facing_type::east, .waterlogged = true};
case 9103:
return {.facing = facing_type::east, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (waterlogged)
{
case true:
return "minecraft:horn_coral_wall_fan:north:true";
case false:
return "minecraft:horn_coral_wall_fan:north:false";
}
case facing_type::south:
switch (waterlogged)
{
case true:
return "minecraft:horn_coral_wall_fan:south:true";
case false:
return "minecraft:horn_coral_wall_fan:south:false";
}
case facing_type::west:
switch (waterlogged)
{
case true:
return "minecraft:horn_coral_wall_fan:west:true";
case false:
return "minecraft:horn_coral_wall_fan:west:false";
}
case facing_type::east:
switch (waterlogged)
{
case true:
return "minecraft:horn_coral_wall_fan:east:true";
case false:
return "minecraft:horn_coral_wall_fan:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
