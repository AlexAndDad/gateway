//
// Created by rhodges on 05/05/2020.
//

#include "compound_service.hpp"
#include "compound_service.ipp"
#include "impl.hpp"

namespace minecraft::nbt
{


    template struct compound_service<impl>;
}