#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct polished_andesite_stairs
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
enum class half_type : std::uint8_t
{
top,
bottom
} half = half_type::bottom;
enum class shape_type : std::uint8_t
{
straight,
inner_left,
inner_right,
outer_left,
outer_right
} shape = shape_type::straight;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 10093;
case false:
return 10094;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10095;
case false:
return 10096;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10097;
case false:
return 10098;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10099;
case false:
return 10100;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10101;
case false:
return 10102;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 10103;
case false:
return 10104;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10105;
case false:
return 10106;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10107;
case false:
return 10108;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10109;
case false:
return 10110;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10111;
case false:
return 10112;
}
}
}
case facing_type::south:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 10113;
case false:
return 10114;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10115;
case false:
return 10116;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10117;
case false:
return 10118;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10119;
case false:
return 10120;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10121;
case false:
return 10122;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 10123;
case false:
return 10124;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10125;
case false:
return 10126;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10127;
case false:
return 10128;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10129;
case false:
return 10130;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10131;
case false:
return 10132;
}
}
}
case facing_type::west:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 10133;
case false:
return 10134;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10135;
case false:
return 10136;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10137;
case false:
return 10138;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10139;
case false:
return 10140;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10141;
case false:
return 10142;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 10143;
case false:
return 10144;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10145;
case false:
return 10146;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10147;
case false:
return 10148;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10149;
case false:
return 10150;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10151;
case false:
return 10152;
}
}
}
case facing_type::east:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 10153;
case false:
return 10154;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10155;
case false:
return 10156;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10157;
case false:
return 10158;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10159;
case false:
return 10160;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10161;
case false:
return 10162;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 10163;
case false:
return 10164;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10165;
case false:
return 10166;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10167;
case false:
return 10168;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10169;
case false:
return 10170;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10171;
case false:
return 10172;
}
}
}
}
}
constexpr static polished_andesite_stairs from_id(block_id_type id)
{
switch (id)
{
case 10093:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 10094:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 10095:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 10096:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 10097:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 10098:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 10099:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 10100:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 10101:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 10102:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 10103:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 10104:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 10105:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 10106:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 10107:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 10108:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 10109:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 10110:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 10111:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 10112:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 10113:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 10114:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 10115:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 10116:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 10117:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 10118:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 10119:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 10120:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 10121:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 10122:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 10123:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 10124:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 10125:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 10126:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 10127:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 10128:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 10129:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 10130:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 10131:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 10132:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 10133:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 10134:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 10135:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 10136:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 10137:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 10138:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 10139:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 10140:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 10141:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 10142:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 10143:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 10144:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 10145:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 10146:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 10147:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 10148:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 10149:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 10150:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 10151:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 10152:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 10153:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 10154:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 10155:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 10156:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 10157:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 10158:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 10159:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 10160:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 10161:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 10162:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 10163:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 10164:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 10165:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 10166:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 10167:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 10168:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 10169:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 10170:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 10171:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 10172:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:north:top:straight:true";
case false:
return "minecraft:polished_andesite_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:north:top:inner_left:true";
case false:
return "minecraft:polished_andesite_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:north:top:inner_right:true";
case false:
return "minecraft:polished_andesite_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:north:top:outer_left:true";
case false:
return "minecraft:polished_andesite_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:north:top:outer_right:true";
case false:
return "minecraft:polished_andesite_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:north:bottom:straight:true";
case false:
return "minecraft:polished_andesite_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:polished_andesite_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:polished_andesite_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:polished_andesite_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:polished_andesite_stairs:north:bottom:outer_right:false";
}
}
}
case facing_type::south:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:south:top:straight:true";
case false:
return "minecraft:polished_andesite_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:south:top:inner_left:true";
case false:
return "minecraft:polished_andesite_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:south:top:inner_right:true";
case false:
return "minecraft:polished_andesite_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:south:top:outer_left:true";
case false:
return "minecraft:polished_andesite_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:south:top:outer_right:true";
case false:
return "minecraft:polished_andesite_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:south:bottom:straight:true";
case false:
return "minecraft:polished_andesite_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:polished_andesite_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:polished_andesite_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:polished_andesite_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:polished_andesite_stairs:south:bottom:outer_right:false";
}
}
}
case facing_type::west:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:west:top:straight:true";
case false:
return "minecraft:polished_andesite_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:west:top:inner_left:true";
case false:
return "minecraft:polished_andesite_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:west:top:inner_right:true";
case false:
return "minecraft:polished_andesite_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:west:top:outer_left:true";
case false:
return "minecraft:polished_andesite_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:west:top:outer_right:true";
case false:
return "minecraft:polished_andesite_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:west:bottom:straight:true";
case false:
return "minecraft:polished_andesite_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:polished_andesite_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:polished_andesite_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:polished_andesite_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:polished_andesite_stairs:west:bottom:outer_right:false";
}
}
}
case facing_type::east:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:east:top:straight:true";
case false:
return "minecraft:polished_andesite_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:east:top:inner_left:true";
case false:
return "minecraft:polished_andesite_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:east:top:inner_right:true";
case false:
return "minecraft:polished_andesite_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:east:top:outer_left:true";
case false:
return "minecraft:polished_andesite_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:east:top:outer_right:true";
case false:
return "minecraft:polished_andesite_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:east:bottom:straight:true";
case false:
return "minecraft:polished_andesite_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:polished_andesite_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:polished_andesite_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:polished_andesite_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:polished_andesite_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
