#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct creeper_head
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 6034;
case 1:
return 6035;
case 2:
return 6036;
case 3:
return 6037;
case 4:
return 6038;
case 5:
return 6039;
case 6:
return 6040;
case 7:
return 6041;
case 8:
return 6042;
case 9:
return 6043;
case 10:
return 6044;
case 11:
return 6045;
case 12:
return 6046;
case 13:
return 6047;
case 14:
return 6048;
case 15:
return 6049;
}
}
constexpr static creeper_head from_id(block_id_type id)
{
switch (id)
{
case 6034:
return {.rotation = 0};
case 6035:
return {.rotation = 1};
case 6036:
return {.rotation = 2};
case 6037:
return {.rotation = 3};
case 6038:
return {.rotation = 4};
case 6039:
return {.rotation = 5};
case 6040:
return {.rotation = 6};
case 6041:
return {.rotation = 7};
case 6042:
return {.rotation = 8};
case 6043:
return {.rotation = 9};
case 6044:
return {.rotation = 10};
case 6045:
return {.rotation = 11};
case 6046:
return {.rotation = 12};
case 6047:
return {.rotation = 13};
case 6048:
return {.rotation = 14};
case 6049:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:creeper_head:0";
case 1:
return "minecraft:creeper_head:1";
case 2:
return "minecraft:creeper_head:2";
case 3:
return "minecraft:creeper_head:3";
case 4:
return "minecraft:creeper_head:4";
case 5:
return "minecraft:creeper_head:5";
case 6:
return "minecraft:creeper_head:6";
case 7:
return "minecraft:creeper_head:7";
case 8:
return "minecraft:creeper_head:8";
case 9:
return "minecraft:creeper_head:9";
case 10:
return "minecraft:creeper_head:10";
case 11:
return "minecraft:creeper_head:11";
case 12:
return "minecraft:creeper_head:12";
case 13:
return "minecraft:creeper_head:13";
case 14:
return "minecraft:creeper_head:14";
case 15:
return "minecraft:creeper_head:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
