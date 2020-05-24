#pragma once
#include "polyfill/net.hpp"

#include <memory>
#include <type_traits>

namespace polyfill::async
{
    namespace detail
    {
        union sbo_storage
        {
            sbo_storage() noexcept {}

            ~sbo_storage() {}

            void *                             short_[6];
            std::unique_ptr< unsigned char[] > long_;
        };

        template < class Ret, class... Args >
        struct poly_handler_vtable
        {
            // move-construct from value - may throw
            void (*const move_construct_from_actual)(sbo_storage &storage,
                                                     void *actual) noexcept;

            // move construct from other SBO. May not throw
            void (*const move_construct)(sbo_storage &storage,
                                         sbo_storage &source) noexcept;

            Ret (*const invoke)(sbo_storage &storage, Args... args);

            void (*const destroy)(sbo_storage &storage) noexcept;

            net::executor (*const get_executor)(
                sbo_storage const &storage) noexcept;
        };

        template < class Actual, class Ret, class... Args >
        static auto make_small_poly_handler_vtable()
        {
            static_assert(sizeof(Actual) <= sizeof(sbo_storage));

            static const struct mine : poly_handler_vtable< Ret, Args... >
            {
                static Actual &realise(sbo_storage &storage) noexcept
                {
                    return *reinterpret_cast< Actual * >(&storage.short_[0]);
                }

                static Actual const &
                realise(sbo_storage const &storage) noexcept
                {
                    return *reinterpret_cast< Actual const * >(
                        &storage.short_[0]);
                }

                static void move_construct_from_actual_(sbo_storage &storage,
                                                        void *source) noexcept
                {
                    new (&realise(storage)) Actual(
                        std::move(*reinterpret_cast< Actual * >(source)));
                }

                static void move_construct_(sbo_storage &storage,
                                            sbo_storage &source) noexcept
                {
                    new (&realise(storage)) Actual(std::move(realise(source)));
                }

                static Ret invoke_(sbo_storage &storage, Args... args)
                {
                    auto act = std::move(realise(storage));
                    destroy_(storage);
                    return act(std::move(args)...);
                }

                static void destroy_(sbo_storage &storage) noexcept
                {
                    realise(storage).~Actual();
                }

                static net::executor
                get_executor_(sbo_storage const &storage) noexcept
                {
                    return net::get_associated_executor(realise(storage));
                }
            } x { { .move_construct_from_actual =
                        &mine::move_construct_from_actual_,
                    .move_construct = &mine::move_construct_,
                    .invoke         = &mine::invoke_,
                    .destroy        = &mine::destroy_,
                    .get_executor   = &mine::get_executor_ } };
            return &x;
        }

        template < class Actual, class Ret, class... Args >
        auto make_big_poly_handler_vtable()
        {
            static_assert(sizeof(Actual) > sizeof(sbo_storage));

            static const struct mine : poly_handler_vtable< Ret, Args... >
            {
                static void move_construct_from_actual(sbo_storage &storage,
                                                       void *source) noexcept
                {
                    constexpr auto size = sizeof(Actual);
                    new (&storage.long_) std::unique_ptr< unsigned char[] >();
                    storage.long_.reset(new unsigned char[size]);
                    new (storage.long_.get()) Actual(
                        std::move(*reinterpret_cast< Actual * >(source)));
                }

                static void move_construct(sbo_storage &storage,
                                           sbo_storage &source) noexcept
                {
                    new (&storage.long_) std::unique_ptr< unsigned char[] >(
                        std::move(source.long_));
                }

                static Ret invoke(sbo_storage &storage, Args... args)
                {
                    auto act = std::move(
                        *reinterpret_cast< Actual * >(storage.long_.get()));
                    storage.long_.reset();
                    destroy(storage);
                    return act(std::move(args)...);
                }

                static void destroy(sbo_storage &storage) noexcept
                {
                    if (storage.long_)
                        reinterpret_cast< Actual * >(storage.long_.get())
                            ->~Actual();
                    storage.long_.~unique_ptr< unsigned char[] >();
                }

                static net::executor
                get_executor(sbo_storage const &storage) noexcept
                {
                    auto &actual =
                        *reinterpret_cast< Actual * >(storage.long_.get());
                    return net::get_associated_executor(actual);
                }
            } x { { .move_construct_from_actual =
                        &mine::move_construct_from_actual,
                    .move_construct = &mine::move_construct,
                    .invoke         = &mine::invoke,
                    .destroy        = &mine::destroy,
                    .get_executor   = &mine::get_executor } };
            return &x;
        }

    }   // namespace detail
    /// A polymorphic completion handler
    /// \tparam Sig
    template < class Sig >
    class poly_handler;

    template < class T, class U >
    concept ConvertibleTo = requires
    {
        std::is_convertible_v< T, U >;
    };

    template < class F, class Ret, class... Args >
    concept TypedCompletionHandler = requires(F f)
    {
        { static_cast< const F & >(f).get_executor() };
        {
            f(Args {}...)
        }
        ->ConvertibleTo< Ret >;
    };

    template < class Ret, class... Args >
    class poly_handler< Ret(Args...) >
    {
        detail::sbo_storage                                storage_;
        detail::poly_handler_vtable< Ret, Args... > const *kind_;

      public:
        using executor_type = net::executor;

        explicit poly_handler(nullptr_t = nullptr)
        : storage_ {}
        , kind_(nullptr)
        {
        }

        template <
            TypedCompletionHandler< Ret, Args... > Actual,
            std::enable_if_t< !std::is_same_v< Actual, poly_handler > &&
                              std::is_invocable_r_v< Ret, Actual, Args... > >
                * = nullptr >
        poly_handler(Actual actual)
        {
            construct(std::move(actual));
        }

        poly_handler(poly_handler &&other) noexcept
        : storage_ {}
        , kind_(std::exchange(other.kind_, nullptr))
        {
            if (kind_)
            {
                kind_->move_construct(storage_, other.storage_);
                kind_->destroy(other.storage_);
            }
        }

        template <
            TypedCompletionHandler< Ret, Args... > Actual,
            std::enable_if_t< !std::is_same_v< Actual, poly_handler > &&
                              std::is_invocable_r_v< Ret, Actual, Args... > >
            * = nullptr >
        poly_handler& operator=(Actual a) noexcept
        {
            destroy();
            construct(std::move(a));

            return *this;
        }

        poly_handler& operator=(nullptr_t) noexcept
        {
            destroy();
        }

        poly_handler &operator=(poly_handler &&other) noexcept
        {
            destroy();
            kind_ = std::exchange(other.kind_, nullptr);
            kind_->move_construct(storage_, other.storage_);
            kind_->destroy(other.storage_);
            return *this;
        }

        ~poly_handler()
        {
            destroy();
        }

        Ret operator()(Args... args)
        {
            auto k = std::exchange(kind_, nullptr);
            if (k)
                // invoke implies destroy
                return k->invoke(storage_, std::move(args)...);
            else
                throw std::bad_function_call();
        }

        bool has_value() const { return kind_ != nullptr; }
             operator bool() const { return has_value(); }

        auto get_executor() const -> executor_type
        {
            assert(kind_);
            return kind_->get_executor(storage_);
        }

      private:

        template<class Actual>
        void construct(Actual&& actual)
        {
            constexpr auto size  = sizeof(Actual);
            constexpr auto limit = sizeof(storage_.short_);
            if constexpr (size > limit)
            {
                // non-sbo
                auto kind = detail::
                make_big_poly_handler_vtable< Actual, Ret, Args... >();
                kind->move_construct_from_actual(storage_, std::addressof(actual));
                kind_ = kind;
            }
            else
            {
                // sbo
                auto kind = detail::
                make_small_poly_handler_vtable< Actual, Ret, Args... >();
                kind->move_construct_from_actual(storage_, std::addressof(actual));
                kind_ = kind;
            }
        }

        void destroy() noexcept
        {
            if(auto kind = std::exchange(kind_, nullptr))
                kind->destroy(storage_);
        }
    };
}   // namespace polyfill::async