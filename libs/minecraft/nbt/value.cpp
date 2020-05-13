#include "value.hpp"

#include "parse_context.hpp"
#include "pretty_printer.hpp"
#include "printer.hpp"
#include "value_parse_handler.hpp"

namespace minecraft::nbt
{
    value::value()
    : var_(monostate())
    {
    }

    compound &value::get_compound()
    {
        assert(holds_alternative< compound >(var_));
        return get< compound >(var_);
    }
    compound const &value::get_compound() const
    {
        assert(holds_alternative< compound >(var_));
        return get< compound >(var_);
    }

    list &value::get_list()
    {
        assert(holds_alternative< list >(var_));
        return get< list >(var_);
    }
    list const &value::get_list() const
    {
        assert(holds_alternative< list >(var_));
        return get< list >(var_);
    }

    string &value::get_string()
    {
        assert(holds_alternative< string >(var_));
        return get< string >(var_);
    }

    int_array &value::get_int_array()
    {
        assert(holds_alternative< int_array >(var_));
        return get< int_array >(var_);
    }

    byte_array &value::get_byte_array()
    {
        assert(holds_alternative< byte_array >(var_));
        return get< byte_array >(var_);
    }
    long_array &value::get_long_array()
    {
        assert(holds_alternative< long_array >(var_));
        return get< long_array >(var_);
    }

    bool value::is(tag_type tag) const
    {
        switch (tag)
        {
            // clang-format off
        case End: return holds_alternative<to_value_t<End> >(var_);
        case Byte: return holds_alternative<to_value_t<Byte> >(var_);
        case Short: return holds_alternative<to_value_t<Short> >(var_);
        case Int: return holds_alternative<to_value_t<Int> >(var_);
        case Long: return holds_alternative<to_value_t<Long> >(var_);
        case Double: return holds_alternative<to_value_t<Double> >(var_);
        case Float: return holds_alternative<to_value_t<Float> >(var_);
        case String: return holds_alternative<to_value_t<String> >(var_);
        case List: return holds_alternative<to_value_t<List> >(var_);
        case Compound: return holds_alternative<to_value_t<Compound> >(var_);
        case Int_Array: return holds_alternative<to_value_t<Int_Array> >(var_);
        case Byte_Array: return holds_alternative<to_value_t<Byte_Array> >(var_);
        case Long_Array: return holds_alternative<to_value_t<Long_Array> >(var_);
            // clang-format on
        }
    }

    auto value::operator[](std::int32_t const &n) -> list::setter
    {
        return visit(
            [n]<class Actual>(Actual &a) -> list::setter {
                if constexpr (std::is_same_v<Actual, list>)
                    return a[n];
                else
                    throw system_error(error::logic_error::list_required);
            },
            as_variant());
    }

    compound::mapped_type &value::operator[](string const& k) {
        if (is(Compound))
        {
            return get_compound()[k];
        }
        else
            throw system_error(error::compound_required);
    }

    compound::mapped_type const &value::operator[](string const& k) const {
        if (is(Compound))
        {
            return get_compound().at(k);
        }
        else
            throw system_error(error::compound_required);
    }

    tag_type value::type() const
    {
        return visit([]< class T >(T const &) { return to_tag_v< T >; }, var_);
    }

    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, value &target, error_code &ec)
    {
        if (ec)
            return first;

        auto context = make_parse_context(value_parse_handler());
        auto next    = parse(first, last, context, ec);
        if (not ec)
        {
            target = value(context.handler().to_compound());
        }
        return next;
    }

    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, value &target)
    {
        auto context = make_parse_context(value_parse_handler());
        auto next    = parse(first, last, context);
        target       = value(context.handler().to_compound());
        return next;
    }

    void compose(value const &arg, compose_buffer &buf)
    {
        auto e = encoder { buf };

        // clang-format off
        auto visitor = overloaded
        {
            [&](compound const &cmp)
            {
                e(cmp, false, false);
            },
            [&](list const &lst)
            {
                e(lst, false);
            },
            [&]< class Arg >(Arg const &)
            {
                throw encoding::not_supported(to_tag_v< Arg >);
            }
        };
        // clang-format on
        visit(visitor, arg.as_variant());
    }

    auto pretty_print(value const &arg) -> pretty_printer<value> { return pretty_printer { arg }; }
    auto operator<<(std::ostream &os, value const &v) -> std::ostream &
    {
        visit(print_visitor { os }, v);
        return os;
    }

    auto operator==(value const &l, value const &r) -> bool
    {
        auto visitor = []< class A, class B >(A const &a, B const &b) -> bool {
            if constexpr (std::is_same_v< A, B >)
            {
                return a == b;
            }
            else
            {
                return false;
            }
        };
        return visit(visitor, l.as_variant(), r.as_variant());
    }

    auto operator!=(value const &l, value const &r) -> bool { return not(l == r); }

}   // namespace minecraft::nbt