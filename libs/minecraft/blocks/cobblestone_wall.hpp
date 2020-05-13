#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct cobblestone_wall
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
return 5641;
case false:
return 5642;
}
case false:
switch (west)
{
case true:
return 5643;
case false:
return 5644;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5645;
case false:
return 5646;
}
case false:
switch (west)
{
case true:
return 5647;
case false:
return 5648;
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
return 5649;
case false:
return 5650;
}
case false:
switch (west)
{
case true:
return 5651;
case false:
return 5652;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5653;
case false:
return 5654;
}
case false:
switch (west)
{
case true:
return 5655;
case false:
return 5656;
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
return 5657;
case false:
return 5658;
}
case false:
switch (west)
{
case true:
return 5659;
case false:
return 5660;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5661;
case false:
return 5662;
}
case false:
switch (west)
{
case true:
return 5663;
case false:
return 5664;
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
return 5665;
case false:
return 5666;
}
case false:
switch (west)
{
case true:
return 5667;
case false:
return 5668;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5669;
case false:
return 5670;
}
case false:
switch (west)
{
case true:
return 5671;
case false:
return 5672;
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
return 5673;
case false:
return 5674;
}
case false:
switch (west)
{
case true:
return 5675;
case false:
return 5676;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5677;
case false:
return 5678;
}
case false:
switch (west)
{
case true:
return 5679;
case false:
return 5680;
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
return 5681;
case false:
return 5682;
}
case false:
switch (west)
{
case true:
return 5683;
case false:
return 5684;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5685;
case false:
return 5686;
}
case false:
switch (west)
{
case true:
return 5687;
case false:
return 5688;
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
return 5689;
case false:
return 5690;
}
case false:
switch (west)
{
case true:
return 5691;
case false:
return 5692;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5693;
case false:
return 5694;
}
case false:
switch (west)
{
case true:
return 5695;
case false:
return 5696;
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
return 5697;
case false:
return 5698;
}
case false:
switch (west)
{
case true:
return 5699;
case false:
return 5700;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5701;
case false:
return 5702;
}
case false:
switch (west)
{
case true:
return 5703;
case false:
return 5704;
}
}
}
}
}
}
}
constexpr static cobblestone_wall from_id(block_id_type id)
{
switch (id)
{
case 5641:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 5642:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 5643:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 5644:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 5645:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 5646:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 5647:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 5648:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 5649:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 5650:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 5651:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 5652:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 5653:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 5654:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 5655:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 5656:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 5657:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 5658:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 5659:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 5660:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 5661:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 5662:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 5663:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 5664:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 5665:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 5666:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 5667:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 5668:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 5669:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 5670:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 5671:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 5672:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 5673:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 5674:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 5675:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 5676:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 5677:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 5678:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 5679:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 5680:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 5681:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 5682:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 5683:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 5684:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 5685:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 5686:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 5687:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 5688:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 5689:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 5690:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 5691:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 5692:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 5693:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 5694:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 5695:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 5696:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 5697:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 5698:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 5699:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 5700:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 5701:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 5702:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 5703:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 5704:
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
return "minecraft:cobblestone_wall:true:true:true:true:true:true";
case false:
return "minecraft:cobblestone_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:true:true:true:true:false:true";
case false:
return "minecraft:cobblestone_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:true:true:true:false:true:true";
case false:
return "minecraft:cobblestone_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:true:true:true:false:false:true";
case false:
return "minecraft:cobblestone_wall:true:true:true:false:false:false";
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
return "minecraft:cobblestone_wall:true:true:false:true:true:true";
case false:
return "minecraft:cobblestone_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:true:true:false:true:false:true";
case false:
return "minecraft:cobblestone_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:true:true:false:false:true:true";
case false:
return "minecraft:cobblestone_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:true:true:false:false:false:true";
case false:
return "minecraft:cobblestone_wall:true:true:false:false:false:false";
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
return "minecraft:cobblestone_wall:true:false:true:true:true:true";
case false:
return "minecraft:cobblestone_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:true:false:true:true:false:true";
case false:
return "minecraft:cobblestone_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:true:false:true:false:true:true";
case false:
return "minecraft:cobblestone_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:true:false:true:false:false:true";
case false:
return "minecraft:cobblestone_wall:true:false:true:false:false:false";
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
return "minecraft:cobblestone_wall:true:false:false:true:true:true";
case false:
return "minecraft:cobblestone_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:true:false:false:true:false:true";
case false:
return "minecraft:cobblestone_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:true:false:false:false:true:true";
case false:
return "minecraft:cobblestone_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:true:false:false:false:false:true";
case false:
return "minecraft:cobblestone_wall:true:false:false:false:false:false";
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
return "minecraft:cobblestone_wall:false:true:true:true:true:true";
case false:
return "minecraft:cobblestone_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:false:true:true:true:false:true";
case false:
return "minecraft:cobblestone_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:false:true:true:false:true:true";
case false:
return "minecraft:cobblestone_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:false:true:true:false:false:true";
case false:
return "minecraft:cobblestone_wall:false:true:true:false:false:false";
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
return "minecraft:cobblestone_wall:false:true:false:true:true:true";
case false:
return "minecraft:cobblestone_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:false:true:false:true:false:true";
case false:
return "minecraft:cobblestone_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:false:true:false:false:true:true";
case false:
return "minecraft:cobblestone_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:false:true:false:false:false:true";
case false:
return "minecraft:cobblestone_wall:false:true:false:false:false:false";
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
return "minecraft:cobblestone_wall:false:false:true:true:true:true";
case false:
return "minecraft:cobblestone_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:false:false:true:true:false:true";
case false:
return "minecraft:cobblestone_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:false:false:true:false:true:true";
case false:
return "minecraft:cobblestone_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:false:false:true:false:false:true";
case false:
return "minecraft:cobblestone_wall:false:false:true:false:false:false";
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
return "minecraft:cobblestone_wall:false:false:false:true:true:true";
case false:
return "minecraft:cobblestone_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:false:false:false:true:false:true";
case false:
return "minecraft:cobblestone_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:false:false:false:false:true:true";
case false:
return "minecraft:cobblestone_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cobblestone_wall:false:false:false:false:false:true";
case false:
return "minecraft:cobblestone_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
