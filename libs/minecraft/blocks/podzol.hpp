#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct podzol
{bool snowy = false;
constexpr block_id_type to_id() const {
switch (snowy)
{
case true:
return 12;
case false:
return 13;
}
}
constexpr static podzol from_id(block_id_type id)
{
switch (id)
{
case 12:
return {.snowy = true};
case 13:
return {.snowy = false};
}}
constexpr std::string_view to_string() const
{switch (snowy)
{
case true:
return "minecraft:podzol:true";
case false:
return "minecraft:podzol:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
