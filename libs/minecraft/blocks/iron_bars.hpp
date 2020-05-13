#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct iron_bars
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
return 4683;
case false:
return 4684;
}
case false:
switch (west)
{
case true:
return 4685;
case false:
return 4686;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 4687;
case false:
return 4688;
}
case false:
switch (west)
{
case true:
return 4689;
case false:
return 4690;
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
return 4691;
case false:
return 4692;
}
case false:
switch (west)
{
case true:
return 4693;
case false:
return 4694;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 4695;
case false:
return 4696;
}
case false:
switch (west)
{
case true:
return 4697;
case false:
return 4698;
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
return 4699;
case false:
return 4700;
}
case false:
switch (west)
{
case true:
return 4701;
case false:
return 4702;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 4703;
case false:
return 4704;
}
case false:
switch (west)
{
case true:
return 4705;
case false:
return 4706;
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
return 4707;
case false:
return 4708;
}
case false:
switch (west)
{
case true:
return 4709;
case false:
return 4710;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 4711;
case false:
return 4712;
}
case false:
switch (west)
{
case true:
return 4713;
case false:
return 4714;
}
}
}
}
}
}
constexpr static iron_bars from_id(block_id_type id)
{
switch (id)
{
case 4683:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 4684:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 4685:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 4686:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 4687:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 4688:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 4689:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 4690:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 4691:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 4692:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 4693:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 4694:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 4695:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 4696:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 4697:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 4698:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 4699:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 4700:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 4701:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 4702:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 4703:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 4704:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 4705:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 4706:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 4707:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 4708:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 4709:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 4710:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 4711:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 4712:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 4713:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 4714:
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
return "minecraft:iron_bars:true:true:true:true:true";
case false:
return "minecraft:iron_bars:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:iron_bars:true:true:true:false:true";
case false:
return "minecraft:iron_bars:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:iron_bars:true:true:false:true:true";
case false:
return "minecraft:iron_bars:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:iron_bars:true:true:false:false:true";
case false:
return "minecraft:iron_bars:true:true:false:false:false";
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
return "minecraft:iron_bars:true:false:true:true:true";
case false:
return "minecraft:iron_bars:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:iron_bars:true:false:true:false:true";
case false:
return "minecraft:iron_bars:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:iron_bars:true:false:false:true:true";
case false:
return "minecraft:iron_bars:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:iron_bars:true:false:false:false:true";
case false:
return "minecraft:iron_bars:true:false:false:false:false";
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
return "minecraft:iron_bars:false:true:true:true:true";
case false:
return "minecraft:iron_bars:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:iron_bars:false:true:true:false:true";
case false:
return "minecraft:iron_bars:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:iron_bars:false:true:false:true:true";
case false:
return "minecraft:iron_bars:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:iron_bars:false:true:false:false:true";
case false:
return "minecraft:iron_bars:false:true:false:false:false";
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
return "minecraft:iron_bars:false:false:true:true:true";
case false:
return "minecraft:iron_bars:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:iron_bars:false:false:true:false:true";
case false:
return "minecraft:iron_bars:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:iron_bars:false:false:false:true:true";
case false:
return "minecraft:iron_bars:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:iron_bars:false:false:false:false:true";
case false:
return "minecraft:iron_bars:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
