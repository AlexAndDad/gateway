#pragma once
#include "minecraft/client/encryption_response.hpp"
#include "minecraft/client/handshake.hpp"
#include "minecraft/client/login_start.hpp"
#include "minecraft/hexdump.hpp"
#include "minecraft/net.hpp"
#include "minecraft/read_frame.hpp"
#include "minecraft/security/private_key.hpp"
#include "minecraft/server/encryption_request.hpp"
#include "minecraft/server/login_success.hpp"
#include "minecraft/stream.hpp"

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace minecraft::server
{
    struct receive_login_params
    {
        void set_server_key(minecraft::security::private_key k) { server_key = std::move(k); }

        void set_server_id(std::string id) { server_encryption_request.server_id = std::move(id); }

        void use_security(bool tf) { use_security_ = tf; }
        bool use_security() const { return use_security_; }

        // inputs
        std::vector< std::uint8_t >      security_token;
        minecraft::security::private_key server_key;
        bool                             use_security_ = true;

        // state
        client::handshake           client_handshake_frame;
        client::login_start         client_login_start;
        server::encryption_request  server_encryption_request;
        client::encryption_response client_encryption_response;
        server::login_success       server_login_success;
        std::vector< std::uint8_t > shared_secret;
        std::function<void(net::mutable_buffer)> on_rx;
        std::function<void(net::const_buffer)> on_tx;
        std::function<void(error_code)> on_fail;

        error_code const& log_fail(error_code const& ec)
        {
            if (on_fail)
                on_fail(ec);
            return ec;
        }

        net::mutable_buffer log_rx(net::mutable_buffer buf)
        {
            if (on_rx)
                on_rx(buf);
            return buf;
        }

        net::const_buffer log_tx(net::const_buffer buf)
        {
            if (on_tx)
                on_tx(buf);
            return buf;
        }

        friend auto operator<<(std::ostream &os, receive_login_params const &arg) -> std::ostream &
        {
            os << "receive login params :\n";
            os << " security token        : " << hexstring(arg.security_token) << std::endl;
            os << " server key            :\n" << arg.server_key.public_pem() << std::endl;
            os << " use security          : " << arg.use_security() << std::endl;
            os << "client handshake frame :\n" << arg.client_handshake_frame << std::endl;
            os << "client login start     :\n" << arg.client_login_start << std::endl;
            os << "server encryption request :\n" << arg.server_encryption_request << std::endl;
            os << "client encryption response :\n" << arg.client_encryption_response << std::endl;
            os << "shared secret : " << hexstring(arg.shared_secret) << std::endl;
            os << arg.server_login_success;
            return os;
        }
    };

    struct login_op_base
    {
        static boost::uuids::uuid generate_uuid();
    };

    template < class Stream, class DynamicBuffer >
    struct receive_login_op
    : net::coroutine
    , login_op_base
    {
        receive_login_op(Stream &stream, DynamicBuffer buffer, receive_login_params &params)
        : stream_(stream)
        , buffer_(buffer)
        , params_(params)
        , tx_buffer_()
        {
            tx_buffer_.reserve(0x10000);
        }

        template < class FrameType >
        static void expect_frame(FrameType &target, net::const_buffer source, error_code &ec)
        {
            auto first = reinterpret_cast< std::uint8_t const * >(source.data());
            auto last  = first + source.size();
            auto which = target.id();
            auto n     = parse2(first, last, which, ec);
            if (!ec.failed())
                if (which != target.id())
                    ec = error::unexpected_packet;
            if (!ec.failed())
            {
                first += n;
                parse(first, last, target, ec);
            }
        }

        template < class Self >
        void operator()(Self &self, error_code ec = {}, std::size_t bytes_transferred = 0)
        {
#include <boost/asio/yield.hpp>
            reenter(this) for (;;)
            {
                yield async_expect_frame(stream_, buffer_, params_.client_handshake_frame, std::move(self));
                if (ec.failed())
                    return self.complete(ec);
                if (params_.client_handshake_frame.validate(ec).failed())
                    return self.complete(ec);

                yield async_expect_frame(stream_, buffer_, params_.client_login_start, std::move(self));
                if (ec.failed())
                    return self.complete(ec);

                if (not params_.use_security())
                {
                    params_.server_login_success.username = params_.client_login_start.name;
                    params_.server_login_success.uuid     = to_string(generate_uuid());
                    goto send_success;
                }

                prepare(params_.server_encryption_request, params_.server_key);
                tx_buffer_.clear();
                encode(params_.server_encryption_request, std::back_inserter(tx_buffer_));
                yield async_write(stream_, net::buffer(tx_buffer_), std::move(self));
                if (ec.failed())
                    return self.complete(ec);

                yield async_expect_frame(stream_, buffer_, params_.client_encryption_response, std::move(self));
                if (ec.failed())
                    return self.complete(ec);

                params_.shared_secret =
                    params_.client_encryption_response.decrypt_secret(params_.server_key, params_.server_encryption_request.verify_token, ec);

                return self.complete(error::not_implemented);

            send_success:
                tx_buffer_.clear();
                encode(params_.server_login_success, tx_buffer_);
                yield async_write(stream_, net::buffer(tx_buffer_), std::move(self));
                return self.complete(ec);
            }
#include <boost/asio/unyield.hpp>

        }   // namespace minecraft::server

        Stream &              stream_;
        DynamicBuffer         buffer_;
        receive_login_params &params_;
        std::vector< char >   tx_buffer_;
    };   // namespace minecraft::server

    template < class Stream, class DynamicBuffer, class CompletionHandler >
    auto
    async_receive_login(Stream &stream, DynamicBuffer buffer, receive_login_params &params, CompletionHandler &&handler)
    {
        using op_type = receive_login_op< Stream, DynamicBuffer >;
        return net::async_compose< CompletionHandler, void(error_code) >(
            op_type(stream, buffer, params), handler, stream);
    }

    template < class NextLayer, class CompletionHandler >
    auto async_receive_login(stream< NextLayer > &stream, receive_login_params &params, CompletionHandler &&handler)
    {
        auto op = [&stream, &params, coro = net::coroutine(), compose_buffer = std::vector< char >()](
                      auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
#include <boost/asio/yield.hpp>
            reenter(coro) for (;;)
            {
                yield stream.async_read_frame(std::move(self));
                if (ec.failed())
                    return self.complete(params.log_fail(ec));
                params.log_rx(stream.current_frame());
                if (expect_frame(stream.current_frame(), params.client_handshake_frame, ec).failed())
                    return self.complete(params.log_fail(ec));

                yield stream.async_read_frame(std::move(self));
                if (ec.failed())
                    return self.complete(params.log_fail(ec));
                params.log_rx(stream.current_frame());
                if (expect_frame(stream.current_frame(), params.client_login_start, ec).failed())
                    return self.complete(params.log_fail(ec));

                if (params.use_security())
                {
                    //
                    // send encryption request
                    //

                    prepare(params.server_encryption_request, params.server_key);
                    compose_buffer.clear();
                    compose(params.server_encryption_request, compose_buffer);
                    yield
                    {
                        auto buf = net::buffer(compose_buffer);
                        params.log_tx(buf);
                        stream.async_write_frame(buf, std::move(self));
                    };
                    if (ec.failed())
                        return self.complete(params.log_fail(ec));

                    //
                    // receive encryption response
                    //

                    yield stream.async_read_frame(std::move(self));
                    if (ec.failed())
                        return self.complete(params.log_fail(ec));
                    params.log_rx(stream.current_frame());
                    if (expect_frame(stream.current_frame(), params.client_encryption_response, ec).failed())
                        return self.complete(params.log_fail(ec));
                    params.shared_secret =
                        params.client_encryption_response.decrypt_secret(params.server_key, params.server_encryption_request.verify_token, ec);
                    if (ec.failed())
                        return self.complete(params.log_fail(ec));

                    //
                    // set encrypted mode
                    //

                    stream.set_encryption(net::buffer(params.shared_secret));

                    //
                    // todo : contact minecraft server here for uuid
                    //

                    params.server_login_success.username = params.client_login_start.name;
                    params.server_login_success.uuid     = to_string(login_op_base::generate_uuid());
                }
                else
                {
                    params.server_login_success.username = params.client_login_start.name;
                    params.server_login_success.uuid     = to_string(login_op_base::generate_uuid());
                }

                //
                // send login success
                //

                compose_buffer.clear();
                compose(params.server_login_success, compose_buffer);
                yield
                {
                    auto buf = net::buffer(compose_buffer);
                    params.log_tx(buf);
                    stream.async_write_frame(buf, std::move(self));
                }
                return self.complete(ec);
            }
#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionHandler, void(error_code) >(std::move(op), handler, stream);
    }
}   // namespace minecraft::server