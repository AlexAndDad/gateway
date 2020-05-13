#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct end_stone_brick_stairs
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
return 9533;
case false:
return 9534;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9535;
case false:
return 9536;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9537;
case false:
return 9538;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9539;
case false:
return 9540;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9541;
case false:
return 9542;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9543;
case false:
return 9544;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9545;
case false:
return 9546;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9547;
case false:
return 9548;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9549;
case false:
return 9550;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9551;
case false:
return 9552;
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
return 9553;
case false:
return 9554;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9555;
case false:
return 9556;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9557;
case false:
return 9558;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9559;
case false:
return 9560;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9561;
case false:
return 9562;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9563;
case false:
return 9564;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9565;
case false:
return 9566;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9567;
case false:
return 9568;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9569;
case false:
return 9570;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9571;
case false:
return 9572;
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
return 9573;
case false:
return 9574;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9575;
case false:
return 9576;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9577;
case false:
return 9578;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9579;
case false:
return 9580;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9581;
case false:
return 9582;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9583;
case false:
return 9584;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9585;
case false:
return 9586;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9587;
case false:
return 9588;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9589;
case false:
return 9590;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9591;
case false:
return 9592;
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
return 9593;
case false:
return 9594;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9595;
case false:
return 9596;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9597;
case false:
return 9598;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9599;
case false:
return 9600;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9601;
case false:
return 9602;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9603;
case false:
return 9604;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9605;
case false:
return 9606;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9607;
case false:
return 9608;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9609;
case false:
return 9610;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9611;
case false:
return 9612;
}
}
}
}
}
constexpr static end_stone_brick_stairs from_id(block_id_type id)
{
switch (id)
{
case 9533:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9534:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9535:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9536:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9537:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9538:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9539:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9540:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9541:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9542:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9543:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9544:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9545:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9546:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9547:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9548:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9549:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9550:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9551:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9552:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9553:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9554:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9555:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9556:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9557:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9558:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9559:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9560:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9561:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9562:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9563:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9564:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9565:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9566:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9567:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9568:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9569:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9570:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9571:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9572:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9573:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9574:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9575:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9576:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9577:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9578:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9579:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9580:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9581:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9582:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9583:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9584:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9585:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9586:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9587:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9588:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9589:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9590:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9591:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9592:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9593:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9594:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9595:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9596:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9597:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9598:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9599:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9600:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9601:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9602:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9603:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9604:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9605:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9606:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9607:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9608:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9609:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9610:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9611:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9612:
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
return "minecraft:end_stone_brick_stairs:north:top:straight:true";
case false:
return "minecraft:end_stone_brick_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:north:top:inner_left:true";
case false:
return "minecraft:end_stone_brick_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:north:top:inner_right:true";
case false:
return "minecraft:end_stone_brick_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:north:top:outer_left:true";
case false:
return "minecraft:end_stone_brick_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:north:top:outer_right:true";
case false:
return "minecraft:end_stone_brick_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:north:bottom:straight:true";
case false:
return "minecraft:end_stone_brick_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:end_stone_brick_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:end_stone_brick_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:end_stone_brick_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:end_stone_brick_stairs:north:bottom:outer_right:false";
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
return "minecraft:end_stone_brick_stairs:south:top:straight:true";
case false:
return "minecraft:end_stone_brick_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:south:top:inner_left:true";
case false:
return "minecraft:end_stone_brick_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:south:top:inner_right:true";
case false:
return "minecraft:end_stone_brick_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:south:top:outer_left:true";
case false:
return "minecraft:end_stone_brick_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:south:top:outer_right:true";
case false:
return "minecraft:end_stone_brick_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:south:bottom:straight:true";
case false:
return "minecraft:end_stone_brick_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:end_stone_brick_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:end_stone_brick_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:end_stone_brick_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:end_stone_brick_stairs:south:bottom:outer_right:false";
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
return "minecraft:end_stone_brick_stairs:west:top:straight:true";
case false:
return "minecraft:end_stone_brick_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:west:top:inner_left:true";
case false:
return "minecraft:end_stone_brick_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:west:top:inner_right:true";
case false:
return "minecraft:end_stone_brick_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:west:top:outer_left:true";
case false:
return "minecraft:end_stone_brick_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:west:top:outer_right:true";
case false:
return "minecraft:end_stone_brick_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:west:bottom:straight:true";
case false:
return "minecraft:end_stone_brick_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:end_stone_brick_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:end_stone_brick_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:end_stone_brick_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:end_stone_brick_stairs:west:bottom:outer_right:false";
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
return "minecraft:end_stone_brick_stairs:east:top:straight:true";
case false:
return "minecraft:end_stone_brick_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:east:top:inner_left:true";
case false:
return "minecraft:end_stone_brick_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:east:top:inner_right:true";
case false:
return "minecraft:end_stone_brick_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:east:top:outer_left:true";
case false:
return "minecraft:end_stone_brick_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:east:top:outer_right:true";
case false:
return "minecraft:end_stone_brick_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:east:bottom:straight:true";
case false:
return "minecraft:end_stone_brick_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:end_stone_brick_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:end_stone_brick_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:end_stone_brick_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:end_stone_brick_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
