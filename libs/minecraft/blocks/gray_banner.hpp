#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct gray_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7473;
case 1:
return 7474;
case 2:
return 7475;
case 3:
return 7476;
case 4:
return 7477;
case 5:
return 7478;
case 6:
return 7479;
case 7:
return 7480;
case 8:
return 7481;
case 9:
return 7482;
case 10:
return 7483;
case 11:
return 7484;
case 12:
return 7485;
case 13:
return 7486;
case 14:
return 7487;
case 15:
return 7488;
}
}
constexpr static gray_banner from_id(block_id_type id)
{
switch (id)
{
case 7473:
return {.rotation = 0};
case 7474:
return {.rotation = 1};
case 7475:
return {.rotation = 2};
case 7476:
return {.rotation = 3};
case 7477:
return {.rotation = 4};
case 7478:
return {.rotation = 5};
case 7479:
return {.rotation = 6};
case 7480:
return {.rotation = 7};
case 7481:
return {.rotation = 8};
case 7482:
return {.rotation = 9};
case 7483:
return {.rotation = 10};
case 7484:
return {.rotation = 11};
case 7485:
return {.rotation = 12};
case 7486:
return {.rotation = 13};
case 7487:
return {.rotation = 14};
case 7488:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:gray_banner:0";
case 1:
return "minecraft:gray_banner:1";
case 2:
return "minecraft:gray_banner:2";
case 3:
return "minecraft:gray_banner:3";
case 4:
return "minecraft:gray_banner:4";
case 5:
return "minecraft:gray_banner:5";
case 6:
return "minecraft:gray_banner:6";
case 7:
return "minecraft:gray_banner:7";
case 8:
return "minecraft:gray_banner:8";
case 9:
return "minecraft:gray_banner:9";
case 10:
return "minecraft:gray_banner:10";
case 11:
return "minecraft:gray_banner:11";
case 12:
return "minecraft:gray_banner:12";
case 13:
return "minecraft:gray_banner:13";
case 14:
return "minecraft:gray_banner:14";
case 15:
return "minecraft:gray_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
