#include "list.hpp"

#include "compound.hpp"

#include <string>

namespace minecraft::nbt
{
    list::list(tag_type type)
    : var_(visit_tag(
          []< tag_type Type >(tag_t< Type >) -> list_variant {
              using value_type = to_value_t< Type >;
              using list_type  = list_impl< value_type >;
              return list_type();
          },
          type))
    {
    }

    auto list::reset(tag_type new_type) -> void *
    {
        return visit_tag(
            [&]< tag_type Type >(tag_t< Type >) -> void * {
                using value_type = to_value_t< Type >;
                using list_type  = list_impl< value_type >;
                auto &nl         = var_.emplace< list_type >();
                return &nl;
            },
            new_type);
    }

    auto list::is(tag_type type) const -> bool
    {
        return visit([type]< class T >(list_impl< T > const &) { return to_tag_v< T > == type; }, var_);
    }

    void list::reserve(std::int32_t cap)
    {
        visit([cap](auto &vec) { vec.reserve(cap); }, var_);
    }

    auto list::size() const -> std::int32_t
    {
        return visit([]< class T >(list_impl< T > const &vec) { return vec.size(); }, var_);
    }

    auto operator==(list const &a, list const &b) -> bool
    {
        auto visitor = []< class A, class B >(A const &a, B const &b) {
            if constexpr (std::is_same_v< A, B >)
                return a == b;
            else
                return false;
        };
        return visit(visitor, a.var_, b.var_);
    }

}   // namespace minecraft::nbt
