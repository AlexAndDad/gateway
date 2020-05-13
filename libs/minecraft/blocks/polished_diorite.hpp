#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct polished_diorite
{constexpr block_id_type to_id() const {
return 5;}
constexpr static polished_diorite from_id(block_id_type id)
{
return polished_diorite();
}
constexpr std::string_view to_string() const
{return "minecraft:polished_diorite";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
