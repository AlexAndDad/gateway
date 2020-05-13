#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct purpur_stairs
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
enum class half_type : std::uint8_t
{
top,
bottom
} half = half_type::bottom;
enum class shape_type : std::uint8_t
{
straight,
inner_left,
inner_right,
outer_left,
outer_right
} shape = shape_type::straight;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 8602;
case false:
return 8603;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 8604;
case false:
return 8605;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 8606;
case false:
return 8607;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 8608;
case false:
return 8609;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 8610;
case false:
return 8611;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 8612;
case false:
return 8613;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 8614;
case false:
return 8615;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 8616;
case false:
return 8617;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 8618;
case false:
return 8619;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 8620;
case false:
return 8621;
}
}
}
case facing_type::south:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 8622;
case false:
return 8623;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 8624;
case false:
return 8625;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 8626;
case false:
return 8627;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 8628;
case false:
return 8629;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 8630;
case false:
return 8631;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 8632;
case false:
return 8633;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 8634;
case false:
return 8635;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 8636;
case false:
return 8637;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 8638;
case false:
return 8639;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 8640;
case false:
return 8641;
}
}
}
case facing_type::west:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 8642;
case false:
return 8643;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 8644;
case false:
return 8645;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 8646;
case false:
return 8647;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 8648;
case false:
return 8649;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 8650;
case false:
return 8651;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 8652;
case false:
return 8653;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 8654;
case false:
return 8655;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 8656;
case false:
return 8657;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 8658;
case false:
return 8659;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 8660;
case false:
return 8661;
}
}
}
case facing_type::east:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 8662;
case false:
return 8663;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 8664;
case false:
return 8665;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 8666;
case false:
return 8667;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 8668;
case false:
return 8669;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 8670;
case false:
return 8671;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 8672;
case false:
return 8673;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 8674;
case false:
return 8675;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 8676;
case false:
return 8677;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 8678;
case false:
return 8679;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 8680;
case false:
return 8681;
}
}
}
}
}
constexpr static purpur_stairs from_id(block_id_type id)
{
switch (id)
{
case 8602:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 8603:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 8604:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 8605:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 8606:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 8607:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 8608:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 8609:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 8610:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 8611:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 8612:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 8613:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 8614:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 8615:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 8616:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 8617:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 8618:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 8619:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 8620:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 8621:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 8622:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 8623:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 8624:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 8625:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 8626:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 8627:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 8628:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 8629:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 8630:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 8631:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 8632:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 8633:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 8634:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 8635:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 8636:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 8637:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 8638:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 8639:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 8640:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 8641:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 8642:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 8643:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 8644:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 8645:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 8646:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 8647:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 8648:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 8649:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 8650:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 8651:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 8652:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 8653:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 8654:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 8655:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 8656:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 8657:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 8658:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 8659:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 8660:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 8661:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 8662:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 8663:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 8664:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 8665:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 8666:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 8667:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 8668:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 8669:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 8670:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 8671:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 8672:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 8673:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 8674:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 8675:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 8676:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 8677:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 8678:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 8679:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 8680:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 8681:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:north:top:straight:true";
case false:
return "minecraft:purpur_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:north:top:inner_left:true";
case false:
return "minecraft:purpur_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:north:top:inner_right:true";
case false:
return "minecraft:purpur_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:north:top:outer_left:true";
case false:
return "minecraft:purpur_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:north:top:outer_right:true";
case false:
return "minecraft:purpur_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:north:bottom:straight:true";
case false:
return "minecraft:purpur_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:purpur_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:purpur_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:purpur_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:purpur_stairs:north:bottom:outer_right:false";
}
}
}
case facing_type::south:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:south:top:straight:true";
case false:
return "minecraft:purpur_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:south:top:inner_left:true";
case false:
return "minecraft:purpur_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:south:top:inner_right:true";
case false:
return "minecraft:purpur_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:south:top:outer_left:true";
case false:
return "minecraft:purpur_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:south:top:outer_right:true";
case false:
return "minecraft:purpur_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:south:bottom:straight:true";
case false:
return "minecraft:purpur_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:purpur_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:purpur_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:purpur_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:purpur_stairs:south:bottom:outer_right:false";
}
}
}
case facing_type::west:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:west:top:straight:true";
case false:
return "minecraft:purpur_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:west:top:inner_left:true";
case false:
return "minecraft:purpur_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:west:top:inner_right:true";
case false:
return "minecraft:purpur_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:west:top:outer_left:true";
case false:
return "minecraft:purpur_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:west:top:outer_right:true";
case false:
return "minecraft:purpur_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:west:bottom:straight:true";
case false:
return "minecraft:purpur_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:purpur_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:purpur_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:purpur_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:purpur_stairs:west:bottom:outer_right:false";
}
}
}
case facing_type::east:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:east:top:straight:true";
case false:
return "minecraft:purpur_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:east:top:inner_left:true";
case false:
return "minecraft:purpur_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:east:top:inner_right:true";
case false:
return "minecraft:purpur_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:east:top:outer_left:true";
case false:
return "minecraft:purpur_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:east:top:outer_right:true";
case false:
return "minecraft:purpur_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:east:bottom:straight:true";
case false:
return "minecraft:purpur_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:purpur_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:purpur_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:purpur_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:purpur_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:purpur_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
