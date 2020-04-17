#include "connection_impl.hpp"

#include "minecraft/protocol/client_connect.hpp"
#include "minecraft/security/rsa.hpp"
#include "minecraft/send_frame.hpp"
#include "minecraft/server/chat_message.hpp"
#include "minecraft/server/play_packet.hpp"
#include "polyfill/hexdump.hpp"
#include "polyfill/report.hpp"

#include <random>
#include <spdlog/spdlog.h>

namespace relay
{
    using namespace std::literals;

    namespace
    {
        std::string generate_server_id()
        {
            auto rng   = std::random_device();
            auto seq   = std::seed_seq { rng(), rng(), rng(), rng(), rng() };
            auto eng   = std::default_random_engine(seq);
            auto chars = "0123456789abcdefghijklmnopqrstuvwxyz"sv;
            auto dist  = std::uniform_int_distribution< std::size_t >(0, chars.size() - 1);

            auto result = std::string();
            std::generate_n(std::back_inserter(result), 16, [&] { return chars[dist(eng)]; });

            return result;
        }

    }   // namespace

    connection_config::connection_config()
    : server_key()
    , server_id(generate_server_id())
    {
        server_key.assign(minecraft::security::rsa(1024));
    };

    auto operator<<(std::ostream &os, connection_config const &cfg) -> std::ostream &
    {
        os << "Connection Config:\n"
              "\tserver id  : "
           << cfg.server_id
           << "\n"
              "\tserver key : "
           << polyfill::hexstring(cfg.server_key.public_asn1()) << "\tupstream host : " << cfg.upstream_host
           << "\tupstream port : " << cfg.upstream_port;
        return os;
    }

    // =========================================

    connection_impl::connection_impl(connection_config config, socket_type &&sock)
    : config_(std::move(config))
    , stream_(std::move(sock))
    , upstream_(socket_type(get_executor()))
    , resolver_(get_executor())
    {
        spdlog::info("{} accepted", this);
    }

    auto connection_impl::start() -> void
    {
        dispatch(bind_executor(get_executor(), [self = shared_from_this()] { self->handle_start(); }));
    }

    auto connection_impl::cancel() -> void
    {
        dispatch(bind_executor(get_executor(), [self = shared_from_this()] { self->handle_cancel(); }));
    }

    auto connection_impl::get_executor() -> executor_type { return stream_.get_executor(); }

    auto connection_impl::handle_cancel() -> void { stream_.close(); }

    auto connection_impl::handle_start() -> void
    {
        //        initiate_read();

        login_params_.set_server_key(config_.server_key);
        login_params_.set_server_id(config_.server_id);
        login_params_.use_security(true);

        minecraft::protocol::async_server_accept(
            stream_,
            this->login_params_,
            bind_executor(get_executor(),
                          [self = this->shared_from_this()](error_code const &ec) { self->handle_login(ec); }));
    }

    template < class NextLayer, class Iter, class CompletionToken >
    auto
    async_send_packets(minecraft::protocol::stream< NextLayer > &stream, Iter first, Iter last, CompletionToken &&token)
    {
        auto op = [&stream, coro = net::coroutine(), first, last](
                      auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
#include <boost/asio/yield.hpp>
            reenter(coro) for (;;)
            {
                if (first == last)
                    return self.complete(ec);
                spdlog::info("writing packet: {}", wise_enum::to_string(first->id()));
                yield stream.async_write_packet(*first++, std::move(self));
                if (ec.failed())
                    return self.complete(ec);
            }
#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionToken, void(error_code) >(std::move(op), token, stream);
    }

    auto connection_impl::initiate_upstream_resove() -> void
    {
        spdlog::trace("{}::{}()", this, __func__);
        resolver_.async_resolve(config_.upstream_host, config_.upstream_port, bind_self([](auto self, auto &&... args) {
                                    self->handle_upstream_resolve(args...);
                                }));
    }

    auto connection_impl::handle_upstream_resolve(error_code ec, protocol::resolver::results_type results) -> void
    {
        if (ec.failed())
        {
            spdlog::warn("{}::{}({})", this, __func__, minecraft::report(ec));
        }
        else
        {
            spdlog::info("{}::{}({})", this, __func__, minecraft::report(ec));
            initiate_upstream_transport(results);
        }
    }

    auto connection_impl::initiate_upstream_transport(protocol::resolver::results_type results) -> void
    {
        spdlog::trace("{}::{}()", this, __func__);
        net::async_connect(
            upstream_.next_layer(), results, bind_self([](auto self, error_code const &ec, auto &&... args) {
                self->handle_upstream_transport(ec);
            }));
    }

    auto connection_impl::handle_upstream_transport(error_code ec) -> void
    {
        if (ec.failed())
        {
            spdlog::warn("{}::{}({})", this, __func__, minecraft::report(ec));
        }
        else
        {
            spdlog::info("{}::{}({})", this, __func__, minecraft::report(ec));
            connect_state_.version(this->login_params_.version());
            connect_state_.name(this->login_params_.name());
            connect_state_.connection_args(config_.upstream_host, upstream_.next_layer().remote_endpoint().port());

            minecraft::protocol::async_client_connect(
                upstream_, connect_state_, bind_self([](auto self, error_code ec) { self->handle_upstream_connect(ec); }));
        }
    }

    auto connection_impl::handle_upstream_connect(error_code ec) -> void
    {
        if (ec.failed())
        {
            spdlog::warn("{}::{}({})", this, __func__, minecraft::report(ec));
        }
        else
        {
            spdlog::info("{}::{}({})", this, __func__, minecraft::report(ec));
        }
    }

    auto connection_impl::handle_login(error_code const &ec) -> void
    {
        if (ec.failed())
        {
            spdlog::warn("{}::{}({})", this, __func__, minecraft::report(ec));
        }
        else
        {
            spdlog::info("{}::{}({})", this, __func__, minecraft::report(ec));
            initiate_upstream_resove();
        }
        std::cout << "login state: \n" << login_params_ << std::endl;
    }

    void connection_impl::initiate_spin()
    {
        stream_.async_read_frame(bind_executor(
            get_executor(), [self = shared_from_this()](error_code ec, std::size_t bt) { self->handle_spin(ec, bt); }));
    }

    void connection_impl::handle_spin(error_code ec, std::size_t bytes_transferrred)
    {
        if (ec.failed())
        {
            std::cerr << "rx error : " << polyfill::report(ec) << std::endl;
        }
        else
        {
            auto id    = std::int32_t();
            auto data  = stream_.current_frame();
            auto first = net::buffers_begin(data);
            auto last  = net::buffers_end(data);
            auto i     = minecraft::parse_var(first, last, id, ec);

            std::cout << "received frame length: " << bytes_transferrred;
            std::cout << " : type " << std::hex << id << std::endl;
            std::cout << polyfill::hexdump(std::string_view(reinterpret_cast< const char * >(data.data()), data.size()))
                      << std::endl;
            initiate_spin();
        }
    }

}   // namespace relay