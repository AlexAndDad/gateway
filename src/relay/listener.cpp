#include "listener.hpp"

#include "minecraft/report.hpp"

#include <spdlog/spdlog.h>

namespace relay
{
    auto operator<<(std::ostream &os, listener_config const &cfg) -> std::ostream &
    {
        os << "Listener Config\n";
        os << "\tlisten port : " << cfg.listen_port;
        os << '\n';
        os << cfg.as_connection_config();
        return os;
    }

    listener::listener(executor_type exec, listener_config config)
    : acceptor_(exec)
    , config_(std::move(config))
    {
        acceptor_.open(protocol::v4());
        acceptor_.set_option(socket_type::reuse_address());
        acceptor_.bind(
            protocol::endpoint(net::ip::make_address("0.0.0.0"), std::uint16_t(::atoi(config_.listen_port.c_str()))));
        acceptor_.listen();
        spdlog::info("relay: listening on {}", minecraft::report(acceptor_));
    }

    void listener::handle_accept(error_code ec, socket_type sock)
    {
        spdlog::trace("{}::{}({}, {})", this, __func__, minecraft::report(ec), minecraft::report(sock));

        if (ec.failed())
        {
            if (ec == net::error::connection_aborted)
                initiate_accept();
            else if (ec != net::error::operation_aborted)
                std::clog << "listener: accept error: " << ec.message() << std::endl;
        }
        else
        {
            auto ep = sock.remote_endpoint();
            std::clog << "listener: new connection from " << ep.address() << ':' << ep.port() << std::endl;

            connections_.create(config_, std::move(sock));

            initiate_accept();
        }
    }

    void listener::handle_cancel()
    {
        acceptor_.cancel();
        connections_.cancel();
    }

    void listener::initiate_accept()
    {
        spdlog::trace("{} initiating accept", this);
        acceptor_.async_accept(
            [this](error_code const &ec, socket_type sock) { this->handle_accept(ec, std::move(sock)); });
    }

}   // namespace relay