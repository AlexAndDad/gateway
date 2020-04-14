#pragma once

#include "minecraft/server/receive_login.hpp"
#include "net.hpp"
#include "polyfill/hexdump.hpp"
#include "gateway/connection_impl.hpp"

#include <iostream>
#include <memory>


namespace gateway
{


    struct connection
    {
        using socket_type = connection_impl::socket_type;

        explicit connection(connection_config config, socket_type &&sock);

        void cancel();

        auto get_weak_impl() const -> std::weak_ptr< connection_impl >;

      private:
        std::shared_ptr< connection_impl > impl_;
    };

}   // namespace gateway