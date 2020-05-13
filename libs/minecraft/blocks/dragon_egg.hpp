#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dragon_egg
{constexpr block_id_type to_id() const {
return 5139;}
constexpr static dragon_egg from_id(block_id_type id)
{
return dragon_egg();
}
constexpr std::string_view to_string() const
{return "minecraft:dragon_egg";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
