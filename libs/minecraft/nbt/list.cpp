#include "list.hpp"

#include "compound.hpp"

#include <string>

namespace minecraft::nbt
{
    list::list(tag_type type)
    : var_(visit_tag(overloaded { [](tag_t< tag_type::End >) -> list_variant { throw "invalid tag"; },
                                  []< tag_type Type >(tag_t< Type >) -> list_variant {
                                      using value_type = to_value_t< Type >;
                                      using list_type  = list_impl< value_type >;
                                      return list_type();
                                  } },
                     type))
    {
    }

    auto list::type_name() const -> std::string_view
    {
        return visit(
            []< class T >(list_impl< T > const &) {
                switch (to_tag_v< T >)
                {
                case End: return "end";
                case Byte: return "byte";
                case Short: return "short";
                case Int: return "int";
                case Long: return "long";
                case Float: return "float";
                case Double: return "double";
                case String: return "string";
                case List: return "list";
                case Compound: return "compound";
                case Int_Array: return "int array";
                case Byte_Array: return "byte array";
                case Long_Array: return "long array";
                }
            },
            var_);
    }

    void list::reserve(std::int32_t cap)
    {
        visit([cap](auto &vec) { vec.reserve(cap); }, var_);
    }

    auto list::size() const -> std::int32_t
    {
        return visit([]< class T >(list_impl< T > const &vec) { return vec.size(); }, var_);
    }

    auto operator==(list const& a, list const& b) -> bool
    {
        auto visitor = []<class A, class B>(A const& a, B const& b)
        {
            if constexpr (std::is_same_v<A, B>)
                return a == b;
            else
                return false;
        };
        return visit(visitor, a.var_, b.var_);
    }


}   // namespace minecraft::nbt
