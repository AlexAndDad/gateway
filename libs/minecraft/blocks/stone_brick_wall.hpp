#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct stone_brick_wall
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
return 10651;
case false:
return 10652;
}
case false:
switch (west)
{
case true:
return 10653;
case false:
return 10654;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10655;
case false:
return 10656;
}
case false:
switch (west)
{
case true:
return 10657;
case false:
return 10658;
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
return 10659;
case false:
return 10660;
}
case false:
switch (west)
{
case true:
return 10661;
case false:
return 10662;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10663;
case false:
return 10664;
}
case false:
switch (west)
{
case true:
return 10665;
case false:
return 10666;
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
return 10667;
case false:
return 10668;
}
case false:
switch (west)
{
case true:
return 10669;
case false:
return 10670;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10671;
case false:
return 10672;
}
case false:
switch (west)
{
case true:
return 10673;
case false:
return 10674;
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
return 10675;
case false:
return 10676;
}
case false:
switch (west)
{
case true:
return 10677;
case false:
return 10678;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10679;
case false:
return 10680;
}
case false:
switch (west)
{
case true:
return 10681;
case false:
return 10682;
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
return 10683;
case false:
return 10684;
}
case false:
switch (west)
{
case true:
return 10685;
case false:
return 10686;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10687;
case false:
return 10688;
}
case false:
switch (west)
{
case true:
return 10689;
case false:
return 10690;
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
return 10691;
case false:
return 10692;
}
case false:
switch (west)
{
case true:
return 10693;
case false:
return 10694;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10695;
case false:
return 10696;
}
case false:
switch (west)
{
case true:
return 10697;
case false:
return 10698;
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
return 10699;
case false:
return 10700;
}
case false:
switch (west)
{
case true:
return 10701;
case false:
return 10702;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10703;
case false:
return 10704;
}
case false:
switch (west)
{
case true:
return 10705;
case false:
return 10706;
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
return 10707;
case false:
return 10708;
}
case false:
switch (west)
{
case true:
return 10709;
case false:
return 10710;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10711;
case false:
return 10712;
}
case false:
switch (west)
{
case true:
return 10713;
case false:
return 10714;
}
}
}
}
}
}
}
constexpr static stone_brick_wall from_id(block_id_type id)
{
switch (id)
{
case 10651:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10652:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10653:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10654:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10655:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10656:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10657:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10658:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10659:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10660:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10661:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10662:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10663:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10664:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10665:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10666:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10667:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10668:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10669:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10670:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10671:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10672:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10673:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10674:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10675:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10676:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10677:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10678:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10679:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10680:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10681:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10682:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 10683:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10684:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10685:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10686:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10687:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10688:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10689:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10690:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10691:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10692:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10693:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10694:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10695:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10696:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10697:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10698:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10699:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10700:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10701:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10702:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10703:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10704:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10705:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10706:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10707:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10708:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10709:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10710:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10711:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10712:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10713:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10714:
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
return "minecraft:stone_brick_wall:true:true:true:true:true:true";
case false:
return "minecraft:stone_brick_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:true:true:true:true:false:true";
case false:
return "minecraft:stone_brick_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:true:true:true:false:true:true";
case false:
return "minecraft:stone_brick_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:true:true:true:false:false:true";
case false:
return "minecraft:stone_brick_wall:true:true:true:false:false:false";
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
return "minecraft:stone_brick_wall:true:true:false:true:true:true";
case false:
return "minecraft:stone_brick_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:true:true:false:true:false:true";
case false:
return "minecraft:stone_brick_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:true:true:false:false:true:true";
case false:
return "minecraft:stone_brick_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:true:true:false:false:false:true";
case false:
return "minecraft:stone_brick_wall:true:true:false:false:false:false";
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
return "minecraft:stone_brick_wall:true:false:true:true:true:true";
case false:
return "minecraft:stone_brick_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:true:false:true:true:false:true";
case false:
return "minecraft:stone_brick_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:true:false:true:false:true:true";
case false:
return "minecraft:stone_brick_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:true:false:true:false:false:true";
case false:
return "minecraft:stone_brick_wall:true:false:true:false:false:false";
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
return "minecraft:stone_brick_wall:true:false:false:true:true:true";
case false:
return "minecraft:stone_brick_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:true:false:false:true:false:true";
case false:
return "minecraft:stone_brick_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:true:false:false:false:true:true";
case false:
return "minecraft:stone_brick_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:true:false:false:false:false:true";
case false:
return "minecraft:stone_brick_wall:true:false:false:false:false:false";
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
return "minecraft:stone_brick_wall:false:true:true:true:true:true";
case false:
return "minecraft:stone_brick_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:false:true:true:true:false:true";
case false:
return "minecraft:stone_brick_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:false:true:true:false:true:true";
case false:
return "minecraft:stone_brick_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:false:true:true:false:false:true";
case false:
return "minecraft:stone_brick_wall:false:true:true:false:false:false";
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
return "minecraft:stone_brick_wall:false:true:false:true:true:true";
case false:
return "minecraft:stone_brick_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:false:true:false:true:false:true";
case false:
return "minecraft:stone_brick_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:false:true:false:false:true:true";
case false:
return "minecraft:stone_brick_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:false:true:false:false:false:true";
case false:
return "minecraft:stone_brick_wall:false:true:false:false:false:false";
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
return "minecraft:stone_brick_wall:false:false:true:true:true:true";
case false:
return "minecraft:stone_brick_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:false:false:true:true:false:true";
case false:
return "minecraft:stone_brick_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:false:false:true:false:true:true";
case false:
return "minecraft:stone_brick_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:false:false:true:false:false:true";
case false:
return "minecraft:stone_brick_wall:false:false:true:false:false:false";
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
return "minecraft:stone_brick_wall:false:false:false:true:true:true";
case false:
return "minecraft:stone_brick_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:false:false:false:true:false:true";
case false:
return "minecraft:stone_brick_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:false:false:false:false:true:true";
case false:
return "minecraft:stone_brick_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:stone_brick_wall:false:false:false:false:false:true";
case false:
return "minecraft:stone_brick_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
