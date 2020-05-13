#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct chipped_anvil
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
return 6078;
case facing_type::south:
return 6079;
case facing_type::west:
return 6080;
case facing_type::east:
return 6081;
}
}
constexpr static chipped_anvil from_id(block_id_type id)
{
switch (id)
{
case 6078:
return {.facing = facing_type::north};
case 6079:
return {.facing = facing_type::south};
case 6080:
return {.facing = facing_type::west};
case 6081:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:chipped_anvil:north";
case facing_type::south:
return "minecraft:chipped_anvil:south";
case facing_type::west:
return "minecraft:chipped_anvil:west";
case facing_type::east:
return "minecraft:chipped_anvil:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
