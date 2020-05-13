#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct mossy_stone_brick_stairs
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
enum class half_type : std::uint8_t
{
top,
bottom
} half = half_type::bottom;
enum class shape_type : std::uint8_t
{
straight,
inner_left,
inner_right,
outer_left,
outer_right
} shape = shape_type::straight;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9293;
case false:
return 9294;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9295;
case false:
return 9296;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9297;
case false:
return 9298;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9299;
case false:
return 9300;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9301;
case false:
return 9302;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9303;
case false:
return 9304;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9305;
case false:
return 9306;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9307;
case false:
return 9308;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9309;
case false:
return 9310;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9311;
case false:
return 9312;
}
}
}
case facing_type::south:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9313;
case false:
return 9314;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9315;
case false:
return 9316;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9317;
case false:
return 9318;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9319;
case false:
return 9320;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9321;
case false:
return 9322;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9323;
case false:
return 9324;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9325;
case false:
return 9326;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9327;
case false:
return 9328;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9329;
case false:
return 9330;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9331;
case false:
return 9332;
}
}
}
case facing_type::west:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9333;
case false:
return 9334;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9335;
case false:
return 9336;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9337;
case false:
return 9338;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9339;
case false:
return 9340;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9341;
case false:
return 9342;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9343;
case false:
return 9344;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9345;
case false:
return 9346;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9347;
case false:
return 9348;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9349;
case false:
return 9350;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9351;
case false:
return 9352;
}
}
}
case facing_type::east:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9353;
case false:
return 9354;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9355;
case false:
return 9356;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9357;
case false:
return 9358;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9359;
case false:
return 9360;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9361;
case false:
return 9362;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9363;
case false:
return 9364;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9365;
case false:
return 9366;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9367;
case false:
return 9368;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9369;
case false:
return 9370;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9371;
case false:
return 9372;
}
}
}
}
}
constexpr static mossy_stone_brick_stairs from_id(block_id_type id)
{
switch (id)
{
case 9293:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9294:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9295:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9296:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9297:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9298:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9299:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9300:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9301:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9302:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9303:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9304:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9305:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9306:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9307:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9308:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9309:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9310:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9311:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9312:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9313:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9314:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9315:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9316:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9317:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9318:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9319:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9320:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9321:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9322:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9323:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9324:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9325:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9326:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9327:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9328:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9329:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9330:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9331:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9332:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9333:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9334:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9335:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9336:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9337:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9338:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9339:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9340:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9341:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9342:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9343:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9344:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9345:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9346:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9347:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9348:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9349:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9350:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9351:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9352:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9353:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9354:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9355:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9356:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9357:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9358:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9359:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9360:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9361:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9362:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9363:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9364:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9365:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9366:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9367:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9368:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9369:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9370:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9371:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9372:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:north:top:straight:true";
case false:
return "minecraft:mossy_stone_brick_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:north:top:inner_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:north:top:inner_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:north:top:outer_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:north:top:outer_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:north:bottom:straight:true";
case false:
return "minecraft:mossy_stone_brick_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:north:bottom:outer_right:false";
}
}
}
case facing_type::south:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:south:top:straight:true";
case false:
return "minecraft:mossy_stone_brick_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:south:top:inner_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:south:top:inner_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:south:top:outer_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:south:top:outer_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:south:bottom:straight:true";
case false:
return "minecraft:mossy_stone_brick_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:south:bottom:outer_right:false";
}
}
}
case facing_type::west:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:west:top:straight:true";
case false:
return "minecraft:mossy_stone_brick_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:west:top:inner_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:west:top:inner_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:west:top:outer_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:west:top:outer_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:west:bottom:straight:true";
case false:
return "minecraft:mossy_stone_brick_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:west:bottom:outer_right:false";
}
}
}
case facing_type::east:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:east:top:straight:true";
case false:
return "minecraft:mossy_stone_brick_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:east:top:inner_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:east:top:inner_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:east:top:outer_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:east:top:outer_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:east:bottom:straight:true";
case false:
return "minecraft:mossy_stone_brick_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:mossy_stone_brick_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:mossy_stone_brick_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:mossy_stone_brick_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
