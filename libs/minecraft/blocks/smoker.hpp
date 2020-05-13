#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct smoker
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
return 11147;
case false:
return 11148;
}
case facing_type::south:
switch (lit)
{
case true:
return 11149;
case false:
return 11150;
}
case facing_type::west:
switch (lit)
{
case true:
return 11151;
case false:
return 11152;
}
case facing_type::east:
switch (lit)
{
case true:
return 11153;
case false:
return 11154;
}
}
}
constexpr static smoker from_id(block_id_type id)
{
switch (id)
{
case 11147:
return {.facing = facing_type::north, .lit = true};
case 11148:
return {.facing = facing_type::north, .lit = false};
case 11149:
return {.facing = facing_type::south, .lit = true};
case 11150:
return {.facing = facing_type::south, .lit = false};
case 11151:
return {.facing = facing_type::west, .lit = true};
case 11152:
return {.facing = facing_type::west, .lit = false};
case 11153:
return {.facing = facing_type::east, .lit = true};
case 11154:
return {.facing = facing_type::east, .lit = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (lit)
{
case true:
return "minecraft:smoker:north:true";
case false:
return "minecraft:smoker:north:false";
}
case facing_type::south:
switch (lit)
{
case true:
return "minecraft:smoker:south:true";
case false:
return "minecraft:smoker:south:false";
}
case facing_type::west:
switch (lit)
{
case true:
return "minecraft:smoker:west:true";
case false:
return "minecraft:smoker:west:false";
}
case facing_type::east:
switch (lit)
{
case true:
return "minecraft:smoker:east:true";
case false:
return "minecraft:smoker:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
