#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct polished_diorite_stairs
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
return 9373;
case false:
return 9374;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9375;
case false:
return 9376;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9377;
case false:
return 9378;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9379;
case false:
return 9380;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9381;
case false:
return 9382;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9383;
case false:
return 9384;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9385;
case false:
return 9386;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9387;
case false:
return 9388;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9389;
case false:
return 9390;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9391;
case false:
return 9392;
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
return 9393;
case false:
return 9394;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9395;
case false:
return 9396;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9397;
case false:
return 9398;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9399;
case false:
return 9400;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9401;
case false:
return 9402;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9403;
case false:
return 9404;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9405;
case false:
return 9406;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9407;
case false:
return 9408;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9409;
case false:
return 9410;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9411;
case false:
return 9412;
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
return 9413;
case false:
return 9414;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9415;
case false:
return 9416;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9417;
case false:
return 9418;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9419;
case false:
return 9420;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9421;
case false:
return 9422;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9423;
case false:
return 9424;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9425;
case false:
return 9426;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9427;
case false:
return 9428;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9429;
case false:
return 9430;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9431;
case false:
return 9432;
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
return 9433;
case false:
return 9434;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9435;
case false:
return 9436;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9437;
case false:
return 9438;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9439;
case false:
return 9440;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9441;
case false:
return 9442;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9443;
case false:
return 9444;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9445;
case false:
return 9446;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9447;
case false:
return 9448;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9449;
case false:
return 9450;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9451;
case false:
return 9452;
}
}
}
}
}
constexpr static polished_diorite_stairs from_id(block_id_type id)
{
switch (id)
{
case 9373:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9374:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9375:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9376:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9377:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9378:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9379:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9380:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9381:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9382:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9383:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9384:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9385:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9386:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9387:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9388:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9389:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9390:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9391:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9392:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9393:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9394:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9395:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9396:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9397:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9398:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9399:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9400:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9401:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9402:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9403:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9404:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9405:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9406:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9407:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9408:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9409:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9410:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9411:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9412:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9413:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9414:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9415:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9416:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9417:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9418:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9419:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9420:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9421:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9422:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9423:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9424:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9425:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9426:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9427:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9428:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9429:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9430:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9431:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9432:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9433:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9434:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9435:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9436:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9437:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9438:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9439:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9440:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9441:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9442:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9443:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9444:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9445:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9446:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9447:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9448:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9449:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9450:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9451:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9452:
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
return "minecraft:polished_diorite_stairs:north:top:straight:true";
case false:
return "minecraft:polished_diorite_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:north:top:inner_left:true";
case false:
return "minecraft:polished_diorite_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:north:top:inner_right:true";
case false:
return "minecraft:polished_diorite_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:north:top:outer_left:true";
case false:
return "minecraft:polished_diorite_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:north:top:outer_right:true";
case false:
return "minecraft:polished_diorite_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:north:bottom:straight:true";
case false:
return "minecraft:polished_diorite_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:polished_diorite_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:polished_diorite_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:polished_diorite_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:polished_diorite_stairs:north:bottom:outer_right:false";
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
return "minecraft:polished_diorite_stairs:south:top:straight:true";
case false:
return "minecraft:polished_diorite_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:south:top:inner_left:true";
case false:
return "minecraft:polished_diorite_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:south:top:inner_right:true";
case false:
return "minecraft:polished_diorite_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:south:top:outer_left:true";
case false:
return "minecraft:polished_diorite_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:south:top:outer_right:true";
case false:
return "minecraft:polished_diorite_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:south:bottom:straight:true";
case false:
return "minecraft:polished_diorite_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:polished_diorite_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:polished_diorite_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:polished_diorite_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:polished_diorite_stairs:south:bottom:outer_right:false";
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
return "minecraft:polished_diorite_stairs:west:top:straight:true";
case false:
return "minecraft:polished_diorite_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:west:top:inner_left:true";
case false:
return "minecraft:polished_diorite_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:west:top:inner_right:true";
case false:
return "minecraft:polished_diorite_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:west:top:outer_left:true";
case false:
return "minecraft:polished_diorite_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:west:top:outer_right:true";
case false:
return "minecraft:polished_diorite_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:west:bottom:straight:true";
case false:
return "minecraft:polished_diorite_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:polished_diorite_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:polished_diorite_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:polished_diorite_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:polished_diorite_stairs:west:bottom:outer_right:false";
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
return "minecraft:polished_diorite_stairs:east:top:straight:true";
case false:
return "minecraft:polished_diorite_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:east:top:inner_left:true";
case false:
return "minecraft:polished_diorite_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:east:top:inner_right:true";
case false:
return "minecraft:polished_diorite_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:east:top:outer_left:true";
case false:
return "minecraft:polished_diorite_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:east:top:outer_right:true";
case false:
return "minecraft:polished_diorite_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:east:bottom:straight:true";
case false:
return "minecraft:polished_diorite_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:polished_diorite_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:polished_diorite_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:polished_diorite_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:polished_diorite_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
