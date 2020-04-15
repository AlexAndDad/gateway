#include "connection.hpp"

#include "minecraft/security/rsa.hpp"
#include "minecraft/send_frame.hpp"
#include "polyfill/hexdump.hpp"

#include <iostream>
#include <minecraft/server/chat_message.hpp>
#include <polyfill/explain.hpp>
#include <polyfill/report.hpp>
#include <random>

namespace masquerade
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
           << polyfill::hexstring(cfg.server_key.public_asn1());
        return os;
    }

    connection_impl::connection_impl(connection_config config, socket_type &&sock)
    : config_(std::move(config))
    , sock_(std::move(sock))
    , resolver_(get_executor())
    , upstream_sock_(get_executor())
    {
    }

    auto connection_impl::start() -> void
    {
        dispatch(bind_executor(get_executor(), [self = shared_from_this()] { self->handle_start(); }));
    }

    auto connection_impl::cancel() -> void
    {
        dispatch(bind_executor(get_executor(), [self = shared_from_this()] { self->handle_cancel(); }));
    }

    auto connection_impl::get_executor() -> executor_type { return sock_.get_executor(); }

    auto connection_impl::handle_cancel() -> void { sock_.cancel(); }

    auto connection_impl::handle_start() -> void { initiate_accept(); }

    void connection_impl::initiate_accept()
    {
        login_params_.set_server_key(config_.server_key);
        login_params_.set_server_id(config_.server_id);
        login_params_.use_security(false);

        minecraft::protocol::async_receive_login(
            sock_,
            net::dynamic_buffer(rx_buffer_),
            this->login_params_,
            bind_executor(get_executor(),
                          [self = this->shared_from_this()](error_code const &ec) { self->handle_accept(ec); }));
    }

    void connection_impl::handle_accept(error_code ec)
    {
        if (ec.failed())
        {
            std::cerr << "connection: accept failed: " << polyfill::report(ec) << std::endl;
        }
        else
        {
            std::cout << "connection: client accepted: " << login_params_.client_login_start.name << std::endl;
            upstream_connect_params_.name(login_params_.client_login_start.name);
            upstream_connect_params_.connection_args(login_params_.client_handshake_frame.server_address,
                                                     login_params_.client_handshake_frame.server_port);
            initiate_upstream_resolve();
            //            initiate_upstream_connect();
        }
    }

    void connection_impl::initiate_upstream_resolve()
    {
        resolver_.async_resolve(
            config_.upstream_host,
            config_.upstream_port,
            bind_executor(get_executor(),
                          [self = shared_from_this()](error_code const &ec, resolver_type::results_type results) {
                              if (ec.failed())
                                  std::cerr << "resolve failed: " << polyfill::report(ec) << std::endl;
                              else
                                  net::async_connect(
                                      self->upstream_sock_,
                                      results,
                                      bind_executor(self->get_executor(), [self](error_code ec, protocol::endpoint ep) {
                                          if (ec.failed())
                                              std::cerr << "upstream connect: " << polyfill::report(ec) << std::endl;
                                          else
                                              self->initiate_upstream_login();
                                      }));
                          }));
    }

    void connection_impl::initiate_upstream_login()
    {
        std::cout << "initiating upstream login: " << upstream_sock_.remote_endpoint().address() << ':'
                  << upstream_sock_.remote_endpoint().port() << std::endl;

        minecraft::protocol::async_connect(upstream_sock_,
                                         net::dynamic_buffer(upstream_rx_buffer_),
                                         upstream_connect_params_,
                                         bind_executor(get_executor(), [self = shared_from_this()](error_code ec) {
                                             self->handle_upstream_login(ec);
                                         }));
    }

    void connection_impl::handle_upstream_login(boost::system::error_code ec)
    {
        if (ec.failed())
        {
            std::cerr << "upstream login failed: " << polyfill::report(ec) << std::endl;
        }
        else
        {
            std::cout << "upstream connected: " << upstream_connect_params_.server_login_success.uuid << std::endl;
        }
    }

    // ======================================================

    connection::connection(connection_config config, socket_type &&sock)
    : impl_(std::make_shared< connection_impl >(std::move(config), std::move(sock)))
    {
        impl_->start();
    }

    void connection::cancel()
    {
        if (impl_)
            impl_->cancel();
    }

    auto connection::get_weak_impl() const -> std::weak_ptr< connection_impl > { return impl_; }

}   // namespace masquerade