#include "data_service.hpp"

#include "data_service.ipp"
#include "impl.hpp"
#include "integral_array.hpp"
#include "list_service.hpp"

namespace minecraft::nbt
{
    namespace
    {
        struct type_visitor
        {
            tag_type operator()(monostate const&) const { return  tag_type::End; }
            tag_type operator()(int8_t const &) const { return tag_type::Byte }
            tag_type operator()(int16_t const &) const { return tag_type::Short; }
            tag_type operator()(int32_t const &) const { return tag_type::Int; }
            tag_type operator()(int64_t const &) const { return tag_type::Long; }
            tag_type operator()(float const &) const { return tag_type::Float; }
            tag_type operator()(double const &) const { return tag_type::Double; }
            tag_type operator()(storage_svc::ptr<string_header> const &) const { return tag_type::String; }
            tag_type operator()(storage_svc::ptr<compound_header> const &) const { return tag_type::Compound; }
        };
        struct releaser
        {
            void operator()(monostate &) const {}
            void operator()(int8_t &) const {}
            void operator()(int16_t &) const {}
            void operator()(int32_t &) const {}
            void operator()(int64_t &) const {}
            void operator()(float &) const {}
            void operator()(double &) const {}
            void operator()(storage_svc::ptr<string_header>& str) const
            {
                if(auto pstr= str.get(sp))
                    if (pstr->release() == 0)
                        str->destroy(sp);
                str.reset();
            }

            storage_provider* sp;
        };
    }

    void data_ref::release(storage_provider* sp)
    {
        visit(releaser{sp}, var_);
        var_ = monostate();
    }

    std::int8_t data_service_base::releaser::operator()(atom_type<tag_type::String>, storage_provider * sp, offset &o) const
    {
        auto str = sp->from_offset<string_header>(std::exchange(o, invalid_offset()));
        auto remaining = str->release();
        if (remaining == 0)
            sp->free(str, size_to_blocks(str->extent()));
        return remaining;
    }

    std::int8_t data_service_base::releaser::operator()(atom_type<tag_type::Compound>, storage_provider *sp, offset &o) const
    {
        return compound_service_base::release(sp, sp->from_offset<compound_header>(std::exchange(o, invalid_offset())));
    }
    std::int8_t data_service_base::releaser::operator()(atom_type<tag_type::Byte_Array>, storage_provider *sp, offset &o) const
    {
        return array_service::release(sp, sp->from_offset<integral_array<std::int8_t>>(std::exchange(o, invalid_offset())));
    }
    std::int8_t data_service_base::releaser::operator()(atom_type<tag_type::Int_Array>, storage_provider *sp, offset &o) const
    {
        return array_service::release(sp, sp->from_offset<integral_array<std::int32_t>>(std::exchange(o, invalid_offset())));
    }
    std::int8_t data_service_base::releaser::operator()(atom_type<tag_type::Long_Array>, storage_provider *sp, offset &o) const
    {
        return array_service::release(sp, sp->from_offset<integral_array<std::int64_t>>(std::exchange(o, invalid_offset())));
    }
    std::int8_t data_service_base::releaser::operator()(atom_type<tag_type::List>, storage_provider *sp, offset &o) const
    {
        return list_service::release(sp, sp->from_offset<list_header>(std::exchange(o, invalid_offset())));
    }


    void release(storage_provider *storage, tag_type type, atom &a)
    {
        switch (type)
        {
        case tag_type::End:
        case tag_type::Float:
        case tag_type::Double:
        case tag_type::Byte:
        case tag_type::Int:
        case tag_type::Short:
        case tag_type::Long:
            break;
        case tag_type::String:
            if (auto str = storage->from_offset< string_header >(a.ref_); str)
                if (str->release() == 0)
                    storage->free(str, size_to_blocks(str->extent()));
            break;
        case tag_type::Compound:
            if (auto cmp = storage->from_offset< compound_header >(a.ref_); cmp)
                compound_service_base::release(storage, cmp);
            break;
        case tag_type::List:
            if (auto list = storage->from_offset< list_header >(a.ref_); list)
                list_service::release(storage, list);
            break;
        case tag_type::Byte_Array:
            if (auto array = storage->from_offset< integral_array< std::int8_t > >(a.ref_); array)
                array_service::release(storage, array);
            break;
        case tag_type::Long_Array:
            if (auto array = storage->from_offset< integral_array< std::int64_t > >(a.ref_); array)
                array_service::release(storage, array);
            break;
        case tag_type::Int_Array:
            if (auto array = storage->from_offset< integral_array< std::int32_t > >(a.ref_); array)
                array_service::release(storage, array);
            break;
        }
        a.ref_ = invalid_offset();
    }

    template struct data_service< impl >;

    template void print< impl >(std::ostream &os, impl *self, std::string_view name, data_ref *ref, std::size_t depth);

    void pretty_print(std::ostream &os, storage_provider *self, data_ref const &ref, std::size_t depth)
    {
        pretty_print(os, self, std::string_view(), ref, depth);
    }

    void pretty_print(std::ostream &    os,
                      storage_provider *self,
                      std::string_view  name,
                      data_ref const &  ref,
                      std::size_t       depth)
    {
        auto indent        = [&] { return std::string(depth, ' '); };
        auto format_string = "{0}{1}('{2}') : {3}\n";
        switch (ref.type)
        {
        default:
            fmt::print(os, format_string, indent(), ref.type, name, "not implemented");
            break;
        case tag_type::Long:
            fmt::print(os, format_string, indent(), ref.type, name, ref.data.long_);
            break;
        case tag_type::Int:
            fmt::print(os, format_string, indent(), ref.type, name, ref.data.int_);
            break;
        case tag_type::Short:
            fmt::print(os, format_string, indent(), ref.type, name, ref.data.short_);
            break;
        case tag_type::Byte:
            fmt::print(os, format_string, indent(), ref.type, name, static_cast< int >(ref.data.byte_));
            break;
        case tag_type::Double:
            fmt::print(os, format_string, indent(), ref.type, name, ref.data.double_);
            break;
        case tag_type::Float:
            fmt::print(os, format_string, indent(), ref.type, name, ref.data.float_);
            break;
        case tag_type::String:
            fmt::print(os, format_string, indent(), ref.type, name, *self->from_offset< string_header >(ref.data.ref_));
            break;
        case tag_type::Compound:
            os << pretty_print(self, name, self->from_offset< compound_header >(ref.data.ref_), depth);
            break;
        }
    }

}   // namespace minecraft::nbt