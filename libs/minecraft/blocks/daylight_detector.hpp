#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct daylight_detector
{bool inverted = false;
std::uint8_t power = 0;
constexpr block_id_type to_id() const {
switch (inverted)
{
case true:
switch (power)
{
case 0:
return 6158;
case 1:
return 6159;
case 2:
return 6160;
case 3:
return 6161;
case 4:
return 6162;
case 5:
return 6163;
case 6:
return 6164;
case 7:
return 6165;
case 8:
return 6166;
case 9:
return 6167;
case 10:
return 6168;
case 11:
return 6169;
case 12:
return 6170;
case 13:
return 6171;
case 14:
return 6172;
case 15:
return 6173;
}
case false:
switch (power)
{
case 0:
return 6174;
case 1:
return 6175;
case 2:
return 6176;
case 3:
return 6177;
case 4:
return 6178;
case 5:
return 6179;
case 6:
return 6180;
case 7:
return 6181;
case 8:
return 6182;
case 9:
return 6183;
case 10:
return 6184;
case 11:
return 6185;
case 12:
return 6186;
case 13:
return 6187;
case 14:
return 6188;
case 15:
return 6189;
}
}
}
constexpr static daylight_detector from_id(block_id_type id)
{
switch (id)
{
case 6158:
return {.inverted = true, .power = 0};
case 6159:
return {.inverted = true, .power = 1};
case 6160:
return {.inverted = true, .power = 2};
case 6161:
return {.inverted = true, .power = 3};
case 6162:
return {.inverted = true, .power = 4};
case 6163:
return {.inverted = true, .power = 5};
case 6164:
return {.inverted = true, .power = 6};
case 6165:
return {.inverted = true, .power = 7};
case 6166:
return {.inverted = true, .power = 8};
case 6167:
return {.inverted = true, .power = 9};
case 6168:
return {.inverted = true, .power = 10};
case 6169:
return {.inverted = true, .power = 11};
case 6170:
return {.inverted = true, .power = 12};
case 6171:
return {.inverted = true, .power = 13};
case 6172:
return {.inverted = true, .power = 14};
case 6173:
return {.inverted = true, .power = 15};
case 6174:
return {.inverted = false, .power = 0};
case 6175:
return {.inverted = false, .power = 1};
case 6176:
return {.inverted = false, .power = 2};
case 6177:
return {.inverted = false, .power = 3};
case 6178:
return {.inverted = false, .power = 4};
case 6179:
return {.inverted = false, .power = 5};
case 6180:
return {.inverted = false, .power = 6};
case 6181:
return {.inverted = false, .power = 7};
case 6182:
return {.inverted = false, .power = 8};
case 6183:
return {.inverted = false, .power = 9};
case 6184:
return {.inverted = false, .power = 10};
case 6185:
return {.inverted = false, .power = 11};
case 6186:
return {.inverted = false, .power = 12};
case 6187:
return {.inverted = false, .power = 13};
case 6188:
return {.inverted = false, .power = 14};
case 6189:
return {.inverted = false, .power = 15};
}}
constexpr std::string_view to_string() const
{switch (inverted)
{
case true:
switch (power)
{
case 0:
return "minecraft:daylight_detector:true:0";
case 1:
return "minecraft:daylight_detector:true:1";
case 2:
return "minecraft:daylight_detector:true:2";
case 3:
return "minecraft:daylight_detector:true:3";
case 4:
return "minecraft:daylight_detector:true:4";
case 5:
return "minecraft:daylight_detector:true:5";
case 6:
return "minecraft:daylight_detector:true:6";
case 7:
return "minecraft:daylight_detector:true:7";
case 8:
return "minecraft:daylight_detector:true:8";
case 9:
return "minecraft:daylight_detector:true:9";
case 10:
return "minecraft:daylight_detector:true:10";
case 11:
return "minecraft:daylight_detector:true:11";
case 12:
return "minecraft:daylight_detector:true:12";
case 13:
return "minecraft:daylight_detector:true:13";
case 14:
return "minecraft:daylight_detector:true:14";
case 15:
return "minecraft:daylight_detector:true:15";
}
case false:
switch (power)
{
case 0:
return "minecraft:daylight_detector:false:0";
case 1:
return "minecraft:daylight_detector:false:1";
case 2:
return "minecraft:daylight_detector:false:2";
case 3:
return "minecraft:daylight_detector:false:3";
case 4:
return "minecraft:daylight_detector:false:4";
case 5:
return "minecraft:daylight_detector:false:5";
case 6:
return "minecraft:daylight_detector:false:6";
case 7:
return "minecraft:daylight_detector:false:7";
case 8:
return "minecraft:daylight_detector:false:8";
case 9:
return "minecraft:daylight_detector:false:9";
case 10:
return "minecraft:daylight_detector:false:10";
case 11:
return "minecraft:daylight_detector:false:11";
case 12:
return "minecraft:daylight_detector:false:12";
case 13:
return "minecraft:daylight_detector:false:13";
case 14:
return "minecraft:daylight_detector:false:14";
case 15:
return "minecraft:daylight_detector:false:15";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
