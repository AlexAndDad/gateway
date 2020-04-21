//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#include "console.hpp"

#include <fmt/ostream.h>
#include <iomanip>
#include <iostream>
#include "polyfill/explain.hpp"

namespace application
{
    auto console::start(std::function< void() > on_done) -> void
    {
        net::co_spawn(
            input_.get_executor(),
            [this]() -> net::awaitable< void > {
                co_await run();
                co_return;
            },
            [on_done](std::exception_ptr ep) {
                try
                {
                    if (ep)
                        std::rethrow_exception(ep);
                }
                catch(...)
                {
                    std::cout << "console: " << polyfill::explain() << std::endl;
                }

                on_done(); });
    }

    auto console::run() -> net::awaitable< void >
    {
        std::string cmdbuffer;
        while (not stopped)
        {
            auto chars = co_await net::async_read_until(input_, inbuf_, "\n", net::use_awaitable);
            cmdbuffer.resize(chars);
            inbuf_.consume(buffer_copy(net::buffer(cmdbuffer), inbuf_.data()));
            while(cmdbuffer.size() && std::isspace(cmdbuffer.back()))
                cmdbuffer.pop_back();

            auto cmdview = cmdbuffer;
            boost::trim(cmdview);
            if (boost::iequals(cmdview.substr(0, 4), "stop"))
                co_return;
            if (boost::iequals(cmdview.substr(0, 4), "quit"))
                co_return;

            fmt::print(std::cout, "console: not recognised: {}\n", std::quoted(cmdbuffer));
        }
    }

    void console::stop()
    {
        dispatch(bind_executor(input_.get_executor(), [this] {
            stopped = true;
            input_.cancel();
        }));
    }

}   // namespace application