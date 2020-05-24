//
// Created by ahodges on 21/05/2020.
//

#pragma once

#include "future.hpp"
#include "net.hpp"

#include <exception>
#include <fmt/core.h>
#include <string_view>

namespace polyfill::async
{
    struct async_task_error : std::runtime_error
    {
        using std::runtime_error::runtime_error;
    };

    template < typename F >
    net::awaitable< typename std::invoke_result_t< F >::value_type >
    async_task(net::executor    exec,
               F                f,
               std::string_view class_name,
               std::string_view function_name)
    {
        auto p = polyfill::async::promise<
            typename std::invoke_result_t< F >::value_type >();
        auto fut = p.get_future();

        net::co_spawn(
            exec,
            [p = std::move(p),
             f = std::move(f),
             class_name,
             function_name]() mutable -> net::awaitable< void > {
                try
                {
                    if constexpr (std::is_same<typename std::invoke_result_t< F >::value_type,void>::value)
                    {
                        co_await f();
                        p.set_value();
                    }
                    else{
                        p.set_value(co_await f());
                    }

                }
                catch (...)
                {
                    try
                    {
                        std::throw_with_nested(async_task_error(fmt::format(
                            "{}::{}() - unhandled exception during async_task.",
                            class_name,
                            function_name)));
                    }
                    catch (...)
                    {
                        p.set_exception(std::current_exception());
                    }
                }
            },
            net::detached);

        co_return co_await fut();
    }

}   // namespace polyfill::async
