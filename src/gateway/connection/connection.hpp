#pragma once

#include "connection_impl.hpp"
#include "minecraft/protocol/server_accept.hpp"
#include "net.hpp"
#include "polyfill/configuration.hpp"
#include "polyfill/hexdump.hpp"

#include <iostream>
#include <memory>

namespace gateway
{
    struct connection
    {
        using socket_type = connection_impl::socket_type;

        explicit connection(polyfill::configuration &config,
                            socket_type &&           sock);

        explicit connection(std::shared_ptr< connection_impl > impl = nullptr)
        : impl_(std::move(impl))
        {
        }

        void cancel();
        auto get() -> connection_impl & { return *(impl_.get()); }
        auto get_weak_impl() const -> std::weak_ptr< connection_impl >;
        auto is_valid() const -> bool {return static_cast<bool>(impl_);}

      private:
        std::shared_ptr< connection_impl > impl_;
    };

}   // namespace gateway