#pragma once

#include <ostream>
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

/*
inline void tag_invoke(print_tag<Type>, std::ostream& os, Type const& arg)
{
    os << wise_enum::to_string(arg);
}

void tag_invoke(print_tag<nvp<N, Type>>, std::string& os, nvp<N, Type> const& arg)
{
    fmt::print(os, "[{} {}]", arg.name, print(arg.value));
}
*/