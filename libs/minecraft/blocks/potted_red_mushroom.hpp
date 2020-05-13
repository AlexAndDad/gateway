#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct potted_red_mushroom
{constexpr block_id_type to_id() const {
return 5790;}
constexpr static potted_red_mushroom from_id(block_id_type id)
{
return potted_red_mushroom();
}
constexpr std::string_view to_string() const
{return "minecraft:potted_red_mushroom";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop