#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct glass
{constexpr block_id_type to_id() const {
return 230;}
constexpr static glass from_id(block_id_type id)
{
return glass();
}
constexpr std::string_view to_string() const
{return "minecraft:glass";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
