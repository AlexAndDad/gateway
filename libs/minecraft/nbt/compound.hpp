#pragma once
#include "config.hpp"
#include "parse_context.hpp"
#include "pretty_printer.hpp"
#include "printer.hpp"

namespace minecraft::nbt
{
    struct compound : boost::unordered_map< std::string, value >
    {
        using boost::unordered_map< std::string, value >::unordered_map;
    };


    void compose(compound const &arg, compose_buffer &buf);

    template <class Iter>
    Iter encode(compound const &arg, Iter first);



    auto parse(const_buffer_iterator first, const_buffer_iterator last, compound &cmp) -> const_buffer_iterator;
    auto parse(const_buffer_iterator first, const_buffer_iterator last, compound &cmp, error_code &ec)
        -> const_buffer_iterator;

    inline auto pretty_print(compound const &arg) -> pretty_printer< compound > { return pretty_printer { arg }; }

    template < class Visitor >
    auto visit(Visitor &&v, compound const &val) -> decltype(auto)
    {
        return v(val);
    }

    std::ostream &operator<<(std::ostream &os, compound const &cmp);
}   // namespace minecraft::nbt

#include "value.hpp"

namespace minecraft::nbt
{

    template <class Iter>
    Iter encode(compound const &arg, Iter first)
    {
        compose_buffer buf;
        compose(arg, buf);

        return std::copy(std::begin(buf), std::end(buf), first);
    }

}