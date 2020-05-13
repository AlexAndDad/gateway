#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct wither_skeleton_skull
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 5974;
case 1:
return 5975;
case 2:
return 5976;
case 3:
return 5977;
case 4:
return 5978;
case 5:
return 5979;
case 6:
return 5980;
case 7:
return 5981;
case 8:
return 5982;
case 9:
return 5983;
case 10:
return 5984;
case 11:
return 5985;
case 12:
return 5986;
case 13:
return 5987;
case 14:
return 5988;
case 15:
return 5989;
}
}
constexpr static wither_skeleton_skull from_id(block_id_type id)
{
switch (id)
{
case 5974:
return {.rotation = 0};
case 5975:
return {.rotation = 1};
case 5976:
return {.rotation = 2};
case 5977:
return {.rotation = 3};
case 5978:
return {.rotation = 4};
case 5979:
return {.rotation = 5};
case 5980:
return {.rotation = 6};
case 5981:
return {.rotation = 7};
case 5982:
return {.rotation = 8};
case 5983:
return {.rotation = 9};
case 5984:
return {.rotation = 10};
case 5985:
return {.rotation = 11};
case 5986:
return {.rotation = 12};
case 5987:
return {.rotation = 13};
case 5988:
return {.rotation = 14};
case 5989:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:wither_skeleton_skull:0";
case 1:
return "minecraft:wither_skeleton_skull:1";
case 2:
return "minecraft:wither_skeleton_skull:2";
case 3:
return "minecraft:wither_skeleton_skull:3";
case 4:
return "minecraft:wither_skeleton_skull:4";
case 5:
return "minecraft:wither_skeleton_skull:5";
case 6:
return "minecraft:wither_skeleton_skull:6";
case 7:
return "minecraft:wither_skeleton_skull:7";
case 8:
return "minecraft:wither_skeleton_skull:8";
case 9:
return "minecraft:wither_skeleton_skull:9";
case 10:
return "minecraft:wither_skeleton_skull:10";
case 11:
return "minecraft:wither_skeleton_skull:11";
case 12:
return "minecraft:wither_skeleton_skull:12";
case 13:
return "minecraft:wither_skeleton_skull:13";
case 14:
return "minecraft:wither_skeleton_skull:14";
case 15:
return "minecraft:wither_skeleton_skull:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
