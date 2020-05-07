#include "string_header.hpp"

#include <fmt/ostream.h>
#include <iostream>
#include <string_view>

namespace minecraft::nbt
{
    std::ostream &operator<<(std::ostream &os, string_header *phdr)
    {
        fmt::print(
            os, "{} (refs: {}): '{}'", tag_type::String, phdr->use_count, std::string_view(phdr->data(), phdr->size()));
        return os;
    }

    std::ostream &operator<<(std::ostream &os, string_header const &phdr)
    {
        fmt::print(os, "'{}'", std::string_view(phdr.data(), phdr.size()));
        return os;
    }

}   // namespace minecraft::nbt