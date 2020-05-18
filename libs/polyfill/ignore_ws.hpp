#pragma once
#include <boost/iterator/iterator_adaptor.hpp>
namespace polyfill
{
    std::string strip_ws(std::string_view in)
    {
        auto s = std::string(in.begin(), in.end());
        s.erase(std::remove_if(s.begin(),
                               s.end(),
                               [](unsigned char x) { return std::isspace(x); }),
                s.end());
        return s;
    }

}   // namespace polyfill