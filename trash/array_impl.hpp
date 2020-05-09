#pragma once
#include "ptr.hpp"

namespace minecraft::nbt
{
    template < class Fundamental >
    struct basic_array_impl
    {
        std::int32_t length;
        std::int8_t  data_[1];

        auto size() const -> int32_t { return length; }

        std::size_t extent() const { return sizeof(*this) + std::max(1, length - 1) * sizeof(data_[0]); }
    };

    template < class Fundamental >
    inline void delete_(ptr< basic_array_impl< Fundamental > > parray)
    {
        if (parray)
        {
            destroy_(parray);
            parray.storage()->free(parray.get(), parray->extent());
        }
    }

    template < class Fundamental >
    inline void destroy_(ptr< basic_array_impl< Fundamental > >)
    {
    }

    using byte_array_impl = basic_array_impl< std::int8_t >;
    using int_array_impl  = basic_array_impl< std::int32_t >;
    using long_array_impl = basic_array_impl< std::int64_t >;

}   // namespace minecraft::nbt