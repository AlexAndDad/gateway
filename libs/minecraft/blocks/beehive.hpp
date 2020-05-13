#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct beehive
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
return 11311;
case 1:
return 11312;
case 2:
return 11313;
case 3:
return 11314;
case 4:
return 11315;
case 5:
return 11316;
}
case facing_type::south:
switch (honey_level)
{
case 0:
return 11317;
case 1:
return 11318;
case 2:
return 11319;
case 3:
return 11320;
case 4:
return 11321;
case 5:
return 11322;
}
case facing_type::west:
switch (honey_level)
{
case 0:
return 11323;
case 1:
return 11324;
case 2:
return 11325;
case 3:
return 11326;
case 4:
return 11327;
case 5:
return 11328;
}
case facing_type::east:
switch (honey_level)
{
case 0:
return 11329;
case 1:
return 11330;
case 2:
return 11331;
case 3:
return 11332;
case 4:
return 11333;
case 5:
return 11334;
}
}
}
constexpr static beehive from_id(block_id_type id)
{
switch (id)
{
case 11311:
return {.facing = facing_type::north, .honey_level = 0};
case 11312:
return {.facing = facing_type::north, .honey_level = 1};
case 11313:
return {.facing = facing_type::north, .honey_level = 2};
case 11314:
return {.facing = facing_type::north, .honey_level = 3};
case 11315:
return {.facing = facing_type::north, .honey_level = 4};
case 11316:
return {.facing = facing_type::north, .honey_level = 5};
case 11317:
return {.facing = facing_type::south, .honey_level = 0};
case 11318:
return {.facing = facing_type::south, .honey_level = 1};
case 11319:
return {.facing = facing_type::south, .honey_level = 2};
case 11320:
return {.facing = facing_type::south, .honey_level = 3};
case 11321:
return {.facing = facing_type::south, .honey_level = 4};
case 11322:
return {.facing = facing_type::south, .honey_level = 5};
case 11323:
return {.facing = facing_type::west, .honey_level = 0};
case 11324:
return {.facing = facing_type::west, .honey_level = 1};
case 11325:
return {.facing = facing_type::west, .honey_level = 2};
case 11326:
return {.facing = facing_type::west, .honey_level = 3};
case 11327:
return {.facing = facing_type::west, .honey_level = 4};
case 11328:
return {.facing = facing_type::west, .honey_level = 5};
case 11329:
return {.facing = facing_type::east, .honey_level = 0};
case 11330:
return {.facing = facing_type::east, .honey_level = 1};
case 11331:
return {.facing = facing_type::east, .honey_level = 2};
case 11332:
return {.facing = facing_type::east, .honey_level = 3};
case 11333:
return {.facing = facing_type::east, .honey_level = 4};
case 11334:
return {.facing = facing_type::east, .honey_level = 5};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (honey_level)
{
case 0:
return "minecraft:beehive:north:0";
case 1:
return "minecraft:beehive:north:1";
case 2:
return "minecraft:beehive:north:2";
case 3:
return "minecraft:beehive:north:3";
case 4:
return "minecraft:beehive:north:4";
case 5:
return "minecraft:beehive:north:5";
}
case facing_type::south:
switch (honey_level)
{
case 0:
return "minecraft:beehive:south:0";
case 1:
return "minecraft:beehive:south:1";
case 2:
return "minecraft:beehive:south:2";
case 3:
return "minecraft:beehive:south:3";
case 4:
return "minecraft:beehive:south:4";
case 5:
return "minecraft:beehive:south:5";
}
case facing_type::west:
switch (honey_level)
{
case 0:
return "minecraft:beehive:west:0";
case 1:
return "minecraft:beehive:west:1";
case 2:
return "minecraft:beehive:west:2";
case 3:
return "minecraft:beehive:west:3";
case 4:
return "minecraft:beehive:west:4";
case 5:
return "minecraft:beehive:west:5";
}
case facing_type::east:
switch (honey_level)
{
case 0:
return "minecraft:beehive:east:0";
case 1:
return "minecraft:beehive:east:1";
case 2:
return "minecraft:beehive:east:2";
case 3:
return "minecraft:beehive:east:3";
case 4:
return "minecraft:beehive:east:4";
case 5:
return "minecraft:beehive:east:5";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
