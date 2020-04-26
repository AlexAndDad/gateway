#pragma once

#include <ostream>
#include <wise_enum/wise_enum.h>

#define WISE_ENUM_ENABLE_IO(Type)                                                                                      \
    inline auto to_string(Type const& t) { return wise_enum::to_string(t); }                                                  \
    inline auto operator<<(std::ostream &os, Type const& t)->std::ostream &                                                   \
    {                                                                                                                  \
        os << to_string(t);                                                                                            \
        return os;                                                                                                     \
    }                                                                                                                  \
    // ============================================================================================

#define WISE_ENUM_MEMBER_ENABLE_IO(Type)                                                                               \
    friend auto to_string(Type const& t) { return wise_enum::to_string(t); }                                                  \
    friend auto operator<<(std::ostream &os, Type const& t)->std::ostream &                                                   \
    {                                                                                                                  \
        os << to_string(t);                                                                                            \
        return os;                                                                                                     \
    }                                                                                                                  \
    // ============================================================================================

