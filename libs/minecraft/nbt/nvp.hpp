#pragma once
#include "compound.hpp"
#include "value_parse_handler.hpp"
#include "encoder.hpp"

namespace minecraft::nbt
{
    //
    // representation in a packet:
    //
    template < tag_type Type >
    struct nvp
    {
        string             name;
        to_value_t< Type > value;
    };

    template < tag_type Type >
    void compose(nvp< Type > nv, compose_buffer &buf)
    {
        auto e = encoder{buf};
        e(Type);
        e(nv.name, false);
        e(nv.value, false);
    }

    template <  >
    inline void compose(nvp< Compound > nv, compose_buffer &buf)
    {
        auto e = encoder{buf};
        e(Compound);
        e(nv.name, false);
        e(nv.value, false, false);
    }


    template < class Iter, tag_type Type >
    Iter encode(nvp< Type > const &arg, Iter first)
    {
        static thread_local compose_buffer buf;
        compose(arg, buf);
        return std::copy(begin(buf), end(buf), first);
    }

    template < tag_type Type >
    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, nvp< Type > &nv)
    {
        auto parser = make_parse_context(value_parse_handler());
        first = parser.expect_nvp< Type >(first, last);
        auto e = parser.handler().pop();
        if (auto t = e.v.type() ; t != Type)
            throw parsing::invalid_tag(t);
        nv.value = std::move(get<to_value_t<Type>>(e.v.as_variant()));
        nv.name = std::move(e.k);
        return first;
    }

    template < tag_type Type >
    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, nvp< Type > &nv, error_code &ec)
    {
        if (!ec)
        {
            try
            {
                return parse(first, last, nv);
            }
            catch (system_error &se)
            {
                ec = se.code();
            }
            catch (...)
            {
                ec = error::other;
            }
        }
        return first;
    }

}   // namespace minecraft::nbt