#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct stone_slab
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
return 7800;
case false:
return 7801;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 7802;
case false:
return 7803;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 7804;
case false:
return 7805;
}
}
}
constexpr static stone_slab from_id(block_id_type id)
{
switch (id)
{
case 7800:
return {.type = type_type::top, .waterlogged = true};
case 7801:
return {.type = type_type::top, .waterlogged = false};
case 7802:
return {.type = type_type::bottom, .waterlogged = true};
case 7803:
return {.type = type_type::bottom, .waterlogged = false};
case 7804:
return {.type = type_type::double_, .waterlogged = true};
case 7805:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:stone_slab:top:true";
case false:
return "minecraft:stone_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:stone_slab:bottom:true";
case false:
return "minecraft:stone_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:stone_slab:double_:true";
case false:
return "minecraft:stone_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
