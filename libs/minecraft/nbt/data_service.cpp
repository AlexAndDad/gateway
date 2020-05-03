#include "data_service.hpp"

#include "data_service.ipp"
#include "impl.hpp"

namespace minecraft::nbt
{
    template struct data_service< impl >;
}