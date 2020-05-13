#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct spruce_door
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
return 8202;
case false:
return 8203;
}
case false:
switch (powered)
{
case true:
return 8204;
case false:
return 8205;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8206;
case false:
return 8207;
}
case false:
switch (powered)
{
case true:
return 8208;
case false:
return 8209;
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
return 8210;
case false:
return 8211;
}
case false:
switch (powered)
{
case true:
return 8212;
case false:
return 8213;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8214;
case false:
return 8215;
}
case false:
switch (powered)
{
case true:
return 8216;
case false:
return 8217;
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
return 8218;
case false:
return 8219;
}
case false:
switch (powered)
{
case true:
return 8220;
case false:
return 8221;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8222;
case false:
return 8223;
}
case false:
switch (powered)
{
case true:
return 8224;
case false:
return 8225;
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
return 8226;
case false:
return 8227;
}
case false:
switch (powered)
{
case true:
return 8228;
case false:
return 8229;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8230;
case false:
return 8231;
}
case false:
switch (powered)
{
case true:
return 8232;
case false:
return 8233;
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
return 8234;
case false:
return 8235;
}
case false:
switch (powered)
{
case true:
return 8236;
case false:
return 8237;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8238;
case false:
return 8239;
}
case false:
switch (powered)
{
case true:
return 8240;
case false:
return 8241;
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
return 8242;
case false:
return 8243;
}
case false:
switch (powered)
{
case true:
return 8244;
case false:
return 8245;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8246;
case false:
return 8247;
}
case false:
switch (powered)
{
case true:
return 8248;
case false:
return 8249;
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
return 8250;
case false:
return 8251;
}
case false:
switch (powered)
{
case true:
return 8252;
case false:
return 8253;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8254;
case false:
return 8255;
}
case false:
switch (powered)
{
case true:
return 8256;
case false:
return 8257;
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
return 8258;
case false:
return 8259;
}
case false:
switch (powered)
{
case true:
return 8260;
case false:
return 8261;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8262;
case false:
return 8263;
}
case false:
switch (powered)
{
case true:
return 8264;
case false:
return 8265;
}
}
}
}
}
}
constexpr static spruce_door from_id(block_id_type id)
{
switch (id)
{
case 8202:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8203:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8204:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8205:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8206:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8207:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8208:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8209:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8210:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8211:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8212:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8213:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8214:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8215:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8216:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8217:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8218:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8219:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8220:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8221:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8222:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8223:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8224:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8225:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8226:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8227:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8228:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8229:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8230:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8231:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8232:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8233:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8234:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8235:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8236:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8237:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8238:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8239:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8240:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8241:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8242:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8243:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8244:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8245:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8246:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8247:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8248:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8249:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8250:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8251:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8252:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8253:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8254:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8255:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8256:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8257:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8258:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8259:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8260:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8261:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8262:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8263:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8264:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8265:
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
return "minecraft:spruce_door:north:upper:left:true:true";
case false:
return "minecraft:spruce_door:north:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:north:upper:left:false:true";
case false:
return "minecraft:spruce_door:north:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:spruce_door:north:upper:right:true:true";
case false:
return "minecraft:spruce_door:north:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:north:upper:right:false:true";
case false:
return "minecraft:spruce_door:north:upper:right:false:false";
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
return "minecraft:spruce_door:north:lower:left:true:true";
case false:
return "minecraft:spruce_door:north:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:north:lower:left:false:true";
case false:
return "minecraft:spruce_door:north:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:spruce_door:north:lower:right:true:true";
case false:
return "minecraft:spruce_door:north:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:north:lower:right:false:true";
case false:
return "minecraft:spruce_door:north:lower:right:false:false";
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
return "minecraft:spruce_door:south:upper:left:true:true";
case false:
return "minecraft:spruce_door:south:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:south:upper:left:false:true";
case false:
return "minecraft:spruce_door:south:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:spruce_door:south:upper:right:true:true";
case false:
return "minecraft:spruce_door:south:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:south:upper:right:false:true";
case false:
return "minecraft:spruce_door:south:upper:right:false:false";
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
return "minecraft:spruce_door:south:lower:left:true:true";
case false:
return "minecraft:spruce_door:south:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:south:lower:left:false:true";
case false:
return "minecraft:spruce_door:south:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:spruce_door:south:lower:right:true:true";
case false:
return "minecraft:spruce_door:south:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:south:lower:right:false:true";
case false:
return "minecraft:spruce_door:south:lower:right:false:false";
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
return "minecraft:spruce_door:west:upper:left:true:true";
case false:
return "minecraft:spruce_door:west:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:west:upper:left:false:true";
case false:
return "minecraft:spruce_door:west:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:spruce_door:west:upper:right:true:true";
case false:
return "minecraft:spruce_door:west:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:west:upper:right:false:true";
case false:
return "minecraft:spruce_door:west:upper:right:false:false";
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
return "minecraft:spruce_door:west:lower:left:true:true";
case false:
return "minecraft:spruce_door:west:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:west:lower:left:false:true";
case false:
return "minecraft:spruce_door:west:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:spruce_door:west:lower:right:true:true";
case false:
return "minecraft:spruce_door:west:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:west:lower:right:false:true";
case false:
return "minecraft:spruce_door:west:lower:right:false:false";
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
return "minecraft:spruce_door:east:upper:left:true:true";
case false:
return "minecraft:spruce_door:east:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:east:upper:left:false:true";
case false:
return "minecraft:spruce_door:east:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:spruce_door:east:upper:right:true:true";
case false:
return "minecraft:spruce_door:east:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:east:upper:right:false:true";
case false:
return "minecraft:spruce_door:east:upper:right:false:false";
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
return "minecraft:spruce_door:east:lower:left:true:true";
case false:
return "minecraft:spruce_door:east:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:east:lower:left:false:true";
case false:
return "minecraft:spruce_door:east:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:spruce_door:east:lower:right:true:true";
case false:
return "minecraft:spruce_door:east:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_door:east:lower:right:false:true";
case false:
return "minecraft:spruce_door:east:lower:right:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
