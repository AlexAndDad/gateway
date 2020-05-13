#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct light_blue_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7409;
case 1:
return 7410;
case 2:
return 7411;
case 3:
return 7412;
case 4:
return 7413;
case 5:
return 7414;
case 6:
return 7415;
case 7:
return 7416;
case 8:
return 7417;
case 9:
return 7418;
case 10:
return 7419;
case 11:
return 7420;
case 12:
return 7421;
case 13:
return 7422;
case 14:
return 7423;
case 15:
return 7424;
}
}
constexpr static light_blue_banner from_id(block_id_type id)
{
switch (id)
{
case 7409:
return {.rotation = 0};
case 7410:
return {.rotation = 1};
case 7411:
return {.rotation = 2};
case 7412:
return {.rotation = 3};
case 7413:
return {.rotation = 4};
case 7414:
return {.rotation = 5};
case 7415:
return {.rotation = 6};
case 7416:
return {.rotation = 7};
case 7417:
return {.rotation = 8};
case 7418:
return {.rotation = 9};
case 7419:
return {.rotation = 10};
case 7420:
return {.rotation = 11};
case 7421:
return {.rotation = 12};
case 7422:
return {.rotation = 13};
case 7423:
return {.rotation = 14};
case 7424:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:light_blue_banner:0";
case 1:
return "minecraft:light_blue_banner:1";
case 2:
return "minecraft:light_blue_banner:2";
case 3:
return "minecraft:light_blue_banner:3";
case 4:
return "minecraft:light_blue_banner:4";
case 5:
return "minecraft:light_blue_banner:5";
case 6:
return "minecraft:light_blue_banner:6";
case 7:
return "minecraft:light_blue_banner:7";
case 8:
return "minecraft:light_blue_banner:8";
case 9:
return "minecraft:light_blue_banner:9";
case 10:
return "minecraft:light_blue_banner:10";
case 11:
return "minecraft:light_blue_banner:11";
case 12:
return "minecraft:light_blue_banner:12";
case 13:
return "minecraft:light_blue_banner:13";
case 14:
return "minecraft:light_blue_banner:14";
case 15:
return "minecraft:light_blue_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
