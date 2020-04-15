#pragma once

#include "connection.hpp"
#include "polyfill/endpoint_hasher.hpp"

namespace relay {
    struct connection_cache
    {
        using protocol = net::ip::tcp;
        using executor_type = net::io_context::executor_type;
        using socket_type = net::basic_stream_socket<protocol, executor_type>;

        void
        create(connection_config config, socket_type &&sock);

        void cancel();


        using by_endpoint_map = std::unordered_map<protocol::endpoint,
            std::weak_ptr<connection_impl>,
            polyfill::endpoint_hasher>;

        by_endpoint_map cache_;
        bool canceled_ = false;
    };
}