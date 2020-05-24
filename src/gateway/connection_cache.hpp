#pragma once

#include "connection.hpp"
#include "polyfill/endpoint_hasher.hpp"
#include "polyfill/configuration.hpp"


namespace gateway {
    struct connection_cache
    {
        using protocol = net::ip::tcp;
        using executor_type = net::io_context::executor_type;
        using socket_type = net::basic_stream_socket<protocol, executor_type>;

        connection
        create(polyfill::configuration & config, socket_type &&sock);

        void cancel();

        std::optional<connection> get(protocol::endpoint key)
        {
            auto ifind = cache_.find(key);
            if (ifind != std::end(cache_))
            {
                auto shared_impl = ifind->second.lock();
                if (not shared_impl)
                    return std::nullopt;

                return connection(std::move(shared_impl));
            }
        }

        using by_endpoint_map = std::unordered_map<protocol::endpoint,
            std::weak_ptr<connection_impl>,
            polyfill::endpoint_hasher>;

        by_endpoint_map cache_;
        bool canceled_ = false;
    };
}