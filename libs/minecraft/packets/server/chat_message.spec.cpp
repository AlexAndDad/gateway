#include "config/net.hpp"
#include "minecraft/net.hpp"
#include "minecraft/packets/server/chat_message.hpp"

#include <boost/beast/_experimental/test/handler.hpp>
#include <boost/beast/_experimental/test/stream.hpp>
#include <catch2/catch.hpp>
#include <minecraft/send_frame.hpp>

#include <minecraft/packets/packet_tests.spec.hpp>

TEST_CASE("minecraft::packets::server::chat_message")
{
    using namespace minecraft;

    SECTION("standard ops")
    {
        auto pkt     = packets::server::chat_message();
        pkt.json_data = R"__json__({ "text": "foo", "bold": "true", })__json__";
        pkt.position  = packets::server::chat_message::game_info ;

        auto expected = "[chat_message [json_data { \"text\": \"foo\", \"bold\": \"true\", }] [position game_info]]";

        auto s       = to_string(pkt);
        CHECK(s == expected);

        auto ss = std::ostringstream();
        ss << pkt;
        CHECK(ss.str() == expected);

        minecraft::tests::packet_round_trip(pkt);
    }

    SECTION("over a stream")
    {
        auto msg      = minecraft::packets::server::chat_message();
        msg.json_data = R"__json__({ "text": "foo", "bold": "true", })__json__";
        msg.position  = minecraft::packets::server::chat_message::chat_position::system_message;

        auto ioc               = net::io_context();
        auto client            = boost::beast::test::stream(ioc);
        auto server            = connect(client);
        auto ec                = error_code();
        auto bytes_transferred = std::size_t(0);
        async_send_frame(server, msg, [&ec, &bytes_transferred](error_code ec_, std::size_t bt_) {
            ec                = ec_;
            bytes_transferred = bt_;
        });

        boost::beast::test::run(ioc);
        CHECK(!ec.failed());
        CHECK(bytes_transferred == 38);
        server.close();

        std::vector< char > buf;
        net::async_read(client, net::dynamic_buffer(buf), [&](error_code ec_, std::size_t bt_) {
            ec                = ec_;
            bytes_transferred = bt_;
        });

        boost::beast::test::run(ioc);
        CHECK(ec == net::error::eof);
        CHECK(bytes_transferred == 38);

        CHECK(buf == std::vector< char > { '%', 15,  '"', '{', ' ', '"', 't', 'e', 'x', 't', '"', ':', ' ',
                                           '"', 'f', 'o', 'o', '"', ',', ' ', '"', 'b', 'o', 'l', 'd', '"',
                                           ':', ' ', '"', 't', 'r', 'u', 'e', '"', ',', ' ', '}', 1 });
    }
}