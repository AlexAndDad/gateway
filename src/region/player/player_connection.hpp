#pragma once

#include <minecraft/region/player_updates_queue.hpp>

namespace region::player
{
    struct player_connection
    {
        player_connection(minecraft::region::server_queue_update update_queue)
        : update_queue_(std::move(update_queue))
        {
        }

        net::awaitable< minecraft::packets::client::client_play_packet > consume_packet()
        {
            co_return co_await update_queue_.server_consumer.consume();
        }

        void send_packet(minecraft::packets::server::server_play_packet packet, error_code &ec)
        {
            update_queue_.server_producer.produce(std::move(packet), ec);
        }

        void cancel()
        {
            update_queue_.server_consumer.cancel();
        }

      private:

        minecraft::region::server_queue_update update_queue_;
    };
}   // namespace region::player