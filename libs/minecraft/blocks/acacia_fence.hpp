#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct acacia_fence
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
return 8138;
case false:
return 8139;
}
case false:
switch (west)
{
case true:
return 8140;
case false:
return 8141;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8142;
case false:
return 8143;
}
case false:
switch (west)
{
case true:
return 8144;
case false:
return 8145;
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
return 8146;
case false:
return 8147;
}
case false:
switch (west)
{
case true:
return 8148;
case false:
return 8149;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8150;
case false:
return 8151;
}
case false:
switch (west)
{
case true:
return 8152;
case false:
return 8153;
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
return 8154;
case false:
return 8155;
}
case false:
switch (west)
{
case true:
return 8156;
case false:
return 8157;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8158;
case false:
return 8159;
}
case false:
switch (west)
{
case true:
return 8160;
case false:
return 8161;
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
return 8162;
case false:
return 8163;
}
case false:
switch (west)
{
case true:
return 8164;
case false:
return 8165;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 8166;
case false:
return 8167;
}
case false:
switch (west)
{
case true:
return 8168;
case false:
return 8169;
}
}
}
}
}
}
constexpr static acacia_fence from_id(block_id_type id)
{
switch (id)
{
case 8138:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 8139:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 8140:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 8141:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 8142:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 8143:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 8144:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 8145:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 8146:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 8147:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 8148:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 8149:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 8150:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 8151:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 8152:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 8153:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 8154:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 8155:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 8156:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 8157:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 8158:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 8159:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 8160:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 8161:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 8162:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 8163:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 8164:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 8165:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 8166:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 8167:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 8168:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 8169:
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
return "minecraft:acacia_fence:true:true:true:true:true";
case false:
return "minecraft:acacia_fence:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:acacia_fence:true:true:true:false:true";
case false:
return "minecraft:acacia_fence:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:acacia_fence:true:true:false:true:true";
case false:
return "minecraft:acacia_fence:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:acacia_fence:true:true:false:false:true";
case false:
return "minecraft:acacia_fence:true:true:false:false:false";
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
return "minecraft:acacia_fence:true:false:true:true:true";
case false:
return "minecraft:acacia_fence:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:acacia_fence:true:false:true:false:true";
case false:
return "minecraft:acacia_fence:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:acacia_fence:true:false:false:true:true";
case false:
return "minecraft:acacia_fence:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:acacia_fence:true:false:false:false:true";
case false:
return "minecraft:acacia_fence:true:false:false:false:false";
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
return "minecraft:acacia_fence:false:true:true:true:true";
case false:
return "minecraft:acacia_fence:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:acacia_fence:false:true:true:false:true";
case false:
return "minecraft:acacia_fence:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:acacia_fence:false:true:false:true:true";
case false:
return "minecraft:acacia_fence:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:acacia_fence:false:true:false:false:true";
case false:
return "minecraft:acacia_fence:false:true:false:false:false";
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
return "minecraft:acacia_fence:false:false:true:true:true";
case false:
return "minecraft:acacia_fence:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:acacia_fence:false:false:true:false:true";
case false:
return "minecraft:acacia_fence:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:acacia_fence:false:false:false:true:true";
case false:
return "minecraft:acacia_fence:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:acacia_fence:false:false:false:false:true";
case false:
return "minecraft:acacia_fence:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
