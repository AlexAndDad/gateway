#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct end_stone_brick_wall
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
return 10971;
case false:
return 10972;
}
case false:
switch (west)
{
case true:
return 10973;
case false:
return 10974;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10975;
case false:
return 10976;
}
case false:
switch (west)
{
case true:
return 10977;
case false:
return 10978;
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
return 10979;
case false:
return 10980;
}
case false:
switch (west)
{
case true:
return 10981;
case false:
return 10982;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10983;
case false:
return 10984;
}
case false:
switch (west)
{
case true:
return 10985;
case false:
return 10986;
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
return 10987;
case false:
return 10988;
}
case false:
switch (west)
{
case true:
return 10989;
case false:
return 10990;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10991;
case false:
return 10992;
}
case false:
switch (west)
{
case true:
return 10993;
case false:
return 10994;
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
return 10995;
case false:
return 10996;
}
case false:
switch (west)
{
case true:
return 10997;
case false:
return 10998;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10999;
case false:
return 11000;
}
case false:
switch (west)
{
case true:
return 11001;
case false:
return 11002;
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
return 11003;
case false:
return 11004;
}
case false:
switch (west)
{
case true:
return 11005;
case false:
return 11006;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11007;
case false:
return 11008;
}
case false:
switch (west)
{
case true:
return 11009;
case false:
return 11010;
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
return 11011;
case false:
return 11012;
}
case false:
switch (west)
{
case true:
return 11013;
case false:
return 11014;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11015;
case false:
return 11016;
}
case false:
switch (west)
{
case true:
return 11017;
case false:
return 11018;
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
return 11019;
case false:
return 11020;
}
case false:
switch (west)
{
case true:
return 11021;
case false:
return 11022;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11023;
case false:
return 11024;
}
case false:
switch (west)
{
case true:
return 11025;
case false:
return 11026;
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
return 11027;
case false:
return 11028;
}
case false:
switch (west)
{
case true:
return 11029;
case false:
return 11030;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 11031;
case false:
return 11032;
}
case false:
switch (west)
{
case true:
return 11033;
case false:
return 11034;
}
}
}
}
}
}
}
constexpr static end_stone_brick_wall from_id(block_id_type id)
{
switch (id)
{
case 10971:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10972:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10973:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10974:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10975:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10976:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10977:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10978:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10979:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10980:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10981:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10982:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10983:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10984:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10985:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10986:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10987:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10988:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10989:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10990:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10991:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10992:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10993:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10994:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10995:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10996:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10997:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10998:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10999:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 11000:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 11001:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 11002:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 11003:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 11004:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 11005:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 11006:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 11007:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 11008:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 11009:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 11010:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 11011:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 11012:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 11013:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 11014:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 11015:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 11016:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 11017:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 11018:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 11019:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 11020:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 11021:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 11022:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 11023:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 11024:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 11025:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 11026:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 11027:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 11028:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 11029:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 11030:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 11031:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 11032:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 11033:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 11034:
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
return "minecraft:end_stone_brick_wall:true:true:true:true:true:true";
case false:
return "minecraft:end_stone_brick_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:true:true:true:true:false:true";
case false:
return "minecraft:end_stone_brick_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:true:true:true:false:true:true";
case false:
return "minecraft:end_stone_brick_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:true:true:true:false:false:true";
case false:
return "minecraft:end_stone_brick_wall:true:true:true:false:false:false";
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
return "minecraft:end_stone_brick_wall:true:true:false:true:true:true";
case false:
return "minecraft:end_stone_brick_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:true:true:false:true:false:true";
case false:
return "minecraft:end_stone_brick_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:true:true:false:false:true:true";
case false:
return "minecraft:end_stone_brick_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:true:true:false:false:false:true";
case false:
return "minecraft:end_stone_brick_wall:true:true:false:false:false:false";
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
return "minecraft:end_stone_brick_wall:true:false:true:true:true:true";
case false:
return "minecraft:end_stone_brick_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:true:false:true:true:false:true";
case false:
return "minecraft:end_stone_brick_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:true:false:true:false:true:true";
case false:
return "minecraft:end_stone_brick_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:true:false:true:false:false:true";
case false:
return "minecraft:end_stone_brick_wall:true:false:true:false:false:false";
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
return "minecraft:end_stone_brick_wall:true:false:false:true:true:true";
case false:
return "minecraft:end_stone_brick_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:true:false:false:true:false:true";
case false:
return "minecraft:end_stone_brick_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:true:false:false:false:true:true";
case false:
return "minecraft:end_stone_brick_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:true:false:false:false:false:true";
case false:
return "minecraft:end_stone_brick_wall:true:false:false:false:false:false";
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
return "minecraft:end_stone_brick_wall:false:true:true:true:true:true";
case false:
return "minecraft:end_stone_brick_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:false:true:true:true:false:true";
case false:
return "minecraft:end_stone_brick_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:false:true:true:false:true:true";
case false:
return "minecraft:end_stone_brick_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:false:true:true:false:false:true";
case false:
return "minecraft:end_stone_brick_wall:false:true:true:false:false:false";
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
return "minecraft:end_stone_brick_wall:false:true:false:true:true:true";
case false:
return "minecraft:end_stone_brick_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:false:true:false:true:false:true";
case false:
return "minecraft:end_stone_brick_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:false:true:false:false:true:true";
case false:
return "minecraft:end_stone_brick_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:false:true:false:false:false:true";
case false:
return "minecraft:end_stone_brick_wall:false:true:false:false:false:false";
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
return "minecraft:end_stone_brick_wall:false:false:true:true:true:true";
case false:
return "minecraft:end_stone_brick_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:false:false:true:true:false:true";
case false:
return "minecraft:end_stone_brick_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:false:false:true:false:true:true";
case false:
return "minecraft:end_stone_brick_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:false:false:true:false:false:true";
case false:
return "minecraft:end_stone_brick_wall:false:false:true:false:false:false";
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
return "minecraft:end_stone_brick_wall:false:false:false:true:true:true";
case false:
return "minecraft:end_stone_brick_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:false:false:false:true:false:true";
case false:
return "minecraft:end_stone_brick_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:false:false:false:false:true:true";
case false:
return "minecraft:end_stone_brick_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:end_stone_brick_wall:false:false:false:false:false:true";
case false:
return "minecraft:end_stone_brick_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
