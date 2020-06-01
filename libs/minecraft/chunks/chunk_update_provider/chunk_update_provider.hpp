//
// Created by ahodges on 28/05/2020.
//

#pragma once

#include "chunk_update_provider_connection.hpp"
#include "chunks/chunk_update.hpp"
#include "net.hpp"
#include "polyfill/async/async_task.hpp"
#include <forward_list>

namespace minecraft::chunks
{
    struct chunk_update_provider
    {
        using executor_type   = net::executor;
        using connection_type = chunk_update_provider_connection;
        using connection_handle = std::shared_ptr<connection_type>;

        chunk_update_provider(executor_type exec)
        : exec_(exec)
        {
        }

        auto connect(chunk_coord_type coord) -> net::awaitable< connection_handle >
        { // Can be called from any strand to create a connection to a chunk column
            co_return co_await polyfill::async::async_task(
                get_executor(),
                [this, coord]() mutable -> net::awaitable< connection_handle > { co_return co_await handle_connect(coord); },
                "chunk_update_provider",
                "connect()");
        }

        auto update(chunk_coord_type coord,connection_type::value_type update) // This func is called from the same strand as this object
        {
            auto ifind = connections_.find(coord);
            if (ifind == std::end(connections_))
                return; // Nobody is listening

            for (auto & conn : ifind->second)
            {
                conn.lock().get()->update(update,++global_sequence_);
            }
        }


        auto get_executor() -> executor_type { return exec_; }

      private:
        auto handle_connect(chunk_coord_type coord) -> net::awaitable< connection_handle > {
            // Get the connection storage list for this chunk
            auto ifind = connections_.find(coord);
            if (ifind == std::end(connections_))
            {
                auto res = connections_.emplace(std::make_pair(coord,std::forward_list< std::weak_ptr< connection_type >>()));
                ifind = res.first;
            }
            // Create the connection
            connection_handle conn = std::make_shared<connection_type>(get_executor(),global_sequence_-1);

            // Push an initial update to it
            auto & chunk = get_chunk(coord);
            conn.get()->update(connection_type::value_type(chunk),global_sequence_);

            // Put the connection in the list
            ifind->second.emplace_front(conn->weak_from_this());
            co_return conn;
        }

        virtual auto get_chunk(chunk_coord_type coords) -> const chunk_column_impl & = 0;

        executor_type exec_;
        std::unordered_map< chunk_coord_type, std::forward_list< std::weak_ptr< connection_type > > > connections_;
        std::size_t global_sequence_ = 0;
    };
}   // namespace minecraft::chunks
