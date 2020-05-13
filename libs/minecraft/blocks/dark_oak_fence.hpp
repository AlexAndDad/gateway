#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dark_oak_fence
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
return 8170;
case false:
return 8171;
}
case false:
switch (west)
{
case true:
return 8172;
case false:
return 8173;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8174;
case false:
return 8175;
}
case false:
switch (west)
{
case true:
return 8176;
case false:
return 8177;
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
return 8178;
case false:
return 8179;
}
case false:
switch (west)
{
case true:
return 8180;
case false:
return 8181;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8182;
case false:
return 8183;
}
case false:
switch (west)
{
case true:
return 8184;
case false:
return 8185;
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
return 8186;
case false:
return 8187;
}
case false:
switch (west)
{
case true:
return 8188;
case false:
return 8189;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8190;
case false:
return 8191;
}
case false:
switch (west)
{
case true:
return 8192;
case false:
return 8193;
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
return 8194;
case false:
return 8195;
}
case false:
switch (west)
{
case true:
return 8196;
case false:
return 8197;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8198;
case false:
return 8199;
}
case false:
switch (west)
{
case true:
return 8200;
case false:
return 8201;
}
}
}
}
}
}
constexpr static dark_oak_fence from_id(block_id_type id)
{
switch (id)
{
case 8170:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 8171:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 8172:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 8173:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 8174:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 8175:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 8176:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 8177:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 8178:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 8179:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 8180:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 8181:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 8182:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 8183:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 8184:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 8185:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 8186:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 8187:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 8188:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 8189:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 8190:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 8191:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 8192:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 8193:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 8194:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 8195:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 8196:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 8197:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 8198:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 8199:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 8200:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 8201:
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
return "minecraft:dark_oak_fence:true:true:true:true:true";
case false:
return "minecraft:dark_oak_fence:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:dark_oak_fence:true:true:true:false:true";
case false:
return "minecraft:dark_oak_fence:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:dark_oak_fence:true:true:false:true:true";
case false:
return "minecraft:dark_oak_fence:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:dark_oak_fence:true:true:false:false:true";
case false:
return "minecraft:dark_oak_fence:true:true:false:false:false";
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
return "minecraft:dark_oak_fence:true:false:true:true:true";
case false:
return "minecraft:dark_oak_fence:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:dark_oak_fence:true:false:true:false:true";
case false:
return "minecraft:dark_oak_fence:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:dark_oak_fence:true:false:false:true:true";
case false:
return "minecraft:dark_oak_fence:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:dark_oak_fence:true:false:false:false:true";
case false:
return "minecraft:dark_oak_fence:true:false:false:false:false";
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
return "minecraft:dark_oak_fence:false:true:true:true:true";
case false:
return "minecraft:dark_oak_fence:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:dark_oak_fence:false:true:true:false:true";
case false:
return "minecraft:dark_oak_fence:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:dark_oak_fence:false:true:false:true:true";
case false:
return "minecraft:dark_oak_fence:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:dark_oak_fence:false:true:false:false:true";
case false:
return "minecraft:dark_oak_fence:false:true:false:false:false";
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
return "minecraft:dark_oak_fence:false:false:true:true:true";
case false:
return "minecraft:dark_oak_fence:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:dark_oak_fence:false:false:true:false:true";
case false:
return "minecraft:dark_oak_fence:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:dark_oak_fence:false:false:false:true:true";
case false:
return "minecraft:dark_oak_fence:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:dark_oak_fence:false:false:false:false:true";
case false:
return "minecraft:dark_oak_fence:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
