#include "data_service.hpp"

#include "data_service.ipp"
#include "impl.hpp"

namespace minecraft::nbt
{
    template struct data_service< impl >;

    template
    void print<impl>(std::ostream &os, impl *self, std::string_view name, data_ref *ref, std::size_t depth);

}