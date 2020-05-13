#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct poppy
{constexpr block_id_type to_id() const {
return 1412;}
constexpr static poppy from_id(block_id_type id)
{
return poppy();
}
constexpr std::string_view to_string() const
{return "minecraft:poppy";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
