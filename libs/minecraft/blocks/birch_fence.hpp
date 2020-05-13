#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct birch_fence
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
return 8074;
case false:
return 8075;
}
case false:
switch (west)
{
case true:
return 8076;
case false:
return 8077;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8078;
case false:
return 8079;
}
case false:
switch (west)
{
case true:
return 8080;
case false:
return 8081;
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
return 8082;
case false:
return 8083;
}
case false:
switch (west)
{
case true:
return 8084;
case false:
return 8085;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8086;
case false:
return 8087;
}
case false:
switch (west)
{
case true:
return 8088;
case false:
return 8089;
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
return 8090;
case false:
return 8091;
}
case false:
switch (west)
{
case true:
return 8092;
case false:
return 8093;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8094;
case false:
return 8095;
}
case false:
switch (west)
{
case true:
return 8096;
case false:
return 8097;
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
return 8098;
case false:
return 8099;
}
case false:
switch (west)
{
case true:
return 8100;
case false:
return 8101;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8102;
case false:
return 8103;
}
case false:
switch (west)
{
case true:
return 8104;
case false:
return 8105;
}
}
}
}
}
}
constexpr static birch_fence from_id(block_id_type id)
{
switch (id)
{
case 8074:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 8075:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 8076:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 8077:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 8078:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 8079:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 8080:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 8081:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 8082:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 8083:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 8084:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 8085:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 8086:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 8087:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 8088:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 8089:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 8090:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 8091:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 8092:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 8093:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 8094:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 8095:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 8096:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 8097:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 8098:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 8099:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 8100:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 8101:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 8102:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 8103:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 8104:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 8105:
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
return "minecraft:birch_fence:true:true:true:true:true";
case false:
return "minecraft:birch_fence:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:birch_fence:true:true:true:false:true";
case false:
return "minecraft:birch_fence:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:birch_fence:true:true:false:true:true";
case false:
return "minecraft:birch_fence:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:birch_fence:true:true:false:false:true";
case false:
return "minecraft:birch_fence:true:true:false:false:false";
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
return "minecraft:birch_fence:true:false:true:true:true";
case false:
return "minecraft:birch_fence:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:birch_fence:true:false:true:false:true";
case false:
return "minecraft:birch_fence:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:birch_fence:true:false:false:true:true";
case false:
return "minecraft:birch_fence:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:birch_fence:true:false:false:false:true";
case false:
return "minecraft:birch_fence:true:false:false:false:false";
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
return "minecraft:birch_fence:false:true:true:true:true";
case false:
return "minecraft:birch_fence:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:birch_fence:false:true:true:false:true";
case false:
return "minecraft:birch_fence:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:birch_fence:false:true:false:true:true";
case false:
return "minecraft:birch_fence:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:birch_fence:false:true:false:false:true";
case false:
return "minecraft:birch_fence:false:true:false:false:false";
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
return "minecraft:birch_fence:false:false:true:true:true";
case false:
return "minecraft:birch_fence:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:birch_fence:false:false:true:false:true";
case false:
return "minecraft:birch_fence:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:birch_fence:false:false:false:true:true";
case false:
return "minecraft:birch_fence:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:birch_fence:false:false:false:false:true";
case false:
return "minecraft:birch_fence:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
