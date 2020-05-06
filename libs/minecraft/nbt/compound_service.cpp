//
// Created by rhodges on 05/05/2020.
//

#include "compound_service.hpp"
#include "compound_service.ipp"
#include "impl.hpp"

namespace minecraft::nbt
{


    template struct compound_service<impl>;

    template
    void print<impl>(std::ostream& os, impl* self, std::string_view name, compound_header* hdr, std::size_t depth);
}