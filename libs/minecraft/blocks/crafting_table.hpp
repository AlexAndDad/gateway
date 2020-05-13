#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct crafting_table
{constexpr block_id_type to_id() const {
return 3354;}
constexpr static crafting_table from_id(block_id_type id)
{
return crafting_table();
}
constexpr std::string_view to_string() const
{return "minecraft:crafting_table";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
