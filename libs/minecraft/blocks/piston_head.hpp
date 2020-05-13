#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct piston_head
{enum class facing_type : std::uint8_t
{
north,
east,
south,
west,
up,
down
} facing = facing_type::north;
bool short_ = false;
enum class type_type : std::uint8_t
{
normal,
sticky
} type = type_type::normal;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (short_)
{
case true:
switch (type)
{
case type_type::normal:
return 1359;
case type_type::sticky:
return 1360;
}
case false:
switch (type)
{
case type_type::normal:
return 1361;
case type_type::sticky:
return 1362;
}
}
case facing_type::east:
switch (short_)
{
case true:
switch (type)
{
case type_type::normal:
return 1363;
case type_type::sticky:
return 1364;
}
case false:
switch (type)
{
case type_type::normal:
return 1365;
case type_type::sticky:
return 1366;
}
}
case facing_type::south:
switch (short_)
{
case true:
switch (type)
{
case type_type::normal:
return 1367;
case type_type::sticky:
return 1368;
}
case false:
switch (type)
{
case type_type::normal:
return 1369;
case type_type::sticky:
return 1370;
}
}
case facing_type::west:
switch (short_)
{
case true:
switch (type)
{
case type_type::normal:
return 1371;
case type_type::sticky:
return 1372;
}
case false:
switch (type)
{
case type_type::normal:
return 1373;
case type_type::sticky:
return 1374;
}
}
case facing_type::up:
switch (short_)
{
case true:
switch (type)
{
case type_type::normal:
return 1375;
case type_type::sticky:
return 1376;
}
case false:
switch (type)
{
case type_type::normal:
return 1377;
case type_type::sticky:
return 1378;
}
}
case facing_type::down:
switch (short_)
{
case true:
switch (type)
{
case type_type::normal:
return 1379;
case type_type::sticky:
return 1380;
}
case false:
switch (type)
{
case type_type::normal:
return 1381;
case type_type::sticky:
return 1382;
}
}
}
}
constexpr static piston_head from_id(block_id_type id)
{
switch (id)
{
case 1359:
return {.facing = facing_type::north, .short_ = true, .type = type_type::normal};
case 1360:
return {.facing = facing_type::north, .short_ = true, .type = type_type::sticky};
case 1361:
return {.facing = facing_type::north, .short_ = false, .type = type_type::normal};
case 1362:
return {.facing = facing_type::north, .short_ = false, .type = type_type::sticky};
case 1363:
return {.facing = facing_type::east, .short_ = true, .type = type_type::normal};
case 1364:
return {.facing = facing_type::east, .short_ = true, .type = type_type::sticky};
case 1365:
return {.facing = facing_type::east, .short_ = false, .type = type_type::normal};
case 1366:
return {.facing = facing_type::east, .short_ = false, .type = type_type::sticky};
case 1367:
return {.facing = facing_type::south, .short_ = true, .type = type_type::normal};
case 1368:
return {.facing = facing_type::south, .short_ = true, .type = type_type::sticky};
case 1369:
return {.facing = facing_type::south, .short_ = false, .type = type_type::normal};
case 1370:
return {.facing = facing_type::south, .short_ = false, .type = type_type::sticky};
case 1371:
return {.facing = facing_type::west, .short_ = true, .type = type_type::normal};
case 1372:
return {.facing = facing_type::west, .short_ = true, .type = type_type::sticky};
case 1373:
return {.facing = facing_type::west, .short_ = false, .type = type_type::normal};
case 1374:
return {.facing = facing_type::west, .short_ = false, .type = type_type::sticky};
case 1375:
return {.facing = facing_type::up, .short_ = true, .type = type_type::normal};
case 1376:
return {.facing = facing_type::up, .short_ = true, .type = type_type::sticky};
case 1377:
return {.facing = facing_type::up, .short_ = false, .type = type_type::normal};
case 1378:
return {.facing = facing_type::up, .short_ = false, .type = type_type::sticky};
case 1379:
return {.facing = facing_type::down, .short_ = true, .type = type_type::normal};
case 1380:
return {.facing = facing_type::down, .short_ = true, .type = type_type::sticky};
case 1381:
return {.facing = facing_type::down, .short_ = false, .type = type_type::normal};
case 1382:
return {.facing = facing_type::down, .short_ = false, .type = type_type::sticky};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (short_)
{
case true:
switch (type)
{
case type_type::normal:
return "minecraft:piston_head:north:true:normal";
case type_type::sticky:
return "minecraft:piston_head:north:true:sticky";
}
case false:
switch (type)
{
case type_type::normal:
return "minecraft:piston_head:north:false:normal";
case type_type::sticky:
return "minecraft:piston_head:north:false:sticky";
}
}
case facing_type::east:
switch (short_)
{
case true:
switch (type)
{
case type_type::normal:
return "minecraft:piston_head:east:true:normal";
case type_type::sticky:
return "minecraft:piston_head:east:true:sticky";
}
case false:
switch (type)
{
case type_type::normal:
return "minecraft:piston_head:east:false:normal";
case type_type::sticky:
return "minecraft:piston_head:east:false:sticky";
}
}
case facing_type::south:
switch (short_)
{
case true:
switch (type)
{
case type_type::normal:
return "minecraft:piston_head:south:true:normal";
case type_type::sticky:
return "minecraft:piston_head:south:true:sticky";
}
case false:
switch (type)
{
case type_type::normal:
return "minecraft:piston_head:south:false:normal";
case type_type::sticky:
return "minecraft:piston_head:south:false:sticky";
}
}
case facing_type::west:
switch (short_)
{
case true:
switch (type)
{
case type_type::normal:
return "minecraft:piston_head:west:true:normal";
case type_type::sticky:
return "minecraft:piston_head:west:true:sticky";
}
case false:
switch (type)
{
case type_type::normal:
return "minecraft:piston_head:west:false:normal";
case type_type::sticky:
return "minecraft:piston_head:west:false:sticky";
}
}
case facing_type::up:
switch (short_)
{
case true:
switch (type)
{
case type_type::normal:
return "minecraft:piston_head:up:true:normal";
case type_type::sticky:
return "minecraft:piston_head:up:true:sticky";
}
case false:
switch (type)
{
case type_type::normal:
return "minecraft:piston_head:up:false:normal";
case type_type::sticky:
return "minecraft:piston_head:up:false:sticky";
}
}
case facing_type::down:
switch (short_)
{
case true:
switch (type)
{
case type_type::normal:
return "minecraft:piston_head:down:true:normal";
case type_type::sticky:
return "minecraft:piston_head:down:true:sticky";
}
case false:
switch (type)
{
case type_type::normal:
return "minecraft:piston_head:down:false:normal";
case type_type::sticky:
return "minecraft:piston_head:down:false:sticky";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
