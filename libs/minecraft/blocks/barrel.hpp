#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct barrel
{enum class facing_type : std::uint8_t
{
north,
east,
south,
west,
up,
down
} facing = facing_type::north;
bool open = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (open)
{
case true:
return 11135;
case false:
return 11136;
}
case facing_type::east:
switch (open)
{
case true:
return 11137;
case false:
return 11138;
}
case facing_type::south:
switch (open)
{
case true:
return 11139;
case false:
return 11140;
}
case facing_type::west:
switch (open)
{
case true:
return 11141;
case false:
return 11142;
}
case facing_type::up:
switch (open)
{
case true:
return 11143;
case false:
return 11144;
}
case facing_type::down:
switch (open)
{
case true:
return 11145;
case false:
return 11146;
}
}
}
constexpr static barrel from_id(block_id_type id)
{
switch (id)
{
case 11135:
return {.facing = facing_type::north, .open = true};
case 11136:
return {.facing = facing_type::north, .open = false};
case 11137:
return {.facing = facing_type::east, .open = true};
case 11138:
return {.facing = facing_type::east, .open = false};
case 11139:
return {.facing = facing_type::south, .open = true};
case 11140:
return {.facing = facing_type::south, .open = false};
case 11141:
return {.facing = facing_type::west, .open = true};
case 11142:
return {.facing = facing_type::west, .open = false};
case 11143:
return {.facing = facing_type::up, .open = true};
case 11144:
return {.facing = facing_type::up, .open = false};
case 11145:
return {.facing = facing_type::down, .open = true};
case 11146:
return {.facing = facing_type::down, .open = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (open)
{
case true:
return "minecraft:barrel:north:true";
case false:
return "minecraft:barrel:north:false";
}
case facing_type::east:
switch (open)
{
case true:
return "minecraft:barrel:east:true";
case false:
return "minecraft:barrel:east:false";
}
case facing_type::south:
switch (open)
{
case true:
return "minecraft:barrel:south:true";
case false:
return "minecraft:barrel:south:false";
}
case facing_type::west:
switch (open)
{
case true:
return "minecraft:barrel:west:true";
case false:
return "minecraft:barrel:west:false";
}
case facing_type::up:
switch (open)
{
case true:
return "minecraft:barrel:up:true";
case false:
return "minecraft:barrel:up:false";
}
case facing_type::down:
switch (open)
{
case true:
return "minecraft:barrel:down:true";
case false:
return "minecraft:barrel:down:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
