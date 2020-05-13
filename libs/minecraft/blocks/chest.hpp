#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct chest
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
enum class type_type : std::uint8_t
{
single,
left,
right
} type = type_type::single;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return 2032;
case false:
return 2033;
}
case type_type::left:
switch (waterlogged)
{
case true:
return 2034;
case false:
return 2035;
}
case type_type::right:
switch (waterlogged)
{
case true:
return 2036;
case false:
return 2037;
}
}
case facing_type::south:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return 2038;
case false:
return 2039;
}
case type_type::left:
switch (waterlogged)
{
case true:
return 2040;
case false:
return 2041;
}
case type_type::right:
switch (waterlogged)
{
case true:
return 2042;
case false:
return 2043;
}
}
case facing_type::west:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return 2044;
case false:
return 2045;
}
case type_type::left:
switch (waterlogged)
{
case true:
return 2046;
case false:
return 2047;
}
case type_type::right:
switch (waterlogged)
{
case true:
return 2048;
case false:
return 2049;
}
}
case facing_type::east:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return 2050;
case false:
return 2051;
}
case type_type::left:
switch (waterlogged)
{
case true:
return 2052;
case false:
return 2053;
}
case type_type::right:
switch (waterlogged)
{
case true:
return 2054;
case false:
return 2055;
}
}
}
}
constexpr static chest from_id(block_id_type id)
{
switch (id)
{
case 2032:
return {.facing = facing_type::north, .type = type_type::single, .waterlogged = true};
case 2033:
return {.facing = facing_type::north, .type = type_type::single, .waterlogged = false};
case 2034:
return {.facing = facing_type::north, .type = type_type::left, .waterlogged = true};
case 2035:
return {.facing = facing_type::north, .type = type_type::left, .waterlogged = false};
case 2036:
return {.facing = facing_type::north, .type = type_type::right, .waterlogged = true};
case 2037:
return {.facing = facing_type::north, .type = type_type::right, .waterlogged = false};
case 2038:
return {.facing = facing_type::south, .type = type_type::single, .waterlogged = true};
case 2039:
return {.facing = facing_type::south, .type = type_type::single, .waterlogged = false};
case 2040:
return {.facing = facing_type::south, .type = type_type::left, .waterlogged = true};
case 2041:
return {.facing = facing_type::south, .type = type_type::left, .waterlogged = false};
case 2042:
return {.facing = facing_type::south, .type = type_type::right, .waterlogged = true};
case 2043:
return {.facing = facing_type::south, .type = type_type::right, .waterlogged = false};
case 2044:
return {.facing = facing_type::west, .type = type_type::single, .waterlogged = true};
case 2045:
return {.facing = facing_type::west, .type = type_type::single, .waterlogged = false};
case 2046:
return {.facing = facing_type::west, .type = type_type::left, .waterlogged = true};
case 2047:
return {.facing = facing_type::west, .type = type_type::left, .waterlogged = false};
case 2048:
return {.facing = facing_type::west, .type = type_type::right, .waterlogged = true};
case 2049:
return {.facing = facing_type::west, .type = type_type::right, .waterlogged = false};
case 2050:
return {.facing = facing_type::east, .type = type_type::single, .waterlogged = true};
case 2051:
return {.facing = facing_type::east, .type = type_type::single, .waterlogged = false};
case 2052:
return {.facing = facing_type::east, .type = type_type::left, .waterlogged = true};
case 2053:
return {.facing = facing_type::east, .type = type_type::left, .waterlogged = false};
case 2054:
return {.facing = facing_type::east, .type = type_type::right, .waterlogged = true};
case 2055:
return {.facing = facing_type::east, .type = type_type::right, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return "minecraft:chest:north:single:true";
case false:
return "minecraft:chest:north:single:false";
}
case type_type::left:
switch (waterlogged)
{
case true:
return "minecraft:chest:north:left:true";
case false:
return "minecraft:chest:north:left:false";
}
case type_type::right:
switch (waterlogged)
{
case true:
return "minecraft:chest:north:right:true";
case false:
return "minecraft:chest:north:right:false";
}
}
case facing_type::south:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return "minecraft:chest:south:single:true";
case false:
return "minecraft:chest:south:single:false";
}
case type_type::left:
switch (waterlogged)
{
case true:
return "minecraft:chest:south:left:true";
case false:
return "minecraft:chest:south:left:false";
}
case type_type::right:
switch (waterlogged)
{
case true:
return "minecraft:chest:south:right:true";
case false:
return "minecraft:chest:south:right:false";
}
}
case facing_type::west:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return "minecraft:chest:west:single:true";
case false:
return "minecraft:chest:west:single:false";
}
case type_type::left:
switch (waterlogged)
{
case true:
return "minecraft:chest:west:left:true";
case false:
return "minecraft:chest:west:left:false";
}
case type_type::right:
switch (waterlogged)
{
case true:
return "minecraft:chest:west:right:true";
case false:
return "minecraft:chest:west:right:false";
}
}
case facing_type::east:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return "minecraft:chest:east:single:true";
case false:
return "minecraft:chest:east:single:false";
}
case type_type::left:
switch (waterlogged)
{
case true:
return "minecraft:chest:east:left:true";
case false:
return "minecraft:chest:east:left:false";
}
case type_type::right:
switch (waterlogged)
{
case true:
return "minecraft:chest:east:right:true";
case false:
return "minecraft:chest:east:right:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
