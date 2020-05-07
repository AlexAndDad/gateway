//
// Created by rhodges on 05/05/2020.
//
#pragma once
#include "offset.hpp"
#include "storage_provider.hpp"
#include "tag_type.hpp"

#include <cassert>
#include <cstdint>
#include <memory>
#include <span>

namespace minecraft::nbt
{
    // a funadmental unit of storage which cannot move
    union atom
    {
        std::int8_t  byte_;
        std::int16_t short_;
        std::int32_t int_;
        std::int64_t long_;
        float        float_;
        double       double_;
        offset       ref_ = invalid_offset();
    };

    inline void move_assign(atom &dest, atom &&src)
    {
        std::memcpy(&dest, &src, sizeof(atom));
        src.ref_ = invalid_offset();
    }

    void release(storage_provider *storage, tag_type type, atom &a);

    struct data_ref
    {
        data_ref()
        : type(tag_type::End)
        {
            data.ref_ = invalid_offset();
        }

        data_ref(tag_type type, atom &&a)
        : type(type)
        , data(a)
        {
            switch (type)
            {
            case tag_type::End:
            case tag_type::Byte:
            case tag_type::Short:
            case tag_type::Int:
            case tag_type::Long:
            case tag_type::Float:
            case tag_type::Double:
                break;
            case tag_type::Byte_Array:
            case tag_type::String:
            case tag_type::List:
            case tag_type::Compound:
            case tag_type::Int_Array:
            case tag_type::Long_Array:
                a.ref_ = invalid_offset();
                break;
            }
        }

        data_ref(tag_type type, atom const &a)
        : type(type)
        , data(a)
        {
        }

        data_ref(data_ref &&other) noexcept

        : data_ref(std::exchange(other.type, tag_type::End), std::move(other.data))
        {
        }

        data_ref &operator=(data_ref &&other) noexcept
        {
            assert(empty());
            type = std::exchange(other.type, tag_type::End);
            std::memcpy(&data, &other.data, sizeof(data));
            other.data.ref_ = invalid_offset();
            return *this;
        }

        tag_type type;
        atom     data;

        bool empty() const noexcept { return this->type == tag_type::End; }

        static auto create_long(std::int64_t n) -> data_ref
        {
            auto result       = data_ref();
            result.type       = tag_type::Long;
            result.data.long_ = n;
            return result;
        }

        static auto create_reference(tag_type tag, offset ref) -> data_ref
        {
            auto result      = data_ref();
            result.type      = tag;
            result.data.ref_ = ref;
            return result;
        }
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
        struct releaser
        {
            std::int8_t operator()(atom_type< tag_type::End >, storage_provider *, std::int8_t &) const { return 0; }
            std::int8_t operator()(atom_type< tag_type::Byte >, storage_provider *, std::int8_t &) const { return 0; }
            std::int8_t operator()(atom_type< tag_type::Short >, storage_provider *, std::int16_t &) const { return 0; }
            std::int8_t operator()(atom_type< tag_type::Int >, storage_provider *, std::int32_t &) const { return 0; }
            std::int8_t operator()(atom_type< tag_type::Long >, storage_provider *, std::int64_t &) const { return 0; }
            std::int8_t operator()(atom_type< tag_type::Float >, storage_provider *, float &) const { return 0; }
            std::int8_t operator()(atom_type< tag_type::Double >, storage_provider *, double &) const { return 0; }
            std::int8_t operator()(atom_type< tag_type::String >, storage_provider *, offset &) const;
            std::int8_t operator()(atom_type< tag_type::Compound >, storage_provider *, offset &) const;
            std::int8_t operator()(atom_type< tag_type::Byte_Array >, storage_provider *, offset &) const;
            std::int8_t operator()(atom_type< tag_type::Int_Array >, storage_provider *, offset &) const;
            std::int8_t operator()(atom_type< tag_type::Long_Array >, storage_provider *, offset &) const;
            std::int8_t operator()(atom_type< tag_type::List >, storage_provider *, offset &) const;
        };

        struct acessor
        {
            std::int8_t &operator()(atom_type< tag_type::End >, atom &a) const { return a.byte_; }
            std::int8_t  operator()(atom_type< tag_type::Byte >, storage_provider *, std::int8_t &) const { return 0; }
            std::int8_t operator()(atom_type< tag_type::Short >, storage_provider *, std::int16_t &) const { return 0; }
            std::int8_t operator()(atom_type< tag_type::Int >, storage_provider *, std::int32_t &) const { return 0; }
            std::int8_t operator()(atom_type< tag_type::Long >, storage_provider *, std::int64_t &) const { return 0; }
            std::int8_t operator()(atom_type< tag_type::Float >, storage_provider *, float &) const { return 0; }
            std::int8_t operator()(atom_type< tag_type::Double >, storage_provider *, double &) const { return 0; }
            std::int8_t operator()(atom_type< tag_type::String >, storage_provider *, offset &) const;
            std::int8_t operator()(atom_type< tag_type::Compound >, storage_provider *, offset &) const;
            std::int8_t operator()(atom_type< tag_type::Byte_Array >, storage_provider *, offset &) const;
            std::int8_t operator()(atom_type< tag_type::Int_Array >, storage_provider *, offset &) const;
            std::int8_t operator()(atom_type< tag_type::Long_Array >, storage_provider *, offset &) const;
            std::int8_t operator()(atom_type< tag_type::List >, storage_provider *, offset &) const;
        };

        template < tag_type Type, class Actual = atom_type_t< Type > >
        static auto impl_release(storage_provider *storage, Actual &atype) -> std::int8_t
        {
            auto op = releaser();
            return op(atom_type< Type >(), storage, atype);
        }

        template < tag_type Type >
        static auto access(atom_type< Type >, atom &a) -> offset &
        {
            return a.ref_;
        }

        static auto access(atom_type< tag_type::End >, atom &a) -> std::int8_t & { return a.byte_; }
        static auto access(atom_type< tag_type::Byte >, atom &a) -> std::int8_t & { return a.byte_; }
        static auto access(atom_type< tag_type::Short >, atom &a) -> std::int16_t & { return a.short_; }
        static auto access(atom_type< tag_type::Int >, atom &a) -> std::int32_t & { return a.int_; }
        static auto access(atom_type< tag_type::Long >, atom &a) -> std::int64_t & { return a.long_; }
        static auto access(atom_type< tag_type::Float >, atom &a) -> float & { return a.float_; }
        static auto access(atom_type< tag_type::Double >, atom &a) -> double & { return a.double_; }

        static auto make_long(std::int64_t n) { return data_ref::create_long(n); }
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
