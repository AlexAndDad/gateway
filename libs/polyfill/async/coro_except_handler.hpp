#pragma once

#include "explain.hpp"
#include <spdlog/spdlog.h>
#include <exception>
#include <string_view>

namespace polyfill
{
    struct coro_except_handler
    {
        coro_except_handler(const std::string_view struct_name,
                            const std::string_view function_name)
        : struct_name_(std::move(struct_name))
        , function_name_(std::move(function_name))
        {
        }

        void operator()(std::exception_ptr ep)
        {
            if (ep)
            {
                spdlog::error("{}::{} - exception: ",
                              struct_name_,
                              function_name_,
                              polyfill::explain());
                std::rethrow_exception(ep);
            }
        }

      private:
        const std::string_view struct_name_;
        const std::string_view function_name_;
    };
}   // namespace polyfill