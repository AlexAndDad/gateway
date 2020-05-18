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

    std::ostream &operator<<(std::ostream &os, slice_impl const &c)
    {
        os << pretty_print(c);
        return os;
    }

    std::ostream &operator<<(std::ostream &os, slice_printer const &p)
    {
        auto &      c       = p.slice;
        std::size_t longest = 0;
        for (auto &horz : c.all())
            longest = std::max(longest, short_string(c[horz]).size());
        longest = std::min(longest, std::size_t(10));

        if (p.yval >= 0)
            fmt::print(os, "y = {:02} : ", p.yval);
        else
            fmt::print(os, "       : ");
        std::string mini;
        for (int x = 0; x < slice_impl::x_extent; ++x)
        {
            mini.clear();
            fmt::format_to(back_inserter(mini), "x = {:02}", x);
            fmt::print(os, "{0:^{1}}", mini, longest + 1);
        }

        for (auto &horz : c.all())
        {
            if (horz.x == 0)
                fmt::print(os, "\nz = {:02} : ", horz.z);
            fmt::print(os,
                       "{0:^{1}}",
                       short_string(c[horz]).substr(0, 10),
                       longest + 1);
        }
        return os;
    }

    bool operator==(slice_impl const &a, slice_impl const &b)
    {
        return std::memcmp(a.zx, b.zx, sizeof(a.zx)) == 0;
    }

    bool operator!=(slice_impl const &a, slice_impl const &b)
    {
        return not(a == b);
    }

}   // namespace minecraft::chunks