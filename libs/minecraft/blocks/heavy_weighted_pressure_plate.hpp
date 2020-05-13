#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct heavy_weighted_pressure_plate
{std::uint8_t power = 0;
constexpr block_id_type to_id() const {
switch (power)
{
case 0:
return 6126;
case 1:
return 6127;
case 2:
return 6128;
case 3:
return 6129;
case 4:
return 6130;
case 5:
return 6131;
case 6:
return 6132;
case 7:
return 6133;
case 8:
return 6134;
case 9:
return 6135;
case 10:
return 6136;
case 11:
return 6137;
case 12:
return 6138;
case 13:
return 6139;
case 14:
return 6140;
case 15:
return 6141;
}
}
constexpr static heavy_weighted_pressure_plate from_id(block_id_type id)
{
switch (id)
{
case 6126:
return {.power = 0};
case 6127:
return {.power = 1};
case 6128:
return {.power = 2};
case 6129:
return {.power = 3};
case 6130:
return {.power = 4};
case 6131:
return {.power = 5};
case 6132:
return {.power = 6};
case 6133:
return {.power = 7};
case 6134:
return {.power = 8};
case 6135:
return {.power = 9};
case 6136:
return {.power = 10};
case 6137:
return {.power = 11};
case 6138:
return {.power = 12};
case 6139:
return {.power = 13};
case 6140:
return {.power = 14};
case 6141:
return {.power = 15};
}}
constexpr std::string_view to_string() const
{switch (power)
{
case 0:
return "minecraft:heavy_weighted_pressure_plate:0";
case 1:
return "minecraft:heavy_weighted_pressure_plate:1";
case 2:
return "minecraft:heavy_weighted_pressure_plate:2";
case 3:
return "minecraft:heavy_weighted_pressure_plate:3";
case 4:
return "minecraft:heavy_weighted_pressure_plate:4";
case 5:
return "minecraft:heavy_weighted_pressure_plate:5";
case 6:
return "minecraft:heavy_weighted_pressure_plate:6";
case 7:
return "minecraft:heavy_weighted_pressure_plate:7";
case 8:
return "minecraft:heavy_weighted_pressure_plate:8";
case 9:
return "minecraft:heavy_weighted_pressure_plate:9";
case 10:
return "minecraft:heavy_weighted_pressure_plate:10";
case 11:
return "minecraft:heavy_weighted_pressure_plate:11";
case 12:
return "minecraft:heavy_weighted_pressure_plate:12";
case 13:
return "minecraft:heavy_weighted_pressure_plate:13";
case 14:
return "minecraft:heavy_weighted_pressure_plate:14";
case 15:
return "minecraft:heavy_weighted_pressure_plate:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
