#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct blue_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7537;
case 1:
return 7538;
case 2:
return 7539;
case 3:
return 7540;
case 4:
return 7541;
case 5:
return 7542;
case 6:
return 7543;
case 7:
return 7544;
case 8:
return 7545;
case 9:
return 7546;
case 10:
return 7547;
case 11:
return 7548;
case 12:
return 7549;
case 13:
return 7550;
case 14:
return 7551;
case 15:
return 7552;
}
}
constexpr static blue_banner from_id(block_id_type id)
{
switch (id)
{
case 7537:
return {.rotation = 0};
case 7538:
return {.rotation = 1};
case 7539:
return {.rotation = 2};
case 7540:
return {.rotation = 3};
case 7541:
return {.rotation = 4};
case 7542:
return {.rotation = 5};
case 7543:
return {.rotation = 6};
case 7544:
return {.rotation = 7};
case 7545:
return {.rotation = 8};
case 7546:
return {.rotation = 9};
case 7547:
return {.rotation = 10};
case 7548:
return {.rotation = 11};
case 7549:
return {.rotation = 12};
case 7550:
return {.rotation = 13};
case 7551:
return {.rotation = 14};
case 7552:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:blue_banner:0";
case 1:
return "minecraft:blue_banner:1";
case 2:
return "minecraft:blue_banner:2";
case 3:
return "minecraft:blue_banner:3";
case 4:
return "minecraft:blue_banner:4";
case 5:
return "minecraft:blue_banner:5";
case 6:
return "minecraft:blue_banner:6";
case 7:
return "minecraft:blue_banner:7";
case 8:
return "minecraft:blue_banner:8";
case 9:
return "minecraft:blue_banner:9";
case 10:
return "minecraft:blue_banner:10";
case 11:
return "minecraft:blue_banner:11";
case 12:
return "minecraft:blue_banner:12";
case 13:
return "minecraft:blue_banner:13";
case 14:
return "minecraft:blue_banner:14";
case 15:
return "minecraft:blue_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
