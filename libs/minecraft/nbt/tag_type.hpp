#pragma once
#include "minecraft/wise_enum.hpp"
#include "offset.hpp"

namespace minecraft::nbt
{
    WISE_ENUM_CLASS((tag_type, std::uint8_t),
                    End,
                    Byte,
                    Short,
                    Int,
                    Long,
                    Float,
                    Double,
                    Byte_Array,
                    String,
                    List,
                    Compound,
                    Int_Array,
                    Long_Array);
    WISE_ENUM_ENABLE_IO(tag_type);

    inline
    auto valid_value(tag_type t)
    {
        switch(t)
        {
        case tag_type::End:
            return false;
        case tag_type::Byte:
        case tag_type::Short:
        case tag_type::Int:
        case tag_type::Long:
        case tag_type::Float:
        case tag_type::Double:
        case tag_type::Byte_Array:
        case tag_type::String:
        case tag_type::List:
        case tag_type::Compound:
        case tag_type::Int_Array:
        case tag_type::Long_Array:
            return true;
        }
        return false;
    }

    // deduce storage for this type

    template < tag_type >
    struct atom_type
    {
        using type                         = offset;
        static constexpr bool by_reference = true;
    };

    template <>
    struct atom_type< tag_type ::End >
    {
        using type                         = std::int8_t;
        static constexpr bool by_reference = false;
    };
    template <>
    struct atom_type< tag_type ::Byte >
    {
        using type                         = std::int8_t;
        static constexpr bool by_reference = false;
    };
    template <>
    struct atom_type< tag_type ::Short >
    {
        using type                         = std::int16_t;
        static constexpr bool by_reference = false;
    };
    template <>
    struct atom_type< tag_type ::Int >
    {
        using type                         = std::int32_t;
        static constexpr bool by_reference = false;
    };
    template <>
    struct atom_type< tag_type ::Long >
    {
        using type                         = std::int64_t;
        static constexpr bool by_reference = false;
    };
    template <>
    struct atom_type< tag_type ::Float >
    {
        using type                         = float;
        static constexpr bool by_reference = false;
    };
    template <>
    struct atom_type< tag_type ::Double >
    {
        using type                         = double;
        static constexpr bool by_reference = false;
    };

    template < tag_type Type >
    using atom_type_t = typename atom_type< Type >::type;

}   // namespace minecraft::nbt