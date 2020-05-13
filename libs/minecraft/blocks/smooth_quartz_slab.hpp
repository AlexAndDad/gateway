#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct smooth_quartz_slab
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
return 10295;
case false:
return 10296;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 10297;
case false:
return 10298;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 10299;
case false:
return 10300;
}
}
}
constexpr static smooth_quartz_slab from_id(block_id_type id)
{
switch (id)
{
case 10295:
return {.type = type_type::top, .waterlogged = true};
case 10296:
return {.type = type_type::top, .waterlogged = false};
case 10297:
return {.type = type_type::bottom, .waterlogged = true};
case 10298:
return {.type = type_type::bottom, .waterlogged = false};
case 10299:
return {.type = type_type::double_, .waterlogged = true};
case 10300:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_slab:top:true";
case false:
return "minecraft:smooth_quartz_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_slab:bottom:true";
case false:
return "minecraft:smooth_quartz_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_slab:double_:true";
case false:
return "minecraft:smooth_quartz_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
