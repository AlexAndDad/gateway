#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jungle_fence
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
return 8106;
case false:
return 8107;
}
case false:
switch (west)
{
case true:
return 8108;
case false:
return 8109;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8110;
case false:
return 8111;
}
case false:
switch (west)
{
case true:
return 8112;
case false:
return 8113;
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
return 8114;
case false:
return 8115;
}
case false:
switch (west)
{
case true:
return 8116;
case false:
return 8117;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8118;
case false:
return 8119;
}
case false:
switch (west)
{
case true:
return 8120;
case false:
return 8121;
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
return 8122;
case false:
return 8123;
}
case false:
switch (west)
{
case true:
return 8124;
case false:
return 8125;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8126;
case false:
return 8127;
}
case false:
switch (west)
{
case true:
return 8128;
case false:
return 8129;
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
return 8130;
case false:
return 8131;
}
case false:
switch (west)
{
case true:
return 8132;
case false:
return 8133;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8134;
case false:
return 8135;
}
case false:
switch (west)
{
case true:
return 8136;
case false:
return 8137;
}
}
}
}
}
}
constexpr static jungle_fence from_id(block_id_type id)
{
switch (id)
{
case 8106:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 8107:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 8108:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 8109:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 8110:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 8111:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 8112:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 8113:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 8114:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 8115:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 8116:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 8117:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 8118:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 8119:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 8120:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 8121:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 8122:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 8123:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 8124:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 8125:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 8126:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 8127:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 8128:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 8129:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 8130:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 8131:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 8132:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 8133:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 8134:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 8135:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 8136:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 8137:
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
return "minecraft:jungle_fence:true:true:true:true:true";
case false:
return "minecraft:jungle_fence:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:jungle_fence:true:true:true:false:true";
case false:
return "minecraft:jungle_fence:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:jungle_fence:true:true:false:true:true";
case false:
return "minecraft:jungle_fence:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:jungle_fence:true:true:false:false:true";
case false:
return "minecraft:jungle_fence:true:true:false:false:false";
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
return "minecraft:jungle_fence:true:false:true:true:true";
case false:
return "minecraft:jungle_fence:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:jungle_fence:true:false:true:false:true";
case false:
return "minecraft:jungle_fence:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:jungle_fence:true:false:false:true:true";
case false:
return "minecraft:jungle_fence:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:jungle_fence:true:false:false:false:true";
case false:
return "minecraft:jungle_fence:true:false:false:false:false";
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
return "minecraft:jungle_fence:false:true:true:true:true";
case false:
return "minecraft:jungle_fence:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:jungle_fence:false:true:true:false:true";
case false:
return "minecraft:jungle_fence:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:jungle_fence:false:true:false:true:true";
case false:
return "minecraft:jungle_fence:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:jungle_fence:false:true:false:false:true";
case false:
return "minecraft:jungle_fence:false:true:false:false:false";
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
return "minecraft:jungle_fence:false:false:true:true:true";
case false:
return "minecraft:jungle_fence:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:jungle_fence:false:false:true:false:true";
case false:
return "minecraft:jungle_fence:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:jungle_fence:false:false:false:true:true";
case false:
return "minecraft:jungle_fence:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:jungle_fence:false:false:false:false:true";
case false:
return "minecraft:jungle_fence:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
