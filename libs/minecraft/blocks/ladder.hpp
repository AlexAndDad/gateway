#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct ladder
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (waterlogged)
{
case true:
return 3635;
case false:
return 3636;
}
case facing_type::south:
switch (waterlogged)
{
case true:
return 3637;
case false:
return 3638;
}
case facing_type::west:
switch (waterlogged)
{
case true:
return 3639;
case false:
return 3640;
}
case facing_type::east:
switch (waterlogged)
{
case true:
return 3641;
case false:
return 3642;
}
}
}
constexpr static ladder from_id(block_id_type id)
{
switch (id)
{
case 3635:
return {.facing = facing_type::north, .waterlogged = true};
case 3636:
return {.facing = facing_type::north, .waterlogged = false};
case 3637:
return {.facing = facing_type::south, .waterlogged = true};
case 3638:
return {.facing = facing_type::south, .waterlogged = false};
case 3639:
return {.facing = facing_type::west, .waterlogged = true};
case 3640:
return {.facing = facing_type::west, .waterlogged = false};
case 3641:
return {.facing = facing_type::east, .waterlogged = true};
case 3642:
return {.facing = facing_type::east, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (waterlogged)
{
case true:
return "minecraft:ladder:north:true";
case false:
return "minecraft:ladder:north:false";
}
case facing_type::south:
switch (waterlogged)
{
case true:
return "minecraft:ladder:south:true";
case false:
return "minecraft:ladder:south:false";
}
case facing_type::west:
switch (waterlogged)
{
case true:
return "minecraft:ladder:west:true";
case false:
return "minecraft:ladder:west:false";
}
case facing_type::east:
switch (waterlogged)
{
case true:
return "minecraft:ladder:east:true";
case false:
return "minecraft:ladder:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
