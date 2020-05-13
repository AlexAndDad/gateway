#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct comparator
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
enum class mode_type : std::uint8_t
{
compare,
subtract
} mode = mode_type::compare;
bool powered = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (mode)
{
case mode_type::compare:
switch (powered)
{
case true:
return 6142;
case false:
return 6143;
}
case mode_type::subtract:
switch (powered)
{
case true:
return 6144;
case false:
return 6145;
}
}
case facing_type::south:
switch (mode)
{
case mode_type::compare:
switch (powered)
{
case true:
return 6146;
case false:
return 6147;
}
case mode_type::subtract:
switch (powered)
{
case true:
return 6148;
case false:
return 6149;
}
}
case facing_type::west:
switch (mode)
{
case mode_type::compare:
switch (powered)
{
case true:
return 6150;
case false:
return 6151;
}
case mode_type::subtract:
switch (powered)
{
case true:
return 6152;
case false:
return 6153;
}
}
case facing_type::east:
switch (mode)
{
case mode_type::compare:
switch (powered)
{
case true:
return 6154;
case false:
return 6155;
}
case mode_type::subtract:
switch (powered)
{
case true:
return 6156;
case false:
return 6157;
}
}
}
}
constexpr static comparator from_id(block_id_type id)
{
switch (id)
{
case 6142:
return {.facing = facing_type::north, .mode = mode_type::compare, .powered = true};
case 6143:
return {.facing = facing_type::north, .mode = mode_type::compare, .powered = false};
case 6144:
return {.facing = facing_type::north, .mode = mode_type::subtract, .powered = true};
case 6145:
return {.facing = facing_type::north, .mode = mode_type::subtract, .powered = false};
case 6146:
return {.facing = facing_type::south, .mode = mode_type::compare, .powered = true};
case 6147:
return {.facing = facing_type::south, .mode = mode_type::compare, .powered = false};
case 6148:
return {.facing = facing_type::south, .mode = mode_type::subtract, .powered = true};
case 6149:
return {.facing = facing_type::south, .mode = mode_type::subtract, .powered = false};
case 6150:
return {.facing = facing_type::west, .mode = mode_type::compare, .powered = true};
case 6151:
return {.facing = facing_type::west, .mode = mode_type::compare, .powered = false};
case 6152:
return {.facing = facing_type::west, .mode = mode_type::subtract, .powered = true};
case 6153:
return {.facing = facing_type::west, .mode = mode_type::subtract, .powered = false};
case 6154:
return {.facing = facing_type::east, .mode = mode_type::compare, .powered = true};
case 6155:
return {.facing = facing_type::east, .mode = mode_type::compare, .powered = false};
case 6156:
return {.facing = facing_type::east, .mode = mode_type::subtract, .powered = true};
case 6157:
return {.facing = facing_type::east, .mode = mode_type::subtract, .powered = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (mode)
{
case mode_type::compare:
switch (powered)
{
case true:
return "minecraft:comparator:north:compare:true";
case false:
return "minecraft:comparator:north:compare:false";
}
case mode_type::subtract:
switch (powered)
{
case true:
return "minecraft:comparator:north:subtract:true";
case false:
return "minecraft:comparator:north:subtract:false";
}
}
case facing_type::south:
switch (mode)
{
case mode_type::compare:
switch (powered)
{
case true:
return "minecraft:comparator:south:compare:true";
case false:
return "minecraft:comparator:south:compare:false";
}
case mode_type::subtract:
switch (powered)
{
case true:
return "minecraft:comparator:south:subtract:true";
case false:
return "minecraft:comparator:south:subtract:false";
}
}
case facing_type::west:
switch (mode)
{
case mode_type::compare:
switch (powered)
{
case true:
return "minecraft:comparator:west:compare:true";
case false:
return "minecraft:comparator:west:compare:false";
}
case mode_type::subtract:
switch (powered)
{
case true:
return "minecraft:comparator:west:subtract:true";
case false:
return "minecraft:comparator:west:subtract:false";
}
}
case facing_type::east:
switch (mode)
{
case mode_type::compare:
switch (powered)
{
case true:
return "minecraft:comparator:east:compare:true";
case false:
return "minecraft:comparator:east:compare:false";
}
case mode_type::subtract:
switch (powered)
{
case true:
return "minecraft:comparator:east:subtract:true";
case false:
return "minecraft:comparator:east:subtract:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
