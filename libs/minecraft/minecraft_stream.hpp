#pragma once

#include "minecraft/net.hpp"
#include "minecraft/security/cipher_context.hpp"

namespace minecraft
{
    using shared_secret = std::array<std::uint8_t, 16>;

    struct encryption_state
    {
        security::cipher_context tx_cipher_;
        security::cipher_context rx_cipher_;
    };

    template < class NextLayer >
    struct minecraft_stream_impl
    {
        using next_layer_type = NextLayer;

        minecraft_stream_impl(next_layer_type&& next)
        : next_layer_(next)
        {

        }

        next_layer_type next_layer_;
        int compression_threshold_;



    };

    template < class NextLayer = net::basic_stream_socket< net::ip::tcp, net::io_context::executor_type > >
    struct minecraft_stream
    {
        using next_layer_type     = NextLayer;
        using implementation_type = minecraft_stream_impl< NextLayer >*;

        minecraft_stream(NextLayer &&next)
        : impl_(construct(std::move(next)))
        {
        }

        minecraft_stream(minecraft_stream &&other)
        : impl_(other.release())
        {
        }

        ~minecraft_stream()
        {
            if (impl_)
            {
                impl_->close();
                destroy(std::exchange(impl_, nullptr));
            }
        }

        implementation_type release() { return std::exchange(impl_, nullptr); }

      private:

        static implementation_type construct(NextLayer&& next)
        {
            return new minecraft_stream_impl< NextLayer >(std::move(next));
        }

        static void destroy(implementation_type impl)
        {
            impl->close();
            delete impl;
        }

        implementation_type impl_;
    };
}   // namespace minecraft