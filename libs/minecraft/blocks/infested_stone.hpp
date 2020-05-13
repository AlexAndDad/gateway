#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct infested_stone
{constexpr block_id_type to_id() const {
return 4485;}
constexpr static infested_stone from_id(block_id_type id)
{
return infested_stone();
}
constexpr std::string_view to_string() const
{return "minecraft:infested_stone";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
