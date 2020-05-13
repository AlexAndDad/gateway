#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct netherrack
{constexpr block_id_type to_id() const {
return 3997;}
constexpr static netherrack from_id(block_id_type id)
{
return netherrack();
}
constexpr std::string_view to_string() const
{return "minecraft:netherrack";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
