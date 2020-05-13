#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct smooth_stone_slab
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
return 7806;
case false:
return 7807;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 7808;
case false:
return 7809;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 7810;
case false:
return 7811;
}
}
}
constexpr static smooth_stone_slab from_id(block_id_type id)
{
switch (id)
{
case 7806:
return {.type = type_type::top, .waterlogged = true};
case 7807:
return {.type = type_type::top, .waterlogged = false};
case 7808:
return {.type = type_type::bottom, .waterlogged = true};
case 7809:
return {.type = type_type::bottom, .waterlogged = false};
case 7810:
return {.type = type_type::double_, .waterlogged = true};
case 7811:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:smooth_stone_slab:top:true";
case false:
return "minecraft:smooth_stone_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:smooth_stone_slab:bottom:true";
case false:
return "minecraft:smooth_stone_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:smooth_stone_slab:double_:true";
case false:
return "minecraft:smooth_stone_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
