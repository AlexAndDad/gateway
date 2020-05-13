#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct end_stone_brick_slab
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
return 10283;
case false:
return 10284;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 10285;
case false:
return 10286;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 10287;
case false:
return 10288;
}
}
}
constexpr static end_stone_brick_slab from_id(block_id_type id)
{
switch (id)
{
case 10283:
return {.type = type_type::top, .waterlogged = true};
case 10284:
return {.type = type_type::top, .waterlogged = false};
case 10285:
return {.type = type_type::bottom, .waterlogged = true};
case 10286:
return {.type = type_type::bottom, .waterlogged = false};
case 10287:
return {.type = type_type::double_, .waterlogged = true};
case 10288:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_slab:top:true";
case false:
return "minecraft:end_stone_brick_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_slab:bottom:true";
case false:
return "minecraft:end_stone_brick_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:end_stone_brick_slab:double_:true";
case false:
return "minecraft:end_stone_brick_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
