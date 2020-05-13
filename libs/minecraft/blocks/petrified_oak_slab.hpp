#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct petrified_oak_slab
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
return 7824;
case false:
return 7825;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 7826;
case false:
return 7827;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 7828;
case false:
return 7829;
}
}
}
constexpr static petrified_oak_slab from_id(block_id_type id)
{
switch (id)
{
case 7824:
return {.type = type_type::top, .waterlogged = true};
case 7825:
return {.type = type_type::top, .waterlogged = false};
case 7826:
return {.type = type_type::bottom, .waterlogged = true};
case 7827:
return {.type = type_type::bottom, .waterlogged = false};
case 7828:
return {.type = type_type::double_, .waterlogged = true};
case 7829:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:petrified_oak_slab:top:true";
case false:
return "minecraft:petrified_oak_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:petrified_oak_slab:bottom:true";
case false:
return "minecraft:petrified_oak_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:petrified_oak_slab:double_:true";
case false:
return "minecraft:petrified_oak_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
