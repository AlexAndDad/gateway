//
// Created by rhodges on 10/05/2020.
//

#include "value_ref.hpp"

namespace minecraft::nbt
{
    value_ref::value_ref(tag_type type)
    : atom()
    , type(type)
    {
        default_initialise(type, atom);
    }

    value_ref::value_ref(const value_ref &other)
    : type(other.type)
    {
        copy_construct(type, atom, other.atom);
    }

    value_ref::value_ref(value_ref &&other)
    : type(std::exchange(other.type, tag_type::End))
    {
        move_construct(type, atom, std::move(other.atom));
    }
    value_ref &value_ref::operator=(const value_ref &other)
    {
        deconstruct(type, atom);
        type = other.type;
        copy_construct(type, atom, other.atom);
        return *this;
    }
    value_ref &value_ref::operator=(value_ref &&other)
    {
        deconstruct(type, atom);
        type = std::exchange(other.type, tag_type::End);
        move_construct(type, atom, std::move(other.atom));
        return *this;
    }

    value_ref::~value_ref() { deconstruct(type, atom); }

    auto value_ref::as_compound(storage_provider *sp) -> ptr< compound_impl >
    {
        assert(sp);
        assert(type == tag_type::Compound);

        return ptr< compound_impl >(sp, atom.cmp_);
    }

    auto value_ref::as_list(storage_provider *sp) -> ptr< generic_list_impl >
    {
        assert(sp);
        assert(type == tag_type::List);

        return ptr< generic_list_impl >(sp, atom.list_);
    }

    auto value_ref::operator=(std::int64_t const &arg) -> value_ref &
    {
        deconstruct(type, atom);
        type       = tag_type::Long;
        atom.long_ = arg;
        return *this;
    }

    auto value_ref::operator=(ref< compound_impl > rstr) -> value_ref &
    {
        assert(empty() or (type == tag_type::Compound and atom.cmp_.empty()));
        type      = tag_type::Compound;
        atom.cmp_ = std::move(rstr);
        return *this;
    }

    auto value_ref::operator=(ref< generic_list_impl > arg) -> value_ref &
    {
        assert(empty());
        type       = tag_type::List;
        atom.list_ = std::move(arg);
        return *this;
    }

    auto value_ref::operator=(ref< string_impl > rstr) -> value_ref &
    {
        assert(empty());
        type      = tag_type::String;
        atom.str_ = std::move(rstr);
        return *this;
    }

}   // namespace minecraft::nbt