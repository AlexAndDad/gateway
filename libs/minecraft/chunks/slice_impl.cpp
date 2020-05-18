//
// Created by rhodges on 17/05/2020.
//

#include "slice_impl.hpp"
#include <fmt/ostream.h>
#include <string_view>

using namespace std::literals;

namespace minecraft::chunks
{
    slice_impl::slice_impl() {}


    std::ostream& operator<<(std::ostream& os, slice_impl const& c)
    {
        auto zsep = ""sv;
        for (int z = 0 ; z < slice_impl::z_extent ; ++z)
        {
            fmt::print(os, "{}z = {:02} :", zsep, z);
            zsep = "\n"sv;
            auto xsep = " "sv;
            for (int x = 0; x < slice_impl::x_extent; ++x)
            {
                fmt::print(os, "{}{}", xsep, c.zx[z][x]);
                xsep = ", "sv;
            }
        }
        return os;
    }

    bool operator==(slice_impl const& a, slice_impl const& b)
    {
        return std::memcmp(a.zx, b.zx, sizeof(a.zx)) == 0;
    }

    bool operator!=(slice_impl const& a, slice_impl const& b)
    {
        return not(a == b);
    }


}   // namespace minecraft::chunks