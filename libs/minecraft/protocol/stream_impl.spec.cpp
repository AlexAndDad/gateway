#include "stream_impl.hpp"

#include <boost/beast/_experimental/test/handler.hpp>
#include <boost/beast/_experimental/test/stream.hpp>
#include <catch2/catch.hpp>
#include <utility>

TEST_CASE("minecraft::stream_impl")
{
    using namespace minecraft;

    auto ioc = net::io_context();

    auto const payload     = std::string("the cat sat on the mat.");
    auto       secret      = shared_secret { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    auto       sender_impl = protocol::stream_impl(boost::beast::test::stream(ioc));
    auto       receiver    = connect(sender_impl.next_layer());

    error_code  ec;
    std::size_t bytes_transferred = 0;

    sender_impl.async_write(net::buffer(payload), [&ec, &bytes_transferred](error_code ec_, std::size_t bt_) {
        ec                = ec_;
        bytes_transferred = bt_;
    });
    boost::beast::test::run(ioc);
    CHECK(not ec.failed());
    CHECK(bytes_transferred == 23);

    sender_impl.enable_encryption(secret);

    ec.clear();
    bytes_transferred = 0;

    sender_impl.async_write(net::buffer(payload), [&ec, &bytes_transferred](error_code ec_, std::size_t bt_) {
        ec                = ec_;
        bytes_transferred = bt_;
    });

    boost::beast::test::run(ioc);
    CHECK(not ec.failed());
    CHECK(bytes_transferred == 23);

    sender_impl.close();

    std::vector< char > rx_data;
    bytes_transferred = net::read(receiver, net::dynamic_buffer(rx_data), ec);
    CHECK(bytes_transferred == 46);
    CHECK(ec == net::error::eof);
    auto expected = std::vector< char > {
        't',    'h', 'e',  ' ',    'c',    'a',    't', ' ', 's',    'a',    't', ' ',    'o',    'n',    ' ', 't',
        'h',    'e', ' ',  'm',    'a',    't',    '.', '~', '\xbe', '\xB5', 'o', '\xE0', '\xF6', '\xF1', 20,  '\x95',
        '\xA1', 'c', '\\', '\x89', '\xBF', '\x84', 21,  22,  '\x89', '3',    20,  '\t',   'I',    '\xC3'
    };

    CHECK(rx_data == expected);
}