#include <ostream>
#include "minecraft/variant.hpp"

namespace minecraft::utils
{
    template < class X, class Y >
    constexpr bool same_type()
    {
        return std::is_same_v< std::decay_t< X >, std::decay_t< Y > >;
    }

    template < class... Ts >
    struct variant_printer
    {
        friend std::ostream &operator<<(std::ostream &os, variant_printer const &vp)
        {
            auto visitor = [&os](auto &&item) {
                if constexpr (same_type<decltype(item), monostate>())
                    os << "empty";
                else
                    os << item;
            };

            visit(visitor, vp.var);
            return os;
        }

        variant< Ts... > const& var;
    };

    template < class... Ts >
    auto print_variant(variant< Ts... > const &var)
    {
        return variant_printer< Ts... >{var};
    }
}   // namespace minecraft::utils