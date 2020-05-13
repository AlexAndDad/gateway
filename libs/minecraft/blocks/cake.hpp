#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct cake
{std::uint8_t bites = 0;
constexpr block_id_type to_id() const {
switch (bites)
{
case 0:
return 4010;
case 1:
return 4011;
case 2:
return 4012;
case 3:
return 4013;
case 4:
return 4014;
case 5:
return 4015;
case 6:
return 4016;
}
}
constexpr static cake from_id(block_id_type id)
{
switch (id)
{
case 4010:
return {.bites = 0};
case 4011:
return {.bites = 1};
case 4012:
return {.bites = 2};
case 4013:
return {.bites = 3};
case 4014:
return {.bites = 4};
case 4015:
return {.bites = 5};
case 4016:
return {.bites = 6};
}}
constexpr std::string_view to_string() const
{switch (bites)
{
case 0:
return "minecraft:cake:0";
case 1:
return "minecraft:cake:1";
case 2:
return "minecraft:cake:2";
case 3:
return "minecraft:cake:3";
case 4:
return "minecraft:cake:4";
case 5:
return "minecraft:cake:5";
case 6:
return "minecraft:cake:6";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
