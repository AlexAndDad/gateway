#pragma once

#ifndef MINECRAFT_CHUNKS_PROVIDER_IMPL
#define MINECRAFT_CHUNKS_PROVIDER_IMPL

#include "chunk_impl.hpp"
#include "chunk_service_traits.hpp"
#include "minecraft/net.hpp"
#include "wait_op_base.hpp"

#include <unordered_map>

namespace minecraft::chunks
{
    struct connection_impl;

    struct provider_impl
    : chunk_service_traits
    , std::enable_shared_from_this< provider_impl >
    {
        using executor_type = net::executor;

        provider_impl(executor_type exec)
        : exec_(exec)
        , connections_()
        , current_snapshot_()
        , current_sequence_(0)
        {
        }

        /// Public interface. Inform the provider that a connection is waiting
        /// for an update \param op

        auto create_connection_impl(net::executor exec)
            -> std::shared_ptr< connection_impl >;

        //
        // service interface
        //
        void notify_update(vector3 pos, blocks::block_type blk);

        void cancel();

        void notify_chunk(chunk_data_impl && cc);
        void notify_chunk(chunk_data_impl const& cc);


        //
        // connection interface
        //

        void notify_waiting(connection_impl *handle);
        void notify_cancel(std::shared_ptr<connection_impl> const& pconn);

      private:
        void initial_update(connection_impl *handle);
        void handle_cancel();
        void handle_notify_waiting(connection_impl *handle);
        void handle_notify_update(vector3 pos, blocks::block_type blk);
        void handle_notify_chunk(chunk_data_impl && cc);
        std::shared_ptr< connection_impl > lookup(connection_impl *handle);

        executor_type exec_;
        std::unordered_map< connection_impl *,
                            std::weak_ptr< connection_impl > >
                                      connections_;
        // if not has_value() then the provider has not yet been initialised
        std::optional< chunk_data_impl > current_snapshot_;

        // provider's global error
        error_code ec_;

        sequence_number current_sequence_ = 0;
    };

}   // namespace minecraft::chunks

#include "chunk_data_impl.hpp"
#include "provider_impl.ipp.hpp"

#endif   // MINECRAFT_CHUNKS_PROVIDER_IMPL