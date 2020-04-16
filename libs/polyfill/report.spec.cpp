#include <catch2/catch.hpp>
#include "polyfill/report.hpp"
#include <sstream>
#include <boost/beast/_experimental/test/handler.hpp>

TEST_CASE("config::net")
{
    using namespace polyfill;

    SECTION("reporter - endpoint")
    {
        std::string buf;
        std::ostringstream oss;

        auto ep = net::ip::tcp::endpoint(net::ip::make_address("127.0.0.1"), 4000);

        oss << report(ep);
        buf = to_string(report(ep));

        CHECK(buf == "127.0.0.1:4000");
        CHECK(oss.str() == "127.0.0.1:4000");
    }

    SECTION("reporter - socket")
    {
        auto ioc = net::io_context(1);

        auto client = net::ip::tcp::socket(ioc);
        auto server = net::ip::tcp::socket(ioc);
        auto acceptor  = net::ip::tcp::acceptor(ioc);

        std::string buf;
        std::ostringstream oss;

        auto ep = net::ip::tcp::endpoint(net::ip::make_address("127.0.0.1"), 4000);

        oss << report(client);
        buf = to_string(report(client));

        CHECK(buf == "Bad file descriptor -> Bad file descriptor");
        CHECK(oss.str() == "Bad file descriptor -> Bad file descriptor");

        acceptor.open(net::ip::tcp::v4());
        acceptor.bind(net::ip::tcp::endpoint(net::ip::address_v4::loopback(), 0));
        acceptor.listen();
        acceptor.async_accept(server, [](auto...) {});
        client.async_connect(acceptor.local_endpoint(), [](auto...){});

        boost::beast::test::run(ioc);

        auto loc = to_string(report(client.local_endpoint()));
        auto rem = to_string(report(client.remote_endpoint()));

        buf = to_string(report(server));
        oss.str("");
        oss << report(server);
        CHECK(buf == (rem + " -> " + loc));
        CHECK(oss.str() == (rem + " -> " + loc));

        buf = to_string(report(client));
        oss.str("");
        oss << report(client);
        CHECK(buf == (loc + " -> " + rem));
        CHECK(oss.str() == (loc + " -> " + rem));

    }
}