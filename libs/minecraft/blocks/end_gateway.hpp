#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct end_gateway
{constexpr block_id_type to_id() const {
return 8688;}
constexpr static end_gateway from_id(block_id_type id)
{
return end_gateway();
}
constexpr std::string_view to_string() const
{return "minecraft:end_gateway";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
