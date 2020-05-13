#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jungle_leaves
{std::uint8_t distance = 7;
bool persistent = false;
constexpr block_id_type to_id() const {
switch (distance)
{
case 1:
switch (persistent)
{
case true:
return 186;
case false:
return 187;
}
case 2:
switch (persistent)
{
case true:
return 188;
case false:
return 189;
}
case 3:
switch (persistent)
{
case true:
return 190;
case false:
return 191;
}
case 4:
switch (persistent)
{
case true:
return 192;
case false:
return 193;
}
case 5:
switch (persistent)
{
case true:
return 194;
case false:
return 195;
}
case 6:
switch (persistent)
{
case true:
return 196;
case false:
return 197;
}
case 7:
switch (persistent)
{
case true:
return 198;
case false:
return 199;
}
}
}
constexpr static jungle_leaves from_id(block_id_type id)
{
switch (id)
{
case 186:
return {.distance = 1, .persistent = true};
case 187:
return {.distance = 1, .persistent = false};
case 188:
return {.distance = 2, .persistent = true};
case 189:
return {.distance = 2, .persistent = false};
case 190:
return {.distance = 3, .persistent = true};
case 191:
return {.distance = 3, .persistent = false};
case 192:
return {.distance = 4, .persistent = true};
case 193:
return {.distance = 4, .persistent = false};
case 194:
return {.distance = 5, .persistent = true};
case 195:
return {.distance = 5, .persistent = false};
case 196:
return {.distance = 6, .persistent = true};
case 197:
return {.distance = 6, .persistent = false};
case 198:
return {.distance = 7, .persistent = true};
case 199:
return {.distance = 7, .persistent = false};
}}
constexpr std::string_view to_string() const
{switch (distance)
{
case 1:
switch (persistent)
{
case true:
return "minecraft:jungle_leaves:1:true";
case false:
return "minecraft:jungle_leaves:1:false";
}
case 2:
switch (persistent)
{
case true:
return "minecraft:jungle_leaves:2:true";
case false:
return "minecraft:jungle_leaves:2:false";
}
case 3:
switch (persistent)
{
case true:
return "minecraft:jungle_leaves:3:true";
case false:
return "minecraft:jungle_leaves:3:false";
}
case 4:
switch (persistent)
{
case true:
return "minecraft:jungle_leaves:4:true";
case false:
return "minecraft:jungle_leaves:4:false";
}
case 5:
switch (persistent)
{
case true:
return "minecraft:jungle_leaves:5:true";
case false:
return "minecraft:jungle_leaves:5:false";
}
case 6:
switch (persistent)
{
case true:
return "minecraft:jungle_leaves:6:true";
case false:
return "minecraft:jungle_leaves:6:false";
}
case 7:
switch (persistent)
{
case true:
return "minecraft:jungle_leaves:7:true";
case false:
return "minecraft:jungle_leaves:7:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
