#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct pink_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7457;
case 1:
return 7458;
case 2:
return 7459;
case 3:
return 7460;
case 4:
return 7461;
case 5:
return 7462;
case 6:
return 7463;
case 7:
return 7464;
case 8:
return 7465;
case 9:
return 7466;
case 10:
return 7467;
case 11:
return 7468;
case 12:
return 7469;
case 13:
return 7470;
case 14:
return 7471;
case 15:
return 7472;
}
}
constexpr static pink_banner from_id(block_id_type id)
{
switch (id)
{
case 7457:
return {.rotation = 0};
case 7458:
return {.rotation = 1};
case 7459:
return {.rotation = 2};
case 7460:
return {.rotation = 3};
case 7461:
return {.rotation = 4};
case 7462:
return {.rotation = 5};
case 7463:
return {.rotation = 6};
case 7464:
return {.rotation = 7};
case 7465:
return {.rotation = 8};
case 7466:
return {.rotation = 9};
case 7467:
return {.rotation = 10};
case 7468:
return {.rotation = 11};
case 7469:
return {.rotation = 12};
case 7470:
return {.rotation = 13};
case 7471:
return {.rotation = 14};
case 7472:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:pink_banner:0";
case 1:
return "minecraft:pink_banner:1";
case 2:
return "minecraft:pink_banner:2";
case 3:
return "minecraft:pink_banner:3";
case 4:
return "minecraft:pink_banner:4";
case 5:
return "minecraft:pink_banner:5";
case 6:
return "minecraft:pink_banner:6";
case 7:
return "minecraft:pink_banner:7";
case 8:
return "minecraft:pink_banner:8";
case 9:
return "minecraft:pink_banner:9";
case 10:
return "minecraft:pink_banner:10";
case 11:
return "minecraft:pink_banner:11";
case 12:
return "minecraft:pink_banner:12";
case 13:
return "minecraft:pink_banner:13";
case 14:
return "minecraft:pink_banner:14";
case 15:
return "minecraft:pink_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
