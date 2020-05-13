#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct cobblestone_slab
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
return 7830;
case false:
return 7831;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 7832;
case false:
return 7833;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 7834;
case false:
return 7835;
}
}
}
constexpr static cobblestone_slab from_id(block_id_type id)
{
switch (id)
{
case 7830:
return {.type = type_type::top, .waterlogged = true};
case 7831:
return {.type = type_type::top, .waterlogged = false};
case 7832:
return {.type = type_type::bottom, .waterlogged = true};
case 7833:
return {.type = type_type::bottom, .waterlogged = false};
case 7834:
return {.type = type_type::double_, .waterlogged = true};
case 7835:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_slab:top:true";
case false:
return "minecraft:cobblestone_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_slab:bottom:true";
case false:
return "minecraft:cobblestone_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_slab:double_:true";
case false:
return "minecraft:cobblestone_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
