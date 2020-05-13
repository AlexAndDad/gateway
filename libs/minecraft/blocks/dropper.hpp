#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dropper
{enum class facing_type : std::uint8_t
{
north,
east,
south,
west,
up,
down
} facing = facing_type::north;
bool triggered = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (triggered)
{
case true:
return 6299;
case false:
return 6300;
}
case facing_type::east:
switch (triggered)
{
case true:
return 6301;
case false:
return 6302;
}
case facing_type::south:
switch (triggered)
{
case true:
return 6303;
case false:
return 6304;
}
case facing_type::west:
switch (triggered)
{
case true:
return 6305;
case false:
return 6306;
}
case facing_type::up:
switch (triggered)
{
case true:
return 6307;
case false:
return 6308;
}
case facing_type::down:
switch (triggered)
{
case true:
return 6309;
case false:
return 6310;
}
}
}
constexpr static dropper from_id(block_id_type id)
{
switch (id)
{
case 6299:
return {.facing = facing_type::north, .triggered = true};
case 6300:
return {.facing = facing_type::north, .triggered = false};
case 6301:
return {.facing = facing_type::east, .triggered = true};
case 6302:
return {.facing = facing_type::east, .triggered = false};
case 6303:
return {.facing = facing_type::south, .triggered = true};
case 6304:
return {.facing = facing_type::south, .triggered = false};
case 6305:
return {.facing = facing_type::west, .triggered = true};
case 6306:
return {.facing = facing_type::west, .triggered = false};
case 6307:
return {.facing = facing_type::up, .triggered = true};
case 6308:
return {.facing = facing_type::up, .triggered = false};
case 6309:
return {.facing = facing_type::down, .triggered = true};
case 6310:
return {.facing = facing_type::down, .triggered = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (triggered)
{
case true:
return "minecraft:dropper:north:true";
case false:
return "minecraft:dropper:north:false";
}
case facing_type::east:
switch (triggered)
{
case true:
return "minecraft:dropper:east:true";
case false:
return "minecraft:dropper:east:false";
}
case facing_type::south:
switch (triggered)
{
case true:
return "minecraft:dropper:south:true";
case false:
return "minecraft:dropper:south:false";
}
case facing_type::west:
switch (triggered)
{
case true:
return "minecraft:dropper:west:true";
case false:
return "minecraft:dropper:west:false";
}
case facing_type::up:
switch (triggered)
{
case true:
return "minecraft:dropper:up:true";
case false:
return "minecraft:dropper:up:false";
}
case facing_type::down:
switch (triggered)
{
case true:
return "minecraft:dropper:down:true";
case false:
return "minecraft:dropper:down:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
