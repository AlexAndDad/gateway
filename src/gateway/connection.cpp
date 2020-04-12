#include "connection.hpp"
#include "hexdump.hpp"
#include <iostream>
#include <polyfill/explain.hpp>
#include <polyfill/report.hpp>
#include "minecraft/security/rsa.hpp"
#include <random>

namespace gateway {

    using namespace std::literals;

    namespace {
        std::string generate_server_id()
        {
            auto rng = std::random_device();
            auto seq = std::seed_seq{rng(), rng(),rng(), rng(), rng()};
            auto eng = std::default_random_engine(seq);
            auto chars = "0123456789abcdefghijklmnopqrstuvwxyz"sv;
            auto dist = std::uniform_int_distribution<std::size_t>(0, chars.size() - 1);

            auto result = std::string();
            std::generate_n(std::back_inserter(result), 20, [&]{
                return chars[dist(eng)];
            });

            return result;
        }

    }

    connection_config::connection_config()
    : server_key()
    , server_id(generate_server_id())
    {
        server_key.assign(minecraft::security::rsa(1024));
    };

    auto operator<<(std::ostream& os, connection_config const& cfg) -> std::ostream&
    {
        os << "Connection Config:\n"
              "\tserver id  :" << cfg.server_id << "\n"
              "\tserver key :\n" << cfg.server_key.public_der();
        return os;
    }

    connection_impl::connection_impl(connection_config config, socket_type &&sock)
    : config_(std::move(config))
    , sock_(std::move(sock))
    , login_state_(config_.server_id, config_.server_key)
    {
    }

    auto
    connection_impl::start() -> void
    {
        dispatch(bind_executor(get_executor(), [self = shared_from_this()] {
            self->handle_start();
        }));
    }

    auto
    connection_impl::cancel() -> void
    {
        dispatch(bind_executor(get_executor(), [self = shared_from_this()] {
            self->handle_cancel();
        }));
    }

    auto
    connection_impl::get_executor() -> executor_type
    {
        return sock_.get_executor();
    }

    auto
    connection_impl::handle_cancel() -> void
    {
        sock_.cancel();
    }

    auto
    connection_impl::handle_start() -> void
    {
        initiate_read();
    }

    auto
    connection_impl::initiate_read() -> void
    {
        auto dynbuf = net::dynamic_buffer(rx_buffer_);

        struct packet_finished
        {
            using dynamic_buffer = decltype(dynbuf);
            using const_buffers_type = dynamic_buffer::const_buffers_type;
            using iterator = net::buffers_iterator<const_buffers_type>;

            using result_type = std::pair<iterator, bool>;

            result_type
            operator()(iterator first, iterator last) const
            {
                auto next = parser.parse_data(first, last);

                if (complete(parser.result()))
                    return std::make_pair(next, true);
                else
                    return std::make_pair(first, false);
            }


            minecraft::frame_parser &parser;
        };

        async_read_until(sock_, net::dynamic_buffer(rx_buffer_),
                         packet_finished{this->parser_},
                         bind_executor(get_executor(),
                                       [self = shared_from_this()](
                                       error_code const &ec,
                                       std::size_t bytes_transferred) {
                                           self->handle_read(ec, bytes_transferred);
                                       }));
    }

    auto
    connection_impl::handle_read(error_code ec, std::size_t bytes_transferred) -> void
    {
        auto &&packet = parser_.result();
        auto dynbuf = net::dynamic_buffer(rx_buffer_);
        if (!ec.failed())
        {
            if (std::holds_alternative<error_code>(packet.as_variant()))
                ec = std::get<error_code>(packet.as_variant());
            else if (std::holds_alternative<minecraft::incomplete>(packet.as_variant()))
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

        auto visitor = [this](auto &&pckt) {
            this->handle_rx(pckt);
        };

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

    auto
    connection_impl::handle_rx(error_code ec) -> void
    {
        throw system_error(ec);
    }

    auto
    connection_impl::handle_rx(minecraft::incomplete) -> void
    {
        assert(!"logic error");
        throw system_error(minecraft::error::incomplete_parse);
    }

    auto
    connection_impl::handle_rx(minecraft::client::handshake const &ch) -> void
    {
        login_state_(ch);
        parser_.state(ch.next_state);
    }

    auto
    connection_impl::handle_rx(minecraft::client::login_start const &packet) -> void
    {
        login_state_(packet);
        queue(login_state_.encryption_request_);
    }

    auto
    connection_impl::maybe_send() -> void
    {
        if (tx_buffer_[0].empty() and not tx_buffer_[1].empty())
        {
            std::swap(tx_buffer_[0], tx_buffer_[1]);
            net::async_write(sock_, net::buffer(tx_buffer_[0]), bind_executor(get_executor(),
                                                                              [self = this->shared_from_this()](
                                                                              error_code const &ec,
                                                                              std::size_t bytes_transferred) {
                                                                                  self->handle_write(ec,
                                                                                                     bytes_transferred);
                                                                              }));
        }
    }

    auto
    connection_impl::handle_write(error_code ec, std::size_t bytes_transferred) -> void
    {
        tx_buffer_[0].clear();
        if (!ec.failed())
            maybe_send();
    }






    // ======================================================

    connection::connection(connection_config config, socket_type &&sock)
    : impl_(std::make_shared<connection_impl>(std::move(config), std::move(sock)))
    {
        impl_->start();
    }

    void
    connection::cancel()
    {
        if (impl_)
            impl_->cancel();
    }

    auto
    connection::get_weak_impl() const -> std::weak_ptr<connection_impl>
    {
        return impl_;
    }

}