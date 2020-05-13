#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct lime_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7441;
case 1:
return 7442;
case 2:
return 7443;
case 3:
return 7444;
case 4:
return 7445;
case 5:
return 7446;
case 6:
return 7447;
case 7:
return 7448;
case 8:
return 7449;
case 9:
return 7450;
case 10:
return 7451;
case 11:
return 7452;
case 12:
return 7453;
case 13:
return 7454;
case 14:
return 7455;
case 15:
return 7456;
}
}
constexpr static lime_banner from_id(block_id_type id)
{
switch (id)
{
case 7441:
return {.rotation = 0};
case 7442:
return {.rotation = 1};
case 7443:
return {.rotation = 2};
case 7444:
return {.rotation = 3};
case 7445:
return {.rotation = 4};
case 7446:
return {.rotation = 5};
case 7447:
return {.rotation = 6};
case 7448:
return {.rotation = 7};
case 7449:
return {.rotation = 8};
case 7450:
return {.rotation = 9};
case 7451:
return {.rotation = 10};
case 7452:
return {.rotation = 11};
case 7453:
return {.rotation = 12};
case 7454:
return {.rotation = 13};
case 7455:
return {.rotation = 14};
case 7456:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:lime_banner:0";
case 1:
return "minecraft:lime_banner:1";
case 2:
return "minecraft:lime_banner:2";
case 3:
return "minecraft:lime_banner:3";
case 4:
return "minecraft:lime_banner:4";
case 5:
return "minecraft:lime_banner:5";
case 6:
return "minecraft:lime_banner:6";
case 7:
return "minecraft:lime_banner:7";
case 8:
return "minecraft:lime_banner:8";
case 9:
return "minecraft:lime_banner:9";
case 10:
return "minecraft:lime_banner:10";
case 11:
return "minecraft:lime_banner:11";
case 12:
return "minecraft:lime_banner:12";
case 13:
return "minecraft:lime_banner:13";
case 14:
return "minecraft:lime_banner:14";
case 15:
return "minecraft:lime_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
