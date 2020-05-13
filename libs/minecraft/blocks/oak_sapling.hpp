#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct oak_sapling
{std::uint8_t stage = 0;
constexpr block_id_type to_id() const {
switch (stage)
{
case 0:
return 21;
case 1:
return 22;
}
}
constexpr static oak_sapling from_id(block_id_type id)
{
switch (id)
{
case 21:
return {.stage = 0};
case 22:
return {.stage = 1};
}}
constexpr std::string_view to_string() const
{switch (stage)
{
case 0:
return "minecraft:oak_sapling:0";
case 1:
return "minecraft:oak_sapling:1";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
