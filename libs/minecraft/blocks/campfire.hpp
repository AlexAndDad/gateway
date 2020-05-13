#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct campfire
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool lit = true;
bool signal_fire = false;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (lit)
{
case true:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return 11232;
case false:
return 11233;
}
case false:
switch (waterlogged)
{
case true:
return 11234;
case false:
return 11235;
}
}
case false:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return 11236;
case false:
return 11237;
}
case false:
switch (waterlogged)
{
case true:
return 11238;
case false:
return 11239;
}
}
}
case facing_type::south:
switch (lit)
{
case true:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return 11240;
case false:
return 11241;
}
case false:
switch (waterlogged)
{
case true:
return 11242;
case false:
return 11243;
}
}
case false:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return 11244;
case false:
return 11245;
}
case false:
switch (waterlogged)
{
case true:
return 11246;
case false:
return 11247;
}
}
}
case facing_type::west:
switch (lit)
{
case true:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return 11248;
case false:
return 11249;
}
case false:
switch (waterlogged)
{
case true:
return 11250;
case false:
return 11251;
}
}
case false:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return 11252;
case false:
return 11253;
}
case false:
switch (waterlogged)
{
case true:
return 11254;
case false:
return 11255;
}
}
}
case facing_type::east:
switch (lit)
{
case true:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return 11256;
case false:
return 11257;
}
case false:
switch (waterlogged)
{
case true:
return 11258;
case false:
return 11259;
}
}
case false:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return 11260;
case false:
return 11261;
}
case false:
switch (waterlogged)
{
case true:
return 11262;
case false:
return 11263;
}
}
}
}
}
constexpr static campfire from_id(block_id_type id)
{
switch (id)
{
case 11232:
return {.facing = facing_type::north, .lit = true, .signal_fire = true, .waterlogged = true};
case 11233:
return {.facing = facing_type::north, .lit = true, .signal_fire = true, .waterlogged = false};
case 11234:
return {.facing = facing_type::north, .lit = true, .signal_fire = false, .waterlogged = true};
case 11235:
return {.facing = facing_type::north, .lit = true, .signal_fire = false, .waterlogged = false};
case 11236:
return {.facing = facing_type::north, .lit = false, .signal_fire = true, .waterlogged = true};
case 11237:
return {.facing = facing_type::north, .lit = false, .signal_fire = true, .waterlogged = false};
case 11238:
return {.facing = facing_type::north, .lit = false, .signal_fire = false, .waterlogged = true};
case 11239:
return {.facing = facing_type::north, .lit = false, .signal_fire = false, .waterlogged = false};
case 11240:
return {.facing = facing_type::south, .lit = true, .signal_fire = true, .waterlogged = true};
case 11241:
return {.facing = facing_type::south, .lit = true, .signal_fire = true, .waterlogged = false};
case 11242:
return {.facing = facing_type::south, .lit = true, .signal_fire = false, .waterlogged = true};
case 11243:
return {.facing = facing_type::south, .lit = true, .signal_fire = false, .waterlogged = false};
case 11244:
return {.facing = facing_type::south, .lit = false, .signal_fire = true, .waterlogged = true};
case 11245:
return {.facing = facing_type::south, .lit = false, .signal_fire = true, .waterlogged = false};
case 11246:
return {.facing = facing_type::south, .lit = false, .signal_fire = false, .waterlogged = true};
case 11247:
return {.facing = facing_type::south, .lit = false, .signal_fire = false, .waterlogged = false};
case 11248:
return {.facing = facing_type::west, .lit = true, .signal_fire = true, .waterlogged = true};
case 11249:
return {.facing = facing_type::west, .lit = true, .signal_fire = true, .waterlogged = false};
case 11250:
return {.facing = facing_type::west, .lit = true, .signal_fire = false, .waterlogged = true};
case 11251:
return {.facing = facing_type::west, .lit = true, .signal_fire = false, .waterlogged = false};
case 11252:
return {.facing = facing_type::west, .lit = false, .signal_fire = true, .waterlogged = true};
case 11253:
return {.facing = facing_type::west, .lit = false, .signal_fire = true, .waterlogged = false};
case 11254:
return {.facing = facing_type::west, .lit = false, .signal_fire = false, .waterlogged = true};
case 11255:
return {.facing = facing_type::west, .lit = false, .signal_fire = false, .waterlogged = false};
case 11256:
return {.facing = facing_type::east, .lit = true, .signal_fire = true, .waterlogged = true};
case 11257:
return {.facing = facing_type::east, .lit = true, .signal_fire = true, .waterlogged = false};
case 11258:
return {.facing = facing_type::east, .lit = true, .signal_fire = false, .waterlogged = true};
case 11259:
return {.facing = facing_type::east, .lit = true, .signal_fire = false, .waterlogged = false};
case 11260:
return {.facing = facing_type::east, .lit = false, .signal_fire = true, .waterlogged = true};
case 11261:
return {.facing = facing_type::east, .lit = false, .signal_fire = true, .waterlogged = false};
case 11262:
return {.facing = facing_type::east, .lit = false, .signal_fire = false, .waterlogged = true};
case 11263:
return {.facing = facing_type::east, .lit = false, .signal_fire = false, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (lit)
{
case true:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:campfire:north:true:true:true";
case false:
return "minecraft:campfire:north:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:campfire:north:true:false:true";
case false:
return "minecraft:campfire:north:true:false:false";
}
}
case false:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:campfire:north:false:true:true";
case false:
return "minecraft:campfire:north:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:campfire:north:false:false:true";
case false:
return "minecraft:campfire:north:false:false:false";
}
}
}
case facing_type::south:
switch (lit)
{
case true:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:campfire:south:true:true:true";
case false:
return "minecraft:campfire:south:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:campfire:south:true:false:true";
case false:
return "minecraft:campfire:south:true:false:false";
}
}
case false:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:campfire:south:false:true:true";
case false:
return "minecraft:campfire:south:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:campfire:south:false:false:true";
case false:
return "minecraft:campfire:south:false:false:false";
}
}
}
case facing_type::west:
switch (lit)
{
case true:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:campfire:west:true:true:true";
case false:
return "minecraft:campfire:west:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:campfire:west:true:false:true";
case false:
return "minecraft:campfire:west:true:false:false";
}
}
case false:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:campfire:west:false:true:true";
case false:
return "minecraft:campfire:west:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:campfire:west:false:false:true";
case false:
return "minecraft:campfire:west:false:false:false";
}
}
}
case facing_type::east:
switch (lit)
{
case true:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:campfire:east:true:true:true";
case false:
return "minecraft:campfire:east:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:campfire:east:true:false:true";
case false:
return "minecraft:campfire:east:true:false:false";
}
}
case false:
switch (signal_fire)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:campfire:east:false:true:true";
case false:
return "minecraft:campfire:east:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:campfire:east:false:false:true";
case false:
return "minecraft:campfire:east:false:false:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
