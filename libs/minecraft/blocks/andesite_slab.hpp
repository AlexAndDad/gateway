#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct andesite_slab
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
return 10307;
case false:
return 10308;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 10309;
case false:
return 10310;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 10311;
case false:
return 10312;
}
}
}
constexpr static andesite_slab from_id(block_id_type id)
{
switch (id)
{
case 10307:
return {.type = type_type::top, .waterlogged = true};
case 10308:
return {.type = type_type::top, .waterlogged = false};
case 10309:
return {.type = type_type::bottom, .waterlogged = true};
case 10310:
return {.type = type_type::bottom, .waterlogged = false};
case 10311:
return {.type = type_type::double_, .waterlogged = true};
case 10312:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:andesite_slab:top:true";
case false:
return "minecraft:andesite_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:andesite_slab:bottom:true";
case false:
return "minecraft:andesite_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:andesite_slab:double_:true";
case false:
return "minecraft:andesite_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
