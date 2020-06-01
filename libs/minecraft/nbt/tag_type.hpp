#pragma once
#include "minecraft/wise_enum.hpp"

namespace minecraft::nbt
{
    WISE_ENUM((tag_type, std::uint8_t),
              (End, 0),
              (Byte, 1),
              (Short, 2),
              (Int, 3),
              (Long, 4),
              (Float, 5),
              (Double, 6),
              (Byte_Array, 7),
              (String, 8),
              (List, 9),
              (Compound, 10),
              (Int_Array, 11),
              (Long_Array, 12));
    WISE_ENUM_ENABLE_IO(tag_type);

    inline auto valid_value(tag_type t)
    {
        switch (t)
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

}   // namespace minecraft::nbt