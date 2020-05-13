#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct purple_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7521;
case 1:
return 7522;
case 2:
return 7523;
case 3:
return 7524;
case 4:
return 7525;
case 5:
return 7526;
case 6:
return 7527;
case 7:
return 7528;
case 8:
return 7529;
case 9:
return 7530;
case 10:
return 7531;
case 11:
return 7532;
case 12:
return 7533;
case 13:
return 7534;
case 14:
return 7535;
case 15:
return 7536;
}
}
constexpr static purple_banner from_id(block_id_type id)
{
switch (id)
{
case 7521:
return {.rotation = 0};
case 7522:
return {.rotation = 1};
case 7523:
return {.rotation = 2};
case 7524:
return {.rotation = 3};
case 7525:
return {.rotation = 4};
case 7526:
return {.rotation = 5};
case 7527:
return {.rotation = 6};
case 7528:
return {.rotation = 7};
case 7529:
return {.rotation = 8};
case 7530:
return {.rotation = 9};
case 7531:
return {.rotation = 10};
case 7532:
return {.rotation = 11};
case 7533:
return {.rotation = 12};
case 7534:
return {.rotation = 13};
case 7535:
return {.rotation = 14};
case 7536:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:purple_banner:0";
case 1:
return "minecraft:purple_banner:1";
case 2:
return "minecraft:purple_banner:2";
case 3:
return "minecraft:purple_banner:3";
case 4:
return "minecraft:purple_banner:4";
case 5:
return "minecraft:purple_banner:5";
case 6:
return "minecraft:purple_banner:6";
case 7:
return "minecraft:purple_banner:7";
case 8:
return "minecraft:purple_banner:8";
case 9:
return "minecraft:purple_banner:9";
case 10:
return "minecraft:purple_banner:10";
case 11:
return "minecraft:purple_banner:11";
case 12:
return "minecraft:purple_banner:12";
case 13:
return "minecraft:purple_banner:13";
case 14:
return "minecraft:purple_banner:14";
case 15:
return "minecraft:purple_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
