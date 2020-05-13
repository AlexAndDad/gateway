#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct pumpkin_stem
{std::uint8_t age = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
return 4756;
case 1:
return 4757;
case 2:
return 4758;
case 3:
return 4759;
case 4:
return 4760;
case 5:
return 4761;
case 6:
return 4762;
case 7:
return 4763;
}
}
constexpr static pumpkin_stem from_id(block_id_type id)
{
switch (id)
{
case 4756:
return {.age = 0};
case 4757:
return {.age = 1};
case 4758:
return {.age = 2};
case 4759:
return {.age = 3};
case 4760:
return {.age = 4};
case 4761:
return {.age = 5};
case 4762:
return {.age = 6};
case 4763:
return {.age = 7};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
return "minecraft:pumpkin_stem:0";
case 1:
return "minecraft:pumpkin_stem:1";
case 2:
return "minecraft:pumpkin_stem:2";
case 3:
return "minecraft:pumpkin_stem:3";
case 4:
return "minecraft:pumpkin_stem:4";
case 5:
return "minecraft:pumpkin_stem:5";
case 6:
return "minecraft:pumpkin_stem:6";
case 7:
return "minecraft:pumpkin_stem:7";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
