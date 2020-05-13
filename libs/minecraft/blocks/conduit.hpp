#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct conduit
{bool waterlogged = true;
constexpr block_id_type to_id() const {
switch (waterlogged)
{
case true:
return 9113;
case false:
return 9114;
}
}
constexpr static conduit from_id(block_id_type id)
{
switch (id)
{
case 9113:
return {.waterlogged = true};
case 9114:
return {.waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (waterlogged)
{
case true:
return "minecraft:conduit:true";
case false:
return "minecraft:conduit:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
