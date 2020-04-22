#include "listener.hpp"

using namespace std::literals;

namespace gateway
{
    auto operator<<(std::ostream &os, listener_config const &cfg) -> std::ostream &
    {
        os << "Listener Config\n";
        os << cfg.as_connection_config();
        return os;
    }

    void listener::handle_accept(error_code ec, socket_type sock)
    {
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

            connections_.create(config_, std::move(sock), bus_);

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
        acceptor_.async_accept(
            [this](error_code const &ec, socket_type sock) { this->handle_accept(ec, std::move(sock)); });
    }

}   // namespace gateway