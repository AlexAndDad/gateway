#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct red_nether_brick_stairs
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
return 10013;
case false:
return 10014;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10015;
case false:
return 10016;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10017;
case false:
return 10018;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10019;
case false:
return 10020;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10021;
case false:
return 10022;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 10023;
case false:
return 10024;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10025;
case false:
return 10026;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10027;
case false:
return 10028;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10029;
case false:
return 10030;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10031;
case false:
return 10032;
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
return 10033;
case false:
return 10034;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10035;
case false:
return 10036;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10037;
case false:
return 10038;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10039;
case false:
return 10040;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10041;
case false:
return 10042;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 10043;
case false:
return 10044;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10045;
case false:
return 10046;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10047;
case false:
return 10048;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10049;
case false:
return 10050;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10051;
case false:
return 10052;
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
return 10053;
case false:
return 10054;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10055;
case false:
return 10056;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10057;
case false:
return 10058;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10059;
case false:
return 10060;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10061;
case false:
return 10062;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 10063;
case false:
return 10064;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10065;
case false:
return 10066;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10067;
case false:
return 10068;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10069;
case false:
return 10070;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10071;
case false:
return 10072;
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
return 10073;
case false:
return 10074;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10075;
case false:
return 10076;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10077;
case false:
return 10078;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10079;
case false:
return 10080;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10081;
case false:
return 10082;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 10083;
case false:
return 10084;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 10085;
case false:
return 10086;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 10087;
case false:
return 10088;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 10089;
case false:
return 10090;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 10091;
case false:
return 10092;
}
}
}
}
}
constexpr static red_nether_brick_stairs from_id(block_id_type id)
{
switch (id)
{
case 10013:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 10014:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 10015:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 10016:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 10017:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 10018:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 10019:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 10020:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 10021:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 10022:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 10023:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 10024:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 10025:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 10026:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 10027:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 10028:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 10029:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 10030:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 10031:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 10032:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 10033:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 10034:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 10035:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 10036:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 10037:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 10038:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 10039:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 10040:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 10041:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 10042:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 10043:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 10044:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 10045:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 10046:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 10047:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 10048:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 10049:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 10050:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 10051:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 10052:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 10053:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 10054:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 10055:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 10056:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 10057:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 10058:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 10059:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 10060:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 10061:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 10062:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 10063:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 10064:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 10065:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 10066:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 10067:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 10068:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 10069:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 10070:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 10071:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 10072:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 10073:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 10074:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 10075:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 10076:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 10077:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 10078:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 10079:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 10080:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 10081:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 10082:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 10083:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 10084:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 10085:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 10086:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 10087:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 10088:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 10089:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 10090:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 10091:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 10092:
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
return "minecraft:red_nether_brick_stairs:north:top:straight:true";
case false:
return "minecraft:red_nether_brick_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:north:top:inner_left:true";
case false:
return "minecraft:red_nether_brick_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:north:top:inner_right:true";
case false:
return "minecraft:red_nether_brick_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:north:top:outer_left:true";
case false:
return "minecraft:red_nether_brick_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:north:top:outer_right:true";
case false:
return "minecraft:red_nether_brick_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:north:bottom:straight:true";
case false:
return "minecraft:red_nether_brick_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:red_nether_brick_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:red_nether_brick_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:red_nether_brick_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:red_nether_brick_stairs:north:bottom:outer_right:false";
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
return "minecraft:red_nether_brick_stairs:south:top:straight:true";
case false:
return "minecraft:red_nether_brick_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:south:top:inner_left:true";
case false:
return "minecraft:red_nether_brick_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:south:top:inner_right:true";
case false:
return "minecraft:red_nether_brick_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:south:top:outer_left:true";
case false:
return "minecraft:red_nether_brick_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:south:top:outer_right:true";
case false:
return "minecraft:red_nether_brick_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:south:bottom:straight:true";
case false:
return "minecraft:red_nether_brick_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:red_nether_brick_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:red_nether_brick_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:red_nether_brick_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:red_nether_brick_stairs:south:bottom:outer_right:false";
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
return "minecraft:red_nether_brick_stairs:west:top:straight:true";
case false:
return "minecraft:red_nether_brick_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:west:top:inner_left:true";
case false:
return "minecraft:red_nether_brick_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:west:top:inner_right:true";
case false:
return "minecraft:red_nether_brick_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:west:top:outer_left:true";
case false:
return "minecraft:red_nether_brick_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:west:top:outer_right:true";
case false:
return "minecraft:red_nether_brick_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:west:bottom:straight:true";
case false:
return "minecraft:red_nether_brick_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:red_nether_brick_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:red_nether_brick_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:red_nether_brick_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:red_nether_brick_stairs:west:bottom:outer_right:false";
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
return "minecraft:red_nether_brick_stairs:east:top:straight:true";
case false:
return "minecraft:red_nether_brick_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:east:top:inner_left:true";
case false:
return "minecraft:red_nether_brick_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:east:top:inner_right:true";
case false:
return "minecraft:red_nether_brick_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:east:top:outer_left:true";
case false:
return "minecraft:red_nether_brick_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:east:top:outer_right:true";
case false:
return "minecraft:red_nether_brick_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:east:bottom:straight:true";
case false:
return "minecraft:red_nether_brick_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:red_nether_brick_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:red_nether_brick_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:red_nether_brick_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_nether_brick_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:red_nether_brick_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
