#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct lectern
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool has_book = false;
bool powered = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (has_book)
{
case true:
switch (powered)
{
case true:
return 11177;
case false:
return 11178;
}
case false:
switch (powered)
{
case true:
return 11179;
case false:
return 11180;
}
}
case facing_type::south:
switch (has_book)
{
case true:
switch (powered)
{
case true:
return 11181;
case false:
return 11182;
}
case false:
switch (powered)
{
case true:
return 11183;
case false:
return 11184;
}
}
case facing_type::west:
switch (has_book)
{
case true:
switch (powered)
{
case true:
return 11185;
case false:
return 11186;
}
case false:
switch (powered)
{
case true:
return 11187;
case false:
return 11188;
}
}
case facing_type::east:
switch (has_book)
{
case true:
switch (powered)
{
case true:
return 11189;
case false:
return 11190;
}
case false:
switch (powered)
{
case true:
return 11191;
case false:
return 11192;
}
}
}
}
constexpr static lectern from_id(block_id_type id)
{
switch (id)
{
case 11177:
return {.facing = facing_type::north, .has_book = true, .powered = true};
case 11178:
return {.facing = facing_type::north, .has_book = true, .powered = false};
case 11179:
return {.facing = facing_type::north, .has_book = false, .powered = true};
case 11180:
return {.facing = facing_type::north, .has_book = false, .powered = false};
case 11181:
return {.facing = facing_type::south, .has_book = true, .powered = true};
case 11182:
return {.facing = facing_type::south, .has_book = true, .powered = false};
case 11183:
return {.facing = facing_type::south, .has_book = false, .powered = true};
case 11184:
return {.facing = facing_type::south, .has_book = false, .powered = false};
case 11185:
return {.facing = facing_type::west, .has_book = true, .powered = true};
case 11186:
return {.facing = facing_type::west, .has_book = true, .powered = false};
case 11187:
return {.facing = facing_type::west, .has_book = false, .powered = true};
case 11188:
return {.facing = facing_type::west, .has_book = false, .powered = false};
case 11189:
return {.facing = facing_type::east, .has_book = true, .powered = true};
case 11190:
return {.facing = facing_type::east, .has_book = true, .powered = false};
case 11191:
return {.facing = facing_type::east, .has_book = false, .powered = true};
case 11192:
return {.facing = facing_type::east, .has_book = false, .powered = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (has_book)
{
case true:
switch (powered)
{
case true:
return "minecraft:lectern:north:true:true";
case false:
return "minecraft:lectern:north:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:lectern:north:false:true";
case false:
return "minecraft:lectern:north:false:false";
}
}
case facing_type::south:
switch (has_book)
{
case true:
switch (powered)
{
case true:
return "minecraft:lectern:south:true:true";
case false:
return "minecraft:lectern:south:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:lectern:south:false:true";
case false:
return "minecraft:lectern:south:false:false";
}
}
case facing_type::west:
switch (has_book)
{
case true:
switch (powered)
{
case true:
return "minecraft:lectern:west:true:true";
case false:
return "minecraft:lectern:west:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:lectern:west:false:true";
case false:
return "minecraft:lectern:west:false:false";
}
}
case facing_type::east:
switch (has_book)
{
case true:
switch (powered)
{
case true:
return "minecraft:lectern:east:true:true";
case false:
return "minecraft:lectern:east:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:lectern:east:false:true";
case false:
return "minecraft:lectern:east:false:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
