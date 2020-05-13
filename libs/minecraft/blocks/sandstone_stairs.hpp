#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct sandstone_stairs
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
return 5154;
case false:
return 5155;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5156;
case false:
return 5157;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5158;
case false:
return 5159;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5160;
case false:
return 5161;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5162;
case false:
return 5163;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5164;
case false:
return 5165;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5166;
case false:
return 5167;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5168;
case false:
return 5169;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5170;
case false:
return 5171;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5172;
case false:
return 5173;
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
return 5174;
case false:
return 5175;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5176;
case false:
return 5177;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5178;
case false:
return 5179;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5180;
case false:
return 5181;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5182;
case false:
return 5183;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5184;
case false:
return 5185;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5186;
case false:
return 5187;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5188;
case false:
return 5189;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5190;
case false:
return 5191;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5192;
case false:
return 5193;
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
return 5194;
case false:
return 5195;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5196;
case false:
return 5197;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5198;
case false:
return 5199;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5200;
case false:
return 5201;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5202;
case false:
return 5203;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5204;
case false:
return 5205;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5206;
case false:
return 5207;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5208;
case false:
return 5209;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5210;
case false:
return 5211;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5212;
case false:
return 5213;
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
return 5214;
case false:
return 5215;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5216;
case false:
return 5217;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5218;
case false:
return 5219;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5220;
case false:
return 5221;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5222;
case false:
return 5223;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5224;
case false:
return 5225;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5226;
case false:
return 5227;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5228;
case false:
return 5229;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5230;
case false:
return 5231;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5232;
case false:
return 5233;
}
}
}
}
}
constexpr static sandstone_stairs from_id(block_id_type id)
{
switch (id)
{
case 5154:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5155:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5156:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5157:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5158:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5159:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5160:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5161:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5162:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5163:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5164:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5165:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5166:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5167:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5168:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5169:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5170:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5171:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5172:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5173:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5174:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5175:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5176:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5177:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5178:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5179:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5180:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5181:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5182:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5183:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5184:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5185:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5186:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5187:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5188:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5189:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5190:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5191:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5192:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5193:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5194:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5195:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5196:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5197:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5198:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5199:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5200:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5201:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5202:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5203:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5204:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5205:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5206:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5207:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5208:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5209:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5210:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5211:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5212:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5213:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5214:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5215:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5216:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5217:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5218:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5219:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5220:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5221:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5222:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5223:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5224:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5225:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5226:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5227:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5228:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5229:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5230:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5231:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5232:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5233:
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
return "minecraft:sandstone_stairs:north:top:straight:true";
case false:
return "minecraft:sandstone_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:north:top:inner_left:true";
case false:
return "minecraft:sandstone_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:north:top:inner_right:true";
case false:
return "minecraft:sandstone_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:north:top:outer_left:true";
case false:
return "minecraft:sandstone_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:north:top:outer_right:true";
case false:
return "minecraft:sandstone_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:north:bottom:straight:true";
case false:
return "minecraft:sandstone_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:sandstone_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:sandstone_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:sandstone_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:sandstone_stairs:north:bottom:outer_right:false";
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
return "minecraft:sandstone_stairs:south:top:straight:true";
case false:
return "minecraft:sandstone_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:south:top:inner_left:true";
case false:
return "minecraft:sandstone_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:south:top:inner_right:true";
case false:
return "minecraft:sandstone_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:south:top:outer_left:true";
case false:
return "minecraft:sandstone_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:south:top:outer_right:true";
case false:
return "minecraft:sandstone_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:south:bottom:straight:true";
case false:
return "minecraft:sandstone_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:sandstone_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:sandstone_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:sandstone_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:sandstone_stairs:south:bottom:outer_right:false";
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
return "minecraft:sandstone_stairs:west:top:straight:true";
case false:
return "minecraft:sandstone_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:west:top:inner_left:true";
case false:
return "minecraft:sandstone_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:west:top:inner_right:true";
case false:
return "minecraft:sandstone_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:west:top:outer_left:true";
case false:
return "minecraft:sandstone_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:west:top:outer_right:true";
case false:
return "minecraft:sandstone_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:west:bottom:straight:true";
case false:
return "minecraft:sandstone_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:sandstone_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:sandstone_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:sandstone_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:sandstone_stairs:west:bottom:outer_right:false";
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
return "minecraft:sandstone_stairs:east:top:straight:true";
case false:
return "minecraft:sandstone_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:east:top:inner_left:true";
case false:
return "minecraft:sandstone_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:east:top:inner_right:true";
case false:
return "minecraft:sandstone_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:east:top:outer_left:true";
case false:
return "minecraft:sandstone_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:east:top:outer_right:true";
case false:
return "minecraft:sandstone_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:east:bottom:straight:true";
case false:
return "minecraft:sandstone_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:sandstone_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:sandstone_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:sandstone_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:sandstone_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
