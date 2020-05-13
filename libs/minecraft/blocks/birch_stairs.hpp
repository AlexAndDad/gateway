#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct birch_stairs
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
return 5468;
case false:
return 5469;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5470;
case false:
return 5471;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5472;
case false:
return 5473;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5474;
case false:
return 5475;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5476;
case false:
return 5477;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5478;
case false:
return 5479;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5480;
case false:
return 5481;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5482;
case false:
return 5483;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5484;
case false:
return 5485;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5486;
case false:
return 5487;
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
return 5488;
case false:
return 5489;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5490;
case false:
return 5491;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5492;
case false:
return 5493;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5494;
case false:
return 5495;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5496;
case false:
return 5497;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5498;
case false:
return 5499;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5500;
case false:
return 5501;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5502;
case false:
return 5503;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5504;
case false:
return 5505;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5506;
case false:
return 5507;
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
return 5508;
case false:
return 5509;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5510;
case false:
return 5511;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5512;
case false:
return 5513;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5514;
case false:
return 5515;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5516;
case false:
return 5517;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5518;
case false:
return 5519;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5520;
case false:
return 5521;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5522;
case false:
return 5523;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5524;
case false:
return 5525;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5526;
case false:
return 5527;
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
return 5528;
case false:
return 5529;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5530;
case false:
return 5531;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5532;
case false:
return 5533;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5534;
case false:
return 5535;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5536;
case false:
return 5537;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5538;
case false:
return 5539;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5540;
case false:
return 5541;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5542;
case false:
return 5543;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5544;
case false:
return 5545;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5546;
case false:
return 5547;
}
}
}
}
}
constexpr static birch_stairs from_id(block_id_type id)
{
switch (id)
{
case 5468:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5469:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5470:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5471:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5472:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5473:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5474:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5475:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5476:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5477:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5478:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5479:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5480:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5481:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5482:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5483:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5484:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5485:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5486:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5487:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5488:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5489:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5490:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5491:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5492:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5493:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5494:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5495:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5496:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5497:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5498:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5499:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5500:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5501:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5502:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5503:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5504:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5505:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5506:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5507:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5508:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5509:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5510:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5511:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5512:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5513:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5514:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5515:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5516:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5517:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5518:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5519:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5520:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5521:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5522:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5523:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5524:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5525:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5526:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5527:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5528:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5529:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5530:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5531:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5532:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5533:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5534:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5535:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5536:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5537:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5538:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5539:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5540:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5541:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5542:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5543:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5544:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5545:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5546:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5547:
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
return "minecraft:birch_stairs:north:top:straight:true";
case false:
return "minecraft:birch_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:north:top:inner_left:true";
case false:
return "minecraft:birch_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:north:top:inner_right:true";
case false:
return "minecraft:birch_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:north:top:outer_left:true";
case false:
return "minecraft:birch_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:north:top:outer_right:true";
case false:
return "minecraft:birch_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:north:bottom:straight:true";
case false:
return "minecraft:birch_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:birch_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:birch_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:birch_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:birch_stairs:north:bottom:outer_right:false";
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
return "minecraft:birch_stairs:south:top:straight:true";
case false:
return "minecraft:birch_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:south:top:inner_left:true";
case false:
return "minecraft:birch_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:south:top:inner_right:true";
case false:
return "minecraft:birch_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:south:top:outer_left:true";
case false:
return "minecraft:birch_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:south:top:outer_right:true";
case false:
return "minecraft:birch_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:south:bottom:straight:true";
case false:
return "minecraft:birch_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:birch_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:birch_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:birch_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:birch_stairs:south:bottom:outer_right:false";
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
return "minecraft:birch_stairs:west:top:straight:true";
case false:
return "minecraft:birch_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:west:top:inner_left:true";
case false:
return "minecraft:birch_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:west:top:inner_right:true";
case false:
return "minecraft:birch_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:west:top:outer_left:true";
case false:
return "minecraft:birch_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:west:top:outer_right:true";
case false:
return "minecraft:birch_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:west:bottom:straight:true";
case false:
return "minecraft:birch_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:birch_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:birch_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:birch_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:birch_stairs:west:bottom:outer_right:false";
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
return "minecraft:birch_stairs:east:top:straight:true";
case false:
return "minecraft:birch_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:east:top:inner_left:true";
case false:
return "minecraft:birch_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:east:top:inner_right:true";
case false:
return "minecraft:birch_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:east:top:outer_left:true";
case false:
return "minecraft:birch_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:east:top:outer_right:true";
case false:
return "minecraft:birch_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:east:bottom:straight:true";
case false:
return "minecraft:birch_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:birch_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:birch_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:birch_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:birch_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:birch_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
