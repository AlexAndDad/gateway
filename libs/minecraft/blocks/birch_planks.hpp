#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct birch_planks
{constexpr block_id_type to_id() const {
return 17;}
constexpr static birch_planks from_id(block_id_type id)
{
return birch_planks();
}
constexpr std::string_view to_string() const
{return "minecraft:birch_planks";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
