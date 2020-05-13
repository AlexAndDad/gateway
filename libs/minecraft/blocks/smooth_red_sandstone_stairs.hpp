#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct smooth_red_sandstone_stairs
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
return 9213;
case false:
return 9214;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9215;
case false:
return 9216;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9217;
case false:
return 9218;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9219;
case false:
return 9220;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9221;
case false:
return 9222;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9223;
case false:
return 9224;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9225;
case false:
return 9226;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9227;
case false:
return 9228;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9229;
case false:
return 9230;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9231;
case false:
return 9232;
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
return 9233;
case false:
return 9234;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9235;
case false:
return 9236;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9237;
case false:
return 9238;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9239;
case false:
return 9240;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9241;
case false:
return 9242;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9243;
case false:
return 9244;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9245;
case false:
return 9246;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9247;
case false:
return 9248;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9249;
case false:
return 9250;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9251;
case false:
return 9252;
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
return 9253;
case false:
return 9254;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9255;
case false:
return 9256;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9257;
case false:
return 9258;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9259;
case false:
return 9260;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9261;
case false:
return 9262;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9263;
case false:
return 9264;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9265;
case false:
return 9266;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9267;
case false:
return 9268;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9269;
case false:
return 9270;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9271;
case false:
return 9272;
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
return 9273;
case false:
return 9274;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9275;
case false:
return 9276;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9277;
case false:
return 9278;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9279;
case false:
return 9280;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9281;
case false:
return 9282;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9283;
case false:
return 9284;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9285;
case false:
return 9286;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9287;
case false:
return 9288;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9289;
case false:
return 9290;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9291;
case false:
return 9292;
}
}
}
}
}
constexpr static smooth_red_sandstone_stairs from_id(block_id_type id)
{
switch (id)
{
case 9213:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9214:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9215:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9216:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9217:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9218:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9219:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9220:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9221:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9222:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9223:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9224:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9225:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9226:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9227:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9228:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9229:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9230:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9231:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9232:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9233:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9234:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9235:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9236:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9237:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9238:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9239:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9240:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9241:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9242:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9243:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9244:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9245:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9246:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9247:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9248:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9249:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9250:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9251:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9252:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9253:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9254:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9255:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9256:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9257:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9258:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9259:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9260:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9261:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9262:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9263:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9264:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9265:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9266:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9267:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9268:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9269:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9270:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9271:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9272:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9273:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9274:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9275:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9276:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9277:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9278:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9279:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9280:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9281:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9282:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9283:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9284:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9285:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9286:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9287:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9288:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9289:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9290:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9291:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9292:
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
return "minecraft:smooth_red_sandstone_stairs:north:top:straight:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:north:top:inner_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:north:top:inner_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:north:top:outer_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:north:top:outer_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:north:bottom:straight:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:north:bottom:outer_right:false";
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
return "minecraft:smooth_red_sandstone_stairs:south:top:straight:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:south:top:inner_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:south:top:inner_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:south:top:outer_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:south:top:outer_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:south:bottom:straight:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:south:bottom:outer_right:false";
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
return "minecraft:smooth_red_sandstone_stairs:west:top:straight:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:west:top:inner_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:west:top:inner_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:west:top:outer_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:west:top:outer_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:west:bottom:straight:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:west:bottom:outer_right:false";
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
return "minecraft:smooth_red_sandstone_stairs:east:top:straight:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:east:top:inner_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:east:top:inner_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:east:top:outer_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:east:top:outer_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:east:bottom:straight:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:smooth_red_sandstone_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
