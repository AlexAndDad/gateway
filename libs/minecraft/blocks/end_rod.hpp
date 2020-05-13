#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct end_rod
{enum class facing_type : std::uint8_t
{
north,
east,
south,
west,
up,
down
} facing = facing_type::up;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
return 8522;
case facing_type::east:
return 8523;
case facing_type::south:
return 8524;
case facing_type::west:
return 8525;
case facing_type::up:
return 8526;
case facing_type::down:
return 8527;
}
}
constexpr static end_rod from_id(block_id_type id)
{
switch (id)
{
case 8522:
return {.facing = facing_type::north};
case 8523:
return {.facing = facing_type::east};
case 8524:
return {.facing = facing_type::south};
case 8525:
return {.facing = facing_type::west};
case 8526:
return {.facing = facing_type::up};
case 8527:
return {.facing = facing_type::down};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:end_rod:north";
case facing_type::east:
return "minecraft:end_rod:east";
case facing_type::south:
return "minecraft:end_rod:south";
case facing_type::west:
return "minecraft:end_rod:west";
case facing_type::up:
return "minecraft:end_rod:up";
case facing_type::down:
return "minecraft:end_rod:down";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
