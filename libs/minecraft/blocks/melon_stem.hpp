#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct melon_stem
{std::uint8_t age = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
return 4764;
case 1:
return 4765;
case 2:
return 4766;
case 3:
return 4767;
case 4:
return 4768;
case 5:
return 4769;
case 6:
return 4770;
case 7:
return 4771;
}
}
constexpr static melon_stem from_id(block_id_type id)
{
switch (id)
{
case 4764:
return {.age = 0};
case 4765:
return {.age = 1};
case 4766:
return {.age = 2};
case 4767:
return {.age = 3};
case 4768:
return {.age = 4};
case 4769:
return {.age = 5};
case 4770:
return {.age = 6};
case 4771:
return {.age = 7};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
return "minecraft:melon_stem:0";
case 1:
return "minecraft:melon_stem:1";
case 2:
return "minecraft:melon_stem:2";
case 3:
return "minecraft:melon_stem:3";
case 4:
return "minecraft:melon_stem:4";
case 5:
return "minecraft:melon_stem:5";
case 6:
return "minecraft:melon_stem:6";
case 7:
return "minecraft:melon_stem:7";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
