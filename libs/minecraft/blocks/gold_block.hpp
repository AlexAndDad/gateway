#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct gold_block
{constexpr block_id_type to_id() const {
return 1426;}
constexpr static gold_block from_id(block_id_type id)
{
return gold_block();
}
constexpr std::string_view to_string() const
{return "minecraft:gold_block";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
