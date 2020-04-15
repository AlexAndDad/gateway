#include "connection_impl.hpp"

#include "minecraft/security/rsa.hpp"
#include "minecraft/send_frame.hpp"
#include "minecraft/server/chat_message.hpp"
#include "polyfill/hexdump.hpp"
#include "polyfill/report.hpp"

#include <random>

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

    auto connection_impl::get_executor() -> executor_type { return stream_.get_executor(); }

    auto connection_impl::handle_cancel() -> void { stream_.close(); }

    auto connection_impl::handle_start() -> void
    {
        //        initiate_read();

        login_params_.set_server_key(config_.server_key);
        login_params_.set_server_id(config_.server_id);
        login_params_.use_security(true);
        login_params_.on_fail = [](error_code ec) {
            std::cout << "handshake: failure: " << polyfill::report(ec) << std::endl;
        };
        login_params_.on_tx = [](net::const_buffer data) {
            std::cout << "handshake: send: " << data.size() << '\n';
            std::cout << polyfill::hexdump(std::string_view(reinterpret_cast< const char * >(data.data()), data.size()))
                      << std::endl;
        };
        login_params_.on_rx = [](net::const_buffer data) {
            std::cout << "handshake: receive: " << data.size() << '\n';
            std::cout << polyfill::hexdump(std::string_view(reinterpret_cast< const char * >(data.data()), data.size()))
                      << std::endl;
        };

        minecraft::protocol::async_receive_login(
            stream_,
            this->login_params_,
            bind_executor(get_executor(),
                          [self = this->shared_from_this()](error_code const &ec) { self->handle_login(ec); }));
    }

    auto connection_impl::handle_login(error_code const &ec) -> void
    {
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
            compose_buffer_.clear();
            compose(frame, compose_buffer_);
            stream_.async_write_frame(net::buffer(compose_buffer_), [](auto...) { std::cout << "chat sent\n"; });
            initiate_spin();
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