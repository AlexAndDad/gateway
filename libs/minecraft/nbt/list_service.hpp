#pragma once
#include "data_service.hpp"
#include "offset.hpp"
#include "storage_provider.hpp"
#include "tag_type.hpp"

#include <cstddef>
#include <cstdint>
#include <span>

namespace minecraft::nbt
{
    struct list_info
    {
    };

    // generic list header
    struct list_header
    {
        list_header(tag_type type = tag_type::End, std::int32_t cap = 0)
        : length(0)
        , capacity(cap)
        , type(type)
        {
        }

        std::int32_t length;
        std::int32_t capacity;
        tag_type     type;
    };

    template < tag_type Type >
    struct basic_list_header : list_header
    {
        using value_type = atom_type_t< Type >;

        basic_list_header(std::int32_t cap)
        : list_header(Type, cap)
        {
        }

        value_type data_[1];

        static auto extent(std::int32_t cap) -> std::size_t
        {
            return sizeof(basic_list_header) + (sizeof(value_type) * std::min(cap - 1, 1));
        }
        auto extent() const -> std::size_t { return extent(capacity); }

        auto elements() -> std::span< value_type > { return std::span< value_type >(data_, data_ + length); }
    };

    struct list_service
    {
        // public access interface

        static auto append(storage_provider* sp, offset id, data_ref arg) -> offset;
        static auto get_size(storage_provider *sp, offset id) -> std::int32_t;
        static auto get_type(storage_provider *sp, offset id) -> tag_type;
        static auto new_list(storage_provider *sp, tag_type type, std::int32_t capacity) -> list_header *;

        // internal interface


        template < tag_type Type >
        struct list_tag
        {
            using type = basic_list_header< Type >;
        };
        template < tag_type Type >
        using list_tag_t = typename list_tag< Type >::type;


        template<tag_type Type>
        static auto grow(storage_provider* sp, basic_list_header<Type>* list, std::int32_t new_capcity) -> basic_list_header<Type>*
        {
            basic_list_header<Type>* nl = static_cast<basic_list_header<Type>*>(new_list(sp, Type, new_capcity));
            nl->length = list->length;
            std::copy_n(list->data_, list->length, nl->data_);
            free(sp, list);
            return nl;
        }


        template < class F >
        static auto visit(F &&f, tag_type type) -> decltype(auto)
        {
            switch (type)
            {
            case tag_type::End:
                return f(list_tag< tag_type::End >());
            case tag_type::Byte:
                return f(list_tag< tag_type::Byte >());
            case tag_type::Short:
                return f(list_tag< tag_type::Short >());
            case tag_type::Int:
                return f(list_tag< tag_type::Int >());
            case tag_type::Long:
                return f(list_tag< tag_type::Long >());
            case tag_type::Float:
                return f(list_tag< tag_type::Float >());
            case tag_type::Double:
                return f(list_tag< tag_type::Double >());
            case tag_type::Byte_Array:
                return f(list_tag< tag_type::Byte_Array >());
            case tag_type::String:
                return f(list_tag< tag_type::String >());
            case tag_type::List:
                return f(list_tag< tag_type::List >());
            case tag_type::Compound:
                return f(list_tag< tag_type::Compound >());
            case tag_type::Int_Array:
                return f(list_tag< tag_type::Int_Array >());
            case tag_type::Long_Array:
                return f(list_tag< tag_type::Long_Array >());
            }
        }

        static auto calc_extent(tag_type tag, std::int32_t capacity) -> std::size_t;

        template < class F, tag_type Type >
        static auto visit(F &&f, basic_list_header< Type > *list) -> decltype(auto)
        {
            return f(list);
        }

        template < tag_type Type >
        struct tag
        {
            static constexpr auto type = Type;
        };

        template < tag_type Type >
        static auto destroy(storage_provider *storage, basic_list_header< Type > *list) -> basic_list_header< Type > *;

        template < tag_type Type >
        static auto free(storage_provider *storage, basic_list_header< Type > *list) -> void
        {
            storage->free(list, size_to_blocks(list->extent()));
        }

        static std::int8_t release(storage_provider *storage, list_header *hdr);
    };
}   // namespace minecraft::nbt