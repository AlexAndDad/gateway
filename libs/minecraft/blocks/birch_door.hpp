#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct birch_door
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
enum class half_type : std::uint8_t
{
upper,
lower
} half = half_type::lower;
enum class hinge_type : std::uint8_t
{
left,
right
} hinge = hinge_type::left;
bool open = false;
bool powered = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8266;
case false:
return 8267;
}
case false:
switch (powered)
{
case true:
return 8268;
case false:
return 8269;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8270;
case false:
return 8271;
}
case false:
switch (powered)
{
case true:
return 8272;
case false:
return 8273;
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8274;
case false:
return 8275;
}
case false:
switch (powered)
{
case true:
return 8276;
case false:
return 8277;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8278;
case false:
return 8279;
}
case false:
switch (powered)
{
case true:
return 8280;
case false:
return 8281;
}
}
}
}
case facing_type::south:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8282;
case false:
return 8283;
}
case false:
switch (powered)
{
case true:
return 8284;
case false:
return 8285;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8286;
case false:
return 8287;
}
case false:
switch (powered)
{
case true:
return 8288;
case false:
return 8289;
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8290;
case false:
return 8291;
}
case false:
switch (powered)
{
case true:
return 8292;
case false:
return 8293;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8294;
case false:
return 8295;
}
case false:
switch (powered)
{
case true:
return 8296;
case false:
return 8297;
}
}
}
}
case facing_type::west:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8298;
case false:
return 8299;
}
case false:
switch (powered)
{
case true:
return 8300;
case false:
return 8301;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8302;
case false:
return 8303;
}
case false:
switch (powered)
{
case true:
return 8304;
case false:
return 8305;
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8306;
case false:
return 8307;
}
case false:
switch (powered)
{
case true:
return 8308;
case false:
return 8309;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8310;
case false:
return 8311;
}
case false:
switch (powered)
{
case true:
return 8312;
case false:
return 8313;
}
}
}
}
case facing_type::east:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8314;
case false:
return 8315;
}
case false:
switch (powered)
{
case true:
return 8316;
case false:
return 8317;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8318;
case false:
return 8319;
}
case false:
switch (powered)
{
case true:
return 8320;
case false:
return 8321;
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8322;
case false:
return 8323;
}
case false:
switch (powered)
{
case true:
return 8324;
case false:
return 8325;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8326;
case false:
return 8327;
}
case false:
switch (powered)
{
case true:
return 8328;
case false:
return 8329;
}
}
}
}
}
}
constexpr static birch_door from_id(block_id_type id)
{
switch (id)
{
case 8266:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8267:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8268:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8269:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8270:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8271:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8272:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8273:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8274:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8275:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8276:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8277:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8278:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8279:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8280:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8281:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8282:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8283:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8284:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8285:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8286:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8287:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8288:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8289:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8290:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8291:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8292:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8293:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8294:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8295:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8296:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8297:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8298:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8299:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8300:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8301:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8302:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8303:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8304:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8305:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8306:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8307:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8308:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8309:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8310:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8311:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8312:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8313:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8314:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8315:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8316:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8317:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8318:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8319:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8320:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8321:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8322:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8323:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8324:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8325:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8326:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8327:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8328:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8329:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:north:upper:left:true:true";
case false:
return "minecraft:birch_door:north:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:north:upper:left:false:true";
case false:
return "minecraft:birch_door:north:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:north:upper:right:true:true";
case false:
return "minecraft:birch_door:north:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:north:upper:right:false:true";
case false:
return "minecraft:birch_door:north:upper:right:false:false";
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:north:lower:left:true:true";
case false:
return "minecraft:birch_door:north:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:north:lower:left:false:true";
case false:
return "minecraft:birch_door:north:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:north:lower:right:true:true";
case false:
return "minecraft:birch_door:north:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:north:lower:right:false:true";
case false:
return "minecraft:birch_door:north:lower:right:false:false";
}
}
}
}
case facing_type::south:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:south:upper:left:true:true";
case false:
return "minecraft:birch_door:south:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:south:upper:left:false:true";
case false:
return "minecraft:birch_door:south:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:south:upper:right:true:true";
case false:
return "minecraft:birch_door:south:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:south:upper:right:false:true";
case false:
return "minecraft:birch_door:south:upper:right:false:false";
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:south:lower:left:true:true";
case false:
return "minecraft:birch_door:south:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:south:lower:left:false:true";
case false:
return "minecraft:birch_door:south:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:south:lower:right:true:true";
case false:
return "minecraft:birch_door:south:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:south:lower:right:false:true";
case false:
return "minecraft:birch_door:south:lower:right:false:false";
}
}
}
}
case facing_type::west:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:west:upper:left:true:true";
case false:
return "minecraft:birch_door:west:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:west:upper:left:false:true";
case false:
return "minecraft:birch_door:west:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:west:upper:right:true:true";
case false:
return "minecraft:birch_door:west:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:west:upper:right:false:true";
case false:
return "minecraft:birch_door:west:upper:right:false:false";
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:west:lower:left:true:true";
case false:
return "minecraft:birch_door:west:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:west:lower:left:false:true";
case false:
return "minecraft:birch_door:west:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:west:lower:right:true:true";
case false:
return "minecraft:birch_door:west:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:west:lower:right:false:true";
case false:
return "minecraft:birch_door:west:lower:right:false:false";
}
}
}
}
case facing_type::east:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:east:upper:left:true:true";
case false:
return "minecraft:birch_door:east:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:east:upper:left:false:true";
case false:
return "minecraft:birch_door:east:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:east:upper:right:true:true";
case false:
return "minecraft:birch_door:east:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:east:upper:right:false:true";
case false:
return "minecraft:birch_door:east:upper:right:false:false";
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:east:lower:left:true:true";
case false:
return "minecraft:birch_door:east:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:east:lower:left:false:true";
case false:
return "minecraft:birch_door:east:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_door:east:lower:right:true:true";
case false:
return "minecraft:birch_door:east:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_door:east:lower:right:false:true";
case false:
return "minecraft:birch_door:east:lower:right:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
