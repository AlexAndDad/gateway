//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "config.hpp"
#include "minecraft/packets/client/handshake.hpp"
#include "minecraft/protocol/stream.hpp"
#include "polyfill/async/has_error.hpp"
#include "polyfill/async/has_resolver.hpp"
#include "polyfill/async/has_timeout.hpp"
#include "polyfill/net/shared_composed_op.hpp"

#include <boost/asio/compose.hpp>
#include <boost/asio/coroutine.hpp>
#include <boost/json.hpp>
#include <minecraft/status_packets.hpp>

namespace bot
{

    template < class NextLayer >
    struct ping_op
    : boost::asio::coroutine
    , polyfill::async::has_error
    , polyfill::async::has_timeout< ping_op< NextLayer > >
    , polyfill::async::has_resolver< ping_op< NextLayer > >
    {
        using has_timeout  = polyfill::async::has_timeout< ping_op< NextLayer > >;
        using has_resolver = polyfill::async::has_resolver< ping_op< NextLayer > >;

        ping_op(minecraft::protocol::stream< NextLayer > &stream, std::string hostname, std::string service)
        : coroutine()
        , has_error()
        , has_timeout(stream.get_executor())
        , has_resolver(stream.get_executor())
        , stream_(stream)
        , hostname_(std::move(hostname))
        , service_(std::move(service))
        , client_packet_()
        , server_packet_()
        , result_()
        , rx_time_()
        , tx_time_()
        {
        }

        using has_resolver::operator();
        using has_timeout:: operator();

        template < class Self >
        using shared = polyfill::net::shared< Self >;
        template < class Self >
        void operator()(Self &self)
        {
            polyfill::net::share(std::move(self));
        }

        void on_timeout()
        {
            this->cancel_resolver();
            this->stream_.cancel();
        }

        void on_resolve() { this->cancel_timeout(); }

        void on_connect() { this->cancel_timeout(); }

        struct connect_event
        {
        };
        bool connecting_ = false;

        template < class Self >
        void operator()(shared< Self > self, connect_event, error_code ec)
        {
            connecting_ = false;
            on_connect();
            (*this)(std::move(self), this->set_error(ec));
        }

        auto connecting() -> bool { return connecting_; }

        struct frame_event
        {
        };

        bool receiving_ = false;

        template < class Self >
        void start_read_frame(shared< Self > self)
        {
            receiving_ = true;
            stream_.async_read_frame(boost::beast::bind_front_handler(std::move(self), frame_event()));
        }

        template < class Self >
        void operator()(shared< Self > self, frame_event, error_code ec, std::size_t)
        {
            rx_time_   = std::chrono::high_resolution_clock::now();
            receiving_ = false;
            this->cancel_timeout();
            (*this)(std::move(self), this->set_error(ec));
        }

        bool receiving() const { return receiving_; }
        bool received() const { return !receiving_; }

        template < class ServerPkt >
        ServerPkt *expect(error_code &ec)
        {
            ServerPkt *result = nullptr;
            auto       span   = minecraft::to_span(stream_.current_frame());
            parse(span.begin(), span.end(), server_packet_, ec);
            if (!ec)
            {
                result = server_packet_.query< ServerPkt >();
                if (!result)
                    ec = minecraft::error::unexpected_packet;
            }
            return result;
        }

        template < class Self >
        void operator()(shared< Self > self, error_code ec = {}, std::size_t = 0)
        {
#include <boost/asio/yield.hpp>
            reenter(this)
            {
                yield
                {
                    this->start_timeout(10s, self);
                    this->start_resolver(hostname_, service_, self);
                }

                while (this->resolving() or this->timing_out())
                {
                    yield {};
                }
                if (ec)
                    goto done;

                for (iter = this->resolve_results().begin(); iter != this->resolve_results().end(); ++iter)
                {
                    yield
                    {
                        this->start_timeout(5s, self);
                        stream_.next_layer().async_connect(
                            iter->endpoint(), boost::beast::bind_front_handler(std::move(self), connect_event()));
                        connecting_ = true;
                    }
                    while (this->connecting() or this->timing_out())
                        yield;
                    if (not ec)
                        break;
                    else if (iter != this->resolve_results().end())
                        ec = this->clear_error();
                    if (ec)
                        goto done;
                }

                yield
                {
                    handshake_.protocol_version = minecraft::protocol::version_type::v1_15_2;
                    handshake_.next_state = minecraft::protocol::connection_state::status;
                    handshake_.server_port = stream_.next_layer().remote_endpoint().port();
                    handshake_.server_address = hostname_;
                    stream_.async_write_packet(handshake_, std::move(self));
                }
                if (this->set_error(ec))
                    goto done;

                yield
                {
                    auto &pkt = client_packet_.emplace< minecraft::client::status_request >();
                    stream_.async_write_packet(pkt, std::move(self));
                }
                if (this->set_error(ec))
                    goto done;

                yield
                {
                    this->start_timeout(5s, self);
                    this->start_read_frame(self);
                }

                while (this->timing_out() or this->receiving())
                    yield;
                if (!ec)
                    if (auto pkt = expect< minecraft::server::status_response >(ec))
                        result_.json = boost::json::parse(pkt->json, ec);
                if (ec)
                    goto done;

                yield
                {
                    auto &pkt   = client_packet_.emplace< minecraft::client::status_ping >();
                    pkt.payload = 1234;
                    tx_time_    = std::chrono::high_resolution_clock::now();
                    stream_.async_write_packet(pkt, std::move(self));
                }
                if (ec)
                    goto done;

                yield
                {
                    this->start_timeout(5s, self);
                    this->start_read_frame(self);
                }
                while (this->receiving() or this->timing_out())
                    yield;

                if (!ec)
                    if (expect< minecraft::server::status_pong >(ec))
                        result_.ping_time =
                            std::chrono::duration_cast< std::chrono::microseconds >(rx_time_ - tx_time_);

            done:
                self.complete(ec, std::move(result_));
            }
#include <boost/asio/unyield.hpp>
        }

      private:
        minecraft::protocol::stream< NextLayer > &          stream_;
        std::string                                         hostname_, service_;
        typename has_resolver::results_type::const_iterator iter;
        minecraft::packets::client::handshake               handshake_;
        minecraft::client::status_packet                    client_packet_;
        minecraft::server::status_packet                    server_packet_;
        ping_result                                         result_;
        std::chrono::high_resolution_clock::time_point      rx_time_, tx_time_;
    };

}   // namespace bot