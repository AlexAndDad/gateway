#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct observer
{enum class facing_type : std::uint8_t
{
north,
east,
south,
west,
up,
down
} facing = facing_type::south;
bool powered = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 8724;
case false:
return 8725;
}
case facing_type::east:
switch (powered)
{
case true:
return 8726;
case false:
return 8727;
}
case facing_type::south:
switch (powered)
{
case true:
return 8728;
case false:
return 8729;
}
case facing_type::west:
switch (powered)
{
case true:
return 8730;
case false:
return 8731;
}
case facing_type::up:
switch (powered)
{
case true:
return 8732;
case false:
return 8733;
}
case facing_type::down:
switch (powered)
{
case true:
return 8734;
case false:
return 8735;
}
}
}
constexpr static observer from_id(block_id_type id)
{
switch (id)
{
case 8724:
return {.facing = facing_type::north, .powered = true};
case 8725:
return {.facing = facing_type::north, .powered = false};
case 8726:
return {.facing = facing_type::east, .powered = true};
case 8727:
return {.facing = facing_type::east, .powered = false};
case 8728:
return {.facing = facing_type::south, .powered = true};
case 8729:
return {.facing = facing_type::south, .powered = false};
case 8730:
return {.facing = facing_type::west, .powered = true};
case 8731:
return {.facing = facing_type::west, .powered = false};
case 8732:
return {.facing = facing_type::up, .powered = true};
case 8733:
return {.facing = facing_type::up, .powered = false};
case 8734:
return {.facing = facing_type::down, .powered = true};
case 8735:
return {.facing = facing_type::down, .powered = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:observer:north:true";
case false:
return "minecraft:observer:north:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:observer:east:true";
case false:
return "minecraft:observer:east:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:observer:south:true";
case false:
return "minecraft:observer:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:observer:west:true";
case false:
return "minecraft:observer:west:false";
}
case facing_type::up:
switch (powered)
{
case true:
return "minecraft:observer:up:true";
case false:
return "minecraft:observer:up:false";
}
case facing_type::down:
switch (powered)
{
case true:
return "minecraft:observer:down:true";
case false:
return "minecraft:observer:down:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
