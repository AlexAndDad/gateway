#include "connection_impl.hpp"

#include "chunk_data_impl.hpp"
#include "provider_impl.hpp"

namespace minecraft::chunks
{
    connection_impl::connection_impl(executor_type                    exec,
                                     std::shared_ptr< provider_impl > provider)
    : exec_(exec)
    , provider_(provider)
    {
    }

    //
    // called by consumer
    //

    void connection_impl::cancel()
    {
        assert(this->provider_);
        provider_->notify_cancel(shared_from_this());
    }

    void connection_impl::notify_update(chunk_data_impl const &c)
    {
        this->current_snapshot_ = std::make_unique< chunk_data_impl >(c);
        this->updates_.clear();
        this->state_ = deliver_snapshot;
        try_invoke();
    }

    void connection_impl::notify_update(block_update u)
    {
        switch (state_)
        {
        case not_ready:
            break;

        case deliver_snapshot:
            assert(this->current_snapshot_);
            current_snapshot_->change_block(u.pos, u.new_state);
            break;

        case deliver_updates:
            updates_.push_back(u);
            break;

        case deliver_error:
            break;

        case stopped:
            assert(!"logic error");
            return;
        }

        try_invoke();
    }

    void connection_impl::try_invoke()
    {
        if (not waiting_)
            return;

        assert(current_op_handler_);

        switch (state_)
        {
            // not state yet ready. must suspend
        case connection_impl::not_ready:
            assert(not ec_);
            break;

            // deliver the snapshot and then move to incremental updates.
        case connection_impl::deliver_snapshot:
        {
            assert(not ec_);
            assert(updates_.empty());
            auto handler = std::move(current_op_handler_);
            auto arg     = chunk_update(std::move(current_snapshot_));
            state_       = connection_impl::deliver_updates;
            waiting_     = false;
            handler(error_code(), std::move(arg));
            break;
        }

            // action depends on how many updates are pending delivery
        case connection_impl::deliver_updates:
            assert(not ec_);
            switch (updates_.size())
            {
                // if zero, then suspend
            case 0:
                break;

                // if 1, then send a single block update
            case 1:
            {
                assert(not current_snapshot_);
                auto handler = std::move(current_op_handler_);
                auto arg     = chunk_update(std::move(updates_.front()));
                updates_.clear();
                waiting_ = false;
                handler(error_code(), std::move(arg));
                break;
            }
                // if more than 1 send a bulk update
            default:
            {
                assert(not current_snapshot_);
                auto handler = std::move(current_op_handler_);
                auto arg     = chunk_update(std::move(updates_));
                waiting_     = false;
                handler(error_code(), std::move(arg));
                break;
            }
            }
            break;

        case connection_impl::deliver_error:
        {
            assert(ec_);
            assert(not current_snapshot_);
            assert(updates_.empty());
            auto handler = std::move(current_op_handler_);
            auto ec      = ec_;
            if (ec == net::error::operation_aborted)
            {
                ec_.clear();
                state_ = not_ready;
            }
            else
            {
                state_ = stopped;
            }
            waiting_     = false;
            handler(ec, chunk_update());
            break;
        }
        case connection_impl::stopped:
            assert(ec_);
            auto handler = std::move(current_op_handler_);
            auto ec = ec_;
            waiting_     = false;
            handler(ec, chunk_update());
            break;
        }
    }

    void connection_impl::notify_error(error_code ec)
    {
        ec_ = ec;
        current_snapshot_.reset();
        updates_.clear();
        state_ = deliver_error;
        try_invoke();
    }

}   // namespace minecraft::chunks
