#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct black_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7601;
case 1:
return 7602;
case 2:
return 7603;
case 3:
return 7604;
case 4:
return 7605;
case 5:
return 7606;
case 6:
return 7607;
case 7:
return 7608;
case 8:
return 7609;
case 9:
return 7610;
case 10:
return 7611;
case 11:
return 7612;
case 12:
return 7613;
case 13:
return 7614;
case 14:
return 7615;
case 15:
return 7616;
}
}
constexpr static black_banner from_id(block_id_type id)
{
switch (id)
{
case 7601:
return {.rotation = 0};
case 7602:
return {.rotation = 1};
case 7603:
return {.rotation = 2};
case 7604:
return {.rotation = 3};
case 7605:
return {.rotation = 4};
case 7606:
return {.rotation = 5};
case 7607:
return {.rotation = 6};
case 7608:
return {.rotation = 7};
case 7609:
return {.rotation = 8};
case 7610:
return {.rotation = 9};
case 7611:
return {.rotation = 10};
case 7612:
return {.rotation = 11};
case 7613:
return {.rotation = 12};
case 7614:
return {.rotation = 13};
case 7615:
return {.rotation = 14};
case 7616:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:black_banner:0";
case 1:
return "minecraft:black_banner:1";
case 2:
return "minecraft:black_banner:2";
case 3:
return "minecraft:black_banner:3";
case 4:
return "minecraft:black_banner:4";
case 5:
return "minecraft:black_banner:5";
case 6:
return "minecraft:black_banner:6";
case 7:
return "minecraft:black_banner:7";
case 8:
return "minecraft:black_banner:8";
case 9:
return "minecraft:black_banner:9";
case 10:
return "minecraft:black_banner:10";
case 11:
return "minecraft:black_banner:11";
case 12:
return "minecraft:black_banner:12";
case 13:
return "minecraft:black_banner:13";
case 14:
return "minecraft:black_banner:14";
case 15:
return "minecraft:black_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
