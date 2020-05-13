#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct birch_sign
{std::uint8_t rotation = 0;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
switch (waterlogged)
{
case true:
return 3443;
case false:
return 3444;
}
case 1:
switch (waterlogged)
{
case true:
return 3445;
case false:
return 3446;
}
case 2:
switch (waterlogged)
{
case true:
return 3447;
case false:
return 3448;
}
case 3:
switch (waterlogged)
{
case true:
return 3449;
case false:
return 3450;
}
case 4:
switch (waterlogged)
{
case true:
return 3451;
case false:
return 3452;
}
case 5:
switch (waterlogged)
{
case true:
return 3453;
case false:
return 3454;
}
case 6:
switch (waterlogged)
{
case true:
return 3455;
case false:
return 3456;
}
case 7:
switch (waterlogged)
{
case true:
return 3457;
case false:
return 3458;
}
case 8:
switch (waterlogged)
{
case true:
return 3459;
case false:
return 3460;
}
case 9:
switch (waterlogged)
{
case true:
return 3461;
case false:
return 3462;
}
case 10:
switch (waterlogged)
{
case true:
return 3463;
case false:
return 3464;
}
case 11:
switch (waterlogged)
{
case true:
return 3465;
case false:
return 3466;
}
case 12:
switch (waterlogged)
{
case true:
return 3467;
case false:
return 3468;
}
case 13:
switch (waterlogged)
{
case true:
return 3469;
case false:
return 3470;
}
case 14:
switch (waterlogged)
{
case true:
return 3471;
case false:
return 3472;
}
case 15:
switch (waterlogged)
{
case true:
return 3473;
case false:
return 3474;
}
}
}
constexpr static birch_sign from_id(block_id_type id)
{
switch (id)
{
case 3443:
return {.rotation = 0, .waterlogged = true};
case 3444:
return {.rotation = 0, .waterlogged = false};
case 3445:
return {.rotation = 1, .waterlogged = true};
case 3446:
return {.rotation = 1, .waterlogged = false};
case 3447:
return {.rotation = 2, .waterlogged = true};
case 3448:
return {.rotation = 2, .waterlogged = false};
case 3449:
return {.rotation = 3, .waterlogged = true};
case 3450:
return {.rotation = 3, .waterlogged = false};
case 3451:
return {.rotation = 4, .waterlogged = true};
case 3452:
return {.rotation = 4, .waterlogged = false};
case 3453:
return {.rotation = 5, .waterlogged = true};
case 3454:
return {.rotation = 5, .waterlogged = false};
case 3455:
return {.rotation = 6, .waterlogged = true};
case 3456:
return {.rotation = 6, .waterlogged = false};
case 3457:
return {.rotation = 7, .waterlogged = true};
case 3458:
return {.rotation = 7, .waterlogged = false};
case 3459:
return {.rotation = 8, .waterlogged = true};
case 3460:
return {.rotation = 8, .waterlogged = false};
case 3461:
return {.rotation = 9, .waterlogged = true};
case 3462:
return {.rotation = 9, .waterlogged = false};
case 3463:
return {.rotation = 10, .waterlogged = true};
case 3464:
return {.rotation = 10, .waterlogged = false};
case 3465:
return {.rotation = 11, .waterlogged = true};
case 3466:
return {.rotation = 11, .waterlogged = false};
case 3467:
return {.rotation = 12, .waterlogged = true};
case 3468:
return {.rotation = 12, .waterlogged = false};
case 3469:
return {.rotation = 13, .waterlogged = true};
case 3470:
return {.rotation = 13, .waterlogged = false};
case 3471:
return {.rotation = 14, .waterlogged = true};
case 3472:
return {.rotation = 14, .waterlogged = false};
case 3473:
return {.rotation = 15, .waterlogged = true};
case 3474:
return {.rotation = 15, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:0:true";
case false:
return "minecraft:birch_sign:0:false";
}
case 1:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:1:true";
case false:
return "minecraft:birch_sign:1:false";
}
case 2:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:2:true";
case false:
return "minecraft:birch_sign:2:false";
}
case 3:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:3:true";
case false:
return "minecraft:birch_sign:3:false";
}
case 4:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:4:true";
case false:
return "minecraft:birch_sign:4:false";
}
case 5:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:5:true";
case false:
return "minecraft:birch_sign:5:false";
}
case 6:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:6:true";
case false:
return "minecraft:birch_sign:6:false";
}
case 7:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:7:true";
case false:
return "minecraft:birch_sign:7:false";
}
case 8:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:8:true";
case false:
return "minecraft:birch_sign:8:false";
}
case 9:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:9:true";
case false:
return "minecraft:birch_sign:9:false";
}
case 10:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:10:true";
case false:
return "minecraft:birch_sign:10:false";
}
case 11:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:11:true";
case false:
return "minecraft:birch_sign:11:false";
}
case 12:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:12:true";
case false:
return "minecraft:birch_sign:12:false";
}
case 13:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:13:true";
case false:
return "minecraft:birch_sign:13:false";
}
case 14:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:14:true";
case false:
return "minecraft:birch_sign:14:false";
}
case 15:
switch (waterlogged)
{
case true:
return "minecraft:birch_sign:15:true";
case false:
return "minecraft:birch_sign:15:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
