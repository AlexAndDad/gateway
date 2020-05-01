#pragma once
#include "minecraft/nvp.hpp"

namespace minecraft
{

    template<class Impl>
    struct has_easy_to_string
    {
        friend auto to_string(has_easy_to_string const &base) -> std::string
        {
            auto &self = static_cast< Impl const & >(base);
            return fmt::format("[{} {}]", self.classname(), Impl::as_nvps(self));
        }
    };

    template<class Impl>
    struct has_easy_ostream
    {
        friend std::ostream &operator<<(std::ostream &os, has_easy_ostream const &base)
        {
            auto &self = static_cast< Impl const & >(base);
            fmt::print(os, "[{} {}]", self.classname(), Impl::as_nvps(self));
            return os;
        }
    };

    template<class Impl>
    struct has_easy_io : has_easy_to_string<Impl>, has_easy_ostream<Impl>
    {
    };
}