#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct bamboo
{std::uint8_t age = 0;
enum class leaves_type : std::uint8_t
{
none,
small,
large
} leaves = leaves_type::none;
std::uint8_t stage = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
switch (leaves)
{
case leaves_type::none:
switch (stage)
{
case 0:
return 9116;
case 1:
return 9117;
}
case leaves_type::small:
switch (stage)
{
case 0:
return 9118;
case 1:
return 9119;
}
case leaves_type::large:
switch (stage)
{
case 0:
return 9120;
case 1:
return 9121;
}
}
case 1:
switch (leaves)
{
case leaves_type::none:
switch (stage)
{
case 0:
return 9122;
case 1:
return 9123;
}
case leaves_type::small:
switch (stage)
{
case 0:
return 9124;
case 1:
return 9125;
}
case leaves_type::large:
switch (stage)
{
case 0:
return 9126;
case 1:
return 9127;
}
}
}
}
constexpr static bamboo from_id(block_id_type id)
{
switch (id)
{
case 9116:
return {.age = 0, .leaves = leaves_type::none, .stage = 0};
case 9117:
return {.age = 0, .leaves = leaves_type::none, .stage = 1};
case 9118:
return {.age = 0, .leaves = leaves_type::small, .stage = 0};
case 9119:
return {.age = 0, .leaves = leaves_type::small, .stage = 1};
case 9120:
return {.age = 0, .leaves = leaves_type::large, .stage = 0};
case 9121:
return {.age = 0, .leaves = leaves_type::large, .stage = 1};
case 9122:
return {.age = 1, .leaves = leaves_type::none, .stage = 0};
case 9123:
return {.age = 1, .leaves = leaves_type::none, .stage = 1};
case 9124:
return {.age = 1, .leaves = leaves_type::small, .stage = 0};
case 9125:
return {.age = 1, .leaves = leaves_type::small, .stage = 1};
case 9126:
return {.age = 1, .leaves = leaves_type::large, .stage = 0};
case 9127:
return {.age = 1, .leaves = leaves_type::large, .stage = 1};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
switch (leaves)
{
case leaves_type::none:
switch (stage)
{
case 0:
return "minecraft:bamboo:0:none:0";
case 1:
return "minecraft:bamboo:0:none:1";
}
case leaves_type::small:
switch (stage)
{
case 0:
return "minecraft:bamboo:0:small:0";
case 1:
return "minecraft:bamboo:0:small:1";
}
case leaves_type::large:
switch (stage)
{
case 0:
return "minecraft:bamboo:0:large:0";
case 1:
return "minecraft:bamboo:0:large:1";
}
}
case 1:
switch (leaves)
{
case leaves_type::none:
switch (stage)
{
case 0:
return "minecraft:bamboo:1:none:0";
case 1:
return "minecraft:bamboo:1:none:1";
}
case leaves_type::small:
switch (stage)
{
case 0:
return "minecraft:bamboo:1:small:0";
case 1:
return "minecraft:bamboo:1:small:1";
}
case leaves_type::large:
switch (stage)
{
case 0:
return "minecraft:bamboo:1:large:0";
case 1:
return "minecraft:bamboo:1:large:1";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
