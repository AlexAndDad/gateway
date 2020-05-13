#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct oak_slab
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
return 7764;
case false:
return 7765;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 7766;
case false:
return 7767;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 7768;
case false:
return 7769;
}
}
}
constexpr static oak_slab from_id(block_id_type id)
{
switch (id)
{
case 7764:
return {.type = type_type::top, .waterlogged = true};
case 7765:
return {.type = type_type::top, .waterlogged = false};
case 7766:
return {.type = type_type::bottom, .waterlogged = true};
case 7767:
return {.type = type_type::bottom, .waterlogged = false};
case 7768:
return {.type = type_type::double_, .waterlogged = true};
case 7769:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:oak_slab:top:true";
case false:
return "minecraft:oak_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:oak_slab:bottom:true";
case false:
return "minecraft:oak_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:oak_slab:double_:true";
case false:
return "minecraft:oak_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
