#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jukebox
{bool has_record = false;
constexpr block_id_type to_id() const {
switch (has_record)
{
case true:
return 3962;
case false:
return 3963;
}
}
constexpr static jukebox from_id(block_id_type id)
{
switch (id)
{
case 3962:
return {.has_record = true};
case 3963:
return {.has_record = false};
}}
constexpr std::string_view to_string() const
{switch (has_record)
{
case true:
return "minecraft:jukebox:true";
case false:
return "minecraft:jukebox:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
