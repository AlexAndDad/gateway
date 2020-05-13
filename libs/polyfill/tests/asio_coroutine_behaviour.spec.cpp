//
// Created by rhodges on 23/04/2020.
//

#include "polyfill/async/future.hpp"
#include "polyfill/net.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <optional>
#include <thread>
#include <tuple>
#include <unordered_map>

using namespace polyfill;

TEST_CASE("polyfill::tests::asio_coroutine_behaviour")
{
    SECTION("which executor")
    {
        struct context
        {
            static auto get_map() -> std::vector< std::tuple< std::string, context * > > &
            {
                static std::vector< std::tuple< std::string, context * > > vec_;
                return vec_;
            }

            context(std::string name)
            : name(name)
            {
            }

            void start()
            {
                work_guard.emplace(net::make_work_guard(ioc));
                thread = std::thread([this] { this->ioc.run(); });
                get_map().emplace_back(name, this);
            }

            std::thread                                                                 thread;
            net::io_context                                                             ioc;
            std::optional< net::executor_work_guard< net::io_context::executor_type > > work_guard;
            std::string                                                                 name;
        };

        std::unordered_map< std::thread::id, std::string > names;

        context a("a");
        context b("b");

        auto which_thread = [] {
            auto id   = std::this_thread::get_id();
            auto iter = std::find_if(context::get_map().begin(), context::get_map().end(), [id](auto &&elem) {
                auto &[name, pcontext] = elem;
                return id == pcontext->thread.get_id();
            });
            return std::get< std::string >(*iter);
        };

        a.start();
        b.start();

        std::promise< void > p;
        net::co_spawn(
            a.ioc.get_executor(),
            [&]() -> net::awaitable< void > {
                //std::cout << "Checkpoint 1 : thread " << which_thread() << std::endl;

                CHECK(which_thread() == "a");

                co_await net::dispatch(b.ioc.get_executor(), net::use_awaitable);

                CHECK(which_thread() == "a");
                //std::cout << "Checkpoint 2 : thread " << which_thread() << std::endl;

                auto ap = async::promise< int >();
                auto f = ap.get_future();
                net::co_spawn(
                    b.ioc.get_executor(),
                    [&which_thread]() -> net::awaitable< int > {
                        CHECK(which_thread() == "b");
                        //std::cout << "Checkpoint 3 : thread " << which_thread() << std::endl;
                        co_return 0;
                    },
                    [ap = std::move(ap)](std::exception_ptr, int x) mutable { ap.set_value(x); });

                auto v = co_await f();
                CHECK(which_thread() == "a");
                CHECK(v == 0);
                //std::cout << "Checkpoint 4 : thread " << which_thread() << " with value " << v << std::endl;

                p.set_value();
                co_return;
            },
            net::detached);

        p.get_future().wait();

        a.work_guard.reset();
        b.work_guard.reset();
        a.thread.join();
        b.thread.join();
    }
}