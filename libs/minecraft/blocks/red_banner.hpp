#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct red_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7585;
case 1:
return 7586;
case 2:
return 7587;
case 3:
return 7588;
case 4:
return 7589;
case 5:
return 7590;
case 6:
return 7591;
case 7:
return 7592;
case 8:
return 7593;
case 9:
return 7594;
case 10:
return 7595;
case 11:
return 7596;
case 12:
return 7597;
case 13:
return 7598;
case 14:
return 7599;
case 15:
return 7600;
}
}
constexpr static red_banner from_id(block_id_type id)
{
switch (id)
{
case 7585:
return {.rotation = 0};
case 7586:
return {.rotation = 1};
case 7587:
return {.rotation = 2};
case 7588:
return {.rotation = 3};
case 7589:
return {.rotation = 4};
case 7590:
return {.rotation = 5};
case 7591:
return {.rotation = 6};
case 7592:
return {.rotation = 7};
case 7593:
return {.rotation = 8};
case 7594:
return {.rotation = 9};
case 7595:
return {.rotation = 10};
case 7596:
return {.rotation = 11};
case 7597:
return {.rotation = 12};
case 7598:
return {.rotation = 13};
case 7599:
return {.rotation = 14};
case 7600:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:red_banner:0";
case 1:
return "minecraft:red_banner:1";
case 2:
return "minecraft:red_banner:2";
case 3:
return "minecraft:red_banner:3";
case 4:
return "minecraft:red_banner:4";
case 5:
return "minecraft:red_banner:5";
case 6:
return "minecraft:red_banner:6";
case 7:
return "minecraft:red_banner:7";
case 8:
return "minecraft:red_banner:8";
case 9:
return "minecraft:red_banner:9";
case 10:
return "minecraft:red_banner:10";
case 11:
return "minecraft:red_banner:11";
case 12:
return "minecraft:red_banner:12";
case 13:
return "minecraft:red_banner:13";
case 14:
return "minecraft:red_banner:14";
case 15:
return "minecraft:red_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
