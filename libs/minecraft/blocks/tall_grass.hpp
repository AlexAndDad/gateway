#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct tall_grass
{enum class half_type : std::uint8_t
{
upper,
lower
} half = half_type::lower;
constexpr block_id_type to_id() const {
switch (half)
{
case half_type::upper:
return 7357;
case half_type::lower:
return 7358;
}
}
constexpr static tall_grass from_id(block_id_type id)
{
switch (id)
{
case 7357:
return {.half = half_type::upper};
case 7358:
return {.half = half_type::lower};
}}
constexpr std::string_view to_string() const
{switch (half)
{
case half_type::upper:
return "minecraft:tall_grass:upper";
case half_type::lower:
return "minecraft:tall_grass:lower";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
