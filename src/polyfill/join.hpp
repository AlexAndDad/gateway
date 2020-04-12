#pragma once

#include<string>
#include<string_view>

namespace polyfill {

    using std::to_string;

    template<class Ch, class Traits>
    inline std::string to_string(std::basic_string_view<Ch, Traits> const& sv)
    {
        return std::string(sv.begin(), sv.end());
    }

    template<class...Others>
    std::string
    join(std::string initial, Others &&...others)
    {
        ((initial += to_string(others)), ...);
        return initial;
    }
}