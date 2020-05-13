#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dragon_head
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 6054;
case 1:
return 6055;
case 2:
return 6056;
case 3:
return 6057;
case 4:
return 6058;
case 5:
return 6059;
case 6:
return 6060;
case 7:
return 6061;
case 8:
return 6062;
case 9:
return 6063;
case 10:
return 6064;
case 11:
return 6065;
case 12:
return 6066;
case 13:
return 6067;
case 14:
return 6068;
case 15:
return 6069;
}
}
constexpr static dragon_head from_id(block_id_type id)
{
switch (id)
{
case 6054:
return {.rotation = 0};
case 6055:
return {.rotation = 1};
case 6056:
return {.rotation = 2};
case 6057:
return {.rotation = 3};
case 6058:
return {.rotation = 4};
case 6059:
return {.rotation = 5};
case 6060:
return {.rotation = 6};
case 6061:
return {.rotation = 7};
case 6062:
return {.rotation = 8};
case 6063:
return {.rotation = 9};
case 6064:
return {.rotation = 10};
case 6065:
return {.rotation = 11};
case 6066:
return {.rotation = 12};
case 6067:
return {.rotation = 13};
case 6068:
return {.rotation = 14};
case 6069:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:dragon_head:0";
case 1:
return "minecraft:dragon_head:1";
case 2:
return "minecraft:dragon_head:2";
case 3:
return "minecraft:dragon_head:3";
case 4:
return "minecraft:dragon_head:4";
case 5:
return "minecraft:dragon_head:5";
case 6:
return "minecraft:dragon_head:6";
case 7:
return "minecraft:dragon_head:7";
case 8:
return "minecraft:dragon_head:8";
case 9:
return "minecraft:dragon_head:9";
case 10:
return "minecraft:dragon_head:10";
case 11:
return "minecraft:dragon_head:11";
case 12:
return "minecraft:dragon_head:12";
case 13:
return "minecraft:dragon_head:13";
case 14:
return "minecraft:dragon_head:14";
case 15:
return "minecraft:dragon_head:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
