#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct skeleton_skull
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 5954;
case 1:
return 5955;
case 2:
return 5956;
case 3:
return 5957;
case 4:
return 5958;
case 5:
return 5959;
case 6:
return 5960;
case 7:
return 5961;
case 8:
return 5962;
case 9:
return 5963;
case 10:
return 5964;
case 11:
return 5965;
case 12:
return 5966;
case 13:
return 5967;
case 14:
return 5968;
case 15:
return 5969;
}
}
constexpr static skeleton_skull from_id(block_id_type id)
{
switch (id)
{
case 5954:
return {.rotation = 0};
case 5955:
return {.rotation = 1};
case 5956:
return {.rotation = 2};
case 5957:
return {.rotation = 3};
case 5958:
return {.rotation = 4};
case 5959:
return {.rotation = 5};
case 5960:
return {.rotation = 6};
case 5961:
return {.rotation = 7};
case 5962:
return {.rotation = 8};
case 5963:
return {.rotation = 9};
case 5964:
return {.rotation = 10};
case 5965:
return {.rotation = 11};
case 5966:
return {.rotation = 12};
case 5967:
return {.rotation = 13};
case 5968:
return {.rotation = 14};
case 5969:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:skeleton_skull:0";
case 1:
return "minecraft:skeleton_skull:1";
case 2:
return "minecraft:skeleton_skull:2";
case 3:
return "minecraft:skeleton_skull:3";
case 4:
return "minecraft:skeleton_skull:4";
case 5:
return "minecraft:skeleton_skull:5";
case 6:
return "minecraft:skeleton_skull:6";
case 7:
return "minecraft:skeleton_skull:7";
case 8:
return "minecraft:skeleton_skull:8";
case 9:
return "minecraft:skeleton_skull:9";
case 10:
return "minecraft:skeleton_skull:10";
case 11:
return "minecraft:skeleton_skull:11";
case 12:
return "minecraft:skeleton_skull:12";
case 13:
return "minecraft:skeleton_skull:13";
case 14:
return "minecraft:skeleton_skull:14";
case 15:
return "minecraft:skeleton_skull:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
