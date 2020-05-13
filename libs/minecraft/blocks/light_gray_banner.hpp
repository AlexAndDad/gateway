#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct light_gray_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7489;
case 1:
return 7490;
case 2:
return 7491;
case 3:
return 7492;
case 4:
return 7493;
case 5:
return 7494;
case 6:
return 7495;
case 7:
return 7496;
case 8:
return 7497;
case 9:
return 7498;
case 10:
return 7499;
case 11:
return 7500;
case 12:
return 7501;
case 13:
return 7502;
case 14:
return 7503;
case 15:
return 7504;
}
}
constexpr static light_gray_banner from_id(block_id_type id)
{
switch (id)
{
case 7489:
return {.rotation = 0};
case 7490:
return {.rotation = 1};
case 7491:
return {.rotation = 2};
case 7492:
return {.rotation = 3};
case 7493:
return {.rotation = 4};
case 7494:
return {.rotation = 5};
case 7495:
return {.rotation = 6};
case 7496:
return {.rotation = 7};
case 7497:
return {.rotation = 8};
case 7498:
return {.rotation = 9};
case 7499:
return {.rotation = 10};
case 7500:
return {.rotation = 11};
case 7501:
return {.rotation = 12};
case 7502:
return {.rotation = 13};
case 7503:
return {.rotation = 14};
case 7504:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:light_gray_banner:0";
case 1:
return "minecraft:light_gray_banner:1";
case 2:
return "minecraft:light_gray_banner:2";
case 3:
return "minecraft:light_gray_banner:3";
case 4:
return "minecraft:light_gray_banner:4";
case 5:
return "minecraft:light_gray_banner:5";
case 6:
return "minecraft:light_gray_banner:6";
case 7:
return "minecraft:light_gray_banner:7";
case 8:
return "minecraft:light_gray_banner:8";
case 9:
return "minecraft:light_gray_banner:9";
case 10:
return "minecraft:light_gray_banner:10";
case 11:
return "minecraft:light_gray_banner:11";
case 12:
return "minecraft:light_gray_banner:12";
case 13:
return "minecraft:light_gray_banner:13";
case 14:
return "minecraft:light_gray_banner:14";
case 15:
return "minecraft:light_gray_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
