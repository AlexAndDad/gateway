#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct honeycomb_block
{constexpr block_id_type to_id() const {
return 11336;}
constexpr static honeycomb_block from_id(block_id_type id)
{
return honeycomb_block();
}
constexpr std::string_view to_string() const
{return "minecraft:honeycomb_block";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
