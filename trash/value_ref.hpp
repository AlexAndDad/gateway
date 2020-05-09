//
// Created by rhodges on 10/05/2020.
//

#ifndef GATEWAY_VALUE_REF_HPP
#define GATEWAY_VALUE_REF_HPP

#include "atom.hpp"
#include "ref.hpp"
#include "array_impl.hpp"
#include "empty_item.hpp"

namespace minecraft::nbt
{
    struct value_ref
    {
        value_ref(tag_type type = tag_type::End);

        value_ref(value_ref const &other);

        value_ref(value_ref &&other);

        value_ref &operator=(value_ref const &other);

        value_ref &operator=(value_ref &&other);

        ~value_ref();

        bool empty() const { return type == tag_type::End; }

        auto operator=(ref<string_impl> rstr)->value_ref&;
        auto operator=(ref<compound_impl> rstr)->value_ref&;
        auto operator=(ref<generic_list_impl> rstr)->value_ref&;
        auto operator=(ref<byte_array_impl> rstr)->value_ref&;
        auto operator=(ref<int_array_impl> rstr)->value_ref&;
        auto operator=(ref<long_array_impl> rstr)->value_ref&;
        auto operator=(std::int64_t const& arg)->value_ref&;
        auto operator=(std::int32_t const& arg)->value_ref&;
        auto operator=(std::int16_t const& arg)->value_ref&;
        auto operator=(std::int8_t const& arg)->value_ref&;
        auto operator=(float const& arg)->value_ref&;
        auto operator=(double const& arg)->value_ref&;
        auto operator=(empty_item& arg)->value_ref&;

        //
        // narrow interface converters
        //

        [[nodiscard]] auto as_list(storage_provider *sp) -> ptr< generic_list_impl >;
        [[nodiscard]] auto as_compound(storage_provider *sp) -> ptr< compound_impl >;

        atom_storage atom;
        tag_type     type;
    };

    /*
    struct value_ptr : value_ref
    {
        value_ptr(value_ref v, storage_provider *sp)
        : value_ref(v)
        , sp_(sp)
        {
        }

      private:
        storage_provider *sp_;
    };
     */
}   // namespace minecraft::nbt

#endif   // GATEWAY_VALUE_REF_HPP
