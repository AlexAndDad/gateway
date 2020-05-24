#pragma once

#include "connection_impl.hpp"
#include "minecraft/protocol/server_accept.hpp"
#include "net.hpp"
#include "polyfill/hexdump.hpp"

#include <iostream>
#include <memory>
#include "polyfill/configuration.hpp"

namespace gateway
{
    struct connection
    {
        using socket_type = connection_impl::socket_type;

        explicit connection(polyfill::configuration & config, socket_type &&sock);

        connection(std::shared_ptr<connection_impl> impl)
        : impl_(std::move(impl))
        {
        }

        void cancel();

        auto get_weak_impl() const -> std::weak_ptr< connection_impl >;

      private:
        std::shared_ptr< connection_impl > impl_;
    };

}   // namespace gateway