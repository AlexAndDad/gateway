#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct prismarine_brick_stairs
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
return 7148;
case false:
return 7149;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7150;
case false:
return 7151;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7152;
case false:
return 7153;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7154;
case false:
return 7155;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7156;
case false:
return 7157;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7158;
case false:
return 7159;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7160;
case false:
return 7161;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7162;
case false:
return 7163;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7164;
case false:
return 7165;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7166;
case false:
return 7167;
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
return 7168;
case false:
return 7169;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7170;
case false:
return 7171;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7172;
case false:
return 7173;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7174;
case false:
return 7175;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7176;
case false:
return 7177;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7178;
case false:
return 7179;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7180;
case false:
return 7181;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7182;
case false:
return 7183;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7184;
case false:
return 7185;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7186;
case false:
return 7187;
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
return 7188;
case false:
return 7189;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7190;
case false:
return 7191;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7192;
case false:
return 7193;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7194;
case false:
return 7195;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7196;
case false:
return 7197;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7198;
case false:
return 7199;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7200;
case false:
return 7201;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7202;
case false:
return 7203;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7204;
case false:
return 7205;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7206;
case false:
return 7207;
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
return 7208;
case false:
return 7209;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7210;
case false:
return 7211;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7212;
case false:
return 7213;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7214;
case false:
return 7215;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7216;
case false:
return 7217;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7218;
case false:
return 7219;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7220;
case false:
return 7221;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7222;
case false:
return 7223;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7224;
case false:
return 7225;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7226;
case false:
return 7227;
}
}
}
}
}
constexpr static prismarine_brick_stairs from_id(block_id_type id)
{
switch (id)
{
case 7148:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7149:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7150:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7151:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7152:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7153:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7154:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7155:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7156:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7157:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7158:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7159:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7160:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7161:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7162:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7163:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7164:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7165:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7166:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7167:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 7168:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7169:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7170:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7171:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7172:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7173:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7174:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7175:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7176:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7177:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7178:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7179:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7180:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7181:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7182:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7183:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7184:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7185:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7186:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7187:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 7188:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7189:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7190:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7191:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7192:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7193:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7194:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7195:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7196:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7197:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7198:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7199:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7200:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7201:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7202:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7203:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7204:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7205:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7206:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7207:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 7208:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7209:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7210:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7211:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7212:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7213:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7214:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7215:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7216:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7217:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7218:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7219:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7220:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7221:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7222:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7223:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7224:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7225:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7226:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7227:
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
return "minecraft:prismarine_brick_stairs:north:top:straight:true";
case false:
return "minecraft:prismarine_brick_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:north:top:inner_left:true";
case false:
return "minecraft:prismarine_brick_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:north:top:inner_right:true";
case false:
return "minecraft:prismarine_brick_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:north:top:outer_left:true";
case false:
return "minecraft:prismarine_brick_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:north:top:outer_right:true";
case false:
return "minecraft:prismarine_brick_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:north:bottom:straight:true";
case false:
return "minecraft:prismarine_brick_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:prismarine_brick_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:prismarine_brick_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:prismarine_brick_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:prismarine_brick_stairs:north:bottom:outer_right:false";
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
return "minecraft:prismarine_brick_stairs:south:top:straight:true";
case false:
return "minecraft:prismarine_brick_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:south:top:inner_left:true";
case false:
return "minecraft:prismarine_brick_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:south:top:inner_right:true";
case false:
return "minecraft:prismarine_brick_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:south:top:outer_left:true";
case false:
return "minecraft:prismarine_brick_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:south:top:outer_right:true";
case false:
return "minecraft:prismarine_brick_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:south:bottom:straight:true";
case false:
return "minecraft:prismarine_brick_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:prismarine_brick_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:prismarine_brick_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:prismarine_brick_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:prismarine_brick_stairs:south:bottom:outer_right:false";
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
return "minecraft:prismarine_brick_stairs:west:top:straight:true";
case false:
return "minecraft:prismarine_brick_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:west:top:inner_left:true";
case false:
return "minecraft:prismarine_brick_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:west:top:inner_right:true";
case false:
return "minecraft:prismarine_brick_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:west:top:outer_left:true";
case false:
return "minecraft:prismarine_brick_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:west:top:outer_right:true";
case false:
return "minecraft:prismarine_brick_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:west:bottom:straight:true";
case false:
return "minecraft:prismarine_brick_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:prismarine_brick_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:prismarine_brick_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:prismarine_brick_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:prismarine_brick_stairs:west:bottom:outer_right:false";
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
return "minecraft:prismarine_brick_stairs:east:top:straight:true";
case false:
return "minecraft:prismarine_brick_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:east:top:inner_left:true";
case false:
return "minecraft:prismarine_brick_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:east:top:inner_right:true";
case false:
return "minecraft:prismarine_brick_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:east:top:outer_left:true";
case false:
return "minecraft:prismarine_brick_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:east:top:outer_right:true";
case false:
return "minecraft:prismarine_brick_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:east:bottom:straight:true";
case false:
return "minecraft:prismarine_brick_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:prismarine_brick_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:prismarine_brick_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:prismarine_brick_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:prismarine_brick_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
