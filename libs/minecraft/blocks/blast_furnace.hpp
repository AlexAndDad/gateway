#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct blast_furnace
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool lit = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (lit)
{
case true:
return 11155;
case false:
return 11156;
}
case facing_type::south:
switch (lit)
{
case true:
return 11157;
case false:
return 11158;
}
case facing_type::west:
switch (lit)
{
case true:
return 11159;
case false:
return 11160;
}
case facing_type::east:
switch (lit)
{
case true:
return 11161;
case false:
return 11162;
}
}
}
constexpr static blast_furnace from_id(block_id_type id)
{
switch (id)
{
case 11155:
return {.facing = facing_type::north, .lit = true};
case 11156:
return {.facing = facing_type::north, .lit = false};
case 11157:
return {.facing = facing_type::south, .lit = true};
case 11158:
return {.facing = facing_type::south, .lit = false};
case 11159:
return {.facing = facing_type::west, .lit = true};
case 11160:
return {.facing = facing_type::west, .lit = false};
case 11161:
return {.facing = facing_type::east, .lit = true};
case 11162:
return {.facing = facing_type::east, .lit = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (lit)
{
case true:
return "minecraft:blast_furnace:north:true";
case false:
return "minecraft:blast_furnace:north:false";
}
case facing_type::south:
switch (lit)
{
case true:
return "minecraft:blast_furnace:south:true";
case false:
return "minecraft:blast_furnace:south:false";
}
case facing_type::west:
switch (lit)
{
case true:
return "minecraft:blast_furnace:west:true";
case false:
return "minecraft:blast_furnace:west:false";
}
case facing_type::east:
switch (lit)
{
case true:
return "minecraft:blast_furnace:east:true";
case false:
return "minecraft:blast_furnace:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
