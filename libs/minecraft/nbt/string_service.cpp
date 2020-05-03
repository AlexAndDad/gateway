#include "string_service.hpp"
#include "string_service.ipp"
#include "impl.hpp"

namespace minecraft::nbt
{
    template struct string_service<impl>;

}   // namespace minecraft::nbt