#include <ostream>
#include <variant>

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
                if constexpr (same_type<decltype(item), std::monostate>())
                    os << "empty";
                else
                    os << item;
            };

            std::visit(visitor, vp.var);
            return os;
        }

        std::variant< Ts... > const& var;
    };

    template < class... Ts >
    auto print_variant(std::variant< Ts... > const &var)
    {
        return variant_printer< Ts... >{var};
    }
}   // namespace minecraft::utils