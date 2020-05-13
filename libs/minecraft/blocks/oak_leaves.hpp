#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct oak_leaves
{std::uint8_t distance = 7;
bool persistent = false;
constexpr block_id_type to_id() const {
switch (distance)
{
case 1:
switch (persistent)
{
case true:
return 144;
case false:
return 145;
}
case 2:
switch (persistent)
{
case true:
return 146;
case false:
return 147;
}
case 3:
switch (persistent)
{
case true:
return 148;
case false:
return 149;
}
case 4:
switch (persistent)
{
case true:
return 150;
case false:
return 151;
}
case 5:
switch (persistent)
{
case true:
return 152;
case false:
return 153;
}
case 6:
switch (persistent)
{
case true:
return 154;
case false:
return 155;
}
case 7:
switch (persistent)
{
case true:
return 156;
case false:
return 157;
}
}
}
constexpr static oak_leaves from_id(block_id_type id)
{
switch (id)
{
case 144:
return {.distance = 1, .persistent = true};
case 145:
return {.distance = 1, .persistent = false};
case 146:
return {.distance = 2, .persistent = true};
case 147:
return {.distance = 2, .persistent = false};
case 148:
return {.distance = 3, .persistent = true};
case 149:
return {.distance = 3, .persistent = false};
case 150:
return {.distance = 4, .persistent = true};
case 151:
return {.distance = 4, .persistent = false};
case 152:
return {.distance = 5, .persistent = true};
case 153:
return {.distance = 5, .persistent = false};
case 154:
return {.distance = 6, .persistent = true};
case 155:
return {.distance = 6, .persistent = false};
case 156:
return {.distance = 7, .persistent = true};
case 157:
return {.distance = 7, .persistent = false};
}}
constexpr std::string_view to_string() const
{switch (distance)
{
case 1:
switch (persistent)
{
case true:
return "minecraft:oak_leaves:1:true";
case false:
return "minecraft:oak_leaves:1:false";
}
case 2:
switch (persistent)
{
case true:
return "minecraft:oak_leaves:2:true";
case false:
return "minecraft:oak_leaves:2:false";
}
case 3:
switch (persistent)
{
case true:
return "minecraft:oak_leaves:3:true";
case false:
return "minecraft:oak_leaves:3:false";
}
case 4:
switch (persistent)
{
case true:
return "minecraft:oak_leaves:4:true";
case false:
return "minecraft:oak_leaves:4:false";
}
case 5:
switch (persistent)
{
case true:
return "minecraft:oak_leaves:5:true";
case false:
return "minecraft:oak_leaves:5:false";
}
case 6:
switch (persistent)
{
case true:
return "minecraft:oak_leaves:6:true";
case false:
return "minecraft:oak_leaves:6:false";
}
case 7:
switch (persistent)
{
case true:
return "minecraft:oak_leaves:7:true";
case false:
return "minecraft:oak_leaves:7:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
