#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct birch_slab
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
return 7776;
case false:
return 7777;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 7778;
case false:
return 7779;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 7780;
case false:
return 7781;
}
}
}
constexpr static birch_slab from_id(block_id_type id)
{
switch (id)
{
case 7776:
return {.type = type_type::top, .waterlogged = true};
case 7777:
return {.type = type_type::top, .waterlogged = false};
case 7778:
return {.type = type_type::bottom, .waterlogged = true};
case 7779:
return {.type = type_type::bottom, .waterlogged = false};
case 7780:
return {.type = type_type::double_, .waterlogged = true};
case 7781:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:birch_slab:top:true";
case false:
return "minecraft:birch_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:birch_slab:bottom:true";
case false:
return "minecraft:birch_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:birch_slab:double_:true";
case false:
return "minecraft:birch_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
