#include "provider_impl.hpp"

#include "connection_impl.hpp"

namespace minecraft::chunks
{
    void provider_impl::notify_update(vector3 pos, blocks::block_type blk)
    {
        post(net::bind_executor(exec_, [self = shared_from_this(), pos, blk] {
            self->handle_notify_update(pos, blk);
        }));
    }
    void provider_impl::notify_waiting(connection_impl *handle)
    {
        post(
            bind_executor(exec_, [handle, self = shared_from_this()]() mutable {
                self->handle_notify_waiting(handle);
            }));
    }

    void provider_impl::notify_cancel(
        std::shared_ptr< connection_impl > const &pconn)
    {
        post(net::bind_executor(exec_, [self = shared_from_this(), pconn] {
            pconn->notify_error(net::error::operation_aborted);
        }));
    }

    auto provider_impl::create_connection_impl(net::executor exec)
        -> std::shared_ptr< connection_impl >
    {
        auto self = shared_from_this();
        auto p    = std::make_shared< connection_impl >(exec, self);
        post(bind_executor(exec_, [p, self] {
            self->connections_.emplace(p.get(), p);
            self->initial_update(p.get());
        }));
        return p;
    }

    // client notifies us that it's ready to receive an update
    void provider_impl::handle_notify_waiting(connection_impl *handle)
    {
        // lookup client
        auto pconn = lookup(handle);
        if (not pconn)
        {
            // client has destroyed itself. do nothing.
        }
        else
        {
            // client may only issue one async_wait op at a time
            assert(pconn->waiting_);
            assert(pconn->current_op_handler_);
            pconn->try_invoke();
        }
    }

    std::shared_ptr< connection_impl >
    provider_impl::lookup(connection_impl *handle)
    {
        auto result = std::shared_ptr< connection_impl >();

        if (auto i = connections_.find(handle); i != connections_.end())
            if (result = i->second.lock(); !result)
                connections_.erase(i);

        return result;
    }

    void provider_impl::initial_update(connection_impl *handle)
    {
        if (ec_)
            handle->notify_error(ec_);
        else if (current_snapshot_)
            handle->notify_update(*current_snapshot_);
    }

    void provider_impl::cancel()
    {
        post(net::bind_executor(
            exec_, [self = shared_from_this()] { self->handle_cancel(); }));
    }

    void provider_impl::handle_cancel()
    {
        ec_ = net::error::operation_aborted;
        for (auto iter = connections_.begin(); iter != connections_.end();
             iter      = connections_.erase(iter))
        {
            if (auto pconn = iter->second.lock(); pconn)
            {
                pconn->notify_error(ec_);
            }
        }
    }
    void provider_impl::notify_chunk(chunk_section_impl const &cc)
    {
        post(net::bind_executor(exec_,
                                [cc = cc, self = shared_from_this()]() mutable {
                                    self->handle_notify_chunk(std::move(cc));
                                }));
    }

    void provider_impl::notify_chunk(chunk_section_impl &&cc)
    {
        post(net::bind_executor(
            exec_, [cc = std::move(cc), self = shared_from_this()]() mutable {
                self->handle_notify_chunk(std::move(cc));
            }));
    }

    void provider_impl::handle_notify_update(vector3               pos,
                                             blocks::block_type blk)
    {
        ++current_sequence_;
        assert(current_snapshot_);
        if (current_snapshot_)
        {
            current_snapshot_->change_block(pos, blk);
            auto u = block_update { pos, blk };
            for (auto iter = connections_.begin(); iter != connections_.end();)
            {
                auto conn = iter->second.lock();
                if (not conn)
                {
                    iter = connections_.erase(iter);
                    continue;
                }

                conn->notify_update(u);
                iter = std::next(iter);
            }
        }
    }

    void provider_impl::handle_notify_chunk(chunk_section_impl &&cc)
    {
        ++current_sequence_;
        current_snapshot_.emplace(std::move(cc));
        for (auto iter = connections_.begin(); iter != connections_.end();)
        {
            auto conn = iter->second.lock();
            if (not conn)
            {
                iter = connections_.erase(iter);
                continue;
            }

            conn->notify_update(*current_snapshot_);
            iter = std::next(iter);
        }
    }

}   // namespace minecraft::chunks