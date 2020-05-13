#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct light_weighted_pressure_plate
{std::uint8_t power = 0;
constexpr block_id_type to_id() const {
switch (power)
{
case 0:
return 6110;
case 1:
return 6111;
case 2:
return 6112;
case 3:
return 6113;
case 4:
return 6114;
case 5:
return 6115;
case 6:
return 6116;
case 7:
return 6117;
case 8:
return 6118;
case 9:
return 6119;
case 10:
return 6120;
case 11:
return 6121;
case 12:
return 6122;
case 13:
return 6123;
case 14:
return 6124;
case 15:
return 6125;
}
}
constexpr static light_weighted_pressure_plate from_id(block_id_type id)
{
switch (id)
{
case 6110:
return {.power = 0};
case 6111:
return {.power = 1};
case 6112:
return {.power = 2};
case 6113:
return {.power = 3};
case 6114:
return {.power = 4};
case 6115:
return {.power = 5};
case 6116:
return {.power = 6};
case 6117:
return {.power = 7};
case 6118:
return {.power = 8};
case 6119:
return {.power = 9};
case 6120:
return {.power = 10};
case 6121:
return {.power = 11};
case 6122:
return {.power = 12};
case 6123:
return {.power = 13};
case 6124:
return {.power = 14};
case 6125:
return {.power = 15};
}}
constexpr std::string_view to_string() const
{switch (power)
{
case 0:
return "minecraft:light_weighted_pressure_plate:0";
case 1:
return "minecraft:light_weighted_pressure_plate:1";
case 2:
return "minecraft:light_weighted_pressure_plate:2";
case 3:
return "minecraft:light_weighted_pressure_plate:3";
case 4:
return "minecraft:light_weighted_pressure_plate:4";
case 5:
return "minecraft:light_weighted_pressure_plate:5";
case 6:
return "minecraft:light_weighted_pressure_plate:6";
case 7:
return "minecraft:light_weighted_pressure_plate:7";
case 8:
return "minecraft:light_weighted_pressure_plate:8";
case 9:
return "minecraft:light_weighted_pressure_plate:9";
case 10:
return "minecraft:light_weighted_pressure_plate:10";
case 11:
return "minecraft:light_weighted_pressure_plate:11";
case 12:
return "minecraft:light_weighted_pressure_plate:12";
case 13:
return "minecraft:light_weighted_pressure_plate:13";
case 14:
return "minecraft:light_weighted_pressure_plate:14";
case 15:
return "minecraft:light_weighted_pressure_plate:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
