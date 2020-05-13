#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct scaffolding
{bool bottom = false;
std::uint8_t distance = 7;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (bottom)
{
case true:
switch (distance)
{
case 0:
switch (waterlogged)
{
case true:
return 11099;
case false:
return 11100;
}
case 1:
switch (waterlogged)
{
case true:
return 11101;
case false:
return 11102;
}
case 2:
switch (waterlogged)
{
case true:
return 11103;
case false:
return 11104;
}
case 3:
switch (waterlogged)
{
case true:
return 11105;
case false:
return 11106;
}
case 4:
switch (waterlogged)
{
case true:
return 11107;
case false:
return 11108;
}
case 5:
switch (waterlogged)
{
case true:
return 11109;
case false:
return 11110;
}
case 6:
switch (waterlogged)
{
case true:
return 11111;
case false:
return 11112;
}
case 7:
switch (waterlogged)
{
case true:
return 11113;
case false:
return 11114;
}
}
case false:
switch (distance)
{
case 0:
switch (waterlogged)
{
case true:
return 11115;
case false:
return 11116;
}
case 1:
switch (waterlogged)
{
case true:
return 11117;
case false:
return 11118;
}
case 2:
switch (waterlogged)
{
case true:
return 11119;
case false:
return 11120;
}
case 3:
switch (waterlogged)
{
case true:
return 11121;
case false:
return 11122;
}
case 4:
switch (waterlogged)
{
case true:
return 11123;
case false:
return 11124;
}
case 5:
switch (waterlogged)
{
case true:
return 11125;
case false:
return 11126;
}
case 6:
switch (waterlogged)
{
case true:
return 11127;
case false:
return 11128;
}
case 7:
switch (waterlogged)
{
case true:
return 11129;
case false:
return 11130;
}
}
}
}
constexpr static scaffolding from_id(block_id_type id)
{
switch (id)
{
case 11099:
return {.bottom = true, .distance = 0, .waterlogged = true};
case 11100:
return {.bottom = true, .distance = 0, .waterlogged = false};
case 11101:
return {.bottom = true, .distance = 1, .waterlogged = true};
case 11102:
return {.bottom = true, .distance = 1, .waterlogged = false};
case 11103:
return {.bottom = true, .distance = 2, .waterlogged = true};
case 11104:
return {.bottom = true, .distance = 2, .waterlogged = false};
case 11105:
return {.bottom = true, .distance = 3, .waterlogged = true};
case 11106:
return {.bottom = true, .distance = 3, .waterlogged = false};
case 11107:
return {.bottom = true, .distance = 4, .waterlogged = true};
case 11108:
return {.bottom = true, .distance = 4, .waterlogged = false};
case 11109:
return {.bottom = true, .distance = 5, .waterlogged = true};
case 11110:
return {.bottom = true, .distance = 5, .waterlogged = false};
case 11111:
return {.bottom = true, .distance = 6, .waterlogged = true};
case 11112:
return {.bottom = true, .distance = 6, .waterlogged = false};
case 11113:
return {.bottom = true, .distance = 7, .waterlogged = true};
case 11114:
return {.bottom = true, .distance = 7, .waterlogged = false};
case 11115:
return {.bottom = false, .distance = 0, .waterlogged = true};
case 11116:
return {.bottom = false, .distance = 0, .waterlogged = false};
case 11117:
return {.bottom = false, .distance = 1, .waterlogged = true};
case 11118:
return {.bottom = false, .distance = 1, .waterlogged = false};
case 11119:
return {.bottom = false, .distance = 2, .waterlogged = true};
case 11120:
return {.bottom = false, .distance = 2, .waterlogged = false};
case 11121:
return {.bottom = false, .distance = 3, .waterlogged = true};
case 11122:
return {.bottom = false, .distance = 3, .waterlogged = false};
case 11123:
return {.bottom = false, .distance = 4, .waterlogged = true};
case 11124:
return {.bottom = false, .distance = 4, .waterlogged = false};
case 11125:
return {.bottom = false, .distance = 5, .waterlogged = true};
case 11126:
return {.bottom = false, .distance = 5, .waterlogged = false};
case 11127:
return {.bottom = false, .distance = 6, .waterlogged = true};
case 11128:
return {.bottom = false, .distance = 6, .waterlogged = false};
case 11129:
return {.bottom = false, .distance = 7, .waterlogged = true};
case 11130:
return {.bottom = false, .distance = 7, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (bottom)
{
case true:
switch (distance)
{
case 0:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:true:0:true";
case false:
return "minecraft:scaffolding:true:0:false";
}
case 1:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:true:1:true";
case false:
return "minecraft:scaffolding:true:1:false";
}
case 2:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:true:2:true";
case false:
return "minecraft:scaffolding:true:2:false";
}
case 3:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:true:3:true";
case false:
return "minecraft:scaffolding:true:3:false";
}
case 4:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:true:4:true";
case false:
return "minecraft:scaffolding:true:4:false";
}
case 5:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:true:5:true";
case false:
return "minecraft:scaffolding:true:5:false";
}
case 6:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:true:6:true";
case false:
return "minecraft:scaffolding:true:6:false";
}
case 7:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:true:7:true";
case false:
return "minecraft:scaffolding:true:7:false";
}
}
case false:
switch (distance)
{
case 0:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:false:0:true";
case false:
return "minecraft:scaffolding:false:0:false";
}
case 1:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:false:1:true";
case false:
return "minecraft:scaffolding:false:1:false";
}
case 2:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:false:2:true";
case false:
return "minecraft:scaffolding:false:2:false";
}
case 3:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:false:3:true";
case false:
return "minecraft:scaffolding:false:3:false";
}
case 4:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:false:4:true";
case false:
return "minecraft:scaffolding:false:4:false";
}
case 5:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:false:5:true";
case false:
return "minecraft:scaffolding:false:5:false";
}
case 6:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:false:6:true";
case false:
return "minecraft:scaffolding:false:6:false";
}
case 7:
switch (waterlogged)
{
case true:
return "minecraft:scaffolding:false:7:true";
case false:
return "minecraft:scaffolding:false:7:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
