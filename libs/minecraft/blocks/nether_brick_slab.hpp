#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct nether_brick_slab
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
return 7848;
case false:
return 7849;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 7850;
case false:
return 7851;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 7852;
case false:
return 7853;
}
}
}
constexpr static nether_brick_slab from_id(block_id_type id)
{
switch (id)
{
case 7848:
return {.type = type_type::top, .waterlogged = true};
case 7849:
return {.type = type_type::top, .waterlogged = false};
case 7850:
return {.type = type_type::bottom, .waterlogged = true};
case 7851:
return {.type = type_type::bottom, .waterlogged = false};
case 7852:
return {.type = type_type::double_, .waterlogged = true};
case 7853:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_slab:top:true";
case false:
return "minecraft:nether_brick_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_slab:bottom:true";
case false:
return "minecraft:nether_brick_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:nether_brick_slab:double_:true";
case false:
return "minecraft:nether_brick_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop