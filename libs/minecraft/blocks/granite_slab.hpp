#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct granite_slab
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
return 10301;
case false:
return 10302;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 10303;
case false:
return 10304;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 10305;
case false:
return 10306;
}
}
}
constexpr static granite_slab from_id(block_id_type id)
{
switch (id)
{
case 10301:
return {.type = type_type::top, .waterlogged = true};
case 10302:
return {.type = type_type::top, .waterlogged = false};
case 10303:
return {.type = type_type::bottom, .waterlogged = true};
case 10304:
return {.type = type_type::bottom, .waterlogged = false};
case 10305:
return {.type = type_type::double_, .waterlogged = true};
case 10306:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:granite_slab:top:true";
case false:
return "minecraft:granite_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:granite_slab:bottom:true";
case false:
return "minecraft:granite_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:granite_slab:double_:true";
case false:
return "minecraft:granite_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
