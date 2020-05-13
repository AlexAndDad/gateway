#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct purple_stained_glass_pane
{bool east = false;
bool north = false;
bool south = false;
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
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6647;
case false:
return 6648;
}
case false:
switch (west)
{
case true:
return 6649;
case false:
return 6650;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6651;
case false:
return 6652;
}
case false:
switch (west)
{
case true:
return 6653;
case false:
return 6654;
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6655;
case false:
return 6656;
}
case false:
switch (west)
{
case true:
return 6657;
case false:
return 6658;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6659;
case false:
return 6660;
}
case false:
switch (west)
{
case true:
return 6661;
case false:
return 6662;
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
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6663;
case false:
return 6664;
}
case false:
switch (west)
{
case true:
return 6665;
case false:
return 6666;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6667;
case false:
return 6668;
}
case false:
switch (west)
{
case true:
return 6669;
case false:
return 6670;
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6671;
case false:
return 6672;
}
case false:
switch (west)
{
case true:
return 6673;
case false:
return 6674;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6675;
case false:
return 6676;
}
case false:
switch (west)
{
case true:
return 6677;
case false:
return 6678;
}
}
}
}
}
}
constexpr static purple_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6647:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6648:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6649:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6650:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6651:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6652:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6653:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6654:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6655:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6656:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6657:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6658:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6659:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6660:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6661:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6662:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6663:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6664:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6665:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6666:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6667:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6668:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6669:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6670:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6671:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6672:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6673:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6674:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6675:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6676:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6677:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6678:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = false};
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
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:purple_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:purple_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:purple_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:purple_stained_glass_pane:true:true:false:false:false";
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:purple_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:purple_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:purple_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:purple_stained_glass_pane:true:false:false:false:false";
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
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:purple_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:purple_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:purple_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:purple_stained_glass_pane:false:true:false:false:false";
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:purple_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:purple_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:purple_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:purple_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:purple_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
