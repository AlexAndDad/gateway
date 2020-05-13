#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct diorite_slab
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
return 10325;
case false:
return 10326;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 10327;
case false:
return 10328;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 10329;
case false:
return 10330;
}
}
}
constexpr static diorite_slab from_id(block_id_type id)
{
switch (id)
{
case 10325:
return {.type = type_type::top, .waterlogged = true};
case 10326:
return {.type = type_type::top, .waterlogged = false};
case 10327:
return {.type = type_type::bottom, .waterlogged = true};
case 10328:
return {.type = type_type::bottom, .waterlogged = false};
case 10329:
return {.type = type_type::double_, .waterlogged = true};
case 10330:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:diorite_slab:top:true";
case false:
return "minecraft:diorite_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:diorite_slab:bottom:true";
case false:
return "minecraft:diorite_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:diorite_slab:double_:true";
case false:
return "minecraft:diorite_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
