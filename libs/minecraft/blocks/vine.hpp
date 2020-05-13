#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct vine
{bool east = false;
bool north = false;
bool south = false;
bool up = false;
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
switch (west)
{
case true:
return 4772;
case false:
return 4773;
}
case false:
switch (west)
{
case true:
return 4774;
case false:
return 4775;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4776;
case false:
return 4777;
}
case false:
switch (west)
{
case true:
return 4778;
case false:
return 4779;
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
return 4780;
case false:
return 4781;
}
case false:
switch (west)
{
case true:
return 4782;
case false:
return 4783;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4784;
case false:
return 4785;
}
case false:
switch (west)
{
case true:
return 4786;
case false:
return 4787;
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
return 4788;
case false:
return 4789;
}
case false:
switch (west)
{
case true:
return 4790;
case false:
return 4791;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4792;
case false:
return 4793;
}
case false:
switch (west)
{
case true:
return 4794;
case false:
return 4795;
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
return 4796;
case false:
return 4797;
}
case false:
switch (west)
{
case true:
return 4798;
case false:
return 4799;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4800;
case false:
return 4801;
}
case false:
switch (west)
{
case true:
return 4802;
case false:
return 4803;
}
}
}
}
}
}
constexpr static vine from_id(block_id_type id)
{
switch (id)
{
case 4772:
return {.east = true, .north = true, .south = true, .up = true, .west = true};
case 4773:
return {.east = true, .north = true, .south = true, .up = true, .west = false};
case 4774:
return {.east = true, .north = true, .south = true, .up = false, .west = true};
case 4775:
return {.east = true, .north = true, .south = true, .up = false, .west = false};
case 4776:
return {.east = true, .north = true, .south = false, .up = true, .west = true};
case 4777:
return {.east = true, .north = true, .south = false, .up = true, .west = false};
case 4778:
return {.east = true, .north = true, .south = false, .up = false, .west = true};
case 4779:
return {.east = true, .north = true, .south = false, .up = false, .west = false};
case 4780:
return {.east = true, .north = false, .south = true, .up = true, .west = true};
case 4781:
return {.east = true, .north = false, .south = true, .up = true, .west = false};
case 4782:
return {.east = true, .north = false, .south = true, .up = false, .west = true};
case 4783:
return {.east = true, .north = false, .south = true, .up = false, .west = false};
case 4784:
return {.east = true, .north = false, .south = false, .up = true, .west = true};
case 4785:
return {.east = true, .north = false, .south = false, .up = true, .west = false};
case 4786:
return {.east = true, .north = false, .south = false, .up = false, .west = true};
case 4787:
return {.east = true, .north = false, .south = false, .up = false, .west = false};
case 4788:
return {.east = false, .north = true, .south = true, .up = true, .west = true};
case 4789:
return {.east = false, .north = true, .south = true, .up = true, .west = false};
case 4790:
return {.east = false, .north = true, .south = true, .up = false, .west = true};
case 4791:
return {.east = false, .north = true, .south = true, .up = false, .west = false};
case 4792:
return {.east = false, .north = true, .south = false, .up = true, .west = true};
case 4793:
return {.east = false, .north = true, .south = false, .up = true, .west = false};
case 4794:
return {.east = false, .north = true, .south = false, .up = false, .west = true};
case 4795:
return {.east = false, .north = true, .south = false, .up = false, .west = false};
case 4796:
return {.east = false, .north = false, .south = true, .up = true, .west = true};
case 4797:
return {.east = false, .north = false, .south = true, .up = true, .west = false};
case 4798:
return {.east = false, .north = false, .south = true, .up = false, .west = true};
case 4799:
return {.east = false, .north = false, .south = true, .up = false, .west = false};
case 4800:
return {.east = false, .north = false, .south = false, .up = true, .west = true};
case 4801:
return {.east = false, .north = false, .south = false, .up = true, .west = false};
case 4802:
return {.east = false, .north = false, .south = false, .up = false, .west = true};
case 4803:
return {.east = false, .north = false, .south = false, .up = false, .west = false};
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
switch (west)
{
case true:
return "minecraft:vine:true:true:true:true:true";
case false:
return "minecraft:vine:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:vine:true:true:true:false:true";
case false:
return "minecraft:vine:true:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:vine:true:true:false:true:true";
case false:
return "minecraft:vine:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:vine:true:true:false:false:true";
case false:
return "minecraft:vine:true:true:false:false:false";
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
return "minecraft:vine:true:false:true:true:true";
case false:
return "minecraft:vine:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:vine:true:false:true:false:true";
case false:
return "minecraft:vine:true:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:vine:true:false:false:true:true";
case false:
return "minecraft:vine:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:vine:true:false:false:false:true";
case false:
return "minecraft:vine:true:false:false:false:false";
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
return "minecraft:vine:false:true:true:true:true";
case false:
return "minecraft:vine:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:vine:false:true:true:false:true";
case false:
return "minecraft:vine:false:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:vine:false:true:false:true:true";
case false:
return "minecraft:vine:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:vine:false:true:false:false:true";
case false:
return "minecraft:vine:false:true:false:false:false";
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
return "minecraft:vine:false:false:true:true:true";
case false:
return "minecraft:vine:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:vine:false:false:true:false:true";
case false:
return "minecraft:vine:false:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:vine:false:false:false:true:true";
case false:
return "minecraft:vine:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:vine:false:false:false:false:true";
case false:
return "minecraft:vine:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
