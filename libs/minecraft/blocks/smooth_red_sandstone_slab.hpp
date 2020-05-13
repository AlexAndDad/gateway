#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct smooth_red_sandstone_slab
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
return 10259;
case false:
return 10260;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 10261;
case false:
return 10262;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 10263;
case false:
return 10264;
}
}
}
constexpr static smooth_red_sandstone_slab from_id(block_id_type id)
{
switch (id)
{
case 10259:
return {.type = type_type::top, .waterlogged = true};
case 10260:
return {.type = type_type::top, .waterlogged = false};
case 10261:
return {.type = type_type::bottom, .waterlogged = true};
case 10262:
return {.type = type_type::bottom, .waterlogged = false};
case 10263:
return {.type = type_type::double_, .waterlogged = true};
case 10264:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_slab:top:true";
case false:
return "minecraft:smooth_red_sandstone_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_slab:bottom:true";
case false:
return "minecraft:smooth_red_sandstone_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:smooth_red_sandstone_slab:double_:true";
case false:
return "minecraft:smooth_red_sandstone_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
