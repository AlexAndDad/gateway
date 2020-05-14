//
// Created by rhodges on 11/05/2020.
//

#include "value_parse_handler.hpp"

namespace minecraft::nbt
{
    void value_parse_handler::on_integral_list(tag_type type, const_byte_span bs)
    {
        switch (type)
        {
        case Byte_Array: handle_element({ std::move(name_), byte_array(bs.begin(), bs.end()) }); break;

        case Int_Array:
        {
            auto n     = bs.size() / sizeof(std::int32_t);
            auto first = bs.data();
            auto last  = first + bs.size();
            auto a     = int_array();
            a.reserve(n);
            while (first < last)
            {
                boost::endian::big_int32_buf_at buf;
                std::memcpy(buf.data(), first, sizeof(std::int32_t));
                a.push_back(buf.value());
                first += sizeof(std::int32_t);
            }
            handle_element({ std::move(name_), std::move(a) });
            break;
        }

        case Long_Array:
        {
            auto n     = bs.size() / sizeof(std::int64_t);
            auto first = bs.data();
            auto last  = first + bs.size();
            auto a     = int_array();
            a.reserve(n);
            while (first < last)
            {
                boost::endian::big_int64_buf_at buf;
                std::memcpy(buf.data(), first, sizeof(std::int64_t));
                a.push_back(buf.value());
                first += sizeof(std::int64_t);
            }
            handle_element({ std::move(name_), std::move(a) });
            break;
        }

        default: assert(!"logic error");
        }
    }

    value_parse_handler::value_parse_handler()
    : parse_handler()
    , parse_stack()
    , name_()
    , compound_depth_(0)
    {
    }
    void value_parse_handler::on_compound_start()
    {
        if (++compound_depth_ > compound_depth_limit)
            throw system_error(error::compound_too_deep);

        push({ std::move(name_), compound() });
    }
    void value_parse_handler::on_key(std::string_view key)
    {
        assert(name_.empty());
        name_.assign(key.begin(), key.end());
    }
    void value_parse_handler::on_string(std::string_view s)
    {
        handle_element({ std::move(name_), string(s.begin(), s.end()) });
    }
    void value_parse_handler::on_end(std::size_t elements)
    {
        // all items remaining on the stack should be treated as the contents of one compound or list, depending
        // onthe caller's taste
        if (compound_depth_)
        {
            --compound_depth_;

            assert(tos() ? tos()->v.is(Compound): true);
            assert(tos() ? tos()->v.get_compound().size() == elements : true);
            handle_element(pop());
        }
    }
    void value_parse_handler::on_list(tag_type tag, std::size_t length)
    {
        auto l = list(tag);
        l.reserve(length);
        push({ std::move(name_), std::move(l) });
    }
    void value_parse_handler::on_list_end(std::size_t n)
    {
        assert(tos()->v.is(List));
        assert(std::size_t(tos()->v.get_list().size()) == n);
        handle_element(pop());
    }
    void value_parse_handler::handle_element(parser_element elem)
    {
        auto stacktop = tos();
        if (stacktop)
        {
            if (stacktop->v.is(tag_type::List))
                stacktop->v.get_list().push_back(std::move(elem.v));
            else if (stacktop->v.is(tag_type::Compound))
                stacktop->v.get_compound().emplace(std::move(elem.k), std::move(elem.v));
            else
                push(std::move(elem));
        }
        else
        {
            push(std::move(elem));
        }
    }

    compound value_parse_handler::expect_single_compound()
    {
        if (size() != 1)
            throw parsing::expected_one(size());

        auto t = tos()->v.type();
        if (t != Compound)
            throw parsing::unexpected_value(Compound, t);

        auto v = pop();
        return std::move(v.v.get_compound());
    }

}   // namespace minecraft::nbt
