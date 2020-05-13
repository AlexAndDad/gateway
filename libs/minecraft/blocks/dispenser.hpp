#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dispenser
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
return 233;
case false:
return 234;
}
case facing_type::east:
switch (triggered)
{
case true:
return 235;
case false:
return 236;
}
case facing_type::south:
switch (triggered)
{
case true:
return 237;
case false:
return 238;
}
case facing_type::west:
switch (triggered)
{
case true:
return 239;
case false:
return 240;
}
case facing_type::up:
switch (triggered)
{
case true:
return 241;
case false:
return 242;
}
case facing_type::down:
switch (triggered)
{
case true:
return 243;
case false:
return 244;
}
}
}
constexpr static dispenser from_id(block_id_type id)
{
switch (id)
{
case 233:
return {.facing = facing_type::north, .triggered = true};
case 234:
return {.facing = facing_type::north, .triggered = false};
case 235:
return {.facing = facing_type::east, .triggered = true};
case 236:
return {.facing = facing_type::east, .triggered = false};
case 237:
return {.facing = facing_type::south, .triggered = true};
case 238:
return {.facing = facing_type::south, .triggered = false};
case 239:
return {.facing = facing_type::west, .triggered = true};
case 240:
return {.facing = facing_type::west, .triggered = false};
case 241:
return {.facing = facing_type::up, .triggered = true};
case 242:
return {.facing = facing_type::up, .triggered = false};
case 243:
return {.facing = facing_type::down, .triggered = true};
case 244:
return {.facing = facing_type::down, .triggered = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (triggered)
{
case true:
return "minecraft:dispenser:north:true";
case false:
return "minecraft:dispenser:north:false";
}
case facing_type::east:
switch (triggered)
{
case true:
return "minecraft:dispenser:east:true";
case false:
return "minecraft:dispenser:east:false";
}
case facing_type::south:
switch (triggered)
{
case true:
return "minecraft:dispenser:south:true";
case false:
return "minecraft:dispenser:south:false";
}
case facing_type::west:
switch (triggered)
{
case true:
return "minecraft:dispenser:west:true";
case false:
return "minecraft:dispenser:west:false";
}
case facing_type::up:
switch (triggered)
{
case true:
return "minecraft:dispenser:up:true";
case false:
return "minecraft:dispenser:up:false";
}
case facing_type::down:
switch (triggered)
{
case true:
return "minecraft:dispenser:down:true";
case false:
return "minecraft:dispenser:down:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
