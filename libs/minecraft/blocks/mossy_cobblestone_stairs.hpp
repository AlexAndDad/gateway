#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct mossy_cobblestone_stairs
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
return 9453;
case false:
return 9454;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9455;
case false:
return 9456;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9457;
case false:
return 9458;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9459;
case false:
return 9460;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9461;
case false:
return 9462;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9463;
case false:
return 9464;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9465;
case false:
return 9466;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9467;
case false:
return 9468;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9469;
case false:
return 9470;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9471;
case false:
return 9472;
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
return 9473;
case false:
return 9474;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9475;
case false:
return 9476;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9477;
case false:
return 9478;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9479;
case false:
return 9480;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9481;
case false:
return 9482;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9483;
case false:
return 9484;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9485;
case false:
return 9486;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9487;
case false:
return 9488;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9489;
case false:
return 9490;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9491;
case false:
return 9492;
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
return 9493;
case false:
return 9494;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9495;
case false:
return 9496;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9497;
case false:
return 9498;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9499;
case false:
return 9500;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9501;
case false:
return 9502;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9503;
case false:
return 9504;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9505;
case false:
return 9506;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9507;
case false:
return 9508;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9509;
case false:
return 9510;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9511;
case false:
return 9512;
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
return 9513;
case false:
return 9514;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9515;
case false:
return 9516;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9517;
case false:
return 9518;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9519;
case false:
return 9520;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9521;
case false:
return 9522;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9523;
case false:
return 9524;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9525;
case false:
return 9526;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9527;
case false:
return 9528;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9529;
case false:
return 9530;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9531;
case false:
return 9532;
}
}
}
}
}
constexpr static mossy_cobblestone_stairs from_id(block_id_type id)
{
switch (id)
{
case 9453:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9454:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9455:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9456:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9457:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9458:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9459:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9460:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9461:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9462:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9463:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9464:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9465:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9466:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9467:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9468:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9469:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9470:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9471:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9472:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9473:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9474:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9475:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9476:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9477:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9478:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9479:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9480:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9481:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9482:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9483:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9484:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9485:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9486:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9487:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9488:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9489:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9490:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9491:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9492:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9493:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9494:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9495:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9496:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9497:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9498:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9499:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9500:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9501:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9502:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9503:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9504:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9505:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9506:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9507:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9508:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9509:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9510:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9511:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9512:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9513:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9514:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9515:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9516:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9517:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9518:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9519:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9520:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9521:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9522:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9523:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9524:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9525:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9526:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9527:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9528:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9529:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9530:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9531:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9532:
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
return "minecraft:mossy_cobblestone_stairs:north:top:straight:true";
case false:
return "minecraft:mossy_cobblestone_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:north:top:inner_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:north:top:inner_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:north:top:outer_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:north:top:outer_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:north:bottom:straight:true";
case false:
return "minecraft:mossy_cobblestone_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:north:bottom:outer_right:false";
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
return "minecraft:mossy_cobblestone_stairs:south:top:straight:true";
case false:
return "minecraft:mossy_cobblestone_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:south:top:inner_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:south:top:inner_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:south:top:outer_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:south:top:outer_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:south:bottom:straight:true";
case false:
return "minecraft:mossy_cobblestone_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:south:bottom:outer_right:false";
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
return "minecraft:mossy_cobblestone_stairs:west:top:straight:true";
case false:
return "minecraft:mossy_cobblestone_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:west:top:inner_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:west:top:inner_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:west:top:outer_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:west:top:outer_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:west:bottom:straight:true";
case false:
return "minecraft:mossy_cobblestone_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:west:bottom:outer_right:false";
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
return "minecraft:mossy_cobblestone_stairs:east:top:straight:true";
case false:
return "minecraft:mossy_cobblestone_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:east:top:inner_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:east:top:inner_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:east:top:outer_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:east:top:outer_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:east:bottom:straight:true";
case false:
return "minecraft:mossy_cobblestone_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:mossy_cobblestone_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:mossy_cobblestone_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
