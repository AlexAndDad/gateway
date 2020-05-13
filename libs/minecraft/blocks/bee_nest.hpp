#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct bee_nest
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
std::uint8_t honey_level = 0;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (honey_level)
{
case 0:
return 11287;
case 1:
return 11288;
case 2:
return 11289;
case 3:
return 11290;
case 4:
return 11291;
case 5:
return 11292;
}
case facing_type::south:
switch (honey_level)
{
case 0:
return 11293;
case 1:
return 11294;
case 2:
return 11295;
case 3:
return 11296;
case 4:
return 11297;
case 5:
return 11298;
}
case facing_type::west:
switch (honey_level)
{
case 0:
return 11299;
case 1:
return 11300;
case 2:
return 11301;
case 3:
return 11302;
case 4:
return 11303;
case 5:
return 11304;
}
case facing_type::east:
switch (honey_level)
{
case 0:
return 11305;
case 1:
return 11306;
case 2:
return 11307;
case 3:
return 11308;
case 4:
return 11309;
case 5:
return 11310;
}
}
}
constexpr static bee_nest from_id(block_id_type id)
{
switch (id)
{
case 11287:
return {.facing = facing_type::north, .honey_level = 0};
case 11288:
return {.facing = facing_type::north, .honey_level = 1};
case 11289:
return {.facing = facing_type::north, .honey_level = 2};
case 11290:
return {.facing = facing_type::north, .honey_level = 3};
case 11291:
return {.facing = facing_type::north, .honey_level = 4};
case 11292:
return {.facing = facing_type::north, .honey_level = 5};
case 11293:
return {.facing = facing_type::south, .honey_level = 0};
case 11294:
return {.facing = facing_type::south, .honey_level = 1};
case 11295:
return {.facing = facing_type::south, .honey_level = 2};
case 11296:
return {.facing = facing_type::south, .honey_level = 3};
case 11297:
return {.facing = facing_type::south, .honey_level = 4};
case 11298:
return {.facing = facing_type::south, .honey_level = 5};
case 11299:
return {.facing = facing_type::west, .honey_level = 0};
case 11300:
return {.facing = facing_type::west, .honey_level = 1};
case 11301:
return {.facing = facing_type::west, .honey_level = 2};
case 11302:
return {.facing = facing_type::west, .honey_level = 3};
case 11303:
return {.facing = facing_type::west, .honey_level = 4};
case 11304:
return {.facing = facing_type::west, .honey_level = 5};
case 11305:
return {.facing = facing_type::east, .honey_level = 0};
case 11306:
return {.facing = facing_type::east, .honey_level = 1};
case 11307:
return {.facing = facing_type::east, .honey_level = 2};
case 11308:
return {.facing = facing_type::east, .honey_level = 3};
case 11309:
return {.facing = facing_type::east, .honey_level = 4};
case 11310:
return {.facing = facing_type::east, .honey_level = 5};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (honey_level)
{
case 0:
return "minecraft:bee_nest:north:0";
case 1:
return "minecraft:bee_nest:north:1";
case 2:
return "minecraft:bee_nest:north:2";
case 3:
return "minecraft:bee_nest:north:3";
case 4:
return "minecraft:bee_nest:north:4";
case 5:
return "minecraft:bee_nest:north:5";
}
case facing_type::south:
switch (honey_level)
{
case 0:
return "minecraft:bee_nest:south:0";
case 1:
return "minecraft:bee_nest:south:1";
case 2:
return "minecraft:bee_nest:south:2";
case 3:
return "minecraft:bee_nest:south:3";
case 4:
return "minecraft:bee_nest:south:4";
case 5:
return "minecraft:bee_nest:south:5";
}
case facing_type::west:
switch (honey_level)
{
case 0:
return "minecraft:bee_nest:west:0";
case 1:
return "minecraft:bee_nest:west:1";
case 2:
return "minecraft:bee_nest:west:2";
case 3:
return "minecraft:bee_nest:west:3";
case 4:
return "minecraft:bee_nest:west:4";
case 5:
return "minecraft:bee_nest:west:5";
}
case facing_type::east:
switch (honey_level)
{
case 0:
return "minecraft:bee_nest:east:0";
case 1:
return "minecraft:bee_nest:east:1";
case 2:
return "minecraft:bee_nest:east:2";
case 3:
return "minecraft:bee_nest:east:3";
case 4:
return "minecraft:bee_nest:east:4";
case 5:
return "minecraft:bee_nest:east:5";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
