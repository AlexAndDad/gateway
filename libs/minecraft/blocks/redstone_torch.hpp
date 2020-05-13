#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct redstone_torch
{bool lit = true;
constexpr block_id_type to_id() const {
switch (lit)
{
case true:
return 3885;
case false:
return 3886;
}
}
constexpr static redstone_torch from_id(block_id_type id)
{
switch (id)
{
case 3885:
return {.lit = true};
case 3886:
return {.lit = false};
}}
constexpr std::string_view to_string() const
{switch (lit)
{
case true:
return "minecraft:redstone_torch:true";
case false:
return "minecraft:redstone_torch:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
