#include "nbt.hpp"

namespace minecraft::nbt
{
    template < class T, class U >
    constexpr bool value_equals(T const &, U const &)
    {
        return false;
    }

    template < class T >
    constexpr bool value_equals(T const &l, T const &r)
    {
        return l == r;
    }

    bool value::operator==(value const &other) const {

        auto visitor = [](auto&& l, auto&& r)
        {
            return value_equals(l, r);
        };
        return visit(visitor, as_variant(), other.as_variant());
    }

    std::ostream& operator<<(std::ostream& os, value const& arg)
    {
        auto visitor = [&os](auto&& x)
        {
            os << x;
        };

        visit(visitor, arg.as_variant());

        return os;
    }

}   // namespace minecraft::nbt