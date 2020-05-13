#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct prismarine_stairs
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
return 7068;
case false:
return 7069;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7070;
case false:
return 7071;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7072;
case false:
return 7073;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7074;
case false:
return 7075;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7076;
case false:
return 7077;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7078;
case false:
return 7079;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7080;
case false:
return 7081;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7082;
case false:
return 7083;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7084;
case false:
return 7085;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7086;
case false:
return 7087;
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
return 7088;
case false:
return 7089;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7090;
case false:
return 7091;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7092;
case false:
return 7093;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7094;
case false:
return 7095;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7096;
case false:
return 7097;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7098;
case false:
return 7099;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7100;
case false:
return 7101;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7102;
case false:
return 7103;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7104;
case false:
return 7105;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7106;
case false:
return 7107;
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
return 7108;
case false:
return 7109;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7110;
case false:
return 7111;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7112;
case false:
return 7113;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7114;
case false:
return 7115;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7116;
case false:
return 7117;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7118;
case false:
return 7119;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7120;
case false:
return 7121;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7122;
case false:
return 7123;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7124;
case false:
return 7125;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7126;
case false:
return 7127;
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
return 7128;
case false:
return 7129;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7130;
case false:
return 7131;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7132;
case false:
return 7133;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7134;
case false:
return 7135;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7136;
case false:
return 7137;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7138;
case false:
return 7139;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7140;
case false:
return 7141;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7142;
case false:
return 7143;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7144;
case false:
return 7145;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7146;
case false:
return 7147;
}
}
}
}
}
constexpr static prismarine_stairs from_id(block_id_type id)
{
switch (id)
{
case 7068:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7069:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7070:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7071:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7072:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7073:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7074:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7075:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7076:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7077:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7078:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7079:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7080:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7081:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7082:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7083:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7084:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7085:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7086:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7087:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 7088:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7089:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7090:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7091:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7092:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7093:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7094:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7095:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7096:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7097:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7098:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7099:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7100:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7101:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7102:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7103:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7104:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7105:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7106:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7107:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 7108:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7109:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7110:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7111:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7112:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7113:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7114:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7115:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7116:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7117:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7118:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7119:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7120:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7121:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7122:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7123:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7124:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7125:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7126:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7127:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 7128:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7129:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7130:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7131:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7132:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7133:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7134:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7135:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7136:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7137:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7138:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7139:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7140:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7141:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7142:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7143:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7144:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7145:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7146:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7147:
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
return "minecraft:prismarine_stairs:north:top:straight:true";
case false:
return "minecraft:prismarine_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:north:top:inner_left:true";
case false:
return "minecraft:prismarine_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:north:top:inner_right:true";
case false:
return "minecraft:prismarine_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:north:top:outer_left:true";
case false:
return "minecraft:prismarine_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:north:top:outer_right:true";
case false:
return "minecraft:prismarine_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:north:bottom:straight:true";
case false:
return "minecraft:prismarine_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:prismarine_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:prismarine_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:prismarine_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:prismarine_stairs:north:bottom:outer_right:false";
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
return "minecraft:prismarine_stairs:south:top:straight:true";
case false:
return "minecraft:prismarine_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:south:top:inner_left:true";
case false:
return "minecraft:prismarine_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:south:top:inner_right:true";
case false:
return "minecraft:prismarine_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:south:top:outer_left:true";
case false:
return "minecraft:prismarine_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:south:top:outer_right:true";
case false:
return "minecraft:prismarine_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:south:bottom:straight:true";
case false:
return "minecraft:prismarine_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:prismarine_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:prismarine_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:prismarine_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:prismarine_stairs:south:bottom:outer_right:false";
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
return "minecraft:prismarine_stairs:west:top:straight:true";
case false:
return "minecraft:prismarine_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:west:top:inner_left:true";
case false:
return "minecraft:prismarine_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:west:top:inner_right:true";
case false:
return "minecraft:prismarine_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:west:top:outer_left:true";
case false:
return "minecraft:prismarine_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:west:top:outer_right:true";
case false:
return "minecraft:prismarine_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:west:bottom:straight:true";
case false:
return "minecraft:prismarine_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:prismarine_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:prismarine_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:prismarine_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:prismarine_stairs:west:bottom:outer_right:false";
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
return "minecraft:prismarine_stairs:east:top:straight:true";
case false:
return "minecraft:prismarine_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:east:top:inner_left:true";
case false:
return "minecraft:prismarine_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:east:top:inner_right:true";
case false:
return "minecraft:prismarine_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:east:top:outer_left:true";
case false:
return "minecraft:prismarine_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:east:top:outer_right:true";
case false:
return "minecraft:prismarine_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:east:bottom:straight:true";
case false:
return "minecraft:prismarine_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:prismarine_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:prismarine_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:prismarine_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:prismarine_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
