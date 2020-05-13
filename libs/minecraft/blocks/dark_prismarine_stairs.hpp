#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dark_prismarine_stairs
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
return 7228;
case false:
return 7229;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7230;
case false:
return 7231;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7232;
case false:
return 7233;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7234;
case false:
return 7235;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7236;
case false:
return 7237;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7238;
case false:
return 7239;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7240;
case false:
return 7241;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7242;
case false:
return 7243;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7244;
case false:
return 7245;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7246;
case false:
return 7247;
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
return 7248;
case false:
return 7249;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7250;
case false:
return 7251;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7252;
case false:
return 7253;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7254;
case false:
return 7255;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7256;
case false:
return 7257;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7258;
case false:
return 7259;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7260;
case false:
return 7261;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7262;
case false:
return 7263;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7264;
case false:
return 7265;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7266;
case false:
return 7267;
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
return 7268;
case false:
return 7269;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7270;
case false:
return 7271;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7272;
case false:
return 7273;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7274;
case false:
return 7275;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7276;
case false:
return 7277;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7278;
case false:
return 7279;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7280;
case false:
return 7281;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7282;
case false:
return 7283;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7284;
case false:
return 7285;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7286;
case false:
return 7287;
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
return 7288;
case false:
return 7289;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7290;
case false:
return 7291;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7292;
case false:
return 7293;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7294;
case false:
return 7295;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7296;
case false:
return 7297;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7298;
case false:
return 7299;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7300;
case false:
return 7301;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7302;
case false:
return 7303;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7304;
case false:
return 7305;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7306;
case false:
return 7307;
}
}
}
}
}
constexpr static dark_prismarine_stairs from_id(block_id_type id)
{
switch (id)
{
case 7228:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7229:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7230:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7231:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7232:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7233:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7234:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7235:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7236:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7237:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7238:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7239:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7240:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7241:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7242:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7243:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7244:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7245:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7246:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7247:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 7248:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7249:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7250:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7251:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7252:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7253:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7254:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7255:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7256:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7257:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7258:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7259:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7260:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7261:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7262:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7263:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7264:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7265:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7266:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7267:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 7268:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7269:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7270:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7271:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7272:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7273:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7274:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7275:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7276:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7277:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7278:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7279:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7280:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7281:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7282:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7283:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7284:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7285:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7286:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7287:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 7288:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7289:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7290:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7291:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7292:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7293:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7294:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7295:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7296:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7297:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7298:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7299:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7300:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7301:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7302:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7303:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7304:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7305:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7306:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7307:
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
return "minecraft:dark_prismarine_stairs:north:top:straight:true";
case false:
return "minecraft:dark_prismarine_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:north:top:inner_left:true";
case false:
return "minecraft:dark_prismarine_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:north:top:inner_right:true";
case false:
return "minecraft:dark_prismarine_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:north:top:outer_left:true";
case false:
return "minecraft:dark_prismarine_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:north:top:outer_right:true";
case false:
return "minecraft:dark_prismarine_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:north:bottom:straight:true";
case false:
return "minecraft:dark_prismarine_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:dark_prismarine_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:dark_prismarine_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:dark_prismarine_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:dark_prismarine_stairs:north:bottom:outer_right:false";
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
return "minecraft:dark_prismarine_stairs:south:top:straight:true";
case false:
return "minecraft:dark_prismarine_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:south:top:inner_left:true";
case false:
return "minecraft:dark_prismarine_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:south:top:inner_right:true";
case false:
return "minecraft:dark_prismarine_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:south:top:outer_left:true";
case false:
return "minecraft:dark_prismarine_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:south:top:outer_right:true";
case false:
return "minecraft:dark_prismarine_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:south:bottom:straight:true";
case false:
return "minecraft:dark_prismarine_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:dark_prismarine_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:dark_prismarine_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:dark_prismarine_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:dark_prismarine_stairs:south:bottom:outer_right:false";
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
return "minecraft:dark_prismarine_stairs:west:top:straight:true";
case false:
return "minecraft:dark_prismarine_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:west:top:inner_left:true";
case false:
return "minecraft:dark_prismarine_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:west:top:inner_right:true";
case false:
return "minecraft:dark_prismarine_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:west:top:outer_left:true";
case false:
return "minecraft:dark_prismarine_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:west:top:outer_right:true";
case false:
return "minecraft:dark_prismarine_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:west:bottom:straight:true";
case false:
return "minecraft:dark_prismarine_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:dark_prismarine_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:dark_prismarine_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:dark_prismarine_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:dark_prismarine_stairs:west:bottom:outer_right:false";
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
return "minecraft:dark_prismarine_stairs:east:top:straight:true";
case false:
return "minecraft:dark_prismarine_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:east:top:inner_left:true";
case false:
return "minecraft:dark_prismarine_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:east:top:inner_right:true";
case false:
return "minecraft:dark_prismarine_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:east:top:outer_left:true";
case false:
return "minecraft:dark_prismarine_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:east:top:outer_right:true";
case false:
return "minecraft:dark_prismarine_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:east:bottom:straight:true";
case false:
return "minecraft:dark_prismarine_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:dark_prismarine_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:dark_prismarine_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:dark_prismarine_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:dark_prismarine_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
