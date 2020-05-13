#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct torch
{constexpr block_id_type to_id() const {
return 1434;}
constexpr static torch from_id(block_id_type id)
{
return torch();
}
constexpr std::string_view to_string() const
{return "minecraft:torch";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
