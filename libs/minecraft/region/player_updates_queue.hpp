#pragma once

#include "async_queue_consume_handle.hpp"
#include "async_queue_produce_handle.hpp"
#include "config/net.hpp"
#include "minecraft/packets/client_play_packet.hpp"
#include "minecraft/packets/server_play_packet.hpp"

using namespace config;

namespace minecraft::region
{
    struct server_queue_update
    {
        using producer_packet_type = packets::server::server_play_packet;
        using producer_handle_type = async_queue_produce_handle< producer_packet_type >;

        using consumer_packet_type = packets::client::client_play_packet;
        using consumer_handle_type = async_queue_consume_handle< consumer_packet_type >;

        server_queue_update(std::string          name,
                            producer_handle_type producer_handler,
                            consumer_handle_type consumer_handler)
        : name(std::move(name))
        , server_producer(std::move(producer_handler))
        , server_consumer(std::move(consumer_handler))
        {
        }

        std::string          name;
        producer_handle_type server_producer;
        consumer_handle_type server_consumer;
    };

    struct client_queue_update
    {
        using producer_packet_type = packets::client::client_play_packet;
        using producer_handle_type = async_queue_produce_handle< producer_packet_type >;

        using consumer_packet_type = packets::server::server_play_packet;
        using consumer_handle_type = async_queue_consume_handle< consumer_packet_type >;

        client_queue_update(std::string          name,
                            producer_handle_type producer_handler,
                            consumer_handle_type consumer_handler)
        : name(std::move(name))
        , client_producer(std::move(producer_handler))
        , client_consumer(std::move(consumer_handler))
        {
        }

        std::string          name;
        producer_handle_type client_producer;
        consumer_handle_type client_consumer;
    };

    struct player_update_queue
    {
        using executor_type = net::io_context::executor_type;
        using strand_type   = net::io_context::strand;

        player_update_queue(executor_type exec)
        : update_queue_consumer_(std::make_shared< async_queue_impl< server_queue_update > >(exec))
        , update_queue_producer_(update_queue_consumer_.get())
        {
        }

        void cancel()
        {
            update_queue_consumer_.cancel();
        }

        net::awaitable< server_queue_update > consume_new_player()
        {
            co_return co_await update_queue_consumer_.consume();
        }

        client_queue_update produce_new_player(std::string name)
        {
            auto server_queue_impl =
                std::make_shared< async_queue_impl< packets::client::client_play_packet > >(get_exec());
            auto client_queue_impl =
                std::make_shared< async_queue_impl< packets::server::server_play_packet > >(get_exec());

            update_queue_producer_.produce(server_queue_update(
                name, async_queue_produce_handle(client_queue_impl), async_queue_consume_handle(server_queue_impl)));

            return client_queue_update(
                name, async_queue_produce_handle(server_queue_impl), async_queue_consume_handle(client_queue_impl));
        }

      private:

        async_queue_consume_handle< server_queue_update > update_queue_consumer_;
        async_queue_produce_handle< server_queue_update > update_queue_producer_;
    };
}   // namespace minecraft::region