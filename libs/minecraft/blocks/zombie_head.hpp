#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct zombie_head
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 5994;
case 1:
return 5995;
case 2:
return 5996;
case 3:
return 5997;
case 4:
return 5998;
case 5:
return 5999;
case 6:
return 6000;
case 7:
return 6001;
case 8:
return 6002;
case 9:
return 6003;
case 10:
return 6004;
case 11:
return 6005;
case 12:
return 6006;
case 13:
return 6007;
case 14:
return 6008;
case 15:
return 6009;
}
}
constexpr static zombie_head from_id(block_id_type id)
{
switch (id)
{
case 5994:
return {.rotation = 0};
case 5995:
return {.rotation = 1};
case 5996:
return {.rotation = 2};
case 5997:
return {.rotation = 3};
case 5998:
return {.rotation = 4};
case 5999:
return {.rotation = 5};
case 6000:
return {.rotation = 6};
case 6001:
return {.rotation = 7};
case 6002:
return {.rotation = 8};
case 6003:
return {.rotation = 9};
case 6004:
return {.rotation = 10};
case 6005:
return {.rotation = 11};
case 6006:
return {.rotation = 12};
case 6007:
return {.rotation = 13};
case 6008:
return {.rotation = 14};
case 6009:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:zombie_head:0";
case 1:
return "minecraft:zombie_head:1";
case 2:
return "minecraft:zombie_head:2";
case 3:
return "minecraft:zombie_head:3";
case 4:
return "minecraft:zombie_head:4";
case 5:
return "minecraft:zombie_head:5";
case 6:
return "minecraft:zombie_head:6";
case 7:
return "minecraft:zombie_head:7";
case 8:
return "minecraft:zombie_head:8";
case 9:
return "minecraft:zombie_head:9";
case 10:
return "minecraft:zombie_head:10";
case 11:
return "minecraft:zombie_head:11";
case 12:
return "minecraft:zombie_head:12";
case 13:
return "minecraft:zombie_head:13";
case 14:
return "minecraft:zombie_head:14";
case 15:
return "minecraft:zombie_head:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
