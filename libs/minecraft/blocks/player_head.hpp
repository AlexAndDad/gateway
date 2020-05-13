#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct player_head
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 6014;
case 1:
return 6015;
case 2:
return 6016;
case 3:
return 6017;
case 4:
return 6018;
case 5:
return 6019;
case 6:
return 6020;
case 7:
return 6021;
case 8:
return 6022;
case 9:
return 6023;
case 10:
return 6024;
case 11:
return 6025;
case 12:
return 6026;
case 13:
return 6027;
case 14:
return 6028;
case 15:
return 6029;
}
}
constexpr static player_head from_id(block_id_type id)
{
switch (id)
{
case 6014:
return {.rotation = 0};
case 6015:
return {.rotation = 1};
case 6016:
return {.rotation = 2};
case 6017:
return {.rotation = 3};
case 6018:
return {.rotation = 4};
case 6019:
return {.rotation = 5};
case 6020:
return {.rotation = 6};
case 6021:
return {.rotation = 7};
case 6022:
return {.rotation = 8};
case 6023:
return {.rotation = 9};
case 6024:
return {.rotation = 10};
case 6025:
return {.rotation = 11};
case 6026:
return {.rotation = 12};
case 6027:
return {.rotation = 13};
case 6028:
return {.rotation = 14};
case 6029:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:player_head:0";
case 1:
return "minecraft:player_head:1";
case 2:
return "minecraft:player_head:2";
case 3:
return "minecraft:player_head:3";
case 4:
return "minecraft:player_head:4";
case 5:
return "minecraft:player_head:5";
case 6:
return "minecraft:player_head:6";
case 7:
return "minecraft:player_head:7";
case 8:
return "minecraft:player_head:8";
case 9:
return "minecraft:player_head:9";
case 10:
return "minecraft:player_head:10";
case 11:
return "minecraft:player_head:11";
case 12:
return "minecraft:player_head:12";
case 13:
return "minecraft:player_head:13";
case 14:
return "minecraft:player_head:14";
case 15:
return "minecraft:player_head:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
