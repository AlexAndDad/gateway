#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct melon
{constexpr block_id_type to_id() const {
return 4747;}
constexpr static melon from_id(block_id_type id)
{
return melon();
}
constexpr std::string_view to_string() const
{return "minecraft:melon";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
