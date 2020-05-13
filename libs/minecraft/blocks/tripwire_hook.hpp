#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct tripwire_hook
{bool attached = false;
enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool powered = false;
constexpr block_id_type to_id() const {
switch (attached)
{
case true:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5243;
case false:
return 5244;
}
case facing_type::south:
switch (powered)
{
case true:
return 5245;
case false:
return 5246;
}
case facing_type::west:
switch (powered)
{
case true:
return 5247;
case false:
return 5248;
}
case facing_type::east:
switch (powered)
{
case true:
return 5249;
case false:
return 5250;
}
}
case false:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5251;
case false:
return 5252;
}
case facing_type::south:
switch (powered)
{
case true:
return 5253;
case false:
return 5254;
}
case facing_type::west:
switch (powered)
{
case true:
return 5255;
case false:
return 5256;
}
case facing_type::east:
switch (powered)
{
case true:
return 5257;
case false:
return 5258;
}
}
}
}
constexpr static tripwire_hook from_id(block_id_type id)
{
switch (id)
{
case 5243:
return {.attached = true, .facing = facing_type::north, .powered = true};
case 5244:
return {.attached = true, .facing = facing_type::north, .powered = false};
case 5245:
return {.attached = true, .facing = facing_type::south, .powered = true};
case 5246:
return {.attached = true, .facing = facing_type::south, .powered = false};
case 5247:
return {.attached = true, .facing = facing_type::west, .powered = true};
case 5248:
return {.attached = true, .facing = facing_type::west, .powered = false};
case 5249:
return {.attached = true, .facing = facing_type::east, .powered = true};
case 5250:
return {.attached = true, .facing = facing_type::east, .powered = false};
case 5251:
return {.attached = false, .facing = facing_type::north, .powered = true};
case 5252:
return {.attached = false, .facing = facing_type::north, .powered = false};
case 5253:
return {.attached = false, .facing = facing_type::south, .powered = true};
case 5254:
return {.attached = false, .facing = facing_type::south, .powered = false};
case 5255:
return {.attached = false, .facing = facing_type::west, .powered = true};
case 5256:
return {.attached = false, .facing = facing_type::west, .powered = false};
case 5257:
return {.attached = false, .facing = facing_type::east, .powered = true};
case 5258:
return {.attached = false, .facing = facing_type::east, .powered = false};
}}
constexpr std::string_view to_string() const
{switch (attached)
{
case true:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:tripwire_hook:true:north:true";
case false:
return "minecraft:tripwire_hook:true:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:tripwire_hook:true:south:true";
case false:
return "minecraft:tripwire_hook:true:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:tripwire_hook:true:west:true";
case false:
return "minecraft:tripwire_hook:true:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:tripwire_hook:true:east:true";
case false:
return "minecraft:tripwire_hook:true:east:false";
}
}
case false:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:tripwire_hook:false:north:true";
case false:
return "minecraft:tripwire_hook:false:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:tripwire_hook:false:south:true";
case false:
return "minecraft:tripwire_hook:false:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:tripwire_hook:false:west:true";
case false:
return "minecraft:tripwire_hook:false:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:tripwire_hook:false:east:true";
case false:
return "minecraft:tripwire_hook:false:east:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
