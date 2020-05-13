#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct water
{std::uint8_t level = 0;
constexpr block_id_type to_id() const {
switch (level)
{
case 0:
return 34;
case 1:
return 35;
case 2:
return 36;
case 3:
return 37;
case 4:
return 38;
case 5:
return 39;
case 6:
return 40;
case 7:
return 41;
case 8:
return 42;
case 9:
return 43;
case 10:
return 44;
case 11:
return 45;
case 12:
return 46;
case 13:
return 47;
case 14:
return 48;
case 15:
return 49;
}
}
constexpr static water from_id(block_id_type id)
{
switch (id)
{
case 34:
return {.level = 0};
case 35:
return {.level = 1};
case 36:
return {.level = 2};
case 37:
return {.level = 3};
case 38:
return {.level = 4};
case 39:
return {.level = 5};
case 40:
return {.level = 6};
case 41:
return {.level = 7};
case 42:
return {.level = 8};
case 43:
return {.level = 9};
case 44:
return {.level = 10};
case 45:
return {.level = 11};
case 46:
return {.level = 12};
case 47:
return {.level = 13};
case 48:
return {.level = 14};
case 49:
return {.level = 15};
}}
constexpr std::string_view to_string() const
{switch (level)
{
case 0:
return "minecraft:water:0";
case 1:
return "minecraft:water:1";
case 2:
return "minecraft:water:2";
case 3:
return "minecraft:water:3";
case 4:
return "minecraft:water:4";
case 5:
return "minecraft:water:5";
case 6:
return "minecraft:water:6";
case 7:
return "minecraft:water:7";
case 8:
return "minecraft:water:8";
case 9:
return "minecraft:water:9";
case 10:
return "minecraft:water:10";
case 11:
return "minecraft:water:11";
case 12:
return "minecraft:water:12";
case 13:
return "minecraft:water:13";
case 14:
return "minecraft:water:14";
case 15:
return "minecraft:water:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
