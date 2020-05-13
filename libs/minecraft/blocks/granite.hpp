#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct granite
{constexpr block_id_type to_id() const {
return 2;}
constexpr static granite from_id(block_id_type id)
{
return granite();
}
constexpr std::string_view to_string() const
{return "minecraft:granite";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
