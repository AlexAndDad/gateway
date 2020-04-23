#include "connection.hpp"

#include "minecraft/security/rsa.hpp"

#include <polyfill/explain.hpp>


namespace gateway
{
    using namespace std::literals;


    connection::connection(connection_config config, socket_type &&sock, minecraft::region::player_update_queue & queue)
    : impl_(std::make_shared< connection_impl >(std::move(config), std::move(sock), queue))
    {
        impl_->start();
    }

    void connection::cancel()
    {
        if (impl_)
            impl_->cancel();
    }

    auto connection::get_weak_impl() const -> std::weak_ptr< connection_impl > { return impl_; }

}   // namespace gateway