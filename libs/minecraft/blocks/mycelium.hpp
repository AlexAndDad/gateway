#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct mycelium
{bool snowy = false;
constexpr block_id_type to_id() const {
switch (snowy)
{
case true:
return 4996;
case false:
return 4997;
}
}
constexpr static mycelium from_id(block_id_type id)
{
switch (id)
{
case 4996:
return {.snowy = true};
case 4997:
return {.snowy = false};
}}
constexpr std::string_view to_string() const
{switch (snowy)
{
case true:
return "minecraft:mycelium:true";
case false:
return "minecraft:mycelium:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
