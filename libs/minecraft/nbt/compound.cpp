#include "compound.hpp"

#include "value_parse_handler.hpp"

namespace minecraft::nbt
{
    auto parse(const_buffer_iterator first, const_buffer_iterator last, compound &cmp) -> const_buffer_iterator
    {
        auto context = make_parse_context(value_parse_handler());
        auto next    = context.parse_compound(first, last);
        cmp          = context.handler().to_compound();
        return next;
    }

    void compose(compound const &arg, compose_buffer &buf)
    {
        auto e = encoder { buf };
        e(arg, false, true);
    }


    auto parse(const_buffer_iterator first, const_buffer_iterator last, compound &cmp, error_code &ec)
        -> const_buffer_iterator
    {
        try
        {
            return parse(first, last, cmp);
        }
        catch (system_error &se)
        {
            ec = se.code();
        }
        catch (...)
        {
            ec = error::parse_error::other;
        }
        return first;
    }

    auto operator<<(std::ostream &os, compound const &cmp) -> std::ostream &
    {
        auto v = print_visitor { os };
        v(cmp);
        return os;
    }

}   // namespace minecraft::nbt