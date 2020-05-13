#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct prismarine_brick_slab
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
return 7314;
case false:
return 7315;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 7316;
case false:
return 7317;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 7318;
case false:
return 7319;
}
}
}
constexpr static prismarine_brick_slab from_id(block_id_type id)
{
switch (id)
{
case 7314:
return {.type = type_type::top, .waterlogged = true};
case 7315:
return {.type = type_type::top, .waterlogged = false};
case 7316:
return {.type = type_type::bottom, .waterlogged = true};
case 7317:
return {.type = type_type::bottom, .waterlogged = false};
case 7318:
return {.type = type_type::double_, .waterlogged = true};
case 7319:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_slab:top:true";
case false:
return "minecraft:prismarine_brick_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_slab:bottom:true";
case false:
return "minecraft:prismarine_brick_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:prismarine_brick_slab:double_:true";
case false:
return "minecraft:prismarine_brick_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
