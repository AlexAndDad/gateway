#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct polished_andesite_slab
{enum class type_type : std::uint8_t
{
top,
bottom,
double_
} type = type_type::bottom;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return 10319;
case false:
return 10320;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 10321;
case false:
return 10322;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 10323;
case false:
return 10324;
}
}
}
constexpr static polished_andesite_slab from_id(block_id_type id)
{
switch (id)
{
case 10319:
return {.type = type_type::top, .waterlogged = true};
case 10320:
return {.type = type_type::top, .waterlogged = false};
case 10321:
return {.type = type_type::bottom, .waterlogged = true};
case 10322:
return {.type = type_type::bottom, .waterlogged = false};
case 10323:
return {.type = type_type::double_, .waterlogged = true};
case 10324:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_slab:top:true";
case false:
return "minecraft:polished_andesite_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_slab:bottom:true";
case false:
return "minecraft:polished_andesite_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:polished_andesite_slab:double_:true";
case false:
return "minecraft:polished_andesite_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
