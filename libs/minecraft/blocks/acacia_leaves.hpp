#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct acacia_leaves
{std::uint8_t distance = 7;
bool persistent = false;
constexpr block_id_type to_id() const {
switch (distance)
{
case 1:
switch (persistent)
{
case true:
return 200;
case false:
return 201;
}
case 2:
switch (persistent)
{
case true:
return 202;
case false:
return 203;
}
case 3:
switch (persistent)
{
case true:
return 204;
case false:
return 205;
}
case 4:
switch (persistent)
{
case true:
return 206;
case false:
return 207;
}
case 5:
switch (persistent)
{
case true:
return 208;
case false:
return 209;
}
case 6:
switch (persistent)
{
case true:
return 210;
case false:
return 211;
}
case 7:
switch (persistent)
{
case true:
return 212;
case false:
return 213;
}
}
}
constexpr static acacia_leaves from_id(block_id_type id)
{
switch (id)
{
case 200:
return {.distance = 1, .persistent = true};
case 201:
return {.distance = 1, .persistent = false};
case 202:
return {.distance = 2, .persistent = true};
case 203:
return {.distance = 2, .persistent = false};
case 204:
return {.distance = 3, .persistent = true};
case 205:
return {.distance = 3, .persistent = false};
case 206:
return {.distance = 4, .persistent = true};
case 207:
return {.distance = 4, .persistent = false};
case 208:
return {.distance = 5, .persistent = true};
case 209:
return {.distance = 5, .persistent = false};
case 210:
return {.distance = 6, .persistent = true};
case 211:
return {.distance = 6, .persistent = false};
case 212:
return {.distance = 7, .persistent = true};
case 213:
return {.distance = 7, .persistent = false};
}}
constexpr std::string_view to_string() const
{switch (distance)
{
case 1:
switch (persistent)
{
case true:
return "minecraft:acacia_leaves:1:true";
case false:
return "minecraft:acacia_leaves:1:false";
}
case 2:
switch (persistent)
{
case true:
return "minecraft:acacia_leaves:2:true";
case false:
return "minecraft:acacia_leaves:2:false";
}
case 3:
switch (persistent)
{
case true:
return "minecraft:acacia_leaves:3:true";
case false:
return "minecraft:acacia_leaves:3:false";
}
case 4:
switch (persistent)
{
case true:
return "minecraft:acacia_leaves:4:true";
case false:
return "minecraft:acacia_leaves:4:false";
}
case 5:
switch (persistent)
{
case true:
return "minecraft:acacia_leaves:5:true";
case false:
return "minecraft:acacia_leaves:5:false";
}
case 6:
switch (persistent)
{
case true:
return "minecraft:acacia_leaves:6:true";
case false:
return "minecraft:acacia_leaves:6:false";
}
case 7:
switch (persistent)
{
case true:
return "minecraft:acacia_leaves:7:true";
case false:
return "minecraft:acacia_leaves:7:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
