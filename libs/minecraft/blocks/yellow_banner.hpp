#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct yellow_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7425;
case 1:
return 7426;
case 2:
return 7427;
case 3:
return 7428;
case 4:
return 7429;
case 5:
return 7430;
case 6:
return 7431;
case 7:
return 7432;
case 8:
return 7433;
case 9:
return 7434;
case 10:
return 7435;
case 11:
return 7436;
case 12:
return 7437;
case 13:
return 7438;
case 14:
return 7439;
case 15:
return 7440;
}
}
constexpr static yellow_banner from_id(block_id_type id)
{
switch (id)
{
case 7425:
return {.rotation = 0};
case 7426:
return {.rotation = 1};
case 7427:
return {.rotation = 2};
case 7428:
return {.rotation = 3};
case 7429:
return {.rotation = 4};
case 7430:
return {.rotation = 5};
case 7431:
return {.rotation = 6};
case 7432:
return {.rotation = 7};
case 7433:
return {.rotation = 8};
case 7434:
return {.rotation = 9};
case 7435:
return {.rotation = 10};
case 7436:
return {.rotation = 11};
case 7437:
return {.rotation = 12};
case 7438:
return {.rotation = 13};
case 7439:
return {.rotation = 14};
case 7440:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:yellow_banner:0";
case 1:
return "minecraft:yellow_banner:1";
case 2:
return "minecraft:yellow_banner:2";
case 3:
return "minecraft:yellow_banner:3";
case 4:
return "minecraft:yellow_banner:4";
case 5:
return "minecraft:yellow_banner:5";
case 6:
return "minecraft:yellow_banner:6";
case 7:
return "minecraft:yellow_banner:7";
case 8:
return "minecraft:yellow_banner:8";
case 9:
return "minecraft:yellow_banner:9";
case 10:
return "minecraft:yellow_banner:10";
case 11:
return "minecraft:yellow_banner:11";
case 12:
return "minecraft:yellow_banner:12";
case 13:
return "minecraft:yellow_banner:13";
case 14:
return "minecraft:yellow_banner:14";
case 15:
return "minecraft:yellow_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
