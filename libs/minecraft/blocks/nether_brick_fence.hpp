#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct nether_brick_fence
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
return 5000;
case false:
return 5001;
}
case false:
switch (west)
{
case true:
return 5002;
case false:
return 5003;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5004;
case false:
return 5005;
}
case false:
switch (west)
{
case true:
return 5006;
case false:
return 5007;
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
return 5008;
case false:
return 5009;
}
case false:
switch (west)
{
case true:
return 5010;
case false:
return 5011;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5012;
case false:
return 5013;
}
case false:
switch (west)
{
case true:
return 5014;
case false:
return 5015;
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
return 5016;
case false:
return 5017;
}
case false:
switch (west)
{
case true:
return 5018;
case false:
return 5019;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5020;
case false:
return 5021;
}
case false:
switch (west)
{
case true:
return 5022;
case false:
return 5023;
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
return 5024;
case false:
return 5025;
}
case false:
switch (west)
{
case true:
return 5026;
case false:
return 5027;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5028;
case false:
return 5029;
}
case false:
switch (west)
{
case true:
return 5030;
case false:
return 5031;
}
}
}
}
}
}
constexpr static nether_brick_fence from_id(block_id_type id)
{
switch (id)
{
case 5000:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 5001:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 5002:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 5003:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 5004:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 5005:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 5006:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 5007:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 5008:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 5009:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 5010:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 5011:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 5012:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 5013:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 5014:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 5015:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 5016:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 5017:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 5018:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 5019:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 5020:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 5021:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 5022:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 5023:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 5024:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 5025:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 5026:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 5027:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 5028:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 5029:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 5030:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 5031:
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
return "minecraft:nether_brick_fence:true:true:true:true:true";
case false:
return "minecraft:nether_brick_fence:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_fence:true:true:true:false:true";
case false:
return "minecraft:nether_brick_fence:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:nether_brick_fence:true:true:false:true:true";
case false:
return "minecraft:nether_brick_fence:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_fence:true:true:false:false:true";
case false:
return "minecraft:nether_brick_fence:true:true:false:false:false";
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
return "minecraft:nether_brick_fence:true:false:true:true:true";
case false:
return "minecraft:nether_brick_fence:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_fence:true:false:true:false:true";
case false:
return "minecraft:nether_brick_fence:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:nether_brick_fence:true:false:false:true:true";
case false:
return "minecraft:nether_brick_fence:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_fence:true:false:false:false:true";
case false:
return "minecraft:nether_brick_fence:true:false:false:false:false";
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
return "minecraft:nether_brick_fence:false:true:true:true:true";
case false:
return "minecraft:nether_brick_fence:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_fence:false:true:true:false:true";
case false:
return "minecraft:nether_brick_fence:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:nether_brick_fence:false:true:false:true:true";
case false:
return "minecraft:nether_brick_fence:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_fence:false:true:false:false:true";
case false:
return "minecraft:nether_brick_fence:false:true:false:false:false";
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
return "minecraft:nether_brick_fence:false:false:true:true:true";
case false:
return "minecraft:nether_brick_fence:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_fence:false:false:true:false:true";
case false:
return "minecraft:nether_brick_fence:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:nether_brick_fence:false:false:false:true:true";
case false:
return "minecraft:nether_brick_fence:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_fence:false:false:false:false:true";
case false:
return "minecraft:nether_brick_fence:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
