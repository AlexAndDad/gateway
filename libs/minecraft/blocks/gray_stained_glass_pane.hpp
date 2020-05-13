#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct gray_stained_glass_pane
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
return 6551;
case false:
return 6552;
}
case false:
switch (west)
{
case true:
return 6553;
case false:
return 6554;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6555;
case false:
return 6556;
}
case false:
switch (west)
{
case true:
return 6557;
case false:
return 6558;
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
return 6559;
case false:
return 6560;
}
case false:
switch (west)
{
case true:
return 6561;
case false:
return 6562;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6563;
case false:
return 6564;
}
case false:
switch (west)
{
case true:
return 6565;
case false:
return 6566;
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
return 6567;
case false:
return 6568;
}
case false:
switch (west)
{
case true:
return 6569;
case false:
return 6570;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6571;
case false:
return 6572;
}
case false:
switch (west)
{
case true:
return 6573;
case false:
return 6574;
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
return 6575;
case false:
return 6576;
}
case false:
switch (west)
{
case true:
return 6577;
case false:
return 6578;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6579;
case false:
return 6580;
}
case false:
switch (west)
{
case true:
return 6581;
case false:
return 6582;
}
}
}
}
}
}
constexpr static gray_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6551:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6552:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6553:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6554:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6555:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6556:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6557:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6558:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6559:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6560:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6561:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6562:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6563:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6564:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6565:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6566:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6567:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6568:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6569:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6570:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6571:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6572:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6573:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6574:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6575:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6576:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6577:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6578:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6579:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6580:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6581:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6582:
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
return "minecraft:gray_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:gray_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:gray_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:gray_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:gray_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:gray_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:gray_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:gray_stained_glass_pane:true:true:false:false:false";
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
return "minecraft:gray_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:gray_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:gray_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:gray_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:gray_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:gray_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:gray_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:gray_stained_glass_pane:true:false:false:false:false";
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
return "minecraft:gray_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:gray_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:gray_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:gray_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:gray_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:gray_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:gray_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:gray_stained_glass_pane:false:true:false:false:false";
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
return "minecraft:gray_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:gray_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:gray_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:gray_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:gray_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:gray_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:gray_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:gray_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
