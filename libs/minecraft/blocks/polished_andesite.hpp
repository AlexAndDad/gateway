#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct polished_andesite
{constexpr block_id_type to_id() const {
return 7;}
constexpr static polished_andesite from_id(block_id_type id)
{
return polished_andesite();
}
constexpr std::string_view to_string() const
{return "minecraft:polished_andesite";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
