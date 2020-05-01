#pragma once

#include <ostream>
#include <wise_enum/wise_enum.h>
#include "minecraft/print.hpp"

#define WISE_ENUM_ENABLE_IO(Type)                                                                                      \
                                                                                                                       \
    inline auto operator<<(std::ostream &os, Type const &t)->std::ostream &                                            \
    {                                                                                                                  \
        os << wise_enum::to_string(t);                                                                                            \
        return os;                                                                                                     \
    }                                                                                                                  \
    // ============================================================================================

#define WISE_ENUM_MEMBER_ENABLE_IO(Type)                                                                               \
                                                                                                                       \
    friend auto operator<<(std::ostream &os, Type const &t)->std::ostream &                                            \
    {                                                                                                                  \
        os << wise_enum::to_string(t);                                                                                            \
        return os;                                                                                                     \
    }                                                                                                                  \
    // ============================================================================================

