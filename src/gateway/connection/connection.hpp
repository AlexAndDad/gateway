#pragma once

#include "connection_impl.hpp"
#include "gateway/net.hpp"
#include "minecraft/protocol/server_accept.hpp"
#include "minecraft/player/player_connection_base.hpp"
#include "polyfill/configuration.hpp"
#include "polyfill/hexdump.hpp"

#include <iostream>
#include <memory>

namespace gateway
{
    struct connection
    {
        using socket_type = connection_impl::socket_type;

        explicit connection(polyfill::configuration &config, socket_type &&sock);

        explicit connection(std::shared_ptr< connection_impl > impl = nullptr)
        : impl_(std::move(impl))
        {
        }

        void cancel();
        auto get() -> connection_impl & { return *(impl_.get()); }
        auto get_weak_impl() const -> std::weak_ptr< connection_impl >;
        auto get_impl() const -> std::shared_ptr<connection_impl> {return impl_;}
        auto is_valid() const -> bool { return static_cast< bool >(impl_); }

        auto transform_to_base() -> std::shared_ptr<minecraft::player::player_connection_base>
        {
            return std::static_pointer_cast<minecraft::player::player_connection_base>(impl_);
        }

      private:
        std::shared_ptr< connection_impl > impl_;
    };

}   // namespace gateway