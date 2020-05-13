#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct enchanting_table
{constexpr block_id_type to_id() const {
return 5116;}
constexpr static enchanting_table from_id(block_id_type id)
{
return enchanting_table();
}
constexpr std::string_view to_string() const
{return "minecraft:enchanting_table";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
