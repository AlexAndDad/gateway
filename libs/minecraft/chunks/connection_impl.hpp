#pragma once
#ifndef MINECRAFT_CHUNKS_CONNECTION_IMPL
#define MINECRAFT_CHUNKS_CONNECTION_IMPL

#include "chunk_section_impl.hpp"
#include "chunk_service_traits.hpp"
#include "chunk_update.hpp"
#include "function2/function2.hpp"
#include "minecraft/net.hpp"
#include "wait_op_base.hpp"

namespace minecraft::chunks
{
    struct provider_impl;

    struct connection_impl
    : chunk_service_traits
    , std::enable_shared_from_this< connection_impl >
    {
        using executor_type = net::executor;
        using value_type    = chunk_update;

        connection_impl(executor_type exec, std::shared_ptr< provider_impl > provider);

        template < class CompletionToken >
        auto async_wait(CompletionToken &&token) ->
            typename net::async_result< std::decay_t< CompletionToken >, void(error_code, value_type) >::return_type;

        void cancel();

      private:
        template < class Handler, class Executor >
        struct wait_op;

        //
        // provider interface
        //
        friend provider_impl;

        // notify of a new 'state of the world'
        void notify_update(chunk_column_impl const &c);

        // notify with an update
        void notify_update(block_update u);

        // notify with an error
        void notify_error(error_code ec);

        // invoke any waiting handler provided we have state
        void try_invoke();

      private:
        // The executor associsted with the client end of the connection
        executor_type                    exec_;
        std::shared_ptr< provider_impl > provider_;

        //
        // provider writes here
        //

        copyable_chunk_column_impl current_snapshot_;
        update_sequence            updates_;
        error_code                 ec_;

        enum : std::uint8_t
        {
            not_ready,          // can't complete because there's no data
            deliver_snapshot,   // will deliver a snapshot
            deliver_updates,    // will deliver updates
            deliver_error,      // will deliver the error code
            stopped             // will deliver error
        } state_ = not_ready;

        // method by which the consumer notifies the provider that there is a
        // new completion handler waiting
        std::atomic< bool > waiting_ = false;

        //
        // this function is writable by the client, invocable and writable by
        // the server
        //
        fu2::function_base< true,
                            false,
                            fu2::capacity_fixed< sizeof(std::shared_ptr< void >) + sizeof(void *) >,
                            false,
                            false,
                            void(error_code, chunk_update) >
            current_op_handler_;
    };
}   // namespace minecraft::chunks

#include "chunk_column_impl.hpp"
#include "connection_impl.ipp.hpp"

#endif   // MINECRAFT_CHUNKS_CONNECTION_IMPL