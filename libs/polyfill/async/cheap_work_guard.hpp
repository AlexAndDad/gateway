#pragma once
#include "polyfill/net.hpp"

#include <cassert>
#include <utility>

namespace polyfill::async
{
    template < class Executor >
    struct cheap_work_guard
    {
        using context_type = std::remove_reference_t< decltype(
            std::declval< Executor >().context()) >;

        using storage_area_type =
            std::aligned_storage_t< sizeof(Executor), alignof(Executor) >;

        explicit cheap_work_guard(Executor const &e) noexcept
        : context_(std::addressof(e.context()))
        {
            e.on_work_started();
        }

        cheap_work_guard(cheap_work_guard const &other) noexcept
        : context_(other.context_)
        {
            add(context_);
        }

        cheap_work_guard(cheap_work_guard &&other) noexcept
        : context_(std::exchange(other.context_, nullptr))
        {
        }

        cheap_work_guard &operator=(cheap_work_guard const &other) noexcept
        {
            auto old = std::exchange(context_, other.context_);
            if (old != context_)
            {
                add(context_);
                destroy(old);
            }
            return *this;
        }

        cheap_work_guard &operator=(cheap_work_guard &&other) noexcept
        {
            auto old =
                std::exchange(context_, std::exchange(other.context_, nullptr));
            destroy(old);
            return *this;
        }

        ~cheap_work_guard() noexcept { destroy(context_); }

        void reset() { destroy(std::exchange(context_, nullptr)); }

      private:
        static void destroy(context_type *c) noexcept
        {
            if (c)
                c->get_executor().on_work_finished();
        }

        static void add(context_type *c) noexcept
        {
            if (c)
                c->get_executor().on_work_started();
        }

        context_type *context_;
    };

    template < class Executor, class = void >
    struct cheapest_work_guard
    {
        using type = net::executor_work_guard< Executor >;
    };

    template < class Executor >
    struct cheapest_work_guard<
        Executor,
        std::void_t< decltype(
            std::declval< Executor >().context().get_executor()) > >
    {
        using type = cheap_work_guard< Executor >;
    };

    template<class Executor>
    using cheapest_work_guard_t = typename cheapest_work_guard<Executor>::type;
}   // namespace polyfill::async