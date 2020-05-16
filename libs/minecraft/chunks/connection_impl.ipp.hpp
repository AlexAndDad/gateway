#include "connection_impl.hpp"
#include "provider_impl.hpp"
#include "wait_op_base.hpp"

namespace minecraft::chunks
{
    template < class Handler, class Executor >
    struct connection_impl::wait_op
    : wait_op_base
    , std::enable_shared_from_this<
          connection_impl::wait_op< Handler, Executor > >
    {
        using executor_type = Executor;

        template < class HandlerArg >
        wait_op(HandlerArg &&handler, Executor exec)
        : handler_(std::forward< HandlerArg >(handler), wg_(exec))
        {
        }

        Handler                              handler_;
        net::executor_work_guard< Executor > wg_;

        Executor get_executor() const { return wg_.get_executor(); }

        void initial_suspend() {}

        void complete(error_code ec, chunk_update &&u)
        {
            handler_(ec, std::move(u));
            delete this;
        }

        void notify_update(chunk_update u) override
        {
            assert(exec_);
            post(bind_executor(exec_, [this, u = std::move(u)]() mutable {
                this->complete(error_code(), std::move(u));
            }));
        }

        void notify_error(error_code ec) override
        {
            assert(exec_);
            post(bind_executor(
                exec_, [this, ec]() { this->complete(ec, chunk_update()); }));
        }
    };

    template < class CompletionToken >
    auto connection_impl::async_wait(CompletionToken &&token) ->
        typename net::async_result< std::decay_t< CompletionToken >,
                                    void(error_code, value_type) >::return_type
    {
        auto exec  = net::get_associated_executor(token, exec_);
        return net::async_initiate< CompletionToken,
                                    void(error_code, value_type) >(
            [&](auto &&handler) {
                assert(this->current_op_handler_.empty());
                this->current_op_handler_ =
                    std::forward< std::decay_t< decltype(handler) > >(handler);
                auto was_waiting = this->waiting_.exchange(true);
                assert(!was_waiting);
                provider_->notify_waiting(this);
            },
            token);
    }

}   // namespace minecraft::chunks
