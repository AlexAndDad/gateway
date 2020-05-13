#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct spruce_stairs
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
return 5388;
case false:
return 5389;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5390;
case false:
return 5391;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5392;
case false:
return 5393;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5394;
case false:
return 5395;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5396;
case false:
return 5397;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5398;
case false:
return 5399;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5400;
case false:
return 5401;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5402;
case false:
return 5403;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5404;
case false:
return 5405;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5406;
case false:
return 5407;
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
return 5408;
case false:
return 5409;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5410;
case false:
return 5411;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5412;
case false:
return 5413;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5414;
case false:
return 5415;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5416;
case false:
return 5417;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5418;
case false:
return 5419;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5420;
case false:
return 5421;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5422;
case false:
return 5423;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5424;
case false:
return 5425;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5426;
case false:
return 5427;
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
return 5428;
case false:
return 5429;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5430;
case false:
return 5431;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5432;
case false:
return 5433;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5434;
case false:
return 5435;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5436;
case false:
return 5437;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5438;
case false:
return 5439;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5440;
case false:
return 5441;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5442;
case false:
return 5443;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5444;
case false:
return 5445;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5446;
case false:
return 5447;
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
return 5448;
case false:
return 5449;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5450;
case false:
return 5451;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5452;
case false:
return 5453;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5454;
case false:
return 5455;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5456;
case false:
return 5457;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5458;
case false:
return 5459;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5460;
case false:
return 5461;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5462;
case false:
return 5463;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5464;
case false:
return 5465;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5466;
case false:
return 5467;
}
}
}
}
}
constexpr static spruce_stairs from_id(block_id_type id)
{
switch (id)
{
case 5388:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5389:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5390:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5391:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5392:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5393:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5394:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5395:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5396:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5397:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5398:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5399:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5400:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5401:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5402:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5403:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5404:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5405:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5406:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5407:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5408:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5409:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5410:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5411:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5412:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5413:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5414:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5415:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5416:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5417:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5418:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5419:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5420:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5421:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5422:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5423:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5424:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5425:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5426:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5427:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5428:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5429:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5430:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5431:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5432:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5433:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5434:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5435:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5436:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5437:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5438:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5439:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5440:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5441:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5442:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5443:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5444:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5445:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5446:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5447:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5448:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5449:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5450:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5451:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5452:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5453:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5454:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5455:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5456:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5457:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5458:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5459:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5460:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5461:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5462:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5463:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5464:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5465:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5466:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5467:
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
return "minecraft:spruce_stairs:north:top:straight:true";
case false:
return "minecraft:spruce_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:north:top:inner_left:true";
case false:
return "minecraft:spruce_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:north:top:inner_right:true";
case false:
return "minecraft:spruce_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:north:top:outer_left:true";
case false:
return "minecraft:spruce_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:north:top:outer_right:true";
case false:
return "minecraft:spruce_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:north:bottom:straight:true";
case false:
return "minecraft:spruce_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:spruce_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:spruce_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:spruce_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:spruce_stairs:north:bottom:outer_right:false";
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
return "minecraft:spruce_stairs:south:top:straight:true";
case false:
return "minecraft:spruce_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:south:top:inner_left:true";
case false:
return "minecraft:spruce_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:south:top:inner_right:true";
case false:
return "minecraft:spruce_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:south:top:outer_left:true";
case false:
return "minecraft:spruce_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:south:top:outer_right:true";
case false:
return "minecraft:spruce_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:south:bottom:straight:true";
case false:
return "minecraft:spruce_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:spruce_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:spruce_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:spruce_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:spruce_stairs:south:bottom:outer_right:false";
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
return "minecraft:spruce_stairs:west:top:straight:true";
case false:
return "minecraft:spruce_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:west:top:inner_left:true";
case false:
return "minecraft:spruce_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:west:top:inner_right:true";
case false:
return "minecraft:spruce_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:west:top:outer_left:true";
case false:
return "minecraft:spruce_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:west:top:outer_right:true";
case false:
return "minecraft:spruce_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:west:bottom:straight:true";
case false:
return "minecraft:spruce_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:spruce_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:spruce_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:spruce_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:spruce_stairs:west:bottom:outer_right:false";
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
return "minecraft:spruce_stairs:east:top:straight:true";
case false:
return "minecraft:spruce_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:east:top:inner_left:true";
case false:
return "minecraft:spruce_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:east:top:inner_right:true";
case false:
return "minecraft:spruce_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:east:top:outer_left:true";
case false:
return "minecraft:spruce_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:east:top:outer_right:true";
case false:
return "minecraft:spruce_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:east:bottom:straight:true";
case false:
return "minecraft:spruce_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:spruce_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:spruce_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:spruce_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:spruce_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:spruce_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
