#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct white_glazed_terracotta
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
return 8838;
case facing_type::south:
return 8839;
case facing_type::west:
return 8840;
case facing_type::east:
return 8841;
}
}
constexpr static white_glazed_terracotta from_id(block_id_type id)
{
switch (id)
{
case 8838:
return {.facing = facing_type::north};
case 8839:
return {.facing = facing_type::south};
case 8840:
return {.facing = facing_type::west};
case 8841:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:white_glazed_terracotta:north";
case facing_type::south:
return "minecraft:white_glazed_terracotta:south";
case facing_type::west:
return "minecraft:white_glazed_terracotta:west";
case facing_type::east:
return "minecraft:white_glazed_terracotta:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
