#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct potted_azure_bluet
{constexpr block_id_type to_id() const {
return 5781;}
constexpr static potted_azure_bluet from_id(block_id_type id)
{
return potted_azure_bluet();
}
constexpr std::string_view to_string() const
{return "minecraft:potted_azure_bluet";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
