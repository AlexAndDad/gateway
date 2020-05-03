#pragma once
#include "data_service.hpp"
#include "string_service.hpp"

namespace minecraft::nbt
{
    template < class Derived >
    auto data_service< Derived >::make_string_ref(offset id) -> data_ref
    {
        auto str = self()->template from_offset< string_header >(id);
        assert(str->type == tag_type::String);
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

}   // namespace minecraft::nbt