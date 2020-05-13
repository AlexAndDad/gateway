#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct diorite_wall
{bool east = false;
bool north = false;
bool south = false;
bool up = true;
bool waterlogged = false;
bool west = false;
constexpr block_id_type to_id() const {
switch (east)
{
case true:
switch (north)
{
case true:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11035;
case false:
return 11036;
}
case false:
switch (west)
{
case true:
return 11037;
case false:
return 11038;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11039;
case false:
return 11040;
}
case false:
switch (west)
{
case true:
return 11041;
case false:
return 11042;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11043;
case false:
return 11044;
}
case false:
switch (west)
{
case true:
return 11045;
case false:
return 11046;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11047;
case false:
return 11048;
}
case false:
switch (west)
{
case true:
return 11049;
case false:
return 11050;
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11051;
case false:
return 11052;
}
case false:
switch (west)
{
case true:
return 11053;
case false:
return 11054;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11055;
case false:
return 11056;
}
case false:
switch (west)
{
case true:
return 11057;
case false:
return 11058;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11059;
case false:
return 11060;
}
case false:
switch (west)
{
case true:
return 11061;
case false:
return 11062;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11063;
case false:
return 11064;
}
case false:
switch (west)
{
case true:
return 11065;
case false:
return 11066;
}
}
}
}
}
case false:
switch (north)
{
case true:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11067;
case false:
return 11068;
}
case false:
switch (west)
{
case true:
return 11069;
case false:
return 11070;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11071;
case false:
return 11072;
}
case false:
switch (west)
{
case true:
return 11073;
case false:
return 11074;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11075;
case false:
return 11076;
}
case false:
switch (west)
{
case true:
return 11077;
case false:
return 11078;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11079;
case false:
return 11080;
}
case false:
switch (west)
{
case true:
return 11081;
case false:
return 11082;
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11083;
case false:
return 11084;
}
case false:
switch (west)
{
case true:
return 11085;
case false:
return 11086;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11087;
case false:
return 11088;
}
case false:
switch (west)
{
case true:
return 11089;
case false:
return 11090;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11091;
case false:
return 11092;
}
case false:
switch (west)
{
case true:
return 11093;
case false:
return 11094;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11095;
case false:
return 11096;
}
case false:
switch (west)
{
case true:
return 11097;
case false:
return 11098;
}
}
}
}
}
}
}
constexpr static diorite_wall from_id(block_id_type id)
{
switch (id)
{
case 11035:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 11036:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 11037:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 11038:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 11039:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 11040:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 11041:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 11042:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 11043:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 11044:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 11045:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 11046:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 11047:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 11048:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 11049:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 11050:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 11051:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 11052:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 11053:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 11054:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 11055:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 11056:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 11057:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 11058:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 11059:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 11060:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 11061:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 11062:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 11063:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 11064:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 11065:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 11066:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 11067:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 11068:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 11069:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 11070:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 11071:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 11072:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 11073:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 11074:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 11075:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 11076:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 11077:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 11078:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 11079:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 11080:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 11081:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 11082:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 11083:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 11084:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 11085:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 11086:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 11087:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 11088:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 11089:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 11090:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 11091:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 11092:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 11093:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 11094:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 11095:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 11096:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 11097:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 11098:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
}}
constexpr std::string_view to_string() const
{switch (east)
{
case true:
switch (north)
{
case true:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:true:true:true:true:true";
case false:
return "minecraft:diorite_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:true:true:true:false:true";
case false:
return "minecraft:diorite_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:true:true:false:true:true";
case false:
return "minecraft:diorite_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:true:true:false:false:true";
case false:
return "minecraft:diorite_wall:true:true:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:true:false:true:true:true";
case false:
return "minecraft:diorite_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:true:false:true:false:true";
case false:
return "minecraft:diorite_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:true:false:false:true:true";
case false:
return "minecraft:diorite_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:true:false:false:false:true";
case false:
return "minecraft:diorite_wall:true:true:false:false:false:false";
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:false:true:true:true:true";
case false:
return "minecraft:diorite_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:false:true:true:false:true";
case false:
return "minecraft:diorite_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:false:true:false:true:true";
case false:
return "minecraft:diorite_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:false:true:false:false:true";
case false:
return "minecraft:diorite_wall:true:false:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:false:false:true:true:true";
case false:
return "minecraft:diorite_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:false:false:true:false:true";
case false:
return "minecraft:diorite_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:false:false:false:true:true";
case false:
return "minecraft:diorite_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:true:false:false:false:false:true";
case false:
return "minecraft:diorite_wall:true:false:false:false:false:false";
}
}
}
}
}
case false:
switch (north)
{
case true:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:true:true:true:true:true";
case false:
return "minecraft:diorite_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:true:true:true:false:true";
case false:
return "minecraft:diorite_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:true:true:false:true:true";
case false:
return "minecraft:diorite_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:true:true:false:false:true";
case false:
return "minecraft:diorite_wall:false:true:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:true:false:true:true:true";
case false:
return "minecraft:diorite_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:true:false:true:false:true";
case false:
return "minecraft:diorite_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:true:false:false:true:true";
case false:
return "minecraft:diorite_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:true:false:false:false:true";
case false:
return "minecraft:diorite_wall:false:true:false:false:false:false";
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:false:true:true:true:true";
case false:
return "minecraft:diorite_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:false:true:true:false:true";
case false:
return "minecraft:diorite_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:false:true:false:true:true";
case false:
return "minecraft:diorite_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:false:true:false:false:true";
case false:
return "minecraft:diorite_wall:false:false:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:false:false:true:true:true";
case false:
return "minecraft:diorite_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:false:false:true:false:true";
case false:
return "minecraft:diorite_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:false:false:false:true:true";
case false:
return "minecraft:diorite_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:diorite_wall:false:false:false:false:false:true";
case false:
return "minecraft:diorite_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
