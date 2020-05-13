#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct magenta_stained_glass_pane
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
return 6391;
case false:
return 6392;
}
case false:
switch (west)
{
case true:
return 6393;
case false:
return 6394;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6395;
case false:
return 6396;
}
case false:
switch (west)
{
case true:
return 6397;
case false:
return 6398;
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
return 6399;
case false:
return 6400;
}
case false:
switch (west)
{
case true:
return 6401;
case false:
return 6402;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6403;
case false:
return 6404;
}
case false:
switch (west)
{
case true:
return 6405;
case false:
return 6406;
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
return 6407;
case false:
return 6408;
}
case false:
switch (west)
{
case true:
return 6409;
case false:
return 6410;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6411;
case false:
return 6412;
}
case false:
switch (west)
{
case true:
return 6413;
case false:
return 6414;
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
return 6415;
case false:
return 6416;
}
case false:
switch (west)
{
case true:
return 6417;
case false:
return 6418;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6419;
case false:
return 6420;
}
case false:
switch (west)
{
case true:
return 6421;
case false:
return 6422;
}
}
}
}
}
}
constexpr static magenta_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6391:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6392:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6393:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6394:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6395:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6396:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6397:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6398:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6399:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6400:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6401:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6402:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6403:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6404:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6405:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6406:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6407:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6408:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6409:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6410:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6411:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6412:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6413:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6414:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6415:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6416:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6417:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6418:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6419:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6420:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6421:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6422:
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
return "minecraft:magenta_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:magenta_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:magenta_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:magenta_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:magenta_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:magenta_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:magenta_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:magenta_stained_glass_pane:true:true:false:false:false";
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
return "minecraft:magenta_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:magenta_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:magenta_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:magenta_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:magenta_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:magenta_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:magenta_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:magenta_stained_glass_pane:true:false:false:false:false";
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
return "minecraft:magenta_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:magenta_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:magenta_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:magenta_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:magenta_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:magenta_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:magenta_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:magenta_stained_glass_pane:false:true:false:false:false";
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
return "minecraft:magenta_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:magenta_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:magenta_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:magenta_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:magenta_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:magenta_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:magenta_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:magenta_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
