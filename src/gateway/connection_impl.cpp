#include "connection_impl.hpp"

#include "minecraft/security/rsa.hpp"
#include "minecraft/server/chat_message.hpp"
#include "minecraft/send_frame.hpp"

#include "polyfill/report.hpp"

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

    // =========================================

    connection_impl::connection_impl(connection_config config, socket_type &&sock)
        : config_(std::move(config))
        , sock_(std::move(sock))
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
                    auto frame      = minecraft::server::chat_message();
                    frame.json_data = R"json({ "text" : "Hello, World!", "bold" : true })json";
                    frame.position  = minecraft::server::chat_message::chat_position ::system_message;
                    minecraft::async_send_frame(self->sock_, frame, [](auto...) { std::cout << "chat sent\n"; });
                    self->initiate_spin();
                }
                std::cout << "login state: \n" << self->login_params_ << std::endl;
            }));
    }

    void connection_impl::initiate_spin()
    {
        minecraft::async_read_frame(
            sock_,
            net::dynamic_buffer(rx_buffer_),
            bind_executor(get_executor(),
                          [self = shared_from_this()](error_code ec, std::size_t bt) { self->handle_spin(ec, bt); }));
    }

    void connection_impl::handle_spin(error_code ec, std::size_t bytes_transferrred)
    {
        if (ec.failed())
        {
            std::cerr << "rx error : " << polyfill::report(ec) << std::endl;
        }
        else
        {
            auto id = std::int32_t();
            auto i  = minecraft::parse_var(rx_buffer_.begin(), rx_buffer_.end(), id, ec);
            std::cout << "received frame length: " << bytes_transferrred;
            std::cout << " : type " << std::hex << id << std::endl;
            net::dynamic_buffer(rx_buffer_).consume(bytes_transferrred);
            initiate_spin();
        }
    }

}