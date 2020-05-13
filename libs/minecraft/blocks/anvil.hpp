#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct anvil
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
return 6074;
case facing_type::south:
return 6075;
case facing_type::west:
return 6076;
case facing_type::east:
return 6077;
}
}
constexpr static anvil from_id(block_id_type id)
{
switch (id)
{
case 6074:
return {.facing = facing_type::north};
case 6075:
return {.facing = facing_type::south};
case 6076:
return {.facing = facing_type::west};
case 6077:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:anvil:north";
case facing_type::south:
return "minecraft:anvil:south";
case facing_type::west:
return "minecraft:anvil:west";
case facing_type::east:
return "minecraft:anvil:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
