#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct grass_block
{bool snowy = false;
constexpr block_id_type to_id() const {
switch (snowy)
{
case true:
return 8;
case false:
return 9;
}
}
constexpr static grass_block from_id(block_id_type id)
{
switch (id)
{
case 8:
return {.snowy = true};
case 9:
return {.snowy = false};
}}
constexpr std::string_view to_string() const
{switch (snowy)
{
case true:
return "minecraft:grass_block:true";
case false:
return "minecraft:grass_block:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
