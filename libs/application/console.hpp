//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "application/net.hpp"

#include <boost/algorithm/string.hpp>
#include <string_view>

namespace application
{
    struct console
    {
        using stream_type = net::posix::stream_descriptor;

        console(net::executor exec, stream_type::native_handle_type fd_in)
        : input_(exec)
        {
            input_.assign(fd_in);
        }

        auto start(std::function<void()> on_done) -> void;

        void stop();

      private:
        auto run() -> net::awaitable< void >;

        net::posix::stream_descriptor input_;
        net::streambuf                inbuf_;
        bool                          stopped = false;
    };

}   // namespace application
