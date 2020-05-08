#include "list_service.hpp"

#include "data_service.hpp"

namespace minecraft::nbt
{
    auto list_service::append(storage_provider *sp, offset id, data_ref arg) -> offset
    {
        auto visitor = [&]< tag_type Type >(list_tag< Type >) -> offset
        {
            list_header* generic = sp->from_offset<list_header>(id);
            assert(generic->type == Type);
            using list_type = basic_list_header<Type>;
            auto list = static_cast<list_type*>(generic);
            if (list->capacity <= list->length)
                list = grow(sp, list, std::min(8, (list->capacity * 3) / 2));
            list->data_[list->length++] = get<to_data_ref_t<Type>>(arg.as_variant());
            return sp->to_offset(list);

        };
        return visit(visitor, arg.type());
    }

    template < tag_type Type >
    auto list_service::destroy(storage_provider *storage, basic_list_header< Type > *list)
        -> basic_list_header< Type > *
    {
        for (auto &element : list->elements())
            data_service_base::impl_release< Type >(storage, element);

        return list;
    }

    auto list_service::get_type(storage_provider *sp, offset id) -> tag_type
    {
        auto plist = sp->from_offset< list_header >(id);
        assert(plist);
        auto result = plist->type;
        assert(valid_value(result));
        return result;
    }

    auto list_service::get_size(storage_provider *sp, offset id) -> std::int32_t
    {
        auto plist = sp->from_offset< list_header >(id);
        assert(plist);
        auto result = plist->length;
        assert(result >= 0);
        return result;
    }

    auto list_service::new_list(storage_provider *sp, tag_type type, std::int32_t capacity) -> list_header *
    {
        auto visitor = [sp, capacity]< tag_type Tag >(list_tag< Tag >) -> list_header * {
            using list_type = basic_list_header< Tag >;
            auto extent     = list_type::extent(capacity);
            auto blocks     = size_to_blocks(extent);
            auto pv         = sp->alloc(blocks);
            auto list       = new (pv) basic_list_header< Tag >(capacity);
            return list;
        };
        return visit(visitor, type);
    }

    std::int8_t list_service::release(storage_provider *storage, list_header *hdr)
    {
        auto impl_release = [storage, hdr]< tag_type Type >(list_tag< Type >) {
            free(storage, destroy(storage, static_cast< basic_list_header< Type > * >(hdr)));
        };

        visit(impl_release, hdr->type);
        return 0;
    }

}   // namespace minecraft::nbt