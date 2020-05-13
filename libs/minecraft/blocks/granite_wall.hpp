#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct granite_wall
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
return 10587;
case false:
return 10588;
}
case false:
switch (west)
{
case true:
return 10589;
case false:
return 10590;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10591;
case false:
return 10592;
}
case false:
switch (west)
{
case true:
return 10593;
case false:
return 10594;
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
return 10595;
case false:
return 10596;
}
case false:
switch (west)
{
case true:
return 10597;
case false:
return 10598;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10599;
case false:
return 10600;
}
case false:
switch (west)
{
case true:
return 10601;
case false:
return 10602;
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
return 10603;
case false:
return 10604;
}
case false:
switch (west)
{
case true:
return 10605;
case false:
return 10606;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10607;
case false:
return 10608;
}
case false:
switch (west)
{
case true:
return 10609;
case false:
return 10610;
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
return 10611;
case false:
return 10612;
}
case false:
switch (west)
{
case true:
return 10613;
case false:
return 10614;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10615;
case false:
return 10616;
}
case false:
switch (west)
{
case true:
return 10617;
case false:
return 10618;
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
return 10619;
case false:
return 10620;
}
case false:
switch (west)
{
case true:
return 10621;
case false:
return 10622;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10623;
case false:
return 10624;
}
case false:
switch (west)
{
case true:
return 10625;
case false:
return 10626;
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
return 10627;
case false:
return 10628;
}
case false:
switch (west)
{
case true:
return 10629;
case false:
return 10630;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10631;
case false:
return 10632;
}
case false:
switch (west)
{
case true:
return 10633;
case false:
return 10634;
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
return 10635;
case false:
return 10636;
}
case false:
switch (west)
{
case true:
return 10637;
case false:
return 10638;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10639;
case false:
return 10640;
}
case false:
switch (west)
{
case true:
return 10641;
case false:
return 10642;
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
return 10643;
case false:
return 10644;
}
case false:
switch (west)
{
case true:
return 10645;
case false:
return 10646;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10647;
case false:
return 10648;
}
case false:
switch (west)
{
case true:
return 10649;
case false:
return 10650;
}
}
}
}
}
}
}
constexpr static granite_wall from_id(block_id_type id)
{
switch (id)
{
case 10587:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10588:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10589:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10590:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10591:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10592:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10593:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10594:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10595:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10596:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10597:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10598:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10599:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10600:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10601:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10602:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10603:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10604:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10605:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10606:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10607:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10608:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10609:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10610:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10611:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10612:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10613:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10614:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10615:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10616:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10617:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10618:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 10619:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10620:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10621:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10622:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10623:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10624:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10625:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10626:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10627:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10628:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10629:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10630:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10631:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10632:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10633:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10634:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10635:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10636:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10637:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10638:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10639:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10640:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10641:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10642:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10643:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10644:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10645:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10646:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10647:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10648:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10649:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10650:
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
return "minecraft:granite_wall:true:true:true:true:true:true";
case false:
return "minecraft:granite_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:true:true:true:true:false:true";
case false:
return "minecraft:granite_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:granite_wall:true:true:true:false:true:true";
case false:
return "minecraft:granite_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:true:true:true:false:false:true";
case false:
return "minecraft:granite_wall:true:true:true:false:false:false";
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
return "minecraft:granite_wall:true:true:false:true:true:true";
case false:
return "minecraft:granite_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:true:true:false:true:false:true";
case false:
return "minecraft:granite_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:granite_wall:true:true:false:false:true:true";
case false:
return "minecraft:granite_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:true:true:false:false:false:true";
case false:
return "minecraft:granite_wall:true:true:false:false:false:false";
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
return "minecraft:granite_wall:true:false:true:true:true:true";
case false:
return "minecraft:granite_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:true:false:true:true:false:true";
case false:
return "minecraft:granite_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:granite_wall:true:false:true:false:true:true";
case false:
return "minecraft:granite_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:true:false:true:false:false:true";
case false:
return "minecraft:granite_wall:true:false:true:false:false:false";
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
return "minecraft:granite_wall:true:false:false:true:true:true";
case false:
return "minecraft:granite_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:true:false:false:true:false:true";
case false:
return "minecraft:granite_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:granite_wall:true:false:false:false:true:true";
case false:
return "minecraft:granite_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:true:false:false:false:false:true";
case false:
return "minecraft:granite_wall:true:false:false:false:false:false";
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
return "minecraft:granite_wall:false:true:true:true:true:true";
case false:
return "minecraft:granite_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:false:true:true:true:false:true";
case false:
return "minecraft:granite_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:granite_wall:false:true:true:false:true:true";
case false:
return "minecraft:granite_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:false:true:true:false:false:true";
case false:
return "minecraft:granite_wall:false:true:true:false:false:false";
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
return "minecraft:granite_wall:false:true:false:true:true:true";
case false:
return "minecraft:granite_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:false:true:false:true:false:true";
case false:
return "minecraft:granite_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:granite_wall:false:true:false:false:true:true";
case false:
return "minecraft:granite_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:false:true:false:false:false:true";
case false:
return "minecraft:granite_wall:false:true:false:false:false:false";
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
return "minecraft:granite_wall:false:false:true:true:true:true";
case false:
return "minecraft:granite_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:false:false:true:true:false:true";
case false:
return "minecraft:granite_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:granite_wall:false:false:true:false:true:true";
case false:
return "minecraft:granite_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:false:false:true:false:false:true";
case false:
return "minecraft:granite_wall:false:false:true:false:false:false";
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
return "minecraft:granite_wall:false:false:false:true:true:true";
case false:
return "minecraft:granite_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:false:false:false:true:false:true";
case false:
return "minecraft:granite_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:granite_wall:false:false:false:false:true:true";
case false:
return "minecraft:granite_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:granite_wall:false:false:false:false:false:true";
case false:
return "minecraft:granite_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
