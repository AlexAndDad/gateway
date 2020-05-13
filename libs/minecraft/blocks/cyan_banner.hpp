#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct cyan_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7505;
case 1:
return 7506;
case 2:
return 7507;
case 3:
return 7508;
case 4:
return 7509;
case 5:
return 7510;
case 6:
return 7511;
case 7:
return 7512;
case 8:
return 7513;
case 9:
return 7514;
case 10:
return 7515;
case 11:
return 7516;
case 12:
return 7517;
case 13:
return 7518;
case 14:
return 7519;
case 15:
return 7520;
}
}
constexpr static cyan_banner from_id(block_id_type id)
{
switch (id)
{
case 7505:
return {.rotation = 0};
case 7506:
return {.rotation = 1};
case 7507:
return {.rotation = 2};
case 7508:
return {.rotation = 3};
case 7509:
return {.rotation = 4};
case 7510:
return {.rotation = 5};
case 7511:
return {.rotation = 6};
case 7512:
return {.rotation = 7};
case 7513:
return {.rotation = 8};
case 7514:
return {.rotation = 9};
case 7515:
return {.rotation = 10};
case 7516:
return {.rotation = 11};
case 7517:
return {.rotation = 12};
case 7518:
return {.rotation = 13};
case 7519:
return {.rotation = 14};
case 7520:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:cyan_banner:0";
case 1:
return "minecraft:cyan_banner:1";
case 2:
return "minecraft:cyan_banner:2";
case 3:
return "minecraft:cyan_banner:3";
case 4:
return "minecraft:cyan_banner:4";
case 5:
return "minecraft:cyan_banner:5";
case 6:
return "minecraft:cyan_banner:6";
case 7:
return "minecraft:cyan_banner:7";
case 8:
return "minecraft:cyan_banner:8";
case 9:
return "minecraft:cyan_banner:9";
case 10:
return "minecraft:cyan_banner:10";
case 11:
return "minecraft:cyan_banner:11";
case 12:
return "minecraft:cyan_banner:12";
case 13:
return "minecraft:cyan_banner:13";
case 14:
return "minecraft:cyan_banner:14";
case 15:
return "minecraft:cyan_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
