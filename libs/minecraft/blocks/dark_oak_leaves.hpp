#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dark_oak_leaves
{std::uint8_t distance = 7;
bool persistent = false;
constexpr block_id_type to_id() const {
switch (distance)
{
case 1:
switch (persistent)
{
case true:
return 214;
case false:
return 215;
}
case 2:
switch (persistent)
{
case true:
return 216;
case false:
return 217;
}
case 3:
switch (persistent)
{
case true:
return 218;
case false:
return 219;
}
case 4:
switch (persistent)
{
case true:
return 220;
case false:
return 221;
}
case 5:
switch (persistent)
{
case true:
return 222;
case false:
return 223;
}
case 6:
switch (persistent)
{
case true:
return 224;
case false:
return 225;
}
case 7:
switch (persistent)
{
case true:
return 226;
case false:
return 227;
}
}
}
constexpr static dark_oak_leaves from_id(block_id_type id)
{
switch (id)
{
case 214:
return {.distance = 1, .persistent = true};
case 215:
return {.distance = 1, .persistent = false};
case 216:
return {.distance = 2, .persistent = true};
case 217:
return {.distance = 2, .persistent = false};
case 218:
return {.distance = 3, .persistent = true};
case 219:
return {.distance = 3, .persistent = false};
case 220:
return {.distance = 4, .persistent = true};
case 221:
return {.distance = 4, .persistent = false};
case 222:
return {.distance = 5, .persistent = true};
case 223:
return {.distance = 5, .persistent = false};
case 224:
return {.distance = 6, .persistent = true};
case 225:
return {.distance = 6, .persistent = false};
case 226:
return {.distance = 7, .persistent = true};
case 227:
return {.distance = 7, .persistent = false};
}}
constexpr std::string_view to_string() const
{switch (distance)
{
case 1:
switch (persistent)
{
case true:
return "minecraft:dark_oak_leaves:1:true";
case false:
return "minecraft:dark_oak_leaves:1:false";
}
case 2:
switch (persistent)
{
case true:
return "minecraft:dark_oak_leaves:2:true";
case false:
return "minecraft:dark_oak_leaves:2:false";
}
case 3:
switch (persistent)
{
case true:
return "minecraft:dark_oak_leaves:3:true";
case false:
return "minecraft:dark_oak_leaves:3:false";
}
case 4:
switch (persistent)
{
case true:
return "minecraft:dark_oak_leaves:4:true";
case false:
return "minecraft:dark_oak_leaves:4:false";
}
case 5:
switch (persistent)
{
case true:
return "minecraft:dark_oak_leaves:5:true";
case false:
return "minecraft:dark_oak_leaves:5:false";
}
case 6:
switch (persistent)
{
case true:
return "minecraft:dark_oak_leaves:6:true";
case false:
return "minecraft:dark_oak_leaves:6:false";
}
case 7:
switch (persistent)
{
case true:
return "minecraft:dark_oak_leaves:7:true";
case false:
return "minecraft:dark_oak_leaves:7:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
