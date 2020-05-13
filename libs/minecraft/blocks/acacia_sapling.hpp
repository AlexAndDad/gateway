#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct acacia_sapling
{std::uint8_t stage = 0;
constexpr block_id_type to_id() const {
switch (stage)
{
case 0:
return 29;
case 1:
return 30;
}
}
constexpr static acacia_sapling from_id(block_id_type id)
{
switch (id)
{
case 29:
return {.stage = 0};
case 30:
return {.stage = 1};
}}
constexpr std::string_view to_string() const
{switch (stage)
{
case 0:
return "minecraft:acacia_sapling:0";
case 1:
return "minecraft:acacia_sapling:1";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
