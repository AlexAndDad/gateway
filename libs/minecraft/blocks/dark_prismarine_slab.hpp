#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dark_prismarine_slab
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
return 7320;
case false:
return 7321;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 7322;
case false:
return 7323;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 7324;
case false:
return 7325;
}
}
}
constexpr static dark_prismarine_slab from_id(block_id_type id)
{
switch (id)
{
case 7320:
return {.type = type_type::top, .waterlogged = true};
case 7321:
return {.type = type_type::top, .waterlogged = false};
case 7322:
return {.type = type_type::bottom, .waterlogged = true};
case 7323:
return {.type = type_type::bottom, .waterlogged = false};
case 7324:
return {.type = type_type::double_, .waterlogged = true};
case 7325:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_slab:top:true";
case false:
return "minecraft:dark_prismarine_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_slab:bottom:true";
case false:
return "minecraft:dark_prismarine_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:dark_prismarine_slab:double_:true";
case false:
return "minecraft:dark_prismarine_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
