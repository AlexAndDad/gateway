#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct moving_piston
{enum class facing_type : std::uint8_t
{
north,
east,
south,
west,
up,
down
} facing = facing_type::north;
enum class type_type : std::uint8_t
{
normal,
sticky
} type = type_type::normal;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (type)
{
case type_type::normal:
return 1399;
case type_type::sticky:
return 1400;
}
case facing_type::east:
switch (type)
{
case type_type::normal:
return 1401;
case type_type::sticky:
return 1402;
}
case facing_type::south:
switch (type)
{
case type_type::normal:
return 1403;
case type_type::sticky:
return 1404;
}
case facing_type::west:
switch (type)
{
case type_type::normal:
return 1405;
case type_type::sticky:
return 1406;
}
case facing_type::up:
switch (type)
{
case type_type::normal:
return 1407;
case type_type::sticky:
return 1408;
}
case facing_type::down:
switch (type)
{
case type_type::normal:
return 1409;
case type_type::sticky:
return 1410;
}
}
}
constexpr static moving_piston from_id(block_id_type id)
{
switch (id)
{
case 1399:
return {.facing = facing_type::north, .type = type_type::normal};
case 1400:
return {.facing = facing_type::north, .type = type_type::sticky};
case 1401:
return {.facing = facing_type::east, .type = type_type::normal};
case 1402:
return {.facing = facing_type::east, .type = type_type::sticky};
case 1403:
return {.facing = facing_type::south, .type = type_type::normal};
case 1404:
return {.facing = facing_type::south, .type = type_type::sticky};
case 1405:
return {.facing = facing_type::west, .type = type_type::normal};
case 1406:
return {.facing = facing_type::west, .type = type_type::sticky};
case 1407:
return {.facing = facing_type::up, .type = type_type::normal};
case 1408:
return {.facing = facing_type::up, .type = type_type::sticky};
case 1409:
return {.facing = facing_type::down, .type = type_type::normal};
case 1410:
return {.facing = facing_type::down, .type = type_type::sticky};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (type)
{
case type_type::normal:
return "minecraft:moving_piston:north:normal";
case type_type::sticky:
return "minecraft:moving_piston:north:sticky";
}
case facing_type::east:
switch (type)
{
case type_type::normal:
return "minecraft:moving_piston:east:normal";
case type_type::sticky:
return "minecraft:moving_piston:east:sticky";
}
case facing_type::south:
switch (type)
{
case type_type::normal:
return "minecraft:moving_piston:south:normal";
case type_type::sticky:
return "minecraft:moving_piston:south:sticky";
}
case facing_type::west:
switch (type)
{
case type_type::normal:
return "minecraft:moving_piston:west:normal";
case type_type::sticky:
return "minecraft:moving_piston:west:sticky";
}
case facing_type::up:
switch (type)
{
case type_type::normal:
return "minecraft:moving_piston:up:normal";
case type_type::sticky:
return "minecraft:moving_piston:up:sticky";
}
case facing_type::down:
switch (type)
{
case type_type::normal:
return "minecraft:moving_piston:down:normal";
case type_type::sticky:
return "minecraft:moving_piston:down:sticky";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
