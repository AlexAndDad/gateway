#pragma once
#include "minecraft/wise_enum.hpp"

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


}