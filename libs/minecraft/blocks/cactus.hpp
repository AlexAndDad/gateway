#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct cactus
{std::uint8_t age = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
return 3929;
case 1:
return 3930;
case 2:
return 3931;
case 3:
return 3932;
case 4:
return 3933;
case 5:
return 3934;
case 6:
return 3935;
case 7:
return 3936;
case 8:
return 3937;
case 9:
return 3938;
case 10:
return 3939;
case 11:
return 3940;
case 12:
return 3941;
case 13:
return 3942;
case 14:
return 3943;
case 15:
return 3944;
}
}
constexpr static cactus from_id(block_id_type id)
{
switch (id)
{
case 3929:
return {.age = 0};
case 3930:
return {.age = 1};
case 3931:
return {.age = 2};
case 3932:
return {.age = 3};
case 3933:
return {.age = 4};
case 3934:
return {.age = 5};
case 3935:
return {.age = 6};
case 3936:
return {.age = 7};
case 3937:
return {.age = 8};
case 3938:
return {.age = 9};
case 3939:
return {.age = 10};
case 3940:
return {.age = 11};
case 3941:
return {.age = 12};
case 3942:
return {.age = 13};
case 3943:
return {.age = 14};
case 3944:
return {.age = 15};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
return "minecraft:cactus:0";
case 1:
return "minecraft:cactus:1";
case 2:
return "minecraft:cactus:2";
case 3:
return "minecraft:cactus:3";
case 4:
return "minecraft:cactus:4";
case 5:
return "minecraft:cactus:5";
case 6:
return "minecraft:cactus:6";
case 7:
return "minecraft:cactus:7";
case 8:
return "minecraft:cactus:8";
case 9:
return "minecraft:cactus:9";
case 10:
return "minecraft:cactus:10";
case 11:
return "minecraft:cactus:11";
case 12:
return "minecraft:cactus:12";
case 13:
return "minecraft:cactus:13";
case 14:
return "minecraft:cactus:14";
case 15:
return "minecraft:cactus:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
