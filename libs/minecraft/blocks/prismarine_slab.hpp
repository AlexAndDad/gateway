#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct prismarine_slab
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
return 7308;
case false:
return 7309;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 7310;
case false:
return 7311;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 7312;
case false:
return 7313;
}
}
}
constexpr static prismarine_slab from_id(block_id_type id)
{
switch (id)
{
case 7308:
return {.type = type_type::top, .waterlogged = true};
case 7309:
return {.type = type_type::top, .waterlogged = false};
case 7310:
return {.type = type_type::bottom, .waterlogged = true};
case 7311:
return {.type = type_type::bottom, .waterlogged = false};
case 7312:
return {.type = type_type::double_, .waterlogged = true};
case 7313:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_slab:top:true";
case false:
return "minecraft:prismarine_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_slab:bottom:true";
case false:
return "minecraft:prismarine_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_slab:double_:true";
case false:
return "minecraft:prismarine_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
