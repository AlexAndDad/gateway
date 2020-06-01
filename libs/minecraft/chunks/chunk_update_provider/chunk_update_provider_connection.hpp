//
// Created by ahodges on 28/05/2020.
//

#pragma once

#include "chunks/chunk_service_traits.hpp"
#include "net.hpp"
#include "polyfill/async/future.hpp"

#include "chunks/chunk_update.hpp"

namespace minecraft::chunks
{
    template < class... Ts >
    struct overloaded : Ts...
    {
        using Ts::operator()...;
    };
    template < class... Ts >
    overloaded(Ts...) -> overloaded< Ts... >;

    struct chunk_update_provider_connection
    : std::enable_shared_from_this< chunk_update_provider_connection >
    , chunk_service_traits
    {
        using executor_type = net::executor;
        using value_type    = chunk_update;

        chunk_update_provider_connection(executor_type exec, sequence_number seq)
        : exec_(exec)
        , seq_(seq)
        {
        }

        auto update(value_type update, sequence_number num) -> void
        {
            net::post(net::bind_executor(get_executor(), [self = shared_from_this(), update = std::move(update), num]() mutable {
                self->handle_update(std::move(update), num);
            }));
        }

        auto wait() -> net::awaitable< value_type >
        {
            auto promise = polyfill::async::promise< value_type >();
            auto fut     = promise.get_future();

            net::post(net::bind_executor(get_executor(), [self = shared_from_this(), promise = std::move(promise)]() mutable {
                BOOST_ASSERT(not self->consumer_waiting_);
                if (self->opt_val_)
                    promise.set_value(std::move(self->opt_val_.value()));
                else
                    self->consumer_waiting_ = std::move(promise);
                return;
            }));
            co_return co_await fut();
        }

        auto get_executor() -> executor_type { return exec_; }

      private:
        // Here handle merging updates if applicable, also if a consumer is waiting, provide it the update.
        auto handle_update(value_type update, sequence_number num) -> void
        {
            BOOST_ASSERT(num == (seq_ + 1));
            seq_ = num;
            try_merge_update(update);   // update is now in an undefined state
            if (consumer_waiting_)
            {
                consumer_waiting_.value().set_value(std::move(opt_val_.value()));
                consumer_waiting_.reset();
                opt_val_.reset();
            }
        }

        auto try_merge_update(value_type &update) -> void
        {
            if (opt_val_)   // We already have a queued update
            {
                auto &val = opt_val_.value();
                visit(overloaded { [&update](copyable_chunk_column_impl &arg1) {
                                      visit(overloaded { [&arg1](copyable_chunk_column_impl &arg2) { arg1 = std::move(arg2); },
                                                         [&arg1](block_update &arg2) { arg1->change_block(arg2.pos, arg2.new_state); },
                                                         [&arg1](update_sequence &arg2) {
                                                             for (auto &block : arg2)
                                                             {
                                                                 arg1->change_block(block.pos, block.new_state, false);
                                                             }
                                                             arg1->recalc();
                                                         } },
                                            update.as_variant());
                                  },
                                   [&update, &val](block_update &arg1) {
                                       visit(overloaded { [&val](copyable_chunk_column_impl &arg2) { val = std::move(arg2); },
                                                          [&val, &arg1](block_update &arg2) {
                                                              auto tmp = update_sequence();
                                                              tmp.emplace_back(arg1);
                                                              tmp.emplace_back(arg2);
                                                              val = std::move(tmp);
                                                          },
                                                          [&val, &arg1](update_sequence &arg2) {
                                                              arg2.emplace_front(arg1);
                                                              val = std::move(arg2);
                                                          } },
                                             update.as_variant());
                                   },
                                   [&update, &val](update_sequence &arg1) {
                                       visit(overloaded {
                                                 [&val](copyable_chunk_column_impl &arg2) { val = std::move(arg2); },
                                                 [&arg1](block_update &arg2) { arg1.emplace_back(arg2); },
                                                 [&arg1](update_sequence &arg2) { arg1.insert(arg1.end(), arg2.begin(), arg2.end()); } },
                                             update.as_variant());
                                   } },
                      val.as_variant());
            }
            else
            {
                opt_val_.emplace(std::move(update));
            }
        };

        executor_type               exec_;
        std::optional< value_type > opt_val_;
        sequence_number             seq_;

        std::optional< polyfill::async::promise< value_type > > consumer_waiting_;
    };

}   // namespace minecraft::chunks
