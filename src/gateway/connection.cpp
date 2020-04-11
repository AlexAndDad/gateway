#include "connection.hpp"
#include "hexdump.hpp"
#include <iostream>

namespace gateway {

    connection_impl::connection_impl(socket_type &&sock)
    : sock_(std::move(sock))
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
                auto next = parser.parse(first, last);

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
    connection_impl::handle_read(error_code const &ec, std::size_t bytes_transferred) -> void
    {
        if (ec.failed())
        {
            if (ec != net::error::operation_aborted)
            {
                std::clog << "connection: " << ec.message() << " : closing" << std::endl;
            }
        }
        else
        {
            std::cout << hexdump(std::string_view(rx_buffer_.data(), bytes_transferred)) << std::endl;
            auto dynbuf = net::dynamic_buffer(rx_buffer_);
            std::cout << parser_.result() << std::endl;
            dynbuf.consume(bytes_transferred);


            initiate_read();
        }
    }




    // ======================================================

    connection::connection(socket_type &&sock)
    : impl_(std::make_shared<connection_impl>(std::move(sock)))
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