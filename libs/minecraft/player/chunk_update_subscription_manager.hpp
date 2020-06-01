//
// Created by ahodges on 28/05/2020.
//

#pragma once

#include "chunks/chunk_tools.hpp"
#include "chunks/chunk_update_provider/chunk_update_provider.hpp"
#include "net.hpp"
#include "polyfill/async/async_queue.hpp"
#include "polyfill/async/coro_except_handler.hpp"

namespace minecraft::player
{
    /// @brief This object shares a strand with the player that owns it, no executor changes will happen when calling the interface
    /// functions
    struct chunk_update_subscription_manager
    {
        using executor_type   = net::executor;
        using provider_type   = chunks::chunk_update_provider;
        using connection_type = provider_type::connection_type;

        chunk_update_subscription_manager(executor_type            exec,
                                          chunks::chunk_coord_type centre_chunk,
                                          std::size_t              radius,
                                          provider_type *          provider)
        : exec_(exec)
        , provider_(provider)
        , centre_chunk_(centre_chunk)
        , radius_(radius)
        {
        }

        // Subscribe to all viewable chunks
        auto start() -> net::awaitable< std::pair<
            std::size_t,
            std::shared_ptr< polyfill::async::async_queue< std::pair< chunks::chunk_coord_type, chunks::copyable_chunk_column_impl > > > > >
        {
            using queue_value_type = std::pair< chunks::chunk_coord_type, chunks::copyable_chunk_column_impl >;
            using queue_type       = polyfill::async::async_queue< queue_value_type >;
            using ptr_to_queue     = std::shared_ptr< queue_type >;
            using result_type      = std::pair< std::size_t, ptr_to_queue >;

            auto gen = chunks::viewable_chunks_generator(centre_chunk_, radius_);
            for (auto &coord : gen)
            {
                auto connection_handler = co_await provider_->connect(coord);
                providers_.emplace(std::make_pair(coord,std::move(connection_handler)));
            }

            auto chunk_quantity = providers_.size();
            auto queue_ptr      = std::make_shared< queue_type >(get_executor());

            for (auto &item : providers_)
            {
                net::co_spawn(
                    get_executor(),
                    [&item, queue_ptr]() mutable -> net::awaitable< void > {
                        auto res = co_await item.second.get()->wait();
                        queue_ptr.get()->push(
                            std::make_pair(item.first, std::move(get< chunks::copyable_chunk_column_impl >(res.as_variant()))));
                    },
                    polyfill::coro_except_handler("chunk_update_subscription_manager", "start()"));
            }
            co_return result_type(chunk_quantity,std::move(queue_ptr));
        }

        executor_type get_executor() { return exec_; }

      private:
        executor_type            exec_;
        provider_type *          provider_;
        chunks::chunk_coord_type centre_chunk_;
        std::size_t              radius_;

        std::unordered_map< chunks::chunk_coord_type, std::shared_ptr< connection_type > > providers_;
    };
}   // namespace minecraft::player
