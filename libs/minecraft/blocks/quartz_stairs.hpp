#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct quartz_stairs
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
return 6207;
case false:
return 6208;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6209;
case false:
return 6210;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6211;
case false:
return 6212;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6213;
case false:
return 6214;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6215;
case false:
return 6216;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6217;
case false:
return 6218;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6219;
case false:
return 6220;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6221;
case false:
return 6222;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6223;
case false:
return 6224;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6225;
case false:
return 6226;
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
return 6227;
case false:
return 6228;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6229;
case false:
return 6230;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6231;
case false:
return 6232;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6233;
case false:
return 6234;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6235;
case false:
return 6236;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6237;
case false:
return 6238;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6239;
case false:
return 6240;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6241;
case false:
return 6242;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6243;
case false:
return 6244;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6245;
case false:
return 6246;
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
return 6247;
case false:
return 6248;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6249;
case false:
return 6250;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6251;
case false:
return 6252;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6253;
case false:
return 6254;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6255;
case false:
return 6256;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6257;
case false:
return 6258;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6259;
case false:
return 6260;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6261;
case false:
return 6262;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6263;
case false:
return 6264;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6265;
case false:
return 6266;
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
return 6267;
case false:
return 6268;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6269;
case false:
return 6270;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6271;
case false:
return 6272;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6273;
case false:
return 6274;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6275;
case false:
return 6276;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6277;
case false:
return 6278;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6279;
case false:
return 6280;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6281;
case false:
return 6282;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6283;
case false:
return 6284;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6285;
case false:
return 6286;
}
}
}
}
}
constexpr static quartz_stairs from_id(block_id_type id)
{
switch (id)
{
case 6207:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 6208:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 6209:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 6210:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 6211:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 6212:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 6213:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 6214:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 6215:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 6216:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 6217:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 6218:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 6219:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 6220:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 6221:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 6222:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 6223:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 6224:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 6225:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 6226:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 6227:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 6228:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 6229:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 6230:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 6231:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 6232:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 6233:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 6234:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 6235:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 6236:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 6237:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 6238:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 6239:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 6240:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 6241:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 6242:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 6243:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 6244:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 6245:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 6246:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 6247:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 6248:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 6249:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 6250:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 6251:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 6252:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 6253:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 6254:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 6255:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 6256:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 6257:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 6258:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 6259:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 6260:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 6261:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 6262:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 6263:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 6264:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 6265:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 6266:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 6267:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 6268:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 6269:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 6270:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 6271:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 6272:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 6273:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 6274:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 6275:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 6276:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 6277:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 6278:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 6279:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 6280:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 6281:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 6282:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 6283:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 6284:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 6285:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 6286:
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
return "minecraft:quartz_stairs:north:top:straight:true";
case false:
return "minecraft:quartz_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:north:top:inner_left:true";
case false:
return "minecraft:quartz_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:north:top:inner_right:true";
case false:
return "minecraft:quartz_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:north:top:outer_left:true";
case false:
return "minecraft:quartz_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:north:top:outer_right:true";
case false:
return "minecraft:quartz_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:north:bottom:straight:true";
case false:
return "minecraft:quartz_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:quartz_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:quartz_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:quartz_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:quartz_stairs:north:bottom:outer_right:false";
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
return "minecraft:quartz_stairs:south:top:straight:true";
case false:
return "minecraft:quartz_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:south:top:inner_left:true";
case false:
return "minecraft:quartz_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:south:top:inner_right:true";
case false:
return "minecraft:quartz_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:south:top:outer_left:true";
case false:
return "minecraft:quartz_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:south:top:outer_right:true";
case false:
return "minecraft:quartz_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:south:bottom:straight:true";
case false:
return "minecraft:quartz_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:quartz_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:quartz_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:quartz_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:quartz_stairs:south:bottom:outer_right:false";
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
return "minecraft:quartz_stairs:west:top:straight:true";
case false:
return "minecraft:quartz_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:west:top:inner_left:true";
case false:
return "minecraft:quartz_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:west:top:inner_right:true";
case false:
return "minecraft:quartz_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:west:top:outer_left:true";
case false:
return "minecraft:quartz_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:west:top:outer_right:true";
case false:
return "minecraft:quartz_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:west:bottom:straight:true";
case false:
return "minecraft:quartz_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:quartz_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:quartz_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:quartz_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:quartz_stairs:west:bottom:outer_right:false";
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
return "minecraft:quartz_stairs:east:top:straight:true";
case false:
return "minecraft:quartz_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:east:top:inner_left:true";
case false:
return "minecraft:quartz_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:east:top:inner_right:true";
case false:
return "minecraft:quartz_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:east:top:outer_left:true";
case false:
return "minecraft:quartz_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:east:top:outer_right:true";
case false:
return "minecraft:quartz_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:east:bottom:straight:true";
case false:
return "minecraft:quartz_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:quartz_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:quartz_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:quartz_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:quartz_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:quartz_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
