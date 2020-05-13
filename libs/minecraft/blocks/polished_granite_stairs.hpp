#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct polished_granite_stairs
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
return 9133;
case false:
return 9134;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9135;
case false:
return 9136;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9137;
case false:
return 9138;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9139;
case false:
return 9140;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9141;
case false:
return 9142;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9143;
case false:
return 9144;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9145;
case false:
return 9146;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9147;
case false:
return 9148;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9149;
case false:
return 9150;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9151;
case false:
return 9152;
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
return 9153;
case false:
return 9154;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9155;
case false:
return 9156;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9157;
case false:
return 9158;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9159;
case false:
return 9160;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9161;
case false:
return 9162;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9163;
case false:
return 9164;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9165;
case false:
return 9166;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9167;
case false:
return 9168;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9169;
case false:
return 9170;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9171;
case false:
return 9172;
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
return 9173;
case false:
return 9174;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9175;
case false:
return 9176;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9177;
case false:
return 9178;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9179;
case false:
return 9180;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9181;
case false:
return 9182;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9183;
case false:
return 9184;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9185;
case false:
return 9186;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9187;
case false:
return 9188;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9189;
case false:
return 9190;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9191;
case false:
return 9192;
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
return 9193;
case false:
return 9194;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9195;
case false:
return 9196;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9197;
case false:
return 9198;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9199;
case false:
return 9200;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9201;
case false:
return 9202;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9203;
case false:
return 9204;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9205;
case false:
return 9206;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9207;
case false:
return 9208;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9209;
case false:
return 9210;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9211;
case false:
return 9212;
}
}
}
}
}
constexpr static polished_granite_stairs from_id(block_id_type id)
{
switch (id)
{
case 9133:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9134:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9135:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9136:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9137:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9138:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9139:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9140:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9141:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9142:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9143:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9144:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9145:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9146:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9147:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9148:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9149:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9150:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9151:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9152:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9153:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9154:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9155:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9156:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9157:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9158:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9159:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9160:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9161:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9162:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9163:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9164:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9165:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9166:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9167:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9168:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9169:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9170:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9171:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9172:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9173:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9174:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9175:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9176:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9177:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9178:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9179:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9180:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9181:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9182:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9183:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9184:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9185:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9186:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9187:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9188:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9189:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9190:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9191:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9192:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9193:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9194:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9195:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9196:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9197:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9198:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9199:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9200:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9201:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9202:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9203:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9204:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9205:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9206:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9207:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9208:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9209:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9210:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9211:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9212:
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
return "minecraft:polished_granite_stairs:north:top:straight:true";
case false:
return "minecraft:polished_granite_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:north:top:inner_left:true";
case false:
return "minecraft:polished_granite_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:north:top:inner_right:true";
case false:
return "minecraft:polished_granite_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:north:top:outer_left:true";
case false:
return "minecraft:polished_granite_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:north:top:outer_right:true";
case false:
return "minecraft:polished_granite_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:north:bottom:straight:true";
case false:
return "minecraft:polished_granite_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:polished_granite_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:polished_granite_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:polished_granite_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:polished_granite_stairs:north:bottom:outer_right:false";
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
return "minecraft:polished_granite_stairs:south:top:straight:true";
case false:
return "minecraft:polished_granite_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:south:top:inner_left:true";
case false:
return "minecraft:polished_granite_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:south:top:inner_right:true";
case false:
return "minecraft:polished_granite_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:south:top:outer_left:true";
case false:
return "minecraft:polished_granite_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:south:top:outer_right:true";
case false:
return "minecraft:polished_granite_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:south:bottom:straight:true";
case false:
return "minecraft:polished_granite_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:polished_granite_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:polished_granite_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:polished_granite_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:polished_granite_stairs:south:bottom:outer_right:false";
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
return "minecraft:polished_granite_stairs:west:top:straight:true";
case false:
return "minecraft:polished_granite_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:west:top:inner_left:true";
case false:
return "minecraft:polished_granite_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:west:top:inner_right:true";
case false:
return "minecraft:polished_granite_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:west:top:outer_left:true";
case false:
return "minecraft:polished_granite_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:west:top:outer_right:true";
case false:
return "minecraft:polished_granite_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:west:bottom:straight:true";
case false:
return "minecraft:polished_granite_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:polished_granite_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:polished_granite_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:polished_granite_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:polished_granite_stairs:west:bottom:outer_right:false";
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
return "minecraft:polished_granite_stairs:east:top:straight:true";
case false:
return "minecraft:polished_granite_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:east:top:inner_left:true";
case false:
return "minecraft:polished_granite_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:east:top:inner_right:true";
case false:
return "minecraft:polished_granite_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:east:top:outer_left:true";
case false:
return "minecraft:polished_granite_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:east:top:outer_right:true";
case false:
return "minecraft:polished_granite_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:east:bottom:straight:true";
case false:
return "minecraft:polished_granite_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:polished_granite_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:polished_granite_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:polished_granite_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:polished_granite_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
