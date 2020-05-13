#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct lava
{std::uint8_t level = 0;
constexpr block_id_type to_id() const {
switch (level)
{
case 0:
return 50;
case 1:
return 51;
case 2:
return 52;
case 3:
return 53;
case 4:
return 54;
case 5:
return 55;
case 6:
return 56;
case 7:
return 57;
case 8:
return 58;
case 9:
return 59;
case 10:
return 60;
case 11:
return 61;
case 12:
return 62;
case 13:
return 63;
case 14:
return 64;
case 15:
return 65;
}
}
constexpr static lava from_id(block_id_type id)
{
switch (id)
{
case 50:
return {.level = 0};
case 51:
return {.level = 1};
case 52:
return {.level = 2};
case 53:
return {.level = 3};
case 54:
return {.level = 4};
case 55:
return {.level = 5};
case 56:
return {.level = 6};
case 57:
return {.level = 7};
case 58:
return {.level = 8};
case 59:
return {.level = 9};
case 60:
return {.level = 10};
case 61:
return {.level = 11};
case 62:
return {.level = 12};
case 63:
return {.level = 13};
case 64:
return {.level = 14};
case 65:
return {.level = 15};
}}
constexpr std::string_view to_string() const
{switch (level)
{
case 0:
return "minecraft:lava:0";
case 1:
return "minecraft:lava:1";
case 2:
return "minecraft:lava:2";
case 3:
return "minecraft:lava:3";
case 4:
return "minecraft:lava:4";
case 5:
return "minecraft:lava:5";
case 6:
return "minecraft:lava:6";
case 7:
return "minecraft:lava:7";
case 8:
return "minecraft:lava:8";
case 9:
return "minecraft:lava:9";
case 10:
return "minecraft:lava:10";
case 11:
return "minecraft:lava:11";
case 12:
return "minecraft:lava:12";
case 13:
return "minecraft:lava:13";
case 14:
return "minecraft:lava:14";
case 15:
return "minecraft:lava:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
