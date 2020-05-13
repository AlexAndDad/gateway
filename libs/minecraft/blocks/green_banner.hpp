#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct green_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7569;
case 1:
return 7570;
case 2:
return 7571;
case 3:
return 7572;
case 4:
return 7573;
case 5:
return 7574;
case 6:
return 7575;
case 7:
return 7576;
case 8:
return 7577;
case 9:
return 7578;
case 10:
return 7579;
case 11:
return 7580;
case 12:
return 7581;
case 13:
return 7582;
case 14:
return 7583;
case 15:
return 7584;
}
}
constexpr static green_banner from_id(block_id_type id)
{
switch (id)
{
case 7569:
return {.rotation = 0};
case 7570:
return {.rotation = 1};
case 7571:
return {.rotation = 2};
case 7572:
return {.rotation = 3};
case 7573:
return {.rotation = 4};
case 7574:
return {.rotation = 5};
case 7575:
return {.rotation = 6};
case 7576:
return {.rotation = 7};
case 7577:
return {.rotation = 8};
case 7578:
return {.rotation = 9};
case 7579:
return {.rotation = 10};
case 7580:
return {.rotation = 11};
case 7581:
return {.rotation = 12};
case 7582:
return {.rotation = 13};
case 7583:
return {.rotation = 14};
case 7584:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:green_banner:0";
case 1:
return "minecraft:green_banner:1";
case 2:
return "minecraft:green_banner:2";
case 3:
return "minecraft:green_banner:3";
case 4:
return "minecraft:green_banner:4";
case 5:
return "minecraft:green_banner:5";
case 6:
return "minecraft:green_banner:6";
case 7:
return "minecraft:green_banner:7";
case 8:
return "minecraft:green_banner:8";
case 9:
return "minecraft:green_banner:9";
case 10:
return "minecraft:green_banner:10";
case 11:
return "minecraft:green_banner:11";
case 12:
return "minecraft:green_banner:12";
case 13:
return "minecraft:green_banner:13";
case 14:
return "minecraft:green_banner:14";
case 15:
return "minecraft:green_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
