#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jungle_stairs
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
return 5548;
case false:
return 5549;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5550;
case false:
return 5551;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5552;
case false:
return 5553;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5554;
case false:
return 5555;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5556;
case false:
return 5557;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5558;
case false:
return 5559;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5560;
case false:
return 5561;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5562;
case false:
return 5563;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5564;
case false:
return 5565;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5566;
case false:
return 5567;
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
return 5568;
case false:
return 5569;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5570;
case false:
return 5571;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5572;
case false:
return 5573;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5574;
case false:
return 5575;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5576;
case false:
return 5577;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5578;
case false:
return 5579;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5580;
case false:
return 5581;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5582;
case false:
return 5583;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5584;
case false:
return 5585;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5586;
case false:
return 5587;
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
return 5588;
case false:
return 5589;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5590;
case false:
return 5591;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5592;
case false:
return 5593;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5594;
case false:
return 5595;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5596;
case false:
return 5597;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5598;
case false:
return 5599;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5600;
case false:
return 5601;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5602;
case false:
return 5603;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5604;
case false:
return 5605;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5606;
case false:
return 5607;
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
return 5608;
case false:
return 5609;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5610;
case false:
return 5611;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5612;
case false:
return 5613;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5614;
case false:
return 5615;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5616;
case false:
return 5617;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 5618;
case false:
return 5619;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 5620;
case false:
return 5621;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 5622;
case false:
return 5623;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 5624;
case false:
return 5625;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 5626;
case false:
return 5627;
}
}
}
}
}
constexpr static jungle_stairs from_id(block_id_type id)
{
switch (id)
{
case 5548:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5549:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5550:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5551:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5552:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5553:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5554:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5555:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5556:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5557:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5558:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5559:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5560:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5561:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5562:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5563:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5564:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5565:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5566:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5567:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5568:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5569:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5570:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5571:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5572:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5573:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5574:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5575:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5576:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5577:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5578:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5579:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5580:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5581:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5582:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5583:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5584:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5585:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5586:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5587:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5588:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5589:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5590:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5591:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5592:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5593:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5594:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5595:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5596:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5597:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5598:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5599:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5600:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5601:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5602:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5603:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5604:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5605:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5606:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5607:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 5608:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 5609:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 5610:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 5611:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 5612:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 5613:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 5614:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 5615:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 5616:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 5617:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 5618:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 5619:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 5620:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 5621:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 5622:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 5623:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 5624:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 5625:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 5626:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 5627:
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
return "minecraft:jungle_stairs:north:top:straight:true";
case false:
return "minecraft:jungle_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:north:top:inner_left:true";
case false:
return "minecraft:jungle_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:north:top:inner_right:true";
case false:
return "minecraft:jungle_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:north:top:outer_left:true";
case false:
return "minecraft:jungle_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:north:top:outer_right:true";
case false:
return "minecraft:jungle_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:north:bottom:straight:true";
case false:
return "minecraft:jungle_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:jungle_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:jungle_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:jungle_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:jungle_stairs:north:bottom:outer_right:false";
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
return "minecraft:jungle_stairs:south:top:straight:true";
case false:
return "minecraft:jungle_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:south:top:inner_left:true";
case false:
return "minecraft:jungle_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:south:top:inner_right:true";
case false:
return "minecraft:jungle_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:south:top:outer_left:true";
case false:
return "minecraft:jungle_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:south:top:outer_right:true";
case false:
return "minecraft:jungle_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:south:bottom:straight:true";
case false:
return "minecraft:jungle_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:jungle_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:jungle_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:jungle_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:jungle_stairs:south:bottom:outer_right:false";
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
return "minecraft:jungle_stairs:west:top:straight:true";
case false:
return "minecraft:jungle_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:west:top:inner_left:true";
case false:
return "minecraft:jungle_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:west:top:inner_right:true";
case false:
return "minecraft:jungle_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:west:top:outer_left:true";
case false:
return "minecraft:jungle_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:west:top:outer_right:true";
case false:
return "minecraft:jungle_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:west:bottom:straight:true";
case false:
return "minecraft:jungle_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:jungle_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:jungle_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:jungle_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:jungle_stairs:west:bottom:outer_right:false";
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
return "minecraft:jungle_stairs:east:top:straight:true";
case false:
return "minecraft:jungle_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:east:top:inner_left:true";
case false:
return "minecraft:jungle_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:east:top:inner_right:true";
case false:
return "minecraft:jungle_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:east:top:outer_left:true";
case false:
return "minecraft:jungle_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:east:top:outer_right:true";
case false:
return "minecraft:jungle_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:east:bottom:straight:true";
case false:
return "minecraft:jungle_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:jungle_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:jungle_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:jungle_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:jungle_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:jungle_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
