#include "polyfill/report.hpp"

#include <boost/beast/_experimental/test/handler.hpp>
#include <catch2/catch.hpp>
#include <sstream>

TEST_CASE("config::net")
{
    using namespace polyfill;

    SECTION("reporter - endpoint")
    {
        std::string        buf;
        std::ostringstream oss;

        auto ep = net::ip::tcp::endpoint(net::ip::make_address("127.0.0.1"), 4000);

        oss << report(ep);
        buf = fmt::format("{}", report(ep));

        CHECK(buf == "127.0.0.1:4000");
        CHECK(oss.str() == "127.0.0.1:4000");
    }

    SECTION("reporter - socket")
    {
        auto ioc = net::io_context(1);

        auto client   = net::ip::tcp::socket(ioc);
        auto server   = net::ip::tcp::socket(ioc);
        auto acceptor = net::ip::tcp::acceptor(ioc);

        std::string        buf;
        std::ostringstream oss;

        auto ep = net::ip::tcp::endpoint(net::ip::make_address("127.0.0.1"), 4000);

        oss << report(client);
        buf = fmt::format("{}", report(client));

        CHECK(buf == "[socket [error_code \"Bad file descriptor\",9,\"system\"]->[error_code \"Bad file descriptor\",9,\"system\"]]");
        CHECK(oss.str() == "[socket [error_code \"Bad file descriptor\",9,\"system\"]->[error_code \"Bad file descriptor\",9,\"system\"]]");

        acceptor.open(net::ip::tcp::v4());
        acceptor.bind(net::ip::tcp::endpoint(net::ip::address_v4::loopback(), 0));
        acceptor.listen();
        acceptor.async_accept(server, [](auto...) {});
        client.async_connect(acceptor.local_endpoint(), [](auto...) {});

        boost::beast::test::run(ioc);

        auto loc = fmt::format("{}", client.local_endpoint());
        auto rem = fmt::format("{}", client.remote_endpoint());

        buf = fmt::format("{}", report(server));
        oss.str("");
        oss << report(server);
        CHECK(buf == fmt::format("[socket {}->{}]", rem, loc));
        CHECK(oss.str() == fmt::format("[socket {}->{}]", rem, loc));

        buf = fmt::format("{}", report(client));
        oss.str("");
        oss << report(client);
        CHECK(buf == fmt::format("[socket {}->{}]", loc, rem));
        CHECK(oss.str() == fmt::format("[socket {}->{}]", loc, rem));
    }
}