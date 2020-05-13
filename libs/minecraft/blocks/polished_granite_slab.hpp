#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct polished_granite_slab
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
return 10253;
case false:
return 10254;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 10255;
case false:
return 10256;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 10257;
case false:
return 10258;
}
}
}
constexpr static polished_granite_slab from_id(block_id_type id)
{
switch (id)
{
case 10253:
return {.type = type_type::top, .waterlogged = true};
case 10254:
return {.type = type_type::top, .waterlogged = false};
case 10255:
return {.type = type_type::bottom, .waterlogged = true};
case 10256:
return {.type = type_type::bottom, .waterlogged = false};
case 10257:
return {.type = type_type::double_, .waterlogged = true};
case 10258:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_slab:top:true";
case false:
return "minecraft:polished_granite_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_slab:bottom:true";
case false:
return "minecraft:polished_granite_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:polished_granite_slab:double_:true";
case false:
return "minecraft:polished_granite_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
