#include "connection.hpp"

#include "hexdump.hpp"
#include "minecraft/security/rsa.hpp"

#include <iostream>
#include <polyfill/explain.hpp>
#include <polyfill/report.hpp>
#include <random>

namespace gateway
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

    /*
"\x30\x81\x9f\x30" \
"\x0d\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01\x01\x01\x05\x00\x03\x81" \
"\x8d\x00\x30\x81\x89\x02\x81\x81\x00\xc4\x81\xc0\xb2\xa3\xc6\x5f" \
"\xf6\x13\xb1\x83\x43\xca\x4a\x79\xdf\x40\x3e\xe0\x37\x3e\x9a\x25" \
"\xcb\xaf\xd9\x00\x64\xb0\xc2\x06\x18\x25\x28\x2b\xc2\x49\x31\x34" \
"\x1b\x77\x17\xcf\x64\xfb\x57\x21\x30\xd1\x56\xf5\x6c\x07\xf3\x99" \
"\x11\x36\xb2\x82\x8d\x7c\x3f\x5b\x3a\xf9\xdf\x15\x5e\x87\xd8\x16" \
"\x66\x27\xe6\xa3\xf3\x66\x3d\xa7\x38\xcc\x76\x07\x0a\xc9\x35\xef" \
"\x9a\xde\x29\x09\x35\xf9\xf3\xb3\x76\x7f\x89\xe1\x41\x08\x3f\x53" \
"\x23\x52\xce\xe1\x96\xfb\x69\xe2\x6e\xe6\xd9\x2d\x96\x2e\xc5\x29" \
"\xde\xb2\x5f\x8d\x3b\xdd\x78\xf8\xe5\x02\x03\x01\x00\x01"

     */

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
           << hexstring(cfg.server_key.public_asn1());
        return os;
    }

    connection_impl::connection_impl(connection_config config, socket_type &&sock)
    : config_(std::move(config))
    , sock_(std::move(sock))
    , login_state_(config_.server_id, config_.server_key)
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

    auto connection_impl::handle_start() -> void
    {
        //        initiate_read();

        login_params_.set_server_key(config_.server_key);
        login_params_.set_server_id(config_.server_id);
        login_params_.use_security(false);

        minecraft::server::async_receive_login(
            sock_,
            net::dynamic_buffer(rx_buffer_),
            this->login_params_,
            bind_executor(get_executor(), [self = this->shared_from_this()](error_code const &ec) {
                if (ec.failed())
                {
                    std::cerr << "login failed: " << polyfill::report(ec) << std::endl;
                }
                else
                {
                    std::cout << "login complete\n";
                    self->initiate_spin();
                }
                std::cout << "login state: \n" << self->login_params_ << std::endl;
            }));
    }

    void connection_impl::initiate_spin()
    {
        rx_buffer_.resize(4096);
        sock_.async_read_some(net::buffer(rx_buffer_),
                        bind_executor(get_executor(), [self = shared_from_this()](error_code ec, std::size_t bt) {
                            self->handle_spin(ec, bt);
                        }));
    }

    void connection_impl::handle_spin(error_code ec, std::size_t bytes_transferrred)
    {
        std::cout << "spin: " << bytes_transferrred << " " << polyfill::report(ec) << std::endl;
        if (not ec.failed())
            initiate_spin();
    }


    auto connection_impl::initiate_read() -> void
    {
        auto dynbuf = net::dynamic_buffer(rx_buffer_);

        struct packet_finished
        {
            using dynamic_buffer     = decltype(dynbuf);
            using const_buffers_type = dynamic_buffer::const_buffers_type;
            using iterator           = net::buffers_iterator< const_buffers_type >;

            using result_type = std::pair< iterator, bool >;

            result_type operator()(iterator first, iterator last) const
            {
                auto next = parser.parse_data(first, last);

                if (complete(parser.result()))
                    return std::make_pair(next, true);
                else
                    return std::make_pair(first, false);
            }

            minecraft::frame_parser &parser;
        };

        async_read_until(
            sock_,
            net::dynamic_buffer(rx_buffer_),
            packet_finished { this->parser_ },
            bind_executor(get_executor(),
                          [self = shared_from_this()](error_code const &ec, std::size_t bytes_transferred) {
                              self->handle_read(ec, bytes_transferred);
                          }));
    }

    auto connection_impl::handle_read(error_code ec, std::size_t bytes_transferred) -> void
    {
        auto &&packet = parser_.result();
        auto   dynbuf = net::dynamic_buffer(rx_buffer_);
        if (!ec.failed())
        {
            if (std::holds_alternative< error_code >(packet.as_variant()))
                ec = std::get< error_code >(packet.as_variant());
            else if (std::holds_alternative< minecraft::incomplete >(packet.as_variant()))
            {
                ec = minecraft::error::incomplete_parse;
            }
        }

        if (ec.failed())
        {
            if (ec != net::error::operation_aborted)
            {
                std::clog << hexdump(std::string_view(rx_buffer_.data(), bytes_transferred)) << std::endl;
                std::clog << "connection: " << ec.message() << " : closing" << std::endl;
            }
            dynbuf.consume(bytes_transferred);
            return;
        }

        std::cout << hexdump(std::string_view(rx_buffer_.data(), bytes_transferred)) << std::endl;
        std::cout << packet << std::endl;

        auto visitor = [this](auto &&pckt) { this->handle_rx(pckt); };

        try
        {
            std::visit(visitor, packet.as_variant());
            dynbuf.consume(bytes_transferred);
            initiate_read();
        }
        catch (...)
        {
            std::clog << "connection : " << polyfill::explain() << std::endl;
        }
    }

    auto connection_impl::handle_rx(error_code ec) -> void { throw system_error(ec); }

    auto connection_impl::handle_rx(minecraft::incomplete) -> void
    {
        assert(!"logic error");
        throw system_error(minecraft::error::incomplete_parse);
    }

    auto connection_impl::handle_rx(minecraft::client::handshake const &ch) -> void
    {
        login_state_(ch);
        parser_.state(ch.next_state);
    }

    auto connection_impl::handle_rx(minecraft::client::login_start const &packet) -> void
    {
        login_state_(packet);
        queue(login_state_.encryption_request_);
    }

    auto connection_impl::handle_rx(minecraft::client::encryption_response const &packet) -> void
    {
        login_state_(packet);
        std::cout << "end of the line" << std::endl;
    }

    auto connection_impl::maybe_send() -> void
    {
        if (tx_buffer_[0].empty() and not tx_buffer_[1].empty())
        {
            std::swap(tx_buffer_[0], tx_buffer_[1]);
            std::cout << "sending: \n" << hexdump(tx_buffer_[0]) << std::endl;
            net::async_write(
                sock_,
                net::buffer(tx_buffer_[0]),
                bind_executor(get_executor(),
                              [self = this->shared_from_this()](error_code const &ec, std::size_t bytes_transferred) {
                                  self->handle_write(ec, bytes_transferred);
                              }));
        }
    }

    auto connection_impl::handle_write(error_code ec, std::size_t bytes_transferred) -> void
    {
        tx_buffer_[0].clear();
        if (!ec.failed())
            maybe_send();
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

}   // namespace gateway