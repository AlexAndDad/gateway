#pragma once

#include "config/net.hpp"

namespace minecraft
{
    namespace net = config::net;
    using config::error_category;
    using config::error_code;
    using config::system_category;
    using config::system_error;

    using tcp         = net::ip::tcp;
    using io_executor = net::io_context::executor_type;

    template < class Executor >
    using basic_tcp_socket =
        typename net::use_awaitable_t< Executor >::template as_default_on_t<
            net::basic_stream_socket< tcp, Executor > >;

    using tcp_socket = basic_tcp_socket<io_executor>;
}   // namespace minecraft