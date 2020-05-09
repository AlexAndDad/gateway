#include "atom.hpp"

namespace minecraft::nbt
{
    template < class F >
    auto generic_list_impl::visit_element(storage_provider *sp, F &&f, std::int32_t n) -> decltype(auto)
    {
        assert(sp);
        assert(n < size_);
        atom_storage dummy;
        return visit(
            sp,
            [&](auto ptr) {
                ptr += n;
                return f(ptr);
            },
            type_,
            data_);
    }

    template < class F >
    auto generic_list_impl::visit_data(storage_provider *sp, F &&f) -> decltype(auto)
    {
        auto self = ptr< generic_list_impl >(sp, this);

        switch (type_)
        {
        default:
        case tag_type::End:
            assert(!"logic error");
        case tag_type::Byte:
            return f(self->data_.to_ptr(sp).cast< std::int8_t >());
            break;
        case tag_type::Short:
            return f(self->data_.to_ptr(sp).cast< std::int16_t >());
            break;
        case tag_type::Int:
            return f(self->data_.to_ptr(sp).cast< std::int32_t >());
            break;
        case tag_type::Long:
            return f(self->data_.to_ptr(sp).cast< std::int64_t >());
            break;
        case tag_type::Float:
            return f(self->data_.to_ptr(sp).cast< float >());
            break;
        case tag_type::Double:
            return f(self->data_.to_ptr(sp).cast< double >());
            break;
        case tag_type::Byte_Array:
            return f(self->data_.to_ptr(sp).cast< ref< basic_array_impl< std::int8_t > > >());
            break;
        case tag_type::String:
            return f(self->data_.to_ptr(sp).cast< ref< string_impl > >());
            break;
        case tag_type::List:
            return f(self->data_.to_ptr(sp).cast< ref< generic_list_impl > >());
            break;
        case tag_type::Compound:
            return f(self->data_.to_ptr(sp).cast< ref< compound_impl > >());
            break;
        case tag_type::Int_Array:
            return f(self->data_.to_ptr(sp).cast< ref< basic_array_impl< std::int16_t > > >());
            break;
        case tag_type::Long_Array:
            return f(self->data_.to_ptr(sp).cast< ref< basic_array_impl< std::int32_t > > >());
            break;
        }
    }

}   // namespace minecraft::nbt