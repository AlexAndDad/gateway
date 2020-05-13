#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct spruce_fence
{bool east = false;
bool north = false;
bool south = false;
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
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8042;
case false:
return 8043;
}
case false:
switch (west)
{
case true:
return 8044;
case false:
return 8045;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8046;
case false:
return 8047;
}
case false:
switch (west)
{
case true:
return 8048;
case false:
return 8049;
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8050;
case false:
return 8051;
}
case false:
switch (west)
{
case true:
return 8052;
case false:
return 8053;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8054;
case false:
return 8055;
}
case false:
switch (west)
{
case true:
return 8056;
case false:
return 8057;
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
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8058;
case false:
return 8059;
}
case false:
switch (west)
{
case true:
return 8060;
case false:
return 8061;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8062;
case false:
return 8063;
}
case false:
switch (west)
{
case true:
return 8064;
case false:
return 8065;
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8066;
case false:
return 8067;
}
case false:
switch (west)
{
case true:
return 8068;
case false:
return 8069;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8070;
case false:
return 8071;
}
case false:
switch (west)
{
case true:
return 8072;
case false:
return 8073;
}
}
}
}
}
}
constexpr static spruce_fence from_id(block_id_type id)
{
switch (id)
{
case 8042:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 8043:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 8044:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 8045:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 8046:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 8047:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 8048:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 8049:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 8050:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 8051:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 8052:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 8053:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 8054:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 8055:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 8056:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 8057:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 8058:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 8059:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 8060:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 8061:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 8062:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 8063:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 8064:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 8065:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 8066:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 8067:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 8068:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 8069:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 8070:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 8071:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 8072:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 8073:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = false};
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
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:spruce_fence:true:true:true:true:true";
case false:
return "minecraft:spruce_fence:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:spruce_fence:true:true:true:false:true";
case false:
return "minecraft:spruce_fence:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:spruce_fence:true:true:false:true:true";
case false:
return "minecraft:spruce_fence:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:spruce_fence:true:true:false:false:true";
case false:
return "minecraft:spruce_fence:true:true:false:false:false";
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:spruce_fence:true:false:true:true:true";
case false:
return "minecraft:spruce_fence:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:spruce_fence:true:false:true:false:true";
case false:
return "minecraft:spruce_fence:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:spruce_fence:true:false:false:true:true";
case false:
return "minecraft:spruce_fence:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:spruce_fence:true:false:false:false:true";
case false:
return "minecraft:spruce_fence:true:false:false:false:false";
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
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:spruce_fence:false:true:true:true:true";
case false:
return "minecraft:spruce_fence:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:spruce_fence:false:true:true:false:true";
case false:
return "minecraft:spruce_fence:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:spruce_fence:false:true:false:true:true";
case false:
return "minecraft:spruce_fence:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:spruce_fence:false:true:false:false:true";
case false:
return "minecraft:spruce_fence:false:true:false:false:false";
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:spruce_fence:false:false:true:true:true";
case false:
return "minecraft:spruce_fence:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:spruce_fence:false:false:true:false:true";
case false:
return "minecraft:spruce_fence:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:spruce_fence:false:false:false:true:true";
case false:
return "minecraft:spruce_fence:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:spruce_fence:false:false:false:false:true";
case false:
return "minecraft:spruce_fence:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
