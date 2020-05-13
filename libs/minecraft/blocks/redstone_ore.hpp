#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct redstone_ore
{bool lit = false;
constexpr block_id_type to_id() const {
switch (lit)
{
case true:
return 3883;
case false:
return 3884;
}
}
constexpr static redstone_ore from_id(block_id_type id)
{
switch (id)
{
case 3883:
return {.lit = true};
case 3884:
return {.lit = false};
}}
constexpr std::string_view to_string() const
{switch (lit)
{
case true:
return "minecraft:redstone_ore:true";
case false:
return "minecraft:redstone_ore:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
