//
// Created by rhodges on 05/05/2020.
//
#pragma once
#include "minecraft/variant.hpp"
#include "offset.hpp"
#include "storage_provider.hpp"
#include "tag_type.hpp"

#include <cassert>
#include <cstdint>
#include <memory>
#include <span>

namespace minecraft::nbt
{
    struct compound_header;
    struct string_header;
    struct list_header;
    template < tag_type >
    struct integral_array;

    template < tag_type >
    struct to_data_ref;

    template <>
    struct to_data_ref< tag_type ::End >
    {
        using type = monostate;
    };
    template <>
    struct to_data_ref< tag_type ::Byte >
    {
        using type = std::int8_t;
    };
    template <>
    struct to_data_ref< tag_type ::Short >
    {
        using type = std::int16_t;
    };
    template <>
    struct to_data_ref< tag_type ::Int >
    {
        using type = std::int32_t;
    };
    template <>
    struct to_data_ref< tag_type ::Long >
    {
        using type = std::int64_t;
    };
    template <>
    struct to_data_ref< tag_type ::Float >
    {
        using type = float;
    };
    template <>
    struct to_data_ref< tag_type ::Double >
    {
        using type = double;
    };

    template <>
    struct to_data_ref< tag_type ::String >
    {
        using type = storage_svc::ptr< string_header >;
    };

    template <>
    struct to_data_ref< tag_type ::Compound >
    {
        using type = storage_svc::ptr< compound_header >;
    };

    template < tag_type Type >
    using to_data_ref_t = typename atom_type< Type >::type;

    // a funadmental unit of storage which cannot move
    struct data_ref
    {
        using vtype = variant< monostate,
                               std::int8_t,
                               std::int16_t,
                               std::int32_t,
                               std::int64_t,
                               float,
                               double,
                               storage_svc::ptr< string_header >,
                               storage_svc::ptr< list_header >,
                               storage_svc::ptr< integral_array< tag_type::Byte > >,
                               storage_svc::ptr< integral_array< tag_type::Int > >,
                               storage_svc::ptr< integral_array< tag_type::Long > > >;

        vtype &      as_variant() { return var_; }
        vtype const &as_variant() const { return var_; }

        tag_type type() const;

        data_ref()
        : var_(monostate())
        {
        }

        template<class T>
        data_ref(std::in_place_t, T&& arg)
            : var_()
        {
            var_.emplace<std::decay_t<T>>(std::forward<T>(arg));
        }

        data_ref(data_ref &&other)
        : var_(std::exchange(other.var_, vtype()))
        {
        }

        data_ref &operator==(data_ref &&other)
        {
            assert(holds_alternative< monostate >(var_));
            var_ = std::exchange(other.var_, vtype());
            return *this;
        }

        void release(storage_provider *sp);

      private:
        vtype var_;
    };

    template < class Self >
    void print(std::ostream &os, Self *self, std::string_view name, data_ref *ref, std::size_t depth = 0);

    void pretty_print(std::ostream &    os,
                      storage_provider *self,
                      std::string_view  name,
                      data_ref const &  ref,
                      std::size_t       depth = 0);
    void pretty_print(std::ostream &os, storage_provider *self, data_ref const &ref, std::size_t depth = 0);

    struct data_service_base
    {
    };

    template < class Derived >
    struct data_service : data_service_base
    {
        auto make_string_ref(offset id) -> data_ref;

        /// conceptually release (and possibly destroy) the data referred to.
        ///
        /// Not all data types are stored as references. These types will indicate a no-op
        /// \param data
        /// \return the new use count. If zero, the data item will have been destroyed
        ///
        auto release(data_ref const &data) -> std::uint8_t;

      private:
        auto self() -> Derived *;
        auto self() const -> Derived const *;
    };

}   // namespace minecraft::nbt
