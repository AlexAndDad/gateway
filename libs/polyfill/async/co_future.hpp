//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "future.hpp"

namespace polyfill::async
{
    template<class T, class Func>
    auto co_future(Func func) -> future<T>
    {
        auto p = async::promise< T >();
        auto f = p.get_future();

        auto exec = net::get_associated_executor(func);
        net::co_spawn(
            exec,
            [p = std::move(p), func = std::move(func)]() mutable -> net::awaitable< void > {
                try
                {
                    p.set_value(co_await func());
                }
                catch (system_error &se)
                {
                    p.set_error(se.code());
                }
                catch (...)
                {
                    p.set_exception(std::current_exception());
                }
            },
            net::detached);

        return f;
    }

}   // namespace polyfill::net