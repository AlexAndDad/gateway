#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct redstone_lamp
{bool lit = false;
constexpr block_id_type to_id() const {
switch (lit)
{
case true:
return 5140;
case false:
return 5141;
}
}
constexpr static redstone_lamp from_id(block_id_type id)
{
switch (id)
{
case 5140:
return {.lit = true};
case 5141:
return {.lit = false};
}}
constexpr std::string_view to_string() const
{switch (lit)
{
case true:
return "minecraft:redstone_lamp:true";
case false:
return "minecraft:redstone_lamp:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop