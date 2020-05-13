#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct oak_sign
{std::uint8_t rotation = 0;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
switch (waterlogged)
{
case true:
return 3379;
case false:
return 3380;
}
case 1:
switch (waterlogged)
{
case true:
return 3381;
case false:
return 3382;
}
case 2:
switch (waterlogged)
{
case true:
return 3383;
case false:
return 3384;
}
case 3:
switch (waterlogged)
{
case true:
return 3385;
case false:
return 3386;
}
case 4:
switch (waterlogged)
{
case true:
return 3387;
case false:
return 3388;
}
case 5:
switch (waterlogged)
{
case true:
return 3389;
case false:
return 3390;
}
case 6:
switch (waterlogged)
{
case true:
return 3391;
case false:
return 3392;
}
case 7:
switch (waterlogged)
{
case true:
return 3393;
case false:
return 3394;
}
case 8:
switch (waterlogged)
{
case true:
return 3395;
case false:
return 3396;
}
case 9:
switch (waterlogged)
{
case true:
return 3397;
case false:
return 3398;
}
case 10:
switch (waterlogged)
{
case true:
return 3399;
case false:
return 3400;
}
case 11:
switch (waterlogged)
{
case true:
return 3401;
case false:
return 3402;
}
case 12:
switch (waterlogged)
{
case true:
return 3403;
case false:
return 3404;
}
case 13:
switch (waterlogged)
{
case true:
return 3405;
case false:
return 3406;
}
case 14:
switch (waterlogged)
{
case true:
return 3407;
case false:
return 3408;
}
case 15:
switch (waterlogged)
{
case true:
return 3409;
case false:
return 3410;
}
}
}
constexpr static oak_sign from_id(block_id_type id)
{
switch (id)
{
case 3379:
return {.rotation = 0, .waterlogged = true};
case 3380:
return {.rotation = 0, .waterlogged = false};
case 3381:
return {.rotation = 1, .waterlogged = true};
case 3382:
return {.rotation = 1, .waterlogged = false};
case 3383:
return {.rotation = 2, .waterlogged = true};
case 3384:
return {.rotation = 2, .waterlogged = false};
case 3385:
return {.rotation = 3, .waterlogged = true};
case 3386:
return {.rotation = 3, .waterlogged = false};
case 3387:
return {.rotation = 4, .waterlogged = true};
case 3388:
return {.rotation = 4, .waterlogged = false};
case 3389:
return {.rotation = 5, .waterlogged = true};
case 3390:
return {.rotation = 5, .waterlogged = false};
case 3391:
return {.rotation = 6, .waterlogged = true};
case 3392:
return {.rotation = 6, .waterlogged = false};
case 3393:
return {.rotation = 7, .waterlogged = true};
case 3394:
return {.rotation = 7, .waterlogged = false};
case 3395:
return {.rotation = 8, .waterlogged = true};
case 3396:
return {.rotation = 8, .waterlogged = false};
case 3397:
return {.rotation = 9, .waterlogged = true};
case 3398:
return {.rotation = 9, .waterlogged = false};
case 3399:
return {.rotation = 10, .waterlogged = true};
case 3400:
return {.rotation = 10, .waterlogged = false};
case 3401:
return {.rotation = 11, .waterlogged = true};
case 3402:
return {.rotation = 11, .waterlogged = false};
case 3403:
return {.rotation = 12, .waterlogged = true};
case 3404:
return {.rotation = 12, .waterlogged = false};
case 3405:
return {.rotation = 13, .waterlogged = true};
case 3406:
return {.rotation = 13, .waterlogged = false};
case 3407:
return {.rotation = 14, .waterlogged = true};
case 3408:
return {.rotation = 14, .waterlogged = false};
case 3409:
return {.rotation = 15, .waterlogged = true};
case 3410:
return {.rotation = 15, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:0:true";
case false:
return "minecraft:oak_sign:0:false";
}
case 1:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:1:true";
case false:
return "minecraft:oak_sign:1:false";
}
case 2:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:2:true";
case false:
return "minecraft:oak_sign:2:false";
}
case 3:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:3:true";
case false:
return "minecraft:oak_sign:3:false";
}
case 4:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:4:true";
case false:
return "minecraft:oak_sign:4:false";
}
case 5:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:5:true";
case false:
return "minecraft:oak_sign:5:false";
}
case 6:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:6:true";
case false:
return "minecraft:oak_sign:6:false";
}
case 7:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:7:true";
case false:
return "minecraft:oak_sign:7:false";
}
case 8:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:8:true";
case false:
return "minecraft:oak_sign:8:false";
}
case 9:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:9:true";
case false:
return "minecraft:oak_sign:9:false";
}
case 10:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:10:true";
case false:
return "minecraft:oak_sign:10:false";
}
case 11:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:11:true";
case false:
return "minecraft:oak_sign:11:false";
}
case 12:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:12:true";
case false:
return "minecraft:oak_sign:12:false";
}
case 13:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:13:true";
case false:
return "minecraft:oak_sign:13:false";
}
case 14:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:14:true";
case false:
return "minecraft:oak_sign:14:false";
}
case 15:
switch (waterlogged)
{
case true:
return "minecraft:oak_sign:15:true";
case false:
return "minecraft:oak_sign:15:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
