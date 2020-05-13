#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct birch_leaves
{std::uint8_t distance = 7;
bool persistent = false;
constexpr block_id_type to_id() const {
switch (distance)
{
case 1:
switch (persistent)
{
case true:
return 172;
case false:
return 173;
}
case 2:
switch (persistent)
{
case true:
return 174;
case false:
return 175;
}
case 3:
switch (persistent)
{
case true:
return 176;
case false:
return 177;
}
case 4:
switch (persistent)
{
case true:
return 178;
case false:
return 179;
}
case 5:
switch (persistent)
{
case true:
return 180;
case false:
return 181;
}
case 6:
switch (persistent)
{
case true:
return 182;
case false:
return 183;
}
case 7:
switch (persistent)
{
case true:
return 184;
case false:
return 185;
}
}
}
constexpr static birch_leaves from_id(block_id_type id)
{
switch (id)
{
case 172:
return {.distance = 1, .persistent = true};
case 173:
return {.distance = 1, .persistent = false};
case 174:
return {.distance = 2, .persistent = true};
case 175:
return {.distance = 2, .persistent = false};
case 176:
return {.distance = 3, .persistent = true};
case 177:
return {.distance = 3, .persistent = false};
case 178:
return {.distance = 4, .persistent = true};
case 179:
return {.distance = 4, .persistent = false};
case 180:
return {.distance = 5, .persistent = true};
case 181:
return {.distance = 5, .persistent = false};
case 182:
return {.distance = 6, .persistent = true};
case 183:
return {.distance = 6, .persistent = false};
case 184:
return {.distance = 7, .persistent = true};
case 185:
return {.distance = 7, .persistent = false};
}}
constexpr std::string_view to_string() const
{switch (distance)
{
case 1:
switch (persistent)
{
case true:
return "minecraft:birch_leaves:1:true";
case false:
return "minecraft:birch_leaves:1:false";
}
case 2:
switch (persistent)
{
case true:
return "minecraft:birch_leaves:2:true";
case false:
return "minecraft:birch_leaves:2:false";
}
case 3:
switch (persistent)
{
case true:
return "minecraft:birch_leaves:3:true";
case false:
return "minecraft:birch_leaves:3:false";
}
case 4:
switch (persistent)
{
case true:
return "minecraft:birch_leaves:4:true";
case false:
return "minecraft:birch_leaves:4:false";
}
case 5:
switch (persistent)
{
case true:
return "minecraft:birch_leaves:5:true";
case false:
return "minecraft:birch_leaves:5:false";
}
case 6:
switch (persistent)
{
case true:
return "minecraft:birch_leaves:6:true";
case false:
return "minecraft:birch_leaves:6:false";
}
case 7:
switch (persistent)
{
case true:
return "minecraft:birch_leaves:7:true";
case false:
return "minecraft:birch_leaves:7:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
