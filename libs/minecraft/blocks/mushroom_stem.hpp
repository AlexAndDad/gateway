#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct mushroom_stem
{bool down = true;
bool east = true;
bool north = true;
bool south = true;
bool up = true;
bool west = true;
constexpr block_id_type to_id() const {
switch (down)
{
case true:
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
switch (west)
{
case true:
return 4619;
case false:
return 4620;
}
case false:
switch (west)
{
case true:
return 4621;
case false:
return 4622;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4623;
case false:
return 4624;
}
case false:
switch (west)
{
case true:
return 4625;
case false:
return 4626;
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
switch (west)
{
case true:
return 4627;
case false:
return 4628;
}
case false:
switch (west)
{
case true:
return 4629;
case false:
return 4630;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4631;
case false:
return 4632;
}
case false:
switch (west)
{
case true:
return 4633;
case false:
return 4634;
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
switch (west)
{
case true:
return 4635;
case false:
return 4636;
}
case false:
switch (west)
{
case true:
return 4637;
case false:
return 4638;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4639;
case false:
return 4640;
}
case false:
switch (west)
{
case true:
return 4641;
case false:
return 4642;
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
switch (west)
{
case true:
return 4643;
case false:
return 4644;
}
case false:
switch (west)
{
case true:
return 4645;
case false:
return 4646;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4647;
case false:
return 4648;
}
case false:
switch (west)
{
case true:
return 4649;
case false:
return 4650;
}
}
}
}
}
case false:
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
switch (west)
{
case true:
return 4651;
case false:
return 4652;
}
case false:
switch (west)
{
case true:
return 4653;
case false:
return 4654;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4655;
case false:
return 4656;
}
case false:
switch (west)
{
case true:
return 4657;
case false:
return 4658;
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
switch (west)
{
case true:
return 4659;
case false:
return 4660;
}
case false:
switch (west)
{
case true:
return 4661;
case false:
return 4662;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4663;
case false:
return 4664;
}
case false:
switch (west)
{
case true:
return 4665;
case false:
return 4666;
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
switch (west)
{
case true:
return 4667;
case false:
return 4668;
}
case false:
switch (west)
{
case true:
return 4669;
case false:
return 4670;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4671;
case false:
return 4672;
}
case false:
switch (west)
{
case true:
return 4673;
case false:
return 4674;
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
switch (west)
{
case true:
return 4675;
case false:
return 4676;
}
case false:
switch (west)
{
case true:
return 4677;
case false:
return 4678;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4679;
case false:
return 4680;
}
case false:
switch (west)
{
case true:
return 4681;
case false:
return 4682;
}
}
}
}
}
}
}
constexpr static mushroom_stem from_id(block_id_type id)
{
switch (id)
{
case 4619:
return {.down = true, .east = true, .north = true, .south = true, .up = true, .west = true};
case 4620:
return {.down = true, .east = true, .north = true, .south = true, .up = true, .west = false};
case 4621:
return {.down = true, .east = true, .north = true, .south = true, .up = false, .west = true};
case 4622:
return {.down = true, .east = true, .north = true, .south = true, .up = false, .west = false};
case 4623:
return {.down = true, .east = true, .north = true, .south = false, .up = true, .west = true};
case 4624:
return {.down = true, .east = true, .north = true, .south = false, .up = true, .west = false};
case 4625:
return {.down = true, .east = true, .north = true, .south = false, .up = false, .west = true};
case 4626:
return {.down = true, .east = true, .north = true, .south = false, .up = false, .west = false};
case 4627:
return {.down = true, .east = true, .north = false, .south = true, .up = true, .west = true};
case 4628:
return {.down = true, .east = true, .north = false, .south = true, .up = true, .west = false};
case 4629:
return {.down = true, .east = true, .north = false, .south = true, .up = false, .west = true};
case 4630:
return {.down = true, .east = true, .north = false, .south = true, .up = false, .west = false};
case 4631:
return {.down = true, .east = true, .north = false, .south = false, .up = true, .west = true};
case 4632:
return {.down = true, .east = true, .north = false, .south = false, .up = true, .west = false};
case 4633:
return {.down = true, .east = true, .north = false, .south = false, .up = false, .west = true};
case 4634:
return {.down = true, .east = true, .north = false, .south = false, .up = false, .west = false};
case 4635:
return {.down = true, .east = false, .north = true, .south = true, .up = true, .west = true};
case 4636:
return {.down = true, .east = false, .north = true, .south = true, .up = true, .west = false};
case 4637:
return {.down = true, .east = false, .north = true, .south = true, .up = false, .west = true};
case 4638:
return {.down = true, .east = false, .north = true, .south = true, .up = false, .west = false};
case 4639:
return {.down = true, .east = false, .north = true, .south = false, .up = true, .west = true};
case 4640:
return {.down = true, .east = false, .north = true, .south = false, .up = true, .west = false};
case 4641:
return {.down = true, .east = false, .north = true, .south = false, .up = false, .west = true};
case 4642:
return {.down = true, .east = false, .north = true, .south = false, .up = false, .west = false};
case 4643:
return {.down = true, .east = false, .north = false, .south = true, .up = true, .west = true};
case 4644:
return {.down = true, .east = false, .north = false, .south = true, .up = true, .west = false};
case 4645:
return {.down = true, .east = false, .north = false, .south = true, .up = false, .west = true};
case 4646:
return {.down = true, .east = false, .north = false, .south = true, .up = false, .west = false};
case 4647:
return {.down = true, .east = false, .north = false, .south = false, .up = true, .west = true};
case 4648:
return {.down = true, .east = false, .north = false, .south = false, .up = true, .west = false};
case 4649:
return {.down = true, .east = false, .north = false, .south = false, .up = false, .west = true};
case 4650:
return {.down = true, .east = false, .north = false, .south = false, .up = false, .west = false};
case 4651:
return {.down = false, .east = true, .north = true, .south = true, .up = true, .west = true};
case 4652:
return {.down = false, .east = true, .north = true, .south = true, .up = true, .west = false};
case 4653:
return {.down = false, .east = true, .north = true, .south = true, .up = false, .west = true};
case 4654:
return {.down = false, .east = true, .north = true, .south = true, .up = false, .west = false};
case 4655:
return {.down = false, .east = true, .north = true, .south = false, .up = true, .west = true};
case 4656:
return {.down = false, .east = true, .north = true, .south = false, .up = true, .west = false};
case 4657:
return {.down = false, .east = true, .north = true, .south = false, .up = false, .west = true};
case 4658:
return {.down = false, .east = true, .north = true, .south = false, .up = false, .west = false};
case 4659:
return {.down = false, .east = true, .north = false, .south = true, .up = true, .west = true};
case 4660:
return {.down = false, .east = true, .north = false, .south = true, .up = true, .west = false};
case 4661:
return {.down = false, .east = true, .north = false, .south = true, .up = false, .west = true};
case 4662:
return {.down = false, .east = true, .north = false, .south = true, .up = false, .west = false};
case 4663:
return {.down = false, .east = true, .north = false, .south = false, .up = true, .west = true};
case 4664:
return {.down = false, .east = true, .north = false, .south = false, .up = true, .west = false};
case 4665:
return {.down = false, .east = true, .north = false, .south = false, .up = false, .west = true};
case 4666:
return {.down = false, .east = true, .north = false, .south = false, .up = false, .west = false};
case 4667:
return {.down = false, .east = false, .north = true, .south = true, .up = true, .west = true};
case 4668:
return {.down = false, .east = false, .north = true, .south = true, .up = true, .west = false};
case 4669:
return {.down = false, .east = false, .north = true, .south = true, .up = false, .west = true};
case 4670:
return {.down = false, .east = false, .north = true, .south = true, .up = false, .west = false};
case 4671:
return {.down = false, .east = false, .north = true, .south = false, .up = true, .west = true};
case 4672:
return {.down = false, .east = false, .north = true, .south = false, .up = true, .west = false};
case 4673:
return {.down = false, .east = false, .north = true, .south = false, .up = false, .west = true};
case 4674:
return {.down = false, .east = false, .north = true, .south = false, .up = false, .west = false};
case 4675:
return {.down = false, .east = false, .north = false, .south = true, .up = true, .west = true};
case 4676:
return {.down = false, .east = false, .north = false, .south = true, .up = true, .west = false};
case 4677:
return {.down = false, .east = false, .north = false, .south = true, .up = false, .west = true};
case 4678:
return {.down = false, .east = false, .north = false, .south = true, .up = false, .west = false};
case 4679:
return {.down = false, .east = false, .north = false, .south = false, .up = true, .west = true};
case 4680:
return {.down = false, .east = false, .north = false, .south = false, .up = true, .west = false};
case 4681:
return {.down = false, .east = false, .north = false, .south = false, .up = false, .west = true};
case 4682:
return {.down = false, .east = false, .north = false, .south = false, .up = false, .west = false};
}}
constexpr std::string_view to_string() const
{switch (down)
{
case true:
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
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:true:true:true:true:true";
case false:
return "minecraft:mushroom_stem:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:true:true:true:false:true";
case false:
return "minecraft:mushroom_stem:true:true:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:true:true:false:true:true";
case false:
return "minecraft:mushroom_stem:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:true:true:false:false:true";
case false:
return "minecraft:mushroom_stem:true:true:true:false:false:false";
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
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:true:false:true:true:true";
case false:
return "minecraft:mushroom_stem:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:true:false:true:false:true";
case false:
return "minecraft:mushroom_stem:true:true:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:true:false:false:true:true";
case false:
return "minecraft:mushroom_stem:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:true:false:false:false:true";
case false:
return "minecraft:mushroom_stem:true:true:false:false:false:false";
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
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:false:true:true:true:true";
case false:
return "minecraft:mushroom_stem:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:false:true:true:false:true";
case false:
return "minecraft:mushroom_stem:true:false:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:false:true:false:true:true";
case false:
return "minecraft:mushroom_stem:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:false:true:false:false:true";
case false:
return "minecraft:mushroom_stem:true:false:true:false:false:false";
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
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:false:false:true:true:true";
case false:
return "minecraft:mushroom_stem:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:false:false:true:false:true";
case false:
return "minecraft:mushroom_stem:true:false:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:false:false:false:true:true";
case false:
return "minecraft:mushroom_stem:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:true:false:false:false:false:true";
case false:
return "minecraft:mushroom_stem:true:false:false:false:false:false";
}
}
}
}
}
case false:
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
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:true:true:true:true:true";
case false:
return "minecraft:mushroom_stem:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:true:true:true:false:true";
case false:
return "minecraft:mushroom_stem:false:true:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:true:true:false:true:true";
case false:
return "minecraft:mushroom_stem:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:true:true:false:false:true";
case false:
return "minecraft:mushroom_stem:false:true:true:false:false:false";
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
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:true:false:true:true:true";
case false:
return "minecraft:mushroom_stem:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:true:false:true:false:true";
case false:
return "minecraft:mushroom_stem:false:true:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:true:false:false:true:true";
case false:
return "minecraft:mushroom_stem:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:true:false:false:false:true";
case false:
return "minecraft:mushroom_stem:false:true:false:false:false:false";
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
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:false:true:true:true:true";
case false:
return "minecraft:mushroom_stem:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:false:true:true:false:true";
case false:
return "minecraft:mushroom_stem:false:false:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:false:true:false:true:true";
case false:
return "minecraft:mushroom_stem:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:false:true:false:false:true";
case false:
return "minecraft:mushroom_stem:false:false:true:false:false:false";
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
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:false:false:true:true:true";
case false:
return "minecraft:mushroom_stem:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:false:false:true:false:true";
case false:
return "minecraft:mushroom_stem:false:false:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:false:false:false:true:true";
case false:
return "minecraft:mushroom_stem:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mushroom_stem:false:false:false:false:false:true";
case false:
return "minecraft:mushroom_stem:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
