#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct polished_diorite_slab
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
return 10271;
case false:
return 10272;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 10273;
case false:
return 10274;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 10275;
case false:
return 10276;
}
}
}
constexpr static polished_diorite_slab from_id(block_id_type id)
{
switch (id)
{
case 10271:
return {.type = type_type::top, .waterlogged = true};
case 10272:
return {.type = type_type::top, .waterlogged = false};
case 10273:
return {.type = type_type::bottom, .waterlogged = true};
case 10274:
return {.type = type_type::bottom, .waterlogged = false};
case 10275:
return {.type = type_type::double_, .waterlogged = true};
case 10276:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_slab:top:true";
case false:
return "minecraft:polished_diorite_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_slab:bottom:true";
case false:
return "minecraft:polished_diorite_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:polished_diorite_slab:double_:true";
case false:
return "minecraft:polished_diorite_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
