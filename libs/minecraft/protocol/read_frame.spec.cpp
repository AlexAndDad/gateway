#include "minecraft/net.hpp"
#include "read_frame.hpp"

#include <boost/beast.hpp>
#include <boost/beast/_experimental/test/handler.hpp>
#include <boost/beast/_experimental/test/stream.hpp>
#include <catch2/catch.hpp>

TEST_CASE("minecraft::read_frame")
{
    using namespace minecraft;
    using namespace std::literals;

    net::io_context ioc;
    auto ec = error_code();
    std::size_t frame_length = 0;

    std::vector<std::uint8_t> store;

    auto iterate = [&ioc, &ec, &frame_length, &store](std::string data)
    {
        store.clear();
        boost::beast::test::stream client(ioc), server(ioc);
        client.connect(server);
        client.write_some(net::buffer(data));
        client.close();
        protocol::async_read_frame(server, net::dynamic_buffer(store), [&](config::error_code ec_, std::size_t bt){
            ec = ec_;
            frame_length = bt;
        });
        boost::beast::test::run(ioc);
    };

    iterate(std::string("\x80\x80\x80\x80\x01", 2) + std::string(0x40, ' '));
    REQUIRE(ec == net::error::eof);
    REQUIRE(frame_length == 0);

    iterate(std::string("\x01\x02", 2));
    REQUIRE(!ec.failed());
    REQUIRE(frame_length == 1);
    REQUIRE(store.size() >= 1);
    REQUIRE(store[0] == std::uint8_t(2));

    iterate(std::string("\x80\x01", 2) + std::string(0x80, ' '));
    REQUIRE(!ec.failed());
    REQUIRE(frame_length == 0x80);
    REQUIRE(store[0] == ' ');

    iterate(std::string("\x80\x01", 2) + std::string(0x40, ' '));
    REQUIRE(ec == net::error::eof);
    REQUIRE(frame_length == 0);





}