#include "minecraft/client/handshake.hpp"
#include "stream.hpp"

#include <boost/beast/_experimental/test/handler.hpp>
#include <boost/beast/_experimental/test/stream.hpp>
#include <boost/beast/core/buffers_to_string.hpp>
#include <catch2/catch.hpp>

TEST_CASE("minecraft::stream")
{
    using namespace minecraft;
    using test_stream = boost::beast::test::stream;
    using boost::beast::test::run;
    auto ioc = net::io_context();

    auto sender   = protocol::stream< test_stream >(test_stream(ioc));
    auto receiver = protocol::stream< test_stream >(connect(sender.next_layer()));

    error_code  ec;
    std::size_t bytes_transferred = 0;

    SECTION("send hello")
    {
        auto frame_data = std::string("Hello");
        sender.async_write_frame(net::buffer(frame_data),
                                 [&ec, &bytes_transferred](error_code ec_, std::size_t bytes_transferred_) {
                                     ec                = ec_;
                                     bytes_transferred = bytes_transferred_;
                                 });
        boost::beast::test::run(ioc);
        CHECK(bytes_transferred == 6);
        CHECK(not ec.failed());

        receiver.async_read_frame([&ec, &bytes_transferred](error_code ec_, std::size_t bytes_transferred_) {
                                      ec                = ec_;
                                      bytes_transferred = bytes_transferred_;
                                  });
        boost::beast::test::run(ioc);
        CHECK(bytes_transferred == 5);
        CHECK(not ec.failed());
        auto frame_body = receiver.current_frame();
        CHECK(boost::beast::buffers_to_string(frame_body) == frame_data);
    }
}