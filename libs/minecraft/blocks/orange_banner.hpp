#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct orange_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7377;
case 1:
return 7378;
case 2:
return 7379;
case 3:
return 7380;
case 4:
return 7381;
case 5:
return 7382;
case 6:
return 7383;
case 7:
return 7384;
case 8:
return 7385;
case 9:
return 7386;
case 10:
return 7387;
case 11:
return 7388;
case 12:
return 7389;
case 13:
return 7390;
case 14:
return 7391;
case 15:
return 7392;
}
}
constexpr static orange_banner from_id(block_id_type id)
{
switch (id)
{
case 7377:
return {.rotation = 0};
case 7378:
return {.rotation = 1};
case 7379:
return {.rotation = 2};
case 7380:
return {.rotation = 3};
case 7381:
return {.rotation = 4};
case 7382:
return {.rotation = 5};
case 7383:
return {.rotation = 6};
case 7384:
return {.rotation = 7};
case 7385:
return {.rotation = 8};
case 7386:
return {.rotation = 9};
case 7387:
return {.rotation = 10};
case 7388:
return {.rotation = 11};
case 7389:
return {.rotation = 12};
case 7390:
return {.rotation = 13};
case 7391:
return {.rotation = 14};
case 7392:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:orange_banner:0";
case 1:
return "minecraft:orange_banner:1";
case 2:
return "minecraft:orange_banner:2";
case 3:
return "minecraft:orange_banner:3";
case 4:
return "minecraft:orange_banner:4";
case 5:
return "minecraft:orange_banner:5";
case 6:
return "minecraft:orange_banner:6";
case 7:
return "minecraft:orange_banner:7";
case 8:
return "minecraft:orange_banner:8";
case 9:
return "minecraft:orange_banner:9";
case 10:
return "minecraft:orange_banner:10";
case 11:
return "minecraft:orange_banner:11";
case 12:
return "minecraft:orange_banner:12";
case 13:
return "minecraft:orange_banner:13";
case 14:
return "minecraft:orange_banner:14";
case 15:
return "minecraft:orange_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
