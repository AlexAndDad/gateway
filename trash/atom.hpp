#pragma once
#include "empty_item.hpp"
#include "ref.hpp"
#include "storage_provider.hpp"

#include <cstdint>

namespace minecraft::nbt
{
    struct string_impl;
    struct generic_list_impl;
    struct compound_impl;
    template < class Fundamental >
    struct basic_array_impl;

    //
    // lookup tag from memory
    //
    template < class T >
    struct select_tag;
    template < class T >
    inline constexpr tag_type which_tag_v = select_tag< T >::value;
    template <>
    inline constexpr tag_type which_tag_v< std::int8_t > = tag_type::Byte;
    template <>
    inline constexpr tag_type which_tag_v< std::int16_t > = tag_type::Short;
    template <>
    inline constexpr tag_type which_tag_v< std::int32_t > = tag_type::Int;
    template <>
    inline constexpr tag_type which_tag_v< std::int64_t > = tag_type::Long;
    template <>
    inline constexpr tag_type which_tag_v< float > = tag_type::Float;
    template <>
    inline constexpr tag_type which_tag_v< double > = tag_type::Double;
    template <>
    inline constexpr tag_type which_tag_v< ref< string_impl > > = tag_type::String;
    template <>
    inline constexpr tag_type which_tag_v< ref< compound_impl > > = tag_type::Compound;
    template <>
    inline constexpr tag_type which_tag_v< ref< generic_list_impl > > = tag_type::List;
    template <>
    inline constexpr tag_type which_tag_v< ref< basic_array_impl< std::int8_t > > > = tag_type::Byte_Array;
    template <>
    inline constexpr tag_type which_tag_v< ref< basic_array_impl< std::int32_t > > > = tag_type::Int_Array;
    template <>
    inline constexpr tag_type which_tag_v< ref< basic_array_impl< std::int64_t > > > = tag_type::Long_Array;

    template < class T >
    inline constexpr tag_type which_tag_v< const T > = which_tag_v< T >;
    template < class T >
    inline constexpr tag_type which_tag_v< volatile T > = which_tag_v< T >;
    template < class T >
    inline constexpr tag_type which_tag_v< T & > = which_tag_v< T >;
    template < class T >
    inline constexpr tag_type which_tag_v< T && > = which_tag_v< T >;

    union atom_storage
    {
        atom_storage()
        : empty_()
        {
        }

        empty_item                              empty_;
        std::int8_t                             byte_;
        std::int16_t                            short_;
        std::int32_t                            int_;
        std::int64_t                            long_;
        float                                   float_;
        double                                  double_;
        ref< string_impl >                      str_;
        ref< compound_impl >                    cmp_;
        ref< generic_list_impl >                list_;
        ref< basic_array_impl< std::int8_t > >  barray_;
        ref< basic_array_impl< std::int32_t > > iarray_;
        ref< basic_array_impl< std::int64_t > > larray_;

        template < class T >
        auto &set(T const &source)
        {
            auto assign = [&source]< class Dest >(Dest &dest) -> Dest & {
                dest = source;
                return dest;
            };
            constexpr auto type = which_tag_v< T >;
            if constexpr (type == tag_type::End)
                return assign(empty_);
            else if constexpr (type == tag_type::Byte)
                return assign(byte_);
            else if constexpr (type == tag_type::Short)
                return assign(short_);
            else if constexpr (type == tag_type::Int)
                return assign(int_);
            else if constexpr (type == tag_type::Long)
                return assign(long_);
            else if constexpr (type == tag_type::Float)
                return assign(float_);
            else if constexpr (type == tag_type::Double)
                return assign(double_);
            else if constexpr (type == tag_type::String)
                return assign(str_);
            else if constexpr (type == tag_type::Compound)
                return assign(cmp_);
            else if constexpr (type == tag_type::List)
                return assign(list_);
            else if constexpr (type == tag_type::Byte_Array)
                return assign(barray_);
            else if constexpr (type == tag_type::Int_Array)
                return assign(iarray_);
            else if constexpr (type == tag_type::Long_Array)
                return assign(larray_);
            else
                static_assert("invalid type");
        }

        template < class T >
        auto &set(T &&source)
        {
            auto assign = [&source]< class Dest >(Dest &dest) -> Dest & {
                dest = std::move(source);
                return dest;
            };
            constexpr auto type = which_tag_v< T >;
            if constexpr (type == tag_type::End)
                return assign(empty_);
            else if constexpr (type == tag_type::Byte)
                return assign(byte_);
            else if constexpr (type == tag_type::Short)
                return assign(short_);
            else if constexpr (type == tag_type::Int)
                return assign(int_);
            else if constexpr (type == tag_type::Long)
                return assign(long_);
            else if constexpr (type == tag_type::Float)
                return assign(float_);
            else if constexpr (type == tag_type::Double)
                return assign(double_);
            else if constexpr (type == tag_type::String)
                return assign(str_);
            else if constexpr (type == tag_type::Compound)
                return assign(cmp_);
            else if constexpr (type == tag_type::List)
                return assign(list_);
            else if constexpr (type == tag_type::Byte_Array)
                return assign(barray_);
            else if constexpr (type == tag_type::Int_Array)
                return assign(iarray_);
            else if constexpr (type == tag_type::Long_Array)
                return assign(larray_);
            else
                static_assert("invalid type");
        }
    };

    template < class F >
    auto visit_atom(storage_provider *sp, F &&f, tag_type type, atom_storage &atom) -> decltype(auto);

    template < class F >
    auto visit_atom(F &&f, tag_type type, atom_storage &atom) -> decltype(auto);
    template < class F >
    auto visit_atom(F &&f, tag_type type, atom_storage const &atom) -> decltype(auto);

    auto copy_construct(tag_type type, atom_storage &target, atom_storage const &source) -> void;
    auto move_construct(tag_type type, atom_storage &target, atom_storage &&source) -> void;
    auto deconstruct(tag_type type, atom_storage &target) -> void;
    auto default_initialise(tag_type type, atom_storage &target) -> void;

    /// If the atom element indicated by type has state, destroy it by deleting and set the atom state to End
    /// \param sp
    /// \param type
    /// \param atom
    void destroy_(storage_provider *sp, tag_type &type, atom_storage &atom);

    template < class Impl >
    struct atom_variant
    {
        auto type() const -> tag_type { return static_cast< Impl const * >(this)->get_type(); }
        auto type(tag_type type) -> void { return static_cast< Impl * >(this)->set_type(type); }
        auto atom() const -> atom_storage const & { return static_cast< Impl const * >(this)->get_atom_storage(); }
        auto atom() -> atom_storage & { return static_cast< Impl * >(this)->get_atom_storage(); }

        void assign_variant(ptr< string_impl > pstr);
        void assign_variant(ptr< compound_impl > pstr);
        void assign_variant(ptr< generic_list_impl > pstr);
        void assign_variant(ptr< basic_array_impl< std::int8_t > > pstr);
        void assign_variant(ptr< basic_array_impl< std::int32_t > > pstr);
        void assign_variant(ptr< basic_array_impl< std::int64_t > > pstr);
        void assign_variant(std::int8_t const &val);
        void assign_variant(std::int16_t const &val);
        void assign_variant(std::int32_t const &val);
        void assign_variant(std::int64_t const &val);
        void assign_variant(double const &val);
        void assign_variant(float const &val);

        template < class F >
        auto visit(F &&f) -> decltype(auto)
        {
            switch (this->type())
            {
            case tag_type::End:
                f(this->atom().empty_);
                break;
            case tag_type::Byte:
                f(this->atom().byte_);
                break;
            case tag_type::Short:
                f(this->atom().short_);
                break;
            case tag_type::Int:
                f(this->atom().int_);
                break;
            case tag_type::Long:
                f(this->atom().long_);
                break;
            case tag_type::Float:
                f(this->atom().float_);
                break;
            case tag_type::Double:
                f(this->atom().double_);
                break;
            case tag_type::Byte_Array:
                f(this->atom().barray_);
                break;
            case tag_type::String:
                f(this->atom().str_);
                break;
            case tag_type::Compound:
                f(this->atom().cmp_);
                break;
            case tag_type::List:
                f(this->atom().list_);
                break;
            case tag_type::Int_Array:
                f(this->atom().iarray_);
                break;
            case tag_type::Long_Array:
                f(this->atom().larray_);
                break;
            default:
                assert(!"logic error");
            }
        }
    };

    struct atom_variant_destroy
    {
        storage_provider *sp;
        template < class T >
        void operator()(ref< T > r) const
        {
            destroy_(sp, std::move(r));
        }

        template < class T >
        void operator()(T &) const
        {
        }
    };

    template < class F, class Impl >
    auto visit(F &&f, atom_variant< Impl > &var) -> decltype(auto);

}   // namespace minecraft::nbt

#include "atom_impl.hpp"
