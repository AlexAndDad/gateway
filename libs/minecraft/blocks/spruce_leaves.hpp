#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct spruce_leaves
{std::uint8_t distance = 7;
bool persistent = false;
constexpr block_id_type to_id() const {
switch (distance)
{
case 1:
switch (persistent)
{
case true:
return 158;
case false:
return 159;
}
case 2:
switch (persistent)
{
case true:
return 160;
case false:
return 161;
}
case 3:
switch (persistent)
{
case true:
return 162;
case false:
return 163;
}
case 4:
switch (persistent)
{
case true:
return 164;
case false:
return 165;
}
case 5:
switch (persistent)
{
case true:
return 166;
case false:
return 167;
}
case 6:
switch (persistent)
{
case true:
return 168;
case false:
return 169;
}
case 7:
switch (persistent)
{
case true:
return 170;
case false:
return 171;
}
}
}
constexpr static spruce_leaves from_id(block_id_type id)
{
switch (id)
{
case 158:
return {.distance = 1, .persistent = true};
case 159:
return {.distance = 1, .persistent = false};
case 160:
return {.distance = 2, .persistent = true};
case 161:
return {.distance = 2, .persistent = false};
case 162:
return {.distance = 3, .persistent = true};
case 163:
return {.distance = 3, .persistent = false};
case 164:
return {.distance = 4, .persistent = true};
case 165:
return {.distance = 4, .persistent = false};
case 166:
return {.distance = 5, .persistent = true};
case 167:
return {.distance = 5, .persistent = false};
case 168:
return {.distance = 6, .persistent = true};
case 169:
return {.distance = 6, .persistent = false};
case 170:
return {.distance = 7, .persistent = true};
case 171:
return {.distance = 7, .persistent = false};
}}
constexpr std::string_view to_string() const
{switch (distance)
{
case 1:
switch (persistent)
{
case true:
return "minecraft:spruce_leaves:1:true";
case false:
return "minecraft:spruce_leaves:1:false";
}
case 2:
switch (persistent)
{
case true:
return "minecraft:spruce_leaves:2:true";
case false:
return "minecraft:spruce_leaves:2:false";
}
case 3:
switch (persistent)
{
case true:
return "minecraft:spruce_leaves:3:true";
case false:
return "minecraft:spruce_leaves:3:false";
}
case 4:
switch (persistent)
{
case true:
return "minecraft:spruce_leaves:4:true";
case false:
return "minecraft:spruce_leaves:4:false";
}
case 5:
switch (persistent)
{
case true:
return "minecraft:spruce_leaves:5:true";
case false:
return "minecraft:spruce_leaves:5:false";
}
case 6:
switch (persistent)
{
case true:
return "minecraft:spruce_leaves:6:true";
case false:
return "minecraft:spruce_leaves:6:false";
}
case 7:
switch (persistent)
{
case true:
return "minecraft:spruce_leaves:7:true";
case false:
return "minecraft:spruce_leaves:7:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
