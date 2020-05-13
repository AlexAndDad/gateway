#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct orange_stained_glass_pane
{bool east = false;
bool north = false;
bool south = false;
bool waterlogged = false;
bool west = false;
constexpr block_id_type to_id() const {
switch (east)
{
case true:
switch (north)
{
case true:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6359;
case false:
return 6360;
}
case false:
switch (west)
{
case true:
return 6361;
case false:
return 6362;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6363;
case false:
return 6364;
}
case false:
switch (west)
{
case true:
return 6365;
case false:
return 6366;
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6367;
case false:
return 6368;
}
case false:
switch (west)
{
case true:
return 6369;
case false:
return 6370;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6371;
case false:
return 6372;
}
case false:
switch (west)
{
case true:
return 6373;
case false:
return 6374;
}
}
}
}
case false:
switch (north)
{
case true:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6375;
case false:
return 6376;
}
case false:
switch (west)
{
case true:
return 6377;
case false:
return 6378;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6379;
case false:
return 6380;
}
case false:
switch (west)
{
case true:
return 6381;
case false:
return 6382;
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6383;
case false:
return 6384;
}
case false:
switch (west)
{
case true:
return 6385;
case false:
return 6386;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6387;
case false:
return 6388;
}
case false:
switch (west)
{
case true:
return 6389;
case false:
return 6390;
}
}
}
}
}
}
constexpr static orange_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6359:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6360:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6361:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6362:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6363:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6364:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6365:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6366:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6367:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6368:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6369:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6370:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6371:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6372:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6373:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6374:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6375:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6376:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6377:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6378:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6379:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6380:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6381:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6382:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6383:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6384:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6385:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6386:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6387:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6388:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6389:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6390:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = false};
}}
constexpr std::string_view to_string() const
{switch (east)
{
case true:
switch (north)
{
case true:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:orange_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:orange_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:orange_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:orange_stained_glass_pane:true:true:false:false:false";
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:orange_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:orange_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:orange_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:orange_stained_glass_pane:true:false:false:false:false";
}
}
}
}
case false:
switch (north)
{
case true:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:orange_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:orange_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:orange_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:orange_stained_glass_pane:false:true:false:false:false";
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:orange_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:orange_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:orange_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:orange_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:orange_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
