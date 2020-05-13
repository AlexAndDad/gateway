#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct mossy_stone_brick_wall
{bool east = false;
bool north = false;
bool south = false;
bool up = true;
bool waterlogged = false;
bool west = false;
constexpr block_id_type to_id() const {
switch (east)
{
case true:
switch (north)
{
case true:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10523;
case false:
return 10524;
}
case false:
switch (west)
{
case true:
return 10525;
case false:
return 10526;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10527;
case false:
return 10528;
}
case false:
switch (west)
{
case true:
return 10529;
case false:
return 10530;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10531;
case false:
return 10532;
}
case false:
switch (west)
{
case true:
return 10533;
case false:
return 10534;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10535;
case false:
return 10536;
}
case false:
switch (west)
{
case true:
return 10537;
case false:
return 10538;
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10539;
case false:
return 10540;
}
case false:
switch (west)
{
case true:
return 10541;
case false:
return 10542;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10543;
case false:
return 10544;
}
case false:
switch (west)
{
case true:
return 10545;
case false:
return 10546;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10547;
case false:
return 10548;
}
case false:
switch (west)
{
case true:
return 10549;
case false:
return 10550;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10551;
case false:
return 10552;
}
case false:
switch (west)
{
case true:
return 10553;
case false:
return 10554;
}
}
}
}
}
case false:
switch (north)
{
case true:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10555;
case false:
return 10556;
}
case false:
switch (west)
{
case true:
return 10557;
case false:
return 10558;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10559;
case false:
return 10560;
}
case false:
switch (west)
{
case true:
return 10561;
case false:
return 10562;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10563;
case false:
return 10564;
}
case false:
switch (west)
{
case true:
return 10565;
case false:
return 10566;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10567;
case false:
return 10568;
}
case false:
switch (west)
{
case true:
return 10569;
case false:
return 10570;
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10571;
case false:
return 10572;
}
case false:
switch (west)
{
case true:
return 10573;
case false:
return 10574;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10575;
case false:
return 10576;
}
case false:
switch (west)
{
case true:
return 10577;
case false:
return 10578;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10579;
case false:
return 10580;
}
case false:
switch (west)
{
case true:
return 10581;
case false:
return 10582;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10583;
case false:
return 10584;
}
case false:
switch (west)
{
case true:
return 10585;
case false:
return 10586;
}
}
}
}
}
}
}
constexpr static mossy_stone_brick_wall from_id(block_id_type id)
{
switch (id)
{
case 10523:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10524:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10525:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10526:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10527:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10528:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10529:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10530:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10531:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10532:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10533:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10534:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10535:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10536:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10537:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10538:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10539:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10540:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10541:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10542:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10543:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10544:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10545:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10546:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10547:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10548:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10549:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10550:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10551:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10552:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10553:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10554:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 10555:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10556:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10557:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10558:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10559:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10560:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10561:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10562:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10563:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10564:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10565:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10566:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10567:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10568:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10569:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10570:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10571:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10572:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10573:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10574:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10575:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10576:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10577:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10578:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10579:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10580:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10581:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10582:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10583:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10584:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10585:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10586:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
}}
constexpr std::string_view to_string() const
{switch (east)
{
case true:
switch (north)
{
case true:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:true:true:true:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:true:true:true:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:true:true:false:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:true:true:false:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:true:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:true:false:true:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:true:false:true:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:true:false:false:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:true:false:false:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:true:false:false:false:false";
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:false:true:true:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:false:true:true:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:false:true:false:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:false:true:false:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:false:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:false:false:true:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:false:false:true:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:false:false:false:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:true:false:false:false:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:true:false:false:false:false:false";
}
}
}
}
}
case false:
switch (north)
{
case true:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:true:true:true:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:true:true:true:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:true:true:false:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:true:true:false:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:true:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:true:false:true:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:true:false:true:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:true:false:false:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:true:false:false:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:true:false:false:false:false";
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:false:true:true:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:false:true:true:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:false:true:false:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:false:true:false:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:false:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:false:false:true:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:false:false:true:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:false:false:false:true:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_stone_brick_wall:false:false:false:false:false:true";
case false:
return "minecraft:mossy_stone_brick_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
