#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct mossy_cobblestone_slab
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
return 10277;
case false:
return 10278;
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return 10279;
case false:
return 10280;
}
case type_type::double_:
switch (waterlogged)
{
case true:
return 10281;
case false:
return 10282;
}
}
}
constexpr static mossy_cobblestone_slab from_id(block_id_type id)
{
switch (id)
{
case 10277:
return {.type = type_type::top, .waterlogged = true};
case 10278:
return {.type = type_type::top, .waterlogged = false};
case 10279:
return {.type = type_type::bottom, .waterlogged = true};
case 10280:
return {.type = type_type::bottom, .waterlogged = false};
case 10281:
return {.type = type_type::double_, .waterlogged = true};
case 10282:
return {.type = type_type::double_, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (type)
{
case type_type::top:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_slab:top:true";
case false:
return "minecraft:mossy_cobblestone_slab:top:false";
}
case type_type::bottom:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_slab:bottom:true";
case false:
return "minecraft:mossy_cobblestone_slab:bottom:false";
}
case type_type::double_:
switch (waterlogged)
{
case true:
return "minecraft:mossy_cobblestone_slab:double_:true";
case false:
return "minecraft:mossy_cobblestone_slab:double_:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
