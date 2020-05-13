#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct sugar_cane
{std::uint8_t age = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
return 3946;
case 1:
return 3947;
case 2:
return 3948;
case 3:
return 3949;
case 4:
return 3950;
case 5:
return 3951;
case 6:
return 3952;
case 7:
return 3953;
case 8:
return 3954;
case 9:
return 3955;
case 10:
return 3956;
case 11:
return 3957;
case 12:
return 3958;
case 13:
return 3959;
case 14:
return 3960;
case 15:
return 3961;
}
}
constexpr static sugar_cane from_id(block_id_type id)
{
switch (id)
{
case 3946:
return {.age = 0};
case 3947:
return {.age = 1};
case 3948:
return {.age = 2};
case 3949:
return {.age = 3};
case 3950:
return {.age = 4};
case 3951:
return {.age = 5};
case 3952:
return {.age = 6};
case 3953:
return {.age = 7};
case 3954:
return {.age = 8};
case 3955:
return {.age = 9};
case 3956:
return {.age = 10};
case 3957:
return {.age = 11};
case 3958:
return {.age = 12};
case 3959:
return {.age = 13};
case 3960:
return {.age = 14};
case 3961:
return {.age = 15};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
return "minecraft:sugar_cane:0";
case 1:
return "minecraft:sugar_cane:1";
case 2:
return "minecraft:sugar_cane:2";
case 3:
return "minecraft:sugar_cane:3";
case 4:
return "minecraft:sugar_cane:4";
case 5:
return "minecraft:sugar_cane:5";
case 6:
return "minecraft:sugar_cane:6";
case 7:
return "minecraft:sugar_cane:7";
case 8:
return "minecraft:sugar_cane:8";
case 9:
return "minecraft:sugar_cane:9";
case 10:
return "minecraft:sugar_cane:10";
case 11:
return "minecraft:sugar_cane:11";
case 12:
return "minecraft:sugar_cane:12";
case 13:
return "minecraft:sugar_cane:13";
case 14:
return "minecraft:sugar_cane:14";
case 15:
return "minecraft:sugar_cane:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
