#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct cocoa
{std::uint8_t age = 0;
enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
switch (facing)
{
case facing_type::north:
return 5142;
case facing_type::south:
return 5143;
case facing_type::west:
return 5144;
case facing_type::east:
return 5145;
}
case 1:
switch (facing)
{
case facing_type::north:
return 5146;
case facing_type::south:
return 5147;
case facing_type::west:
return 5148;
case facing_type::east:
return 5149;
}
case 2:
switch (facing)
{
case facing_type::north:
return 5150;
case facing_type::south:
return 5151;
case facing_type::west:
return 5152;
case facing_type::east:
return 5153;
}
}
}
constexpr static cocoa from_id(block_id_type id)
{
switch (id)
{
case 5142:
return {.age = 0, .facing = facing_type::north};
case 5143:
return {.age = 0, .facing = facing_type::south};
case 5144:
return {.age = 0, .facing = facing_type::west};
case 5145:
return {.age = 0, .facing = facing_type::east};
case 5146:
return {.age = 1, .facing = facing_type::north};
case 5147:
return {.age = 1, .facing = facing_type::south};
case 5148:
return {.age = 1, .facing = facing_type::west};
case 5149:
return {.age = 1, .facing = facing_type::east};
case 5150:
return {.age = 2, .facing = facing_type::north};
case 5151:
return {.age = 2, .facing = facing_type::south};
case 5152:
return {.age = 2, .facing = facing_type::west};
case 5153:
return {.age = 2, .facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
switch (facing)
{
case facing_type::north:
return "minecraft:cocoa:0:north";
case facing_type::south:
return "minecraft:cocoa:0:south";
case facing_type::west:
return "minecraft:cocoa:0:west";
case facing_type::east:
return "minecraft:cocoa:0:east";
}
case 1:
switch (facing)
{
case facing_type::north:
return "minecraft:cocoa:1:north";
case facing_type::south:
return "minecraft:cocoa:1:south";
case facing_type::west:
return "minecraft:cocoa:1:west";
case facing_type::east:
return "minecraft:cocoa:1:east";
}
case 2:
switch (facing)
{
case facing_type::north:
return "minecraft:cocoa:2:north";
case facing_type::south:
return "minecraft:cocoa:2:south";
case facing_type::west:
return "minecraft:cocoa:2:west";
case facing_type::east:
return "minecraft:cocoa:2:east";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
