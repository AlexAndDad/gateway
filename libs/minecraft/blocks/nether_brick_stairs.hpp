#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct nether_brick_stairs
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
return 5032;
case false:
return 5033;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5034;
case false:
return 5035;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5036;
case false:
return 5037;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5038;
case false:
return 5039;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5040;
case false:
return 5041;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5042;
case false:
return 5043;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5044;
case false:
return 5045;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5046;
case false:
return 5047;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5048;
case false:
return 5049;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5050;
case false:
return 5051;
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
return 5052;
case false:
return 5053;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5054;
case false:
return 5055;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5056;
case false:
return 5057;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5058;
case false:
return 5059;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5060;
case false:
return 5061;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5062;
case false:
return 5063;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5064;
case false:
return 5065;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5066;
case false:
return 5067;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5068;
case false:
return 5069;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5070;
case false:
return 5071;
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
return 5072;
case false:
return 5073;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5074;
case false:
return 5075;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5076;
case false:
return 5077;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5078;
case false:
return 5079;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5080;
case false:
return 5081;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5082;
case false:
return 5083;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5084;
case false:
return 5085;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5086;
case false:
return 5087;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5088;
case false:
return 5089;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5090;
case false:
return 5091;
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
return 5092;
case false:
return 5093;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5094;
case false:
return 5095;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5096;
case false:
return 5097;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5098;
case false:
return 5099;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5100;
case false:
return 5101;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5102;
case false:
return 5103;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5104;
case false:
return 5105;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5106;
case false:
return 5107;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5108;
case false:
return 5109;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5110;
case false:
return 5111;
}
}
}
}
}
constexpr static nether_brick_stairs from_id(block_id_type id)
{
switch (id)
{
case 5032:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5033:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5034:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5035:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5036:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5037:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5038:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5039:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5040:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5041:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5042:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5043:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5044:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5045:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5046:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5047:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5048:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5049:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5050:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5051:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5052:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5053:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5054:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5055:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5056:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5057:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5058:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5059:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5060:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5061:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5062:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5063:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5064:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5065:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5066:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5067:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5068:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5069:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5070:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5071:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5072:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5073:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5074:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5075:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5076:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5077:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5078:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5079:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5080:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5081:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5082:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5083:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5084:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5085:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5086:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5087:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5088:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5089:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5090:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5091:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5092:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5093:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5094:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5095:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5096:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5097:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5098:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5099:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5100:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5101:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5102:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5103:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5104:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5105:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5106:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5107:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5108:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5109:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5110:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5111:
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
return "minecraft:nether_brick_stairs:north:top:straight:true";
case false:
return "minecraft:nether_brick_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:north:top:inner_left:true";
case false:
return "minecraft:nether_brick_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:north:top:inner_right:true";
case false:
return "minecraft:nether_brick_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:north:top:outer_left:true";
case false:
return "minecraft:nether_brick_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:north:top:outer_right:true";
case false:
return "minecraft:nether_brick_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:north:bottom:straight:true";
case false:
return "minecraft:nether_brick_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:nether_brick_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:nether_brick_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:nether_brick_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:nether_brick_stairs:north:bottom:outer_right:false";
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
return "minecraft:nether_brick_stairs:south:top:straight:true";
case false:
return "minecraft:nether_brick_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:south:top:inner_left:true";
case false:
return "minecraft:nether_brick_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:south:top:inner_right:true";
case false:
return "minecraft:nether_brick_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:south:top:outer_left:true";
case false:
return "minecraft:nether_brick_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:south:top:outer_right:true";
case false:
return "minecraft:nether_brick_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:south:bottom:straight:true";
case false:
return "minecraft:nether_brick_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:nether_brick_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:nether_brick_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:nether_brick_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:nether_brick_stairs:south:bottom:outer_right:false";
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
return "minecraft:nether_brick_stairs:west:top:straight:true";
case false:
return "minecraft:nether_brick_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:west:top:inner_left:true";
case false:
return "minecraft:nether_brick_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:west:top:inner_right:true";
case false:
return "minecraft:nether_brick_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:west:top:outer_left:true";
case false:
return "minecraft:nether_brick_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:west:top:outer_right:true";
case false:
return "minecraft:nether_brick_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:west:bottom:straight:true";
case false:
return "minecraft:nether_brick_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:nether_brick_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:nether_brick_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:nether_brick_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:nether_brick_stairs:west:bottom:outer_right:false";
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
return "minecraft:nether_brick_stairs:east:top:straight:true";
case false:
return "minecraft:nether_brick_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:east:top:inner_left:true";
case false:
return "minecraft:nether_brick_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:east:top:inner_right:true";
case false:
return "minecraft:nether_brick_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:east:top:outer_left:true";
case false:
return "minecraft:nether_brick_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:east:top:outer_right:true";
case false:
return "minecraft:nether_brick_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:east:bottom:straight:true";
case false:
return "minecraft:nether_brick_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:nether_brick_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:nether_brick_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:nether_brick_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:nether_brick_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
