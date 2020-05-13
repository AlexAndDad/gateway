#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct stone_brick_slab
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
return 7842;
case false:
return 7843;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 7844;
case false:
return 7845;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 7846;
case false:
return 7847;
}
}
}
constexpr static stone_brick_slab from_id(block_id_type id)
{
switch (id)
{
case 7842:
return {.type = type_type::top, .waterlogged = true};
case 7843:
return {.type = type_type::top, .waterlogged = false};
case 7844:
return {.type = type_type::bottom, .waterlogged = true};
case 7845:
return {.type = type_type::bottom, .waterlogged = false};
case 7846:
return {.type = type_type::double_, .waterlogged = true};
case 7847:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_slab:top:true";
case false:
return "minecraft:stone_brick_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_slab:bottom:true";
case false:
return "minecraft:stone_brick_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_slab:double_:true";
case false:
return "minecraft:stone_brick_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
