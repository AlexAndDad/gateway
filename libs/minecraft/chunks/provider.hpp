#pragma once
#include "chunk_column_impl.hpp"
#include "connection.hpp"
#include "connection_impl.hpp"
#include "provider_impl.hpp"

namespace minecraft::chunks
{
    struct provider
    {
        provider(net::executor exec);
        provider(provider &&)      = default;
        provider &operator         =(provider &&);
        provider(provider const &) = delete;
        provider &operator=(provider const &) = delete;
        ~provider();

        auto cancel() -> void;
        auto valid() -> bool { return static_cast< bool >(impl_); }
        auto connect(connection_impl::executor_type e) -> connection;

        /// Notify the provider of a new (or initial) replacement chunk.
        ///
        /// This will propagate down to consumers as a state of the world snapshot
        /// \param the chunk_column to copy/move
        auto notify(chunk_column_impl const &cc) -> void;
        auto notify(chunk_column_impl &&cc) -> void;
        auto notify(vector3 pos, blocks::block_type blk) -> void;

      private:
        std::shared_ptr< provider_impl > impl_;
    };
}   // namespace minecraft::chunks