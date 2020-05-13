#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct brain_coral
{bool waterlogged = true;
constexpr block_id_type to_id() const {
switch (waterlogged)
{
case true:
return 8996;
case false:
return 8997;
}
}
constexpr static brain_coral from_id(block_id_type id)
{
switch (id)
{
case 8996:
return {.waterlogged = true};
case 8997:
return {.waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (waterlogged)
{
case true:
return "minecraft:brain_coral:true";
case false:
return "minecraft:brain_coral:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
