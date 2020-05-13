#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct sandstone_slab
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
return 7812;
case false:
return 7813;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 7814;
case false:
return 7815;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 7816;
case false:
return 7817;
}
}
}
constexpr static sandstone_slab from_id(block_id_type id)
{
switch (id)
{
case 7812:
return {.type = type_type::top, .waterlogged = true};
case 7813:
return {.type = type_type::top, .waterlogged = false};
case 7814:
return {.type = type_type::bottom, .waterlogged = true};
case 7815:
return {.type = type_type::bottom, .waterlogged = false};
case 7816:
return {.type = type_type::double_, .waterlogged = true};
case 7817:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_slab:top:true";
case false:
return "minecraft:sandstone_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_slab:bottom:true";
case false:
return "minecraft:sandstone_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:sandstone_slab:double_:true";
case false:
return "minecraft:sandstone_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
