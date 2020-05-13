#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct turtle_egg
{std::uint8_t eggs = 1;
std::uint8_t hatch = 0;
constexpr block_id_type to_id() const {
switch (eggs)
{
case 1:
switch (hatch)
{
case 0:
return 8962;
case 1:
return 8963;
case 2:
return 8964;
}
case 2:
switch (hatch)
{
case 0:
return 8965;
case 1:
return 8966;
case 2:
return 8967;
}
case 3:
switch (hatch)
{
case 0:
return 8968;
case 1:
return 8969;
case 2:
return 8970;
}
case 4:
switch (hatch)
{
case 0:
return 8971;
case 1:
return 8972;
case 2:
return 8973;
}
}
}
constexpr static turtle_egg from_id(block_id_type id)
{
switch (id)
{
case 8962:
return {.eggs = 1, .hatch = 0};
case 8963:
return {.eggs = 1, .hatch = 1};
case 8964:
return {.eggs = 1, .hatch = 2};
case 8965:
return {.eggs = 2, .hatch = 0};
case 8966:
return {.eggs = 2, .hatch = 1};
case 8967:
return {.eggs = 2, .hatch = 2};
case 8968:
return {.eggs = 3, .hatch = 0};
case 8969:
return {.eggs = 3, .hatch = 1};
case 8970:
return {.eggs = 3, .hatch = 2};
case 8971:
return {.eggs = 4, .hatch = 0};
case 8972:
return {.eggs = 4, .hatch = 1};
case 8973:
return {.eggs = 4, .hatch = 2};
}}
constexpr std::string_view to_string() const
{switch (eggs)
{
case 1:
switch (hatch)
{
case 0:
return "minecraft:turtle_egg:1:0";
case 1:
return "minecraft:turtle_egg:1:1";
case 2:
return "minecraft:turtle_egg:1:2";
}
case 2:
switch (hatch)
{
case 0:
return "minecraft:turtle_egg:2:0";
case 1:
return "minecraft:turtle_egg:2:1";
case 2:
return "minecraft:turtle_egg:2:2";
}
case 3:
switch (hatch)
{
case 0:
return "minecraft:turtle_egg:3:0";
case 1:
return "minecraft:turtle_egg:3:1";
case 2:
return "minecraft:turtle_egg:3:2";
}
case 4:
switch (hatch)
{
case 0:
return "minecraft:turtle_egg:4:0";
case 1:
return "minecraft:turtle_egg:4:1";
case 2:
return "minecraft:turtle_egg:4:2";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
