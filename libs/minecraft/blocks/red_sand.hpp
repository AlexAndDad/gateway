#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct red_sand
{constexpr block_id_type to_id() const {
return 67;}
constexpr static red_sand from_id(block_id_type id)
{
return red_sand();
}
constexpr std::string_view to_string() const
{return "minecraft:red_sand";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
