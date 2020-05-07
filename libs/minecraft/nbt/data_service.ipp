#pragma once
#include "data_service.hpp"
#include "string_service.hpp"

#include <fmt/ostream.h>

namespace minecraft::nbt
{
    template < class Derived >
    auto data_service< Derived >::make_string_ref(offset id) -> data_ref
    {
        auto str = self()->template from_offset< string_header >(id);
        assert(str->use_count > 0);
        return data_ref::create_reference(tag_type::String, id);
    }

    template < class Derived >
    auto data_service< Derived >::release(data_ref const &data) -> std::uint8_t
    {
        switch (data.type)
        {
        case tag_type::String:
            return self()->release_string(data.data.ref_);
        case tag_type::Compound:
            return self()->release_compound(data.data.ref_);
        default:
            return 0;
        }
    }

    template < class Derived >
    auto data_service< Derived >::self() -> Derived *
    {
        return static_cast< Derived * >(this);
    }

    template < class Derived >
    auto data_service< Derived >::self() const -> Derived const *
    {
        return static_cast< Derived const * >(this);
    }

    template < class Self >
    void print(std::ostream &os, Self *self, std::string_view name, data_ref *ref, std::size_t depth)
    {
        switch (ref->type)
        {
        case tag_type::String:
            fmt::print(os,
                       "{}{}('{}') : {}\n",
                       std::string(depth, ' '),
                       ref->type,
                       name,
                       *(self->template from_offset< string_header >(ref->data.ref_)));
            break;
        case tag_type::Long:
            fmt::print(os, "{}{}('{}') : {}\n", std::string(depth, ' '), ref->type, name, ref->data.long_);
            break;
        default:
            assert(!"not implemented");
        }
    }

}   // namespace minecraft::nbt